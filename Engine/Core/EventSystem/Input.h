#pragma once
#include "InputDefs.h"

//Recieves Data from Input layer

namespace Mithril {

	class Input
	{
	public:
		static void UpdateKey(KEYCODES key);
		static void UpdateCursorPositions(double xPos, double yPos);
		static void UpdateMouseButton(MOUSECODES button);
		static void OnUpdate();

		static double GetXOffset();
		static double GetYOffset();
	private:
		static KEYCODES m_currentKey;
		static KEYCODES m_prevKey;

		static MOUSECODES m_currentMouseButton;
		static MOUSECODES m_prevMouseButton;

		static double m_xCursorPos;
		static double m_yCursorPos;

		static double m_prevXCursorPos;
		static double m_prevYCursorPos;

		static double m_xCursorOffset;
		static double m_yCursorOffset;

		static double m_xScrollOffset;
		static double m_yScrollOffset;
	};  
}