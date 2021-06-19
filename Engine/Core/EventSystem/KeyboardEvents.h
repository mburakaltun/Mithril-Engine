#pragma once
#include "EventBase.h"
#include "../InputDefs.h"

namespace Mithril
{
	//Key Press Event
	class KeyPressEvent : public EventBase
	{
	public:
		KeyPressEvent(KEYCODES key);
		std::string GetDescription() const override;
		KEYCODES GetKeyCode() const;
	private:
		KEYCODES m_key;
	};

	//Key Release Event
	class KeyReleaseEvent : public EventBase
	{
	public:
		KeyReleaseEvent(KEYCODES key);
		std::string GetDescription() const override;
		KEYCODES GetKeyCode() const;
	private:
		KEYCODES m_key;
	};

	//Key Hold Event 
	class KeyHoldEvent : public EventBase
	{
	public:
		KeyHoldEvent(KEYCODES key);
		std::string GetDescription() const override;
		KEYCODES GetKeyCode() const;
	private:
		KEYCODES m_key;
	};
}