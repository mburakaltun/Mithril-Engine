#pragma once
#include "Mithril.h"
#include "LayerSystem/LayerDeck.h"
#include <Rendering/GLRenderEngine.h>
#include "WindowSystem/WindowBase.h"
#include <memory>
#include "EventSystem/EventSystem.h"
#include "Input.h"
#include <util/ModelLoader.h>
#include "ECS/Entity.h"
#include "ECS/Mesh.h"
#include "Math/Math.h"

namespace Mithril
{
	class MithrilEngine
	{
	private:
		class Cursor
		{
		public:
			void Lock();
			void Unlock();
		};

		friend class CoreSystemsLayer; //Core systems layer will have access to core engine systems
	public:
		MithrilEngine(const std::string& appName, const int windowWidth, const int windowHeight);
		virtual ~MithrilEngine() = default;
		//Executes the application
		void Execute();
	private:
		//Initializes the engine event layers, observers(they currently do not exist) and starts windowing and rendering systems
		void Init();

	protected:
		//Application Start function. Will be initialized only at the start of the Execution.
		//Application Run function. Will be run continuously during Execution.
		virtual void Start() = 0;
		virtual void Run() = 0;
		void Terminate(); // Terminates the application
		void setWindowSize();
		bool IsKeyPressed(KEYCODES key);

		//Layer Insertion functions
		void InsertDebugLayer();
		
		//Camera control API
		void SetActiveCameraPosition(const vec3& position);
		void setActiveCameraHeading(float yaw, float pitch);

		//Directional light control functions
		void SetDirLightDirection(const vec3& direction);
		void SetDirLightColor(const vec3& color);

		//Cursor functions
		void LockCursor();
		void UnlockCursor();
	private:
		bool IsTerminated();
		void HandleResize(int windowWidth, int windowHeight);

		std::unique_ptr<WindowBase> m_window;
		std::unique_ptr<RenderAPIContext> m_renderEngine;
		LayerDeck m_layerDeck;
		EventSystem m_eventSystem;
	};
}