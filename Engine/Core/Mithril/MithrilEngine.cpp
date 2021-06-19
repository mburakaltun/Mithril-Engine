#include "MithrilEngine.h"
#include "InputLayer.h"
#include "DebugLayer.h"
#include "CoreSystemsLayer.h"
#include "WindowGLFW.h"
#include "ECS/Entity.h"

namespace Mithril
{
	MithrilEngine::MithrilEngine(const std::string& appName, const int windowWidth, const int windowHeight) : 
		m_eventSystem(&m_layerDeck)
	{
		//Insterting layerts to the layerdeck
		// Inserting Core Systems Layer
		m_layerDeck.InsertLayer(std::static_pointer_cast<LayerBase>(std::make_shared<CoreSystemsLayer>(this)));
		//Inserting Input layer
		m_layerDeck.InsertLayer(std::static_pointer_cast<LayerBase>(std::make_shared<InputLayer>()));

		//Creating the window
#ifdef GLFW_WINDOWING_SYSTEM
		m_window = std::make_unique<WindowGLFW>(windowWidth, windowHeight, appName, &m_eventSystem);
#endif

		m_window->MakeContextCurrent();

		//Creating the rendering API context
#ifdef OPENGL_RENDERING_CONTEXT
		m_renderEngine = std::make_unique<GLRenderEngine>(windowWidth, windowHeight);
#endif
		Mesh::setRenderAPIContextPointer(m_renderEngine.get());
		PointLight::setRenderAPIContextPointer(m_renderEngine.get());
	}

	void MithrilEngine::Execute()
	{
		Start();

		while (!m_window->shouldClose())
		{
			Run();
			m_window->OnUpdate();
			m_layerDeck.OnUpdate();

			//rendering the scene
			m_renderEngine->RenderScene();
		}
	}

	void MithrilEngine::Init()
	{
	}

	void MithrilEngine::Terminate()
	{
		m_window->SetToClose();
	}

	void MithrilEngine::setWindowSize()
	{
		//TODO: Implement
	}

	bool MithrilEngine::IsKeyPressed(KEYCODES key)
	{
		return m_window->IsKeyPressed(key);
	}

	void MithrilEngine::InsertDebugLayer()
	{
		//Inserting Debug Layer
		m_layerDeck.InsertLayer(std::static_pointer_cast<LayerBase>(std::make_shared<DebugLayer>()));
	}

	void MithrilEngine::SetActiveCameraPosition(const vec3& position)
	{
		m_renderEngine->SetActiveCameraPosition(position.x, position.y, position.z);
	}

	void MithrilEngine::setActiveCameraHeading(float yaw, float pitch)
	{
		m_renderEngine->SetActiveCameraHeading(yaw, pitch);
	}

	void MithrilEngine::SetDirLightDirection(const vec3& direction)
	{
		m_renderEngine->SetDirLightDirection(direction.x, direction.y, direction.z);
	}

	void MithrilEngine::SetDirLightColor(const vec3& color)
	{
		m_renderEngine->SetDirLightColor(color.x, color.y, color.z);
	}

	void MithrilEngine::LockCursor()
	{
		m_window->LockCursor();
	}

	void MithrilEngine::UnlockCursor()
	{
		m_window->UnlockCursor();
	}

	bool MithrilEngine::IsTerminated()
	{
		return m_window->shouldClose();
	}

	void MithrilEngine::HandleResize(int windowWidth, int windowHeight)
	{
		m_renderEngine->SetViewPort(windowWidth, windowHeight);
	}
}