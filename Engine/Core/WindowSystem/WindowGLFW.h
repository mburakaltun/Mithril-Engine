#pragma once
#include "WindowSystem/WindowBase.h"
#include "Mithril.h"

namespace Mithril 
{
	class WindowGLFW : public WindowBase 
	{
	public:
		WindowGLFW(int width, int height, const std::string& windowName, EventSystem* eventSystem);
		~WindowGLFW();
		void OnUpdate() override;
		int shouldClose() override;
		void SetToClose() override;
		bool IsKeyPressed(KEYCODES key) override;
		const float GetTime() override;
		void UnlockCursor() override;
		void LockCursor() override;
		void MakeContextCurrent() override;
	private:
		//GLFW Specific callbacks
		static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
		static void windowCloseCallback(GLFWwindow* window);
		static void windowSizeCallback(GLFWwindow* window, int width, int height);

		GLFWwindow* m_window;
	};
}