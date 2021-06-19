#include "PointLight.h"

namespace Mithril
{
	RenderAPIContext* PointLight::renderEngine;

	PointLight::PointLight()
	{
		m_renderContextID = renderEngine->CreatePointLight();
	}

	PointLight::~PointLight()
	{
		renderEngine->DeletePointLight(m_renderContextID);
	}
	void PointLight::setRenderAPIContextPointer(RenderAPIContext* pointer)
	{
		renderEngine = pointer;
	}

	void PointLight::setPosition(const vec3& value)
	{
		renderEngine->SetPointLightLocation(m_renderContextID, value.x, value.y, value.z);
	}

	void PointLight::setColor(const vec3& value)
	{
		renderEngine->SetPointLightColor(m_renderContextID, value.x, value.y, value.z);
	}
}