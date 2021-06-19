#include "Mesh.h"

namespace Mithril
{
	RenderAPIContext *Mesh::renderEngine = nullptr;

	Mesh::Mesh(const std::vector<VertexPNT>& vertexData, const std::vector<unsigned int>& indexData)
	{
		m_renderContextID = renderEngine->CreateMesh(vertexData, indexData);
	}

	Mesh::~Mesh()
	{
		renderEngine->DeleteMesh(m_renderContextID);
	}

	void Mesh::setRenderAPIContextPointer(RenderAPIContext* pointer)
	{
		renderEngine = pointer;
	}

	void Mesh::setPosition(const vec3& value)
	{
		renderEngine->SetMeshPosition(m_renderContextID, value.x, value.y, value.z);
	}

	void Mesh::setOrientation(const vec3& value)
	{
		renderEngine->SetMeshRotation(m_renderContextID, value.x, value.y, value.z);
	}

	void Mesh::setScale(const vec3& value)
	{
		renderEngine->SetMeshScale(m_renderContextID, value.x, value.y, value.z);
	}
}