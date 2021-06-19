#pragma once
#include <vector>
#include "GLVertexPNT.h"

namespace Mithril
{
	class GLMesh
	{
	public:
		GLMesh() = delete; //Empty constructor defaults to 24 vertex cube
		GLMesh(const GLVertexPNT* vertexData, const unsigned int vertexDataSize, const unsigned int* indexData, const unsigned int indexDataSize);
		~GLMesh();

		void Bind() const;
		void UnBind() const;
		const unsigned int getIndexCount() const;
		unsigned int getID() const;
	private:
		void AddAttribute(const unsigned int index, const unsigned int size, const unsigned int stride, const void* start);

		unsigned int m_VAO;
		unsigned int m_VBO;
		unsigned int m_EBO;
		unsigned int m_indexCount;
	};
}