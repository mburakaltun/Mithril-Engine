#include "InputLayer.h"
#include "Input.h"
#include "LoggingSystem/Logger.h"

namespace Mithril
{
	void InputLayer::OnUpdate() const
	{
		Input::OnUpdate();
	}

	void InputLayer::OnEvent(EventBase& event)
	{
		EventCategory category = event.GetCategory();
		if (category != EventCategory::KEYBOARD_EVENT && category != EventCategory::MOUSE_EVENT)
		{
			return;
		}

		DispatchInput(event);

		event.HandleEvent();
	}

	void InputLayer::OnInsert() const
	{
		Logger::StampedLog("Input Layer has been Insterted");
	}

	void InputLayer::DispatchInput(EventBase& event) const
	{

		EventBase* eventPtr = &event;

		switch (event.GetType())
		{
		case EventType::KEY_PRESS:;
			Input::UpdateKey(static_cast<KeyPressEvent*>(eventPtr)->GetKeyCode());
			break;
		case EventType::KEY_HOLD:
			Input::UpdateKey(static_cast<KeyHoldEvent*>(eventPtr)->GetKeyCode());
			break;
		case EventType::KEY_RELEASE:
			Input::UpdateKey(static_cast<KeyReleaseEvent*>(eventPtr)->GetKeyCode());
			break;
		case EventType::MOUSE_BUTTON_CLICK:
			Input::UpdateMouseButton(static_cast<MouseClickEvent*>(eventPtr)->GetButton());
			break;
		case EventType::MOUSE_CURSOR_MOVE:
			MouseCursorMoveEvent* eventPtr = static_cast<MouseCursorMoveEvent*>(&event);
			Input::UpdateCursorPositions(static_cast<MouseCursorMoveEvent*>(eventPtr)->GetXPos(), static_cast<MouseCursorMoveEvent*>(eventPtr)->GetYPos());
			break;
		}
	}
}
