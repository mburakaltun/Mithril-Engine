#pragma once
#include "EventBase.h"

//Events That are only specific to Window.

namespace Mithril
{
	class WindowResizeEvent : public EventBase
	{
	public:
		WindowResizeEvent(int windowWidth, int windowHeight);
		std::string GetDescription() const override;
		int getHeight() const;
		int getWidth() const;
	private:
		int m_windowWidth;
		int m_windowHeight;
	};

	class WindowCloseEvent : public EventBase
	{
	public:
		WindowCloseEvent();
		std::string GetDescription() const override;
	private:
	};
}