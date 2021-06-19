#include "GLTexture.h"
#include "GL/glew.h"
#include "vendor/STB/stb_image.h"
#include "util/ResourceManager.h"
#include <iostream>

namespace Mithril {

    GLTexture::GLTexture() : initFlag(false)
    {
    }

    GLTexture::~GLTexture()
    {
        if (!initFlag) //Only destroying initialized texture objects
            return;

        //else
        glDeleteTextures(1, &m_textureID);

#ifdef _DEBUG
        std::cout << "Texture with ID " << m_textureID << " has been destoyed." << std::endl;
#endif
    }

    void GLTexture::Init(const std::string& texturePath) {
        glGenTextures(1, &m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true); 

        std::basic_string<unsigned char> textureData;
        ResourceManager::readImage(texturePath.c_str(), textureData, &width, &height, &nrChannels);
        if (textureData.size() != 0)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData.c_str());
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            throw std::runtime_error("Error: Failed to load texture.");
        }

        initFlag = true;
	}

    void GLTexture::Bind()
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_textureID);
    }

    void GLTexture::Bind(unsigned int slot)
    {
#ifdef _DEBUG
        if (slot > 31) {
            throw std::runtime_error("Error: Slot number cannot exceed 31.");
        }
#endif // _DEBUG

        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_textureID);
    }

    void GLTexture::Unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    int GLTexture::GetTextureID()
    {
        return m_textureID;
    }
}