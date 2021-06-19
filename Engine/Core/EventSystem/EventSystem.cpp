#include "EventSystem.h"

namespace Mithril
{
	EventSystem::EventSystem(LayerDeck* layerDeck)
	{
		m_LayerDeck = layerDeck;
	}
	void EventSystem::SignalEvent(EventBase&& event)
	{
		m_LayerDeck->ProcessEvent(event);
	}
}