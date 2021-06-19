#include "GLRenderEngine.h"
#include <iostream>

namespace Mithril
{
    GLRenderEngine::GLRenderEngine(const int windowWidth, const int windowHeight)
	{
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error("Failed to initialize GLEW");
        }

        m_renderer.Init("../Opengl/shaders/PBRVertexpart1.shader", "../Opengl/shaders/PBRFragmentpart1.shader");
        
        //Set viewPort will handle this line
        SetViewPort(windowWidth, windowHeight);

        //Setting directional light uniforms
        m_renderer.UpdateDirLightUniforms(m_dirLight);

        glEnable(GL_DEPTH_TEST);

        std::cout << "Engine Successfully Initialized." << std::endl;
	}

    void GLRenderEngine::SetViewPort(int windowWidth, int windowHeight)
    {
        glViewport(0, 0, windowWidth, windowHeight);
        m_activeCamera.SetProjectionAspectRatio((float)windowWidth/(float)windowHeight);
    }

    unsigned int GLRenderEngine::CreateMesh(const std::vector<VertexPNT>& vertexData, const std::vector<unsigned int>& indexData)
    {
        ModelPtr newModel = std::make_shared<GLModel>(
            (GLVertexPNT*)vertexData.data(), vertexData.size() * sizeof(GLVertexPNT), indexData.data(), indexData.size() * sizeof(unsigned int));
        
        unsigned int modelID = newModel->getID();
        m_modelStorage[modelID] = newModel;

        return modelID;
    }

    bool GLRenderEngine::DeleteMesh(unsigned int id)
    {
        return m_modelStorage.erase(id);
    }

    void GLRenderEngine::SetMeshPosition(unsigned int id, float x, float y, float z)
    {
        auto modelLocation = m_modelStorage.find(id);
        
        if (modelLocation == m_modelStorage.end())
        {
            return;
        }

        modelLocation->second->setPosition({ x , y, z });
    }
    void GLRenderEngine::SetMeshScale(unsigned int id, float xScale, float yScale, float zScale)
    {
        auto modelLocation = m_modelStorage.find(id);

        if (modelLocation == m_modelStorage.end())
        {
            return;
        }

        modelLocation->second->setScale({ xScale , yScale, zScale });
    }
    
    void GLRenderEngine::SetMeshRotation(unsigned int id, float xDegrees, float yDegrees, float zDegrees)
    {
        auto modelLocation = m_modelStorage.find(id);

        if (modelLocation == m_modelStorage.end())
        {
            return;
        }

        modelLocation->second->setRotation({ xDegrees , yDegrees, zDegrees });
    }

    void GLRenderEngine::SetActiveCameraPosition(float x, float y, float z)
    {
        m_activeCamera.SetPosition(x, y, z);
    }

    void GLRenderEngine::SetActiveCameraHeading(float yaw, float pitch)
    {
        m_activeCamera.SetHeading(yaw, pitch);
    }

    void GLRenderEngine::SetDirLightDirection(float x, float y, float z)
    {
        m_dirLight.setDireciton({ x, y, z });
        m_renderer.UpdateDirLightUniforms(m_dirLight);
    }

    void GLRenderEngine::SetDirLightColor(float r, float g, float b)
    {
        m_dirLight.setColor({ r, g, b });
        m_renderer.UpdateDirLightUniforms(m_dirLight);
    }

    unsigned int GLRenderEngine::CreatePointLight()
    {
        GLPointLight pointLight;

        unsigned int id = pointLight.GetID();

        m_pointLightStorage[id] = pointLight;

        m_renderer.AddNewPointLightUniform(m_pointLightStorage[id]);
        return id;
    }

    bool GLRenderEngine::DeletePointLight(unsigned int id)
    {
        bool retVal = m_pointLightStorage.erase(id);

        m_renderer.UpdateAllPointLightUniforms(m_pointLightStorage);

        return retVal;
    }

    void GLRenderEngine::SetPointLightLocation(unsigned int id, float x, float y, float z)
    {
        auto pointLightLocation = m_pointLightStorage.find(id);

        if (pointLightLocation == m_pointLightStorage.end())
        {
            return;
        }

        pointLightLocation->second.SetPosition({ x, y, z });

        m_renderer.UpdatePointLightUniform(pointLightLocation->second);
        
    }

    void GLRenderEngine::SetPointLightColor(unsigned int id, float r, float g, float b)
    {
        auto pointLightLocation = m_pointLightStorage.find(id);

        if (pointLightLocation == m_pointLightStorage.end())
        {
            return;
        }

        pointLightLocation->second.setColor({ r, g, b });

        m_renderer.UpdatePointLightUniform(pointLightLocation->second);
    }

    void GLRenderEngine::RenderScene()
    {
        //Clearing color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_renderer.Draw(m_activeCamera, m_modelStorage);
    }
}