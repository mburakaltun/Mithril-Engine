
#include "Renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <sstream>

namespace Mithril
{
	Renderer::Renderer() : m_pointLightArraySize(0)
	{
	}

	void Renderer::Init(const std::string& vShaderpath, const std::string& fShaderpath)
	{
		/*Creating and Initializing the shader programs*/
		m_shader.Init(vShaderpath, fShaderpath);

		/*Creating and Initializing Texture maps*/
		std::shared_ptr<GLTexture> diffuseMap = std::make_shared<GLTexture>();
		diffuseMap->Init("../OpenGL/resources/container.jpg");
		m_textures.emplace("diffuse", diffuseMap);

		m_shader.setUniform1f("pointLightCount", m_pointLightArraySize);
	}

	void Renderer::Draw(const RenderCamera& camera, const std::unordered_map<unsigned int, std::shared_ptr<GLModel>>& models)
	{
		/*Fetching Diffuse map and binding it to appropriate slot*/

		static auto& diffuseMap = m_textures["diffuse"];
		diffuseMap->Bind((unsigned int)textureSlots::DIFFUSE_MAP_SLOT);
		
		m_shader.Use();

		//Setting the view matrix uniform in projection

		m_shader.setUniformMatrix4f("View", camera.GetViewMatrix());
		m_shader.setUniformMatrix4f("Projection", camera.GetProjectionMatrix());
		m_shader.setUniform3f("viewPos", camera.GetPosition());

		/*looping over the models and drawing them one by one*/

		for (auto& model : models)
		{
			model.second->Bind();
			m_shader.setUniformMatrix4f("Model", model.second->getModelMatrix());
			glDrawElements(GL_TRIANGLES, model.second->getIndexCount(), GL_UNSIGNED_INT, 0);
		}
	}

	void Renderer::UpdateDirLightUniforms(const GLDirectionalLight& dirLight)
	{
		m_shader.setUniform3f("dirLight.direction", dirLight.getDirection());
		m_shader.setUniform3f("dirLight.color", dirLight.getColor());
	}

	void Renderer::AddNewPointLightUniform(GLPointLight& light)
	{
		std::ostringstream lightStructUniform;
		lightStructUniform << "pointLights[" << m_pointLightArraySize << "]";

		m_shader.setUniform3f(lightStructUniform.str() + ".position", light.GetPosition());
		m_shader.setUniform3f(lightStructUniform.str() + ".color", light.GetColor());
		m_shader.setUniform1f("pointLightCount", m_pointLightArraySize + 1);

		light.SetArrayLocation(m_pointLightArraySize);

		m_pointLightArraySize++;
	}

	void Renderer::UpdatePointLightUniform(GLPointLight& light)
	{
		std::ostringstream lightStructUniform;
		lightStructUniform << "pointLights[" << light.GetArrayLocation() << "]";

		m_shader.setUniform3f(lightStructUniform.str() + ".position", light.GetPosition());
		m_shader.setUniform3f(lightStructUniform.str() + ".color", light.GetColor());

	}

	void Renderer::UpdateAllPointLightUniforms(std::unordered_map<unsigned int, GLPointLight> pointLights)
	{
		m_pointLightArraySize = 0;

		for (auto& pointLight : pointLights)
		{
			pointLight.second.SetArrayLocation(m_pointLightArraySize);
			UpdatePointLightUniform(std::get<1>(pointLight));

			m_pointLightArraySize++;
		}

		m_shader.setUniform1f("pointLightCount", m_pointLightArraySize);
	}
}
