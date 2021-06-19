#include "WindowBase.h"

namespace Mithril 
{
	WindowBase::WindowBase(int width, int height, const std::string& windowName, EventSystem* eventSystem)
	{
		m_windowHeight = height;
		m_windowWidth = width;
		m_windowName = windowName;
		m_eventSystem = eventSystem;
	}
}