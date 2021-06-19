#include "LayerDeck.h"

namespace Mithril
{
	void LayerDeck::InsertLayer(const LayerPtr& newLayer)
	{
		m_layerStorage.push_back(newLayer);
		newLayer->OnInsert();
	}

	void LayerDeck::ProcessEvent(EventBase& event)
	{
		for (EventIterator i = m_layerStorage.rbegin(); i != m_layerStorage.rend(); i++)
		{
			i->get()->OnEvent(event);

			//Prematurely end the loop if Event is handled by the layer
			if (event.isHandled())
				break;
		}
	}

	void LayerDeck::OnUpdate()
	{
		for (UpdateIterator i = m_layerStorage.begin(); i != m_layerStorage.end(); i++)
		{
			i->get()->OnUpdate();
		}
	}
}