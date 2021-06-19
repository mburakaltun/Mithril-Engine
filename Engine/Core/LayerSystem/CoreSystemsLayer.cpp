#include "CoreSystemsLayer.h"
#include "LoggingSystem/Logger.h"

namespace Mithril
{
	CoreSystemsLayer::CoreSystemsLayer(MithrilEngine* mithrilEngine)
	{
		m_coreSystem = mithrilEngine;
	}

	void CoreSystemsLayer::OnInsert() const
	{
		Logger::Log("Inserted Core Systems Layer.");
	}

	void CoreSystemsLayer::OnUpdate() const
	{
	}

	void CoreSystemsLayer::OnEvent(EventBase& event)
	{
		if (event.GetCategory() != EventCategory::WINDOW_EVENT)
			return;

		//else
		//TODO: Implement handling code

		switch (event.GetType())
		{
		case EventType::WINDOW_CLOSE:
			m_coreSystem->Terminate();
			break;
		case EventType::WINDOW_RESIZE:
		{
			WindowResizeEvent* e = static_cast<WindowResizeEvent*>(&event);
			m_coreSystem->HandleResize(e->getWidth(), e->getHeight());
		}
			break;
		}
	}
}
