#pragma once
#include "Vertex/vec3.h"
#include <Core/RenderSystem/RenderAPIContext.h>

namespace Mithril
{
	class PointLight
	{
	public:
		PointLight();
		~PointLight();

		static void setRenderAPIContextPointer(RenderAPIContext* pointer);
		void setPosition(const vec3& value);
		void setColor(const vec3& value);

	private:
		unsigned int m_renderContextID;
		static RenderAPIContext* renderEngine;
	};
}