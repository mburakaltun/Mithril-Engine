#include "GLPointLight.h"

namespace Mithril
{
	unsigned int GLPointLight::id_Counter = 0;

	GLPointLight::GLPointLight() : m_position(0.0f), m_color(0.0f), m_arrayLocation(-1)
	{
		m_id = id_Counter;
		id_Counter++;
	}

	GLPointLight::GLPointLight(const glm::vec3& position, const glm::vec3& color) : m_position(position), m_color(color), m_arrayLocation(-1)
	{
		m_id = id_Counter;
		id_Counter++;
	}

	const glm::vec3& GLPointLight::GetPosition()
	{
		return m_position;
	}

	const glm::vec3& GLPointLight::GetColor()
	{
		return m_color;
	}

	void GLPointLight::SetPosition(const glm::vec3& position)
	{
		m_position = position;
	}

	void GLPointLight::setColor(const glm::vec3& color)
	{
		m_color = color;
	}

	void GLPointLight::SetArrayLocation(unsigned int newLoc)
	{
		m_arrayLocation = newLoc;
	}

	unsigned int GLPointLight::GetArrayLocation()
	{
		return m_arrayLocation;
	}

	unsigned int GLPointLight::GetID()
	{
		return m_id;
	}
}