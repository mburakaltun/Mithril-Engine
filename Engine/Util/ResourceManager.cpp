#define TINYOBJLOADER_IMPLEMENTATION
#define GLM_ENABLE_EXPERIMENTAL
#include "ResourceManager.h"
#include "vendor/TinyObjectLoader/tiny_obj_loader.h"
#include <unordered_map>
#include <glm/gtx/hash.hpp>
#include "../vendor/STB/stb_image.h"
#include <glm/glm.hpp>

void ResourceManager::readShaderSource(const char* filePath, std::string& out) {
	std::ifstream File(filePath);
	std::string temp;
	out.clear();

	if (File.good()) {
		while (File.good()) {
			std::getline(File, temp);
			out.append(temp);
			out.append("\n");
		}

		std::cout << std::endl;

	}
	else {
		std::cout << "Could not open the given file" << std::endl;
	}
}

void ResourceManager::readImage(const char* filePath, std::basic_string<unsigned char>& imageData, int *width, int *height, int* nChannels)
{
	unsigned char* data = stbi_load(filePath, width, height, nChannels, 0);

	if (!stbi_failure_reason()) {
		imageData.assign(data, (*width) * (*height) * (*nChannels));
		stbi_image_free(data);
	} else {
		std::cout << "Cannot read the given texture file." << std::endl;
		std::cout << stbi_failure_reason();
		*width = 0; *height = 0; *nChannels = 0;
	}
}

bool compareVertices(Mithril::GLVertexPNT& v1, Mithril::GLVertexPNT& v2) {

	glm::bvec3 v = glm::equal(v1.m_vertexCoords, v2.m_vertexCoords);
	glm::bvec3 n = glm::equal(v1.m_normal, v2.m_normal);
	glm::bvec2 t = glm::equal(v1.m_textureCoords, v2.m_textureCoords);

	if (v.x && v.y && v.z && n.x && n.y && n.z && t.x && t.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#if 0
std::shared_ptr<Mithril::Model> ResourceManager::loadModel(const std::string &modelPath)
{
	//clearing model verticex and index data just in case
	std::vector<Mithril::Vertex> vertices;
	std::vector<unsigned int> indices;
	std::unordered_map<size_t, unsigned int> uniqueVertices;

	bool isTextured = true;

	//std::string inputfile = "cornell_box.obj";
	tinyobj::ObjReaderConfig reader_config;
	reader_config.mtl_search_path = "./"; // Path to material files

	tinyobj::ObjReader reader;
	Mithril::Vertex temp_vertex(glm::vec3(0.0f));

	if (!reader.ParseFromFile(modelPath, reader_config)) {
		if (!reader.Error().empty()) {
			std::cerr << "TinyObjReader: " << reader.Error();
		}
		exit(1);
	}

	if (!reader.Warning().empty()) {
		std::cout << "TinyObjReader: " << reader.Warning();
	}

	auto& attrib = reader.GetAttrib();
	auto& shapes = reader.GetShapes();
	auto& materials = reader.GetMaterials();

	if (attrib.texcoords.empty()) isTextured = false;
	// Loop over shapes
	for (size_t s = 0; s < shapes.size(); s++) {
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
			int fv = shapes[s].mesh.num_face_vertices[f];

			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++) {
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				temp_vertex.m_vertexCoords.x = attrib.vertices[3 * idx.vertex_index + 0];
				temp_vertex.m_vertexCoords.y = attrib.vertices[3 * idx.vertex_index + 1];
				temp_vertex.m_vertexCoords.z = attrib.vertices[3 * idx.vertex_index + 2];
				//temp_vertex.normal.x = attrib.normals[3 * idx.normal_index + 0];
				//temp_vertex.normal.y = attrib.normals[3 * idx.normal_index + 1];
				//temp_vertex.normal.z = attrib.normals[3 * idx.normal_index + 2];
				//temp_vertex.textureCoords.x = attrib.texcoords[2 * idx.texcoord_index + 0];
				//temp_vertex.textureCoords.y = attrib.texcoords[2 * idx.texcoord_index + 1];


				/*
				bool foundFlag = false;
				unsigned int counter = 0;

				for (auto& vertex : vertices) {
					if (compareVertices(temp_vertex, vertex)) {
						++duplicateCounter;
						foundFlag = true;
						break;
					}
					++counter;
				}
				
				if (!foundFlag)
					vertices.push_back(temp_vertex);
				

				indices.push_back(counter);

				*/

				auto vertexHash = std::hash<glm::vec3>()(temp_vertex.m_vertexCoords);

				if (uniqueVertices.count(vertexHash) == 0) {
					uniqueVertices[vertexHash] = static_cast<unsigned int>(vertices.size());
					vertices.push_back(temp_vertex);
				}

				indices.push_back(uniqueVertices[vertexHash]);
			}

			index_offset += fv;

			// per-face material
			shapes[s].mesh.material_ids[f];
		}
	}

	std::cout << "Number of vertices: " << vertices.size()  << std::endl;

	return std::make_shared<Mithril::Model>(vertices, indices, isTextured);
}
#endif