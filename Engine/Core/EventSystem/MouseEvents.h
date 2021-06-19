#pragma once
#include "EventBase.h"
#include "../Mithril.h"
#include "../InputDefs.h"

namespace Mithril
{
	class MouseClickEvent : public EventBase
	{
	public:
		MouseClickEvent(MOUSECODES button);
		std::string GetDescription() const override;
		MOUSECODES GetButton() const;
	private:
		MOUSECODES m_button;
	};

	class MouseScrollEvent : public EventBase
	{
	public:
		MouseScrollEvent(double xOffset, double yOffset);
		std::string GetDescription() const override;
		double GetXOffset() const;
		double GetYOffset() const;
	private:
		double m_xOffset;
		double m_yOffset;
	};

	class MouseCursorMoveEvent : public EventBase
	{
	public:
		MouseCursorMoveEvent(double xPos, double yPos);
		std::string GetDescription() const override;
		double GetXPos() const;
		double GetYPos() const;
	private:
		double m_xPos;
		double m_yPos;
	};
}