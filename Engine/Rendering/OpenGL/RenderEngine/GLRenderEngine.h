#pragma once
#include <Core/Mithril.h>
#include <Core/RenderSystem/RenderAPIContext.h>
#include <unordered_map>
#include <memory>
#include "OpenGL/Graphics/GLModel.h"
#include "OpenGL/Renderer/Renderer.h"
#include "OpenGL/Graphics/RenderCamera.h"
#include "OpenGL/Graphics/GLDirectionalLight.h"
#include "OpenGL/Graphics/GLPointLight.h"

namespace Mithril
{
	class GLRenderEngine : public RenderAPIContext
	{
		using ModelPtr = std::shared_ptr<GLModel>;
		using ModelStorage = std::unordered_map<unsigned int, ModelPtr>;
	public:
		GLRenderEngine(const int windowWidth, const int windowHeight);
		~GLRenderEngine() = default;

		void SetViewPort(int width, int height) override;

		unsigned int CreateMesh(const std::vector<VertexPNT>& vertexData, const std::vector<unsigned int>& indexData) override;
		//Deletes a Mesh
		bool DeleteMesh(unsigned int id) override;

		//Mesh translation functions
		void SetMeshPosition(unsigned int id, float x, float y, float z) override;
		void SetMeshScale(unsigned int id, float xScale, float yScale, float zScale) override;
		void SetMeshRotation(unsigned int id, float xDegrees, float yDegrees, float zDegrees) override;

		void SetActiveCameraPosition(float x, float y, float z) override;
		void SetActiveCameraHeading(float yaw, float pitch) override;

		//Directional light manipulation methods
		void SetDirLightDirection(float x, float y, float z) override;
		void SetDirLightColor(float r, float g, float b) override;

		//Point Light manipulation functions
		unsigned int CreatePointLight() override;
		bool DeletePointLight(unsigned int id) override;
		void SetPointLightLocation(unsigned int id, float x, float y, float z) override;
		void SetPointLightColor(unsigned int id, float r, float g, float b) override;

		void RenderScene() override;
	private:
		//Models
		std::unordered_map<unsigned int, std::shared_ptr<GLModel>> m_modelStorage;

		//Point Light
		std::unordered_map<unsigned int, GLPointLight> m_pointLightStorage;

		Renderer m_renderer;
		RenderCamera m_activeCamera;
		GLDirectionalLight m_dirLight;
	};
}