#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Rendering/OpenGL/Graphics/GLModel.h>



class ResourceManager {
public:
	static void readShaderSource(const char* filePath, std::string& out);
	//load image onto a basic string
	static void readImage(const char* filePath, std::basic_string<unsigned char>& imageData, int* width, int* height, int* nChannels);
	//Load a wavefront obj file into a model

	static std::shared_ptr<Mithril::GLModel> loadModel(const std::string &modelPath);
};