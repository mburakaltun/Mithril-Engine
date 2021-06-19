#pragma once

#include "LayerBase.h"
#include <vector>
#include <memory>

//Creates an ADT for storing elements of 

namespace Mithril
{
	using LayerPtr = std::shared_ptr<LayerBase>;
	class LayerDeck
	{
		using LayerStorage = std::vector<LayerPtr>;
		using UpdateIterator = LayerStorage::iterator;
		using EventIterator = LayerStorage::reverse_iterator;
	public:
		LayerDeck() = default;
		~LayerDeck() = default;

	void InsertLayer(const LayerPtr& newLayer);
	void ProcessEvent(EventBase& event);
	void OnUpdate();
	private:
		LayerStorage m_layerStorage;
	};
}