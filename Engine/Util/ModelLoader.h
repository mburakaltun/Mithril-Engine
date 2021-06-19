#pragma once
#include <memory>
#include <vector>
#include <string>

namespace Mithril
{
	class VertexPNT;
}

using namespace Mithril;

typedef std::pair<std::vector<VertexPNT>, std::vector<unsigned int>> MeshData;

class MithrilModelLoader
{
public:
	static MeshData loadDefaultTexturedCube();
	static MeshData loadWavefrontOBJFile(const std::string& modelPath);
private:
	static void setVertexNormals(std::vector<Mithril::VertexPNT>& vertexdata, const std::vector<unsigned int>& indexData);
};