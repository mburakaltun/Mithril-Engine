#include "MouseEvents.h"

namespace Mithril
{
	MouseClickEvent::MouseClickEvent(MOUSECODES button) :
		EventBase(EventCategory::MOUSE_EVENT, EventType::MOUSE_BUTTON_CLICK),
		m_button(button)
	{
	}

	std::string MouseClickEvent::GetDescription() const
	{
		std::string desc("MouseClickEvent Occured : Key = ");
		desc += std::to_string(static_cast<int>(m_button));

		return desc;
	}

	MOUSECODES MouseClickEvent::GetButton() const
	{
		return m_button;
	}
	
	MouseScrollEvent::MouseScrollEvent(double xOffset, double yOffset) :
		EventBase(EventCategory::MOUSE_EVENT, EventType::MOUSE_SCROLL),
		m_xOffset(xOffset), m_yOffset(yOffset)
	{
	}

	std::string MouseScrollEvent::GetDescription() const
	{
		std::string desc("MouseScrollEvent Occured : xOffset = ");
		desc += std::to_string(m_xOffset);
		desc += ", yOffset = ";
		desc += std::to_string(m_yOffset);

		return desc;
	}

	double MouseScrollEvent::GetXOffset() const
	{
		return m_xOffset;
	}

	double MouseScrollEvent::GetYOffset() const
	{
		return m_yOffset;
	}

	MouseCursorMoveEvent::MouseCursorMoveEvent(double xPos, double yPos) :
		EventBase(EventCategory::MOUSE_EVENT, EventType::MOUSE_CURSOR_MOVE)
	{
		m_xPos = xPos;
		m_yPos = yPos;
	}

	std::string MouseCursorMoveEvent::GetDescription() const
	{
		std::string desc("MouseCursorMoveEvent Occured : xOffset = ");
		desc += std::to_string(m_xPos);
		desc += ", yOffset = ";
		desc += std::to_string(m_yPos);

		return desc;
	}

	double MouseCursorMoveEvent::GetXPos() const
	{
		return m_xPos;
	}

	double MouseCursorMoveEvent::GetYPos() const
	{
		return m_yPos;
	}
}