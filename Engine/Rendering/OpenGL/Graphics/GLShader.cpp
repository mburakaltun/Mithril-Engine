#include "GLShader.h"
#include "GL/glew.h"
#include <iostream>
#include "util/ResourceManager.h"
#include "glm/gtc/type_ptr.hpp"
#include <exception>

namespace Mithril {

	GLShader::GLShader() : m_initFlag(false)
	{
		m_shaderID = 0;
	}

	void GLShader::Init(const std::string& vShaderPath, const std::string& fShaderPath)
	{
		if (m_initFlag)
		{
			throw std::runtime_error("Error: Trying to initialize an already initialized shader");
		}

		m_initFlag = true;
		std::string vShaderSource, fShaderSource;

		//reading input files into appropriate strings
		ResourceManager::readShaderSource(vShaderPath.c_str(), vShaderSource);
		ResourceManager::readShaderSource(fShaderPath.c_str(), fShaderSource);

		const char* vShaderSource_ptr = vShaderSource.c_str();
		const char* fShaderSource_ptr = fShaderSource.c_str();

		//Creating gl Shader Objects and shader program
		unsigned int vShaderID = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		m_shaderID = glCreateProgram();

		//attempting to compile the shaders

		glShaderSource(vShaderID, 1, &vShaderSource_ptr, nullptr);
		glShaderSource(fShaderID, 1, &fShaderSource_ptr, nullptr);

		glCompileShader(vShaderID);
		compilationErrorCheck(vShaderID);
		glCompileShader(fShaderID);
		compilationErrorCheck(fShaderID);

		glAttachShader(m_shaderID, vShaderID);
		glAttachShader(m_shaderID, fShaderID);
		glLinkProgram(m_shaderID);

		//Final integrity check
		linkErrorCheck();

		//deleting shaders
		glDeleteShader(vShaderID);
		glDeleteShader(fShaderID);
	}

	GLShader::~GLShader()
	{
		if (m_initFlag)
		{
			glDeleteProgram(m_shaderID);
#ifdef _DEBUG
			std::cout << "Shader program with ID " << m_shaderID << " has been destoyed." << std::endl;
#endif //_DEBUG
		}
	}

	void GLShader::Use() const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		glUseProgram(m_shaderID);
	}

	const unsigned int GLShader::GetID() const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		return m_shaderID;
	}

	void GLShader::setUniform1i(const std::string& uniformName, const int input) const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		GLint loc = getUniformLocation(uniformName);

		if (loc == -1) //Uniform with given name does not exist
		{
			std::cout << "Uiform with name " << uniformName << " is undefined." << std::endl;
		}
		else
		{
			glProgramUniform1i(m_shaderID, loc, input);
		}
	}

	void GLShader::setUniform1f(const std::string& uniformName, const float input) const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		GLint loc = getUniformLocation(uniformName);

		if (loc == -1) //Uniform with given name does not exist
		{
			std::cout << "Uiform with name " << uniformName << " is undefined." << std::endl;
		}
		else
		{
			glProgramUniform1f(m_shaderID, loc, input);
		}
	}

	void GLShader::setUniform2f(const std::string& uniformName, const vec2& input) const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		GLint loc = getUniformLocation(uniformName);

		if (loc == -1) //Uniform with given name does not exist
		{
			std::cout << "Uniform with name " << uniformName << " is undefined." << std::endl;
		}
		else
		{
			glProgramUniform2f(m_shaderID, loc, input.x, input.y);
		}
	}

	void GLShader::setUniform3f(const std::string& uniformName, const vec3& input) const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		int loc = getUniformLocation(uniformName);

		if (loc == -1) //Uniform with given name does not exist
		{
			std::cout << "Uniform with name " << uniformName << " is undefined." << std::endl;
		}
		else
		{
			glProgramUniform3f(m_shaderID, loc, input.x, input.y, input.z);
		}
	}

	void GLShader::setUniform4f(const std::string& uniformName, const vec4& input) const
	{
#ifdef _DEBUG
		if (!m_initFlag) //shader has not been initialized
			throw std::runtime_error("Error: trying to bind an uninitialized shader.");
#endif
		GLint loc = getUniformLocation(uniformName);

		if (loc == -1) //Uniform with given name does not exist
		{
			std::cout << "Uiform with name " << uniformName << " is undefined." << std::endl;
		}
		else
		{
			glProgramUniform4f(m_shaderID, loc, input.x, input.y, input.z, input.z);
		}
	}

	void GLShader::setUniformMatrix4f(const std::string& uniformName, const mat4& input) const
	{
		GLint loc = getUniformLocation(uniformName);

		if (loc == -1) //Uniform with given name does not exist
		{
			std::cout << "uUiform with name " << uniformName << " is undefined." << std::endl;
		}
		else
		{
			glProgramUniformMatrix4fv(m_shaderID, loc, 1, GL_FALSE, glm::value_ptr(input));
		}
	}

	void GLShader::compilationErrorCheck(unsigned int shaderID) const
	{
		int  successState;
		char errMessage[512];

		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &successState);

		//something went wrong
		if (!successState)
		{
			glGetShaderInfoLog(shaderID, 512, nullptr, errMessage);

			std::cout << "Shader with id: " << shaderID << " has failed to compile\n" << errMessage << std::endl;

		}
	}

	void GLShader::linkErrorCheck() const
	{
		GLint  successState;
		char errMessage[512];

		glGetProgramiv(m_shaderID, GL_LINK_STATUS, &successState);

		//something went wrong
		if (!successState)
		{
			glGetProgramInfoLog(m_shaderID, 512, nullptr, errMessage);

			std::cout << "Program with id " << m_shaderID << " has failed to link\n";
			std::cout << errMessage << std::endl;
		}
	}

	const int GLShader::getUniformLocation(const std::string& uniformName) const
	{
		int location;

		if (m_uniformCache.find(uniformName) != m_uniformCache.end())
		{
			location = m_uniformCache[uniformName];
		}
		else
		{
			location = glGetUniformLocation(m_shaderID, uniformName.c_str());
			m_uniformCache[uniformName] = location;
		}

		return location;
	}
}
