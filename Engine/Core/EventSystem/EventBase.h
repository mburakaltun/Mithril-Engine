#pragma once
#include <string>

//Base Event Class
//Concrete classes of this type will be generated by the EventSystem
//EventSystem will dispatch appropriate events to the engine

namespace Mithril
{
	enum class EventCategory
	{
		NONE,
		WINDOW_EVENT,
		KEYBOARD_EVENT,
		MOUSE_EVENT,
		UI_EVENT
	};

	enum class EventType
	{
		NONE,
		WINDOW_RESIZE,
		WINDOW_CLOSE,
		KEY_PRESS,
		KEY_HOLD,
		KEY_RELEASE,
		MOUSE_CURSOR_MOVE,
		MOUSE_BUTTON_CLICK,
		MOUSE_SCROLL
	};

	class EventBase
	{
	public:
		EventBase(EventCategory category, EventType type);
		virtual ~EventBase() = default;

		EventType GetType() const;
		EventCategory GetCategory() const;
		virtual std::string GetDescription() const = 0;
		bool isHandled() const;
		void HandleEvent();
	protected:
		bool m_handled = false;
		EventType m_type;
		EventCategory m_category;
	};
}