#include "GLMesh.h"
#include <GL/glew.h>
#include <iostream>

namespace Mithril
{
	GLMesh::GLMesh(const GLVertexPNT* vertexData, const unsigned int vertexDataSize, const unsigned int* indexData, const unsigned int indexDataSize)
	{
		m_indexCount = indexDataSize / sizeof(unsigned int);

		//Creating and binding Vertex Array Object
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		//Creating Vertex and Index buffers
		glGenBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, vertexDataSize, vertexData, GL_STATIC_DRAW);

		glGenBuffers(1, &m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSize, indexData, GL_STATIC_DRAW);

		//Adding Vertex attribute for coordinates
		AddAttribute(0, sizeof(GLVertexPNT::m_vertexCoords) / sizeof(float), sizeof(GLVertexPNT), static_cast<void*>(0));
		AddAttribute(1, sizeof(GLVertexPNT::m_normal) / sizeof(float), sizeof(GLVertexPNT), (void*)sizeof(GLVertexPNT::m_vertexCoords));
		AddAttribute(2, sizeof(GLVertexPNT::m_textureCoords) / sizeof(float), sizeof(GLVertexPNT),
			(void*)(sizeof(GLVertexPNT::m_vertexCoords) + sizeof(GLVertexPNT::m_normal)));

		//Unbinding vertex array object
		glBindVertexArray(0);
	}

	GLMesh::~GLMesh()
	{
#ifdef _DEBUG
		std::cout << "Mesh with id " << m_VAO << " is destoryed" << std::endl;
#endif // _DEBUG
		glDeleteBuffers(1, &m_VBO);
		glDeleteBuffers(1, &m_EBO);
		glDeleteVertexArrays(1, &m_VAO);
	}

	void GLMesh::AddAttribute(const unsigned int index, const unsigned int size, const unsigned int stride, const void* start)
	{
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, start);
		glEnableVertexAttribArray(index);
	}

	void GLMesh::Bind() const
	{
		glBindVertexArray(m_VAO);
	}

	void GLMesh::UnBind() const
	{
		glBindVertexArray(0);
	}

	const unsigned int GLMesh::getIndexCount() const
	{
		return m_indexCount;
	}
	unsigned int GLMesh::getID() const
	{
		return m_VAO;
	}
}