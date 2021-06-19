#include "Input.h"

namespace Mithril
{
	KEYCODES Input::m_currentKey = KEYCODES::MITHRIL_KEY_NONE;
	KEYCODES Input::m_prevKey = KEYCODES::MITHRIL_KEY_NONE;

	MOUSECODES Input::m_currentMouseButton = MOUSECODES::MITHRIL_MOUSE_BUTTON_NONE;
	MOUSECODES Input::m_prevMouseButton = MOUSECODES::MITHRIL_MOUSE_BUTTON_NONE;

	double Input::m_xCursorPos = 0.0;
	double Input::m_yCursorPos = 0.0;

	double Input::m_prevXCursorPos = 0.0;
	double Input::m_prevYCursorPos = 0.0;

	double Input::m_xCursorOffset = 0.0;
	double Input::m_yCursorOffset = 0.0;

	double Input::m_xScrollOffset = 0.0;
	double Input::m_yScrollOffset = 0.0;

	void Input::UpdateKey(KEYCODES key)
	{
		m_currentKey = key;
	}

	void Input::UpdateCursorPositions(double xPos, double yPos)
	{
		m_xCursorPos = xPos;
		m_yCursorPos = yPos;
	}

	void Input::UpdateMouseButton(MOUSECODES button)
	{
		m_prevMouseButton = m_currentMouseButton;
		m_currentMouseButton = button;
	}

	void Input::OnUpdate()
	{
		//Stepping Keys and Buttons
		m_prevKey = m_currentKey;
		m_currentKey = KEYCODES::MITHRIL_KEY_NONE;

		m_currentMouseButton = m_currentMouseButton;
		m_currentMouseButton = MOUSECODES::MITHRIL_MOUSE_BUTTON_NONE;

		//calcuating cursor position offsets
		m_xCursorOffset = m_xCursorPos - m_prevXCursorPos;
		m_yCursorOffset = m_yCursorPos - m_prevYCursorPos;

		m_prevXCursorPos = m_xCursorPos;
		m_prevYCursorPos = m_yCursorPos;

		//Nullifying offsets
		m_xScrollOffset = 0.0;
		m_yScrollOffset = 0.0;
	}

	double Input::GetXOffset()
	{
		return m_xCursorOffset;
	}

	double Input::GetYOffset()
	{
		return m_yCursorOffset;
	}
}