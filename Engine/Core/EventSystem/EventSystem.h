#pragma once
#include "EventSystem.h"
#include "WindowEvents.h"
#include "MouseEvents.h"
#include "KeyboardEvents.h"
#include <Core/LayerSystem/LayerDeck.h>

namespace Mithril
{
	class EventSystem
	{
	public:
		EventSystem(LayerDeck* layerDeck);
		void SignalEvent(EventBase&& event);
	private:
		LayerDeck* m_LayerDeck;
	};
}