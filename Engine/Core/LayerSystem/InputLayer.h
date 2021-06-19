#pragma once
#include "LayerSystem/LayerBase.h"
#include "EventSystem/KeyboardEvents.h"
#include "EventSystem/MouseEvents.h"

namespace Mithril
{
	class InputLayer : public LayerBase
	{
	public:
		InputLayer() = default;
		
		void OnUpdate() const override;
		void OnEvent(EventBase& event) override;
		void OnInsert() const override;
	private:
		void DispatchInput(EventBase& event) const;

	};
}