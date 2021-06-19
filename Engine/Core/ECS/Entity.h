#pragma once

#include <vector>
#include <memory>
#include "Mesh.h"
#include "PointLight.h"
#include "Vertex/VertexPNT.h"
#include <Core/typedefs.h>

namespace Mithril
{
	class Entity
	{
	public:
		Entity() = default;
		~Entity() = default;

		//Addding components
		void AddMeshComponent(const MeshData& meshData);
		void AddPointLightComponent();
		void Move(const vec3& value); //adds value to current position
		void SetPosition(const vec3& value);
		void Rotate(const vec3& value);
		void SetRotation(const vec3& value);
		void Scale(const vec3& value);
		void Scale(float value);
		void SetScale(const vec3& value);
		void SetScale(float value);

		//Change point light color
		void SetPointLightColor(const vec3& color);

	private:
		vec3 m_position;
		vec3 m_orientation;
		vec3 m_scale{ 1.0f, 1.0f, 1.0f };

		std::unique_ptr<Mesh> m_meshComponent;
		std::unique_ptr<PointLight> m_pointLightComponent;
	};
}