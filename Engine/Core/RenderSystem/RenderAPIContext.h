#pragma once
#include <Core/Mithril.h>
#include <Core/ECS/Vertex/VertexPNT.h>
#include <vector>

namespace Mithril
{
	class RenderAPIContext
	{
	public:
		virtual ~RenderAPIContext() = default;
		//Sets the view port of all cameras
		virtual void SetViewPort(int width, int height) = 0;
		//Creates a Mesh
		virtual unsigned int CreateMesh(const std::vector<VertexPNT>& vertexdata, const std::vector<unsigned int> & indexdata) = 0;
		//Deletes a Mesh
		virtual bool DeleteMesh(unsigned int id) = 0;

		//Mesh manipulation functions
		virtual void SetMeshPosition(unsigned int id, float x, float y, float z) = 0;
		virtual void SetMeshScale(unsigned int id, float xScale, float yScale, float zScale) = 0;
		virtual void SetMeshRotation(unsigned int id, float xDegrees, float yDegrees, float zDegrees) = 0;

		//Active camera manipulation methods
		virtual void SetActiveCameraPosition(float x, float y, float z) = 0;
		virtual void SetActiveCameraHeading(float yaw, float pitch) = 0;

		//Directional light manipulation methods
		virtual void SetDirLightDirection(float x, float y, float z) = 0;
		virtual void SetDirLightColor(float r, float g, float b) = 0;

		//Point Light manipulation functions
		virtual unsigned int CreatePointLight() = 0;
		virtual bool DeletePointLight(unsigned int id) = 0;
		virtual void SetPointLightLocation(unsigned int id, float x, float y, float z) = 0;
		virtual void SetPointLightColor(unsigned int id, float r, float g, float b) = 0;

		//Renders all models in the context
		virtual void RenderScene() = 0;
	private:
	};
}