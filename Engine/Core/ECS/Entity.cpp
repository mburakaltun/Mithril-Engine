#include "Entity.h"

namespace Mithril
{
	void Entity::AddMeshComponent(const MeshData& meshData)
	{
		m_meshComponent = std::make_unique<Mesh>(meshData.first, meshData.second);
		m_meshComponent->setPosition(m_position);
		m_meshComponent->setScale(m_scale);
		m_meshComponent->setOrientation(m_orientation);
	}

	void Entity::AddPointLightComponent()
	{
		m_pointLightComponent = std::make_unique<PointLight>();
		m_pointLightComponent->setPosition(m_position);
	}

	void Entity::Move(const vec3& value)
	{
		m_position += value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setPosition(m_position);
		}

		if (m_pointLightComponent.get() != nullptr)
		{
			m_pointLightComponent->setPosition(m_position);
		}
	}

	void Entity::SetPosition(const vec3& value)
	{
		m_position = value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setPosition(m_position);
		}

		if (m_pointLightComponent.get() != nullptr)
		{
			m_pointLightComponent->setPosition(m_position);
		}
	}

	void Entity::Rotate(const vec3& value)
	{
		m_orientation += value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setOrientation(m_orientation);
		}
	}

	void Entity::SetRotation(const vec3& value)
	{
		m_orientation = value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setOrientation(m_orientation);
		}
	}

	void Entity::Scale(const vec3& value)
	{
		m_scale *= value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setScale(m_scale);
		}
	}

	void Entity::Scale(float value)
	{
		m_scale *= value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setScale(m_scale);
		}
	}

	void Entity::SetScale(const vec3& value)
	{
		m_scale = value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setScale(m_scale);
		}
	}

	void Entity::SetScale(float value)
	{
		m_scale = value;
		if (m_meshComponent.get() != nullptr)
		{
			m_meshComponent->setScale(m_scale);
		}
	}

	void Entity::SetPointLightColor(const vec3& color)
	{
		if (m_pointLightComponent.get() != nullptr)
		{
			m_pointLightComponent->setColor(color);
		}
	}
}