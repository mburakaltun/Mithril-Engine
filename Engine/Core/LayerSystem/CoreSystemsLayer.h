#pragma once
#include <Core/LayerSystem/LayerBase.h>
#include "MithrilEngine.h"

//Core systems Layer
//Has Access to Core systems of the engine
//Will mainly handle window resize and close events

namespace Mithril
{
	class CoreSystemsLayer : public LayerBase
	{
	public:
		CoreSystemsLayer(MithrilEngine* mithrilEnginePtr);
		~CoreSystemsLayer() = default;
		void OnInsert() const override;
		void OnUpdate() const override;
		void OnEvent(EventBase& event) override;
	private:
		MithrilEngine* m_coreSystem;
	};
}