#pragma once

#include "GLMesh.h"
#include <glm/glm.hpp>

namespace Mithril
{
	class GLModel
	{	
		using vec3 = glm::vec3;
		using mat4 = glm::mat4;
	public:
		GLModel() = delete;
		GLModel(const GLVertexPNT* vertexData, const unsigned int vertexDataSize, const unsigned int* indexData, const unsigned int indexDataSize);

		void Bind() const;
		void UnBind() const;

		//setter functions
		void setRotation(const vec3& newRot);
		void setPosition(const vec3& newPos);
		void setScale(const vec3&  newScale);

		//getter functions
		const unsigned int getIndexCount() const;
		const mat4 getModelMatrix() const;
		unsigned int getID() const;
	private:
		void updateModelMatrix();

		GLMesh m_mesh;
		vec3 m_position;
		vec3 m_scale;
		vec3 m_orientation;
		mat4 m_ModelMatrix;
	};
}