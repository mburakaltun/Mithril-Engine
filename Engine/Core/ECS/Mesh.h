#pragma once

#include "Vertex/vec3.h"
#include <Core/RenderSystem/RenderAPIContext.h>

namespace Mithril
{
	class Mesh
	{
	public:
		Mesh(const std::vector<VertexPNT>& vertexData, const std::vector<unsigned int>& indexData);
		~Mesh();

		static void setRenderAPIContextPointer(RenderAPIContext* pointer);

		void setPosition(const vec3& value);
		void setOrientation(const vec3& value);
		void setScale(const vec3& value);
		
	private:
		unsigned int m_renderContextID;
		static RenderAPIContext* renderEngine;
	};
}