#pragma once
#include "Core/EventSystem/EventBase.h"
/*
Layer Interface for Engine layers
Concrete Classes derived dorm this interface will process Event
*/

namespace Mithril
{
	class LayerBase
	{
	public:
		virtual ~LayerBase() = default;

		virtual void OnInsert() const = 0;
		virtual void OnUpdate() const = 0;
		virtual void OnEvent(EventBase& event) = 0;
	private:
	};
}