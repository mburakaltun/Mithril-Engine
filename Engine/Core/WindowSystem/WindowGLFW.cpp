#include "WindowGLFW.h"
#include <iostream>
#include "EventSystem/KeyboardEvents.h";
#include "EventSystem/WindowEvents.h";
#include "EventSystem/MouseEvents.h";

namespace Mithril 
{
	WindowGLFW::WindowGLFW(int width, int height, const std::string& windowName, EventSystem* eventSystem) : 
		WindowBase(width, height, windowName, eventSystem)
	{
		/* Initialize the library */
		if (!glfwInit()) {
			throw std::runtime_error("Error: Could not initialize the window");
		}

		//Setting the window hints
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		/* Createing the instance of GLFW*/
		m_window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

		if (!m_window)
		{
			glfwTerminate();
			throw std::runtime_error("Error: Could not initialize the window properly");
		}

		glfwSetWindowUserPointer(m_window, this);

		//Setting the GLFW specific event callback functions
		glfwSetKeyCallback(m_window, keyboardCallback);
		glfwSetCursorPosCallback(m_window, cursorPositionCallback);
		glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
		glfwSetScrollCallback(m_window, mouseScrollCallback);
		glfwSetWindowCloseCallback(m_window, windowCloseCallback);
		glfwSetWindowSizeCallback(m_window, windowSizeCallback);

	}

	WindowGLFW::~WindowGLFW()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowGLFW::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowGLFW* windowGLFW = (WindowGLFW*) glfwGetWindowUserPointer(window);
		KEYCODES keycode = static_cast<KEYCODES>(key);
		switch (action)
		{
		case GLFW_PRESS:
			windowGLFW->m_eventSystem->SignalEvent(KeyPressEvent(keycode));
			break;
		case GLFW_RELEASE:
			windowGLFW->m_eventSystem->SignalEvent(KeyReleaseEvent(keycode));
			break;
		case GLFW_REPEAT:
			windowGLFW->m_eventSystem->SignalEvent(KeyPressEvent(keycode));
			break;
		default:
			windowGLFW->m_eventSystem->SignalEvent(KeyPressEvent(keycode));
			break;
		}
	}

	void WindowGLFW::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		WindowGLFW* windowGLFW = (WindowGLFW*)glfwGetWindowUserPointer(window);
		windowGLFW->m_eventSystem->SignalEvent(MouseCursorMoveEvent(xpos, ypos));
	}

	void WindowGLFW::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		WindowGLFW* windowGLFW = (WindowGLFW*)glfwGetWindowUserPointer(window);
		MOUSECODES buttonCode = static_cast<MOUSECODES>(button);

		if (action == GLFW_PRESS)
		{
			windowGLFW->m_eventSystem->SignalEvent(MouseClickEvent(buttonCode));
		}
	}

	void WindowGLFW::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowGLFW* windowGLFW = (WindowGLFW*)glfwGetWindowUserPointer(window);
		windowGLFW->m_eventSystem->SignalEvent(MouseScrollEvent(xOffset, yOffset));
	}

	void WindowGLFW::windowCloseCallback(GLFWwindow* window)
	{
		WindowGLFW* windowGLFW = (WindowGLFW*)glfwGetWindowUserPointer(window);
		windowGLFW->m_eventSystem->SignalEvent(WindowCloseEvent());
	}

	void WindowGLFW::windowSizeCallback(GLFWwindow* window, int width, int height)
	{
		WindowGLFW* windowGLFW = (WindowGLFW*)glfwGetWindowUserPointer(window);

		//Resizing the window

		windowGLFW->m_windowWidth = width;
		windowGLFW->m_windowHeight = height;
		windowGLFW->m_eventSystem->SignalEvent(WindowResizeEvent(width, height));
	}

	void WindowGLFW::OnUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}


	int WindowGLFW::shouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}

	void WindowGLFW::SetToClose()
	{
		glfwSetWindowShouldClose(m_window, 1);
	}

	bool WindowGLFW::IsKeyPressed(KEYCODES key)
	{
		return glfwGetKey(m_window, static_cast<int>(key)) == GLFW_PRESS;
	}

	const float WindowGLFW::GetTime()
	{
		return static_cast<float>(glfwGetTime());
	}

	void WindowGLFW::UnlockCursor()
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void WindowGLFW::LockCursor()
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void WindowGLFW::MakeContextCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}
}