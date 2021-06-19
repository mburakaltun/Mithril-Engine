#include "DebugLayer.h"
#include "LoggingSystem/Logger.h"

namespace Mithril
{
	void DebugLayer::OnInsert() const
	{
		Logger::Log("Debug Layer Has Been Insterted");
	}

	void DebugLayer::OnUpdate() const
	{
	}

	void DebugLayer::OnEvent(EventBase& event)
	{
		Logger::StampedLog(event.GetDescription());
	}
}