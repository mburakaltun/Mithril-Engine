#include "ModelLoader.h"
#include <Core/ECS/Vertex/Hash.h>
#include <Core/Math/Math.h>
#include "../Core/ECS/Vertex/vec3.h"
#include "../Core/ECS/Vertex/vec2.h"
#include "../Core/ECS/Vertex/VertexPNT.h"
#include "../vendor/TinyObjectLoader/tiny_obj_loader.h"
#include <unordered_map>
#include <iostream>
#include <functional>


std::pair<std::vector<VertexPNT>, std::vector<unsigned int>> MithrilModelLoader::loadDefaultTexturedCube()
{
	std::vector<Mithril::VertexPNT> vertexArray(
		{
			{0.5f,   0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 1.0f},
			{0.5f,  -0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 0.0f},
			{-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 0.0f},
			{-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 1.0f},
			{0.5f,   0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 1.0f},
			{0.5f,  -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 0.0f},
			{-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 0.0f},
			{-0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 1.0f},

			{0.5f,   0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 1.0f},
			{0.5f,  -0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 0.0f},
			{-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 0.0f},
			{-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 1.0f},
			{0.5f,   0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 1.0f},
			{0.5f,  -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 0.0f},
			{-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 0.0f},
			{-0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 1.0f},

			{0.5f,   0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 1.0f},
			{0.5f,  -0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 0.0f},
			{-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 0.0f},
			{-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 1.0f},
			{0.5f,   0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 1.0f},
			{0.5f,  -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     0.0f, 0.0f},
			{-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 0.0f},
			{-0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,     1.0f, 1.0f}
		}
	);

	std::vector<unsigned int> indexArray(
		{
		0,3,1,
		1,3,2,

		7,4,5,
		7,5,6,

		0 + 8,4 + 8,3 + 8,
		4 + 8,7 + 8,3 + 8,

		3 + 16,6 + 16,2 + 16,
		3 + 16,7 + 16,6 + 16,

		0 + 16,5 + 16,4 + 16,
		0 + 16,1 + 16,5 + 16,

		1 + 8,2 + 8,5 + 8,
		5 + 8,2 + 8,6 + 8
		}
	);

	setVertexNormals(vertexArray, indexArray);

	return MeshData(vertexArray, indexArray);
}

std::pair<std::vector<VertexPNT>, std::vector<unsigned int>> MithrilModelLoader::loadWavefrontOBJFile(const std::string& modelPath)
{
	std::vector<Mithril::VertexPNT> vertices;
	std::vector<unsigned int> indices;
	std::unordered_map<VertexPNT, unsigned int> uniqueVertices;

	//Reading the file with the help of tinyObjLoader
	tinyobj::ObjReaderConfig reader_config;
	reader_config.mtl_search_path = "./";

	tinyobj::ObjReader reader;
	Mithril::VertexPNT tempVertex;

	bool isTextured = true;

	if (!reader.ParseFromFile(modelPath, reader_config))
	{
		if (!reader.Error().empty())
			std::cerr << "ERROR: TinyObjReader: " << reader.Error();

		return loadDefaultTexturedCube();
	}

	if (!reader.Warning().empty())
	{
		std::cout << "WARNING: TinyObjLoader: " << reader.Warning();
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
				tempVertex.coords.x = attrib.vertices[3UL * idx.vertex_index + 0UL];
				tempVertex.coords.y = attrib.vertices[3UL * idx.vertex_index + 1UL];
				tempVertex.coords.z = attrib.vertices[3UL * idx.vertex_index + 2UL];
				
				if (attrib.texcoords.size() > 0)
				{
					tempVertex.uv.x = attrib.texcoords[2 * idx.texcoord_index + 0];
					tempVertex.uv.y = attrib.texcoords[2 * idx.texcoord_index + 1];
				}

				//auto vertexHash = std::hash<Mithril::vec3>()(tempVertex.coords);

				if (uniqueVertices.count(tempVertex) == 0) {
					uniqueVertices[tempVertex] = static_cast<unsigned int>(vertices.size());
					vertices.push_back(tempVertex);
				}

				indices.push_back(uniqueVertices[tempVertex]);
			}

			index_offset += fv;

			// per-face material
			shapes[s].mesh.material_ids[f];
		}
	}

	//Centralizing and scaling the object 
	Mithril::vec3 centreOfMass;

	for (auto& vertex : vertices)
	{
		centreOfMass += vertex.coords;
	}

	centreOfMass /= vertices.size();

	for (auto& vertex : vertices)
	{
		vertex.coords -= centreOfMass;
	}

	std::cout << "Number of vertices: " << vertices.size() << std::endl;

	setVertexNormals(vertices, indices);

	return MeshData(vertices, indices);
}

void MithrilModelLoader::setVertexNormals(std::vector<Mithril::VertexPNT>& vertexdata, const std::vector<unsigned int>& indexData)
{
	/*Iterating over all faces and adding vertex normals to these values*/

	for (size_t i = 0; i < indexData.size(); i += 3UL)
	{
		size_t i1 = indexData[i];
		size_t i2 = indexData[i + 1UL];
		size_t i3 = indexData[i + 2UL];

		Mithril::vec3 edge1 = vertexdata[i1].coords;
		Mithril::vec3 edge2 = vertexdata[i2].coords;
		Mithril::vec3 edge3 = vertexdata[i3].coords;

		//Mithril::vec3 faceNormal = glm::normalize(glm::cross(edge1 - edge2, edge1 - edge3));
		Mithril::vec3 faceNormal = Mithril::Math::normalize(Mithril::Math::cross(edge1 - edge2, edge1 - edge3));

		vertexdata[i1].normal += faceNormal;
		vertexdata[i2].normal += faceNormal;
		vertexdata[i3].normal += faceNormal;
	}

	for (auto& vertex : vertexdata)
	{
		vertex.normal = Mithril::Math::normalize(vertex.normal);
	}
}