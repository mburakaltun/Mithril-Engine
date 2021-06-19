#pragma once

#include <string>

namespace Mithril {
	class GLTexture {
	public:
		GLTexture();
		~GLTexture();
		void Init(const std::string& texturePath);
		void Bind();
		void Bind(unsigned int slot);
		void Unbind();
		int GetTextureID();
	private:
		unsigned int m_textureID;
		bool initFlag;
	};
}