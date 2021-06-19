#pragma once
#include "GLDirectionalLight.h"
#include <glm/glm.hpp>

namespace Mithril
{
	GLDirectionalLight::GLDirectionalLight() : m_direction(0.0f, 1.0f, 0.0f), m_color(0.8f, 0.8f, 0.8f)
	{
	}

	GLDirectionalLight::GLDirectionalLight(const glm::vec3& direction, const glm::vec3& color) : m_direction(direction), m_color(color)
	{
	}

	void GLDirectionalLight::setColor(const glm::vec3& color)
	{
		m_color = color;
	}

	void GLDirectionalLight::setDireciton(const glm::vec3& direction)
	{
		m_direction = glm::normalize(direction);
	}

	const glm::vec3& GLDirectionalLight::getDirection() const
	{
		return m_direction;
	}

	const glm::vec3& GLDirectionalLight::getColor() const
	{
		return m_color;
	}
}