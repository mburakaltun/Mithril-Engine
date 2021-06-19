#include "WindowEvents.h"

namespace Mithril
{
	WindowResizeEvent::WindowResizeEvent(int width, int height) : 
		EventBase(EventCategory::WINDOW_EVENT, EventType::WINDOW_RESIZE),
		m_windowWidth(width), 
		m_windowHeight(height)
	{
	}
	
	std::string WindowResizeEvent::GetDescription() const
	{
		std::string desc(" WindowResizeEvent Occured: ");
		desc += "WindowWidth = ";
		desc += std::to_string(m_windowWidth);
		desc += ", WindowHeight = ";
		desc += std::to_string(m_windowHeight);

		return desc;
	}

	int WindowResizeEvent::getHeight() const
	{
		return m_windowHeight;
	}

	int WindowResizeEvent::getWidth() const
	{
		return m_windowWidth;
	}

	WindowCloseEvent::WindowCloseEvent() :
		EventBase(EventCategory::WINDOW_EVENT, EventType::WINDOW_CLOSE)
	{
	}

	std::string WindowCloseEvent::GetDescription() const
	{
		std::string desc(" WindowCloseEvent Occured");
		return desc;
	}
	
}