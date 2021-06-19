#pragma once

#include "glm/glm.hpp"
#include <string>
#include <unordered_map>

/*
The Shader class that manages creation and deletion of OpenGL shaders.
1st argument of the constructor is vertex shader path and the 2nd one is the fragment shader path
the constructor immediately compiles and links the shader program.
Use() function uses the shader 
The destructor calls appropriate OpenGL function to delete the shader program tied with m_shaderID parameter.
*/
namespace Mithril {
	class GLShader {
		using vec2 = glm::vec2;
		using vec3 = glm::vec3;
		using vec4 = glm::vec4;
		using mat4 = glm::mat4;
	public:
		GLShader(); //No default constructor for shader
		~GLShader();
		void Init(const std::string& vShaderPath, const std::string& fShaderPath);

		void Use() const;
		const unsigned int GetID() const;

		//uniform setter funcitons
		void setUniform1i(const std::string& uniformName, const int input) const;
		void setUniform1f(const std::string& uniformName, const float input) const;
		void setUniform2f(const std::string& uniformName, const vec2& input) const;
		void setUniform3f(const std::string& uniformName, const vec3& input) const;
		void setUniform4f(const std::string& uniformName, const vec4& input) const;
		void setUniformMatrix4f(const std::string& uniformName, const mat4& input) const;
	private:
		void compilationErrorCheck(unsigned int shaderID) const;
		void linkErrorCheck() const;

		//Function that fetches uniform locations from teh shader
		const int getUniformLocation(const std::string& uniformName) const;

		unsigned int m_shaderID;
		//Initialization flag
		bool m_initFlag;

		//Storing uniform variable locations for fast uniform access
		mutable std::unordered_map<std::string, int> m_uniformCache;

	};
}