#pragma once

#include <glm/glm.hpp>

namespace Mithril
{
	class GLDirectionalLight
	{
	public:
		GLDirectionalLight();
		GLDirectionalLight(const glm::vec3& direction, const glm::vec3& color);
		void setColor(const glm::vec3& color);
		void setDireciton(const glm::vec3& direction);

		const glm::vec3& getDirection() const;
		const glm::vec3& getColor() const;
	private:
		glm::vec3 m_direction;
		glm::vec3 m_color;
	};
}