#include "KeyboardEvents.h"

namespace Mithril
{
	KeyPressEvent::KeyPressEvent(KEYCODES key) :
		EventBase(EventCategory::KEYBOARD_EVENT, EventType::KEY_PRESS),
		m_key(key)
	{
	}

	std::string KeyPressEvent::GetDescription() const
	{
		std::string desc("KeyPressEvent Occured : Key = ");
		desc += std::to_string(static_cast<int>(m_key));

		return desc;
	}

	KEYCODES KeyPressEvent::GetKeyCode() const
	{
		return m_key;
	}

	KeyReleaseEvent::KeyReleaseEvent(KEYCODES key) :
		EventBase(EventCategory::KEYBOARD_EVENT, EventType::KEY_RELEASE),
		m_key(key)
	{
	}

	std::string KeyReleaseEvent::GetDescription() const
	{
		std::string desc("KeyReleaseEvent Occured : Key = ");
		desc += std::to_string(static_cast<int>(m_key));

		return desc;
	}

	KEYCODES KeyReleaseEvent::GetKeyCode() const
	{
		return m_key;
	}

	KeyHoldEvent::KeyHoldEvent(KEYCODES key) :
		EventBase(EventCategory::KEYBOARD_EVENT, EventType::KEY_HOLD),
		m_key(key)
	{
	}

	std::string KeyHoldEvent::GetDescription() const
	{
		std::string desc("KeyHoldEvent Occured : Key = ");
		desc += std::to_string(static_cast<int>(m_key));

		return desc;
	}
	KEYCODES KeyHoldEvent::GetKeyCode() const
	{
		return m_key;
	}
}