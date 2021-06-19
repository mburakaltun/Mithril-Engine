#pragma once

#include <glm/glm.hpp>

namespace Mithril
{
	class GLPointLight
	{
	public:
		GLPointLight();
		GLPointLight(const glm::vec3& position, const glm::vec3& color);

		const glm::vec3& GetPosition();
		const glm::vec3& GetColor();

		void SetPosition(const glm::vec3& position);
		void setColor(const glm::vec3& color);

		void SetArrayLocation(unsigned int newLoc);
		unsigned int  GetArrayLocation();

		unsigned int GetID();
	private:
		glm::vec3 m_position;
		glm::vec3 m_color;
		unsigned int m_id;

		//Array index in shader array
		unsigned int m_arrayLocation;

		static unsigned int id_Counter;
	};
}