#include "GLModel.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Mithril
{
	GLModel::GLModel(const GLVertexPNT* vertexData, const unsigned int vertexDataSize, const unsigned int* indexData, const unsigned int indexDataSize) :
		m_mesh(vertexData, vertexDataSize, indexData, indexDataSize),
		m_position(0.0f), m_scale(1.0f), m_orientation(0.0f)
	{
		updateModelMatrix();
	}

	void GLModel::Bind() const
	{
		m_mesh.Bind();
	}

	void GLModel::UnBind() const
	{
		m_mesh.UnBind();
	}

	void GLModel::setRotation(const vec3& newRot)
	{
		m_orientation = newRot;
		updateModelMatrix();
	}

	void GLModel::setPosition(const vec3& newPos)
	{
		m_position = newPos;
		updateModelMatrix();
	}

	void GLModel::setScale(const vec3& newScale)
	{
		m_scale = newScale;
		updateModelMatrix();
	}

	const unsigned int GLModel::getIndexCount() const
	{
		return m_mesh.getIndexCount();
	}

	const glm::mat4 GLModel::getModelMatrix() const
	{
		return m_ModelMatrix;
	}

	unsigned int GLModel::getID() const
	{
		return m_mesh.getID();
	}

	void GLModel::updateModelMatrix()
	{
		m_ModelMatrix = glm::mat4(1.0f);
		m_ModelMatrix = glm::translate(m_ModelMatrix, m_position);
		m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_orientation.x), glm::vec3(1.0, 0.0, 0.0));
		m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_orientation.y), glm::vec3(0.0, 1.0, 0.0));
		m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_orientation.z), glm::vec3(0.0, 0.0, 1.0));
		m_ModelMatrix = glm::scale(m_ModelMatrix, m_scale);
	}
}