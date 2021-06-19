#include "EventBase.h"

namespace Mithril
{
	EventBase::EventBase(EventCategory category, EventType type)
		: m_category(category), m_type(type)
	{
	}

	EventType EventBase::GetType() const
	{
		return m_type;
	}

	EventCategory EventBase::GetCategory() const
	{
		return m_category;
	}

	bool EventBase::isHandled() const
	{
		return m_handled;
	}

	void EventBase::HandleEvent()
	{
		m_handled = true;
	}
}