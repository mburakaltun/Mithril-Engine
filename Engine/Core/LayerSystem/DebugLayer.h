#pragma once
#include "LoggingSystem/Logger.h"
#include "LayerSystem/LayerBase.h"

//Most Basic Debugging Layer

namespace Mithril
{
	class DebugLayer : public LayerBase
	{
	public:
		DebugLayer() = default;
		~DebugLayer() = default;

		void OnInsert() const override;
		void OnUpdate() const override;
		void OnEvent(EventBase& event) override;
	private:
	};
}