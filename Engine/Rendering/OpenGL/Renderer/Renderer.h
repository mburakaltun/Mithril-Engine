#pragma once

#include <Core/Mithril.h>
#include <string>
#include <vector>
#include "../Graphics/GLModel.h"
#include "../Graphics/GLShader.h"
#include "../Graphics/RenderCamera.h"
#include "../Graphics/GLTexture.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include "../Graphics/GLDirectionalLight.h"
#include "../Graphics/GLPointLight.h"

namespace Mithril
{
	class Renderer
	{
		enum class textureSlots : unsigned int
		{
			DIFFUSE_MAP_SLOT = 0u,
		};

		using mat4 = glm::mat4;
	public:
		Renderer();
		void Init(const std::string& vShaderpath, const std::string& fShaderpath);
		void setProjectionMatrix(const float fov, const float aspectRatio, const float nearPlane, const float farPlane);

		void Draw(const RenderCamera& second, const std::unordered_map<unsigned int, std::shared_ptr<GLModel>>& models);

		//Updating Dir Light Uniforms
		void UpdateDirLightUniforms(const GLDirectionalLight& dirLight);

		//Point Light Uniform Functions
		void AddNewPointLightUniform(GLPointLight& light);
		void UpdatePointLightUniform(GLPointLight& light);
		void UpdateAllPointLightUniforms(std::unordered_map<unsigned int, GLPointLight> pointLights);
	private:
		GLShader m_shader;
		std::unordered_map<std::string, std::shared_ptr<GLTexture>> m_textures;

		unsigned int m_pointLightArraySize;
	};
}