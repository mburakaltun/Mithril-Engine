#pragma once
#include "MithrilCore.h"

#ifdef GLFW_WINDOWING_SYSTEM 

namespace Mithril
{
	/*Key values for GLFW Windowing API*/
	enum class KEYCODES : int
	{
		MITHRIL_KEY_NONE = -1, /*None*/
		MITHRIL_KEY_SPACE = 32,
		MITHRIL_KEY_APOSTROPHE = 39,  /* ' */
		MITHRIL_KEY_COMMA = 44,  /* , */
		MITHRIL_KEY_MINUS = 45,  /* - */
		MITHRIL_KEY_PERIOD = 46,  /* . */
		MITHRIL_KEY_SLASH = 47,  /* / */
		MITHRIL_KEY_0 = 48,
		MITHRIL_KEY_1 = 49,
		MITHRIL_KEY_2 = 50,
		MITHRIL_KEY_3 = 51,
		MITHRIL_KEY_4 = 52,
		MITHRIL_KEY_5 = 53,
		MITHRIL_KEY_6 = 54,
		MITHRIL_KEY_7 = 55,
		MITHRIL_KEY_8 = 56,
		MITHRIL_KEY_9 = 57,
		MITHRIL_KEY_SEMICOLON = 59,  /* ; */
		MITHRIL_KEY_EQUAL = 61,  /* = */
		MITHRIL_KEY_A = 65,
		MITHRIL_KEY_B = 66,
		MITHRIL_KEY_C = 67,
		MITHRIL_KEY_D = 68,
		MITHRIL_KEY_E = 69,
		MITHRIL_KEY_F = 70,
		MITHRIL_KEY_G = 71,
		MITHRIL_KEY_H = 72,
		MITHRIL_KEY_I = 73,
		MITHRIL_KEY_J = 74,
		MITHRIL_KEY_K = 75,
		MITHRIL_KEY_L = 76,
		MITHRIL_KEY_M = 77,
		MITHRIL_KEY_N = 78,
		MITHRIL_KEY_O = 79,
		MITHRIL_KEY_P = 80,
		MITHRIL_KEY_Q = 81,
		MITHRIL_KEY_R = 82,
		MITHRIL_KEY_S = 83,
		MITHRIL_KEY_T = 84,
		MITHRIL_KEY_U = 85,
		MITHRIL_KEY_V = 86,
		MITHRIL_KEY_W = 87,
		MITHRIL_KEY_X = 88,
		MITHRIL_KEY_Y = 89,
		MITHRIL_KEY_Z = 90,
		MITHRIL_KEY_LEFT_BRACKET = 91,  /* [ */
		MITHRIL_KEY_BACKSLASH = 92,  /* \ */
		MITHRIL_KEY_RIGHT_BRACKET = 93,  /* ] */
		MITHRIL_KEY_GRAVE_ACCENT = 96,  /* ` */
		MITHRIL_KEY_WORLD_1 = 161, /* non-US*/

		/* Function keys */
		MITHRIL_KEY_ESCAPE = 256,
		MITHRIL_KEY_ENTER = 257,
		MITHRIL_KEY_TAB = 258,
		MITHRIL_KEY_BACKSPACE = 259,
		MITHRIL_KEY_INSERT = 260,
		MITHRIL_KEY_DELETE = 261,
		MITHRIL_KEY_RIGHT = 262,
		MITHRIL_KEY_LEFT = 263,
		MITHRIL_KEY_DOWN = 264,
		MITHRIL_KEY_UP = 265,
		MITHRIL_KEY_PAGE_UP = 266,
		MITHRIL_KEY_PAGE_DOWN = 267,
		MITHRIL_KEY_HOME = 268,
		MITHRIL_KEY_END = 269,
		MITHRIL_KEY_CAPS_LOCK = 280,
		MITHRIL_KEY_SCROLL_LOCK = 281,
		MITHRIL_KEY_NUM_LOCK = 282,
		MITHRIL_KEY_PRINT_SCREEN = 283,
		MITHRIL_KEY_PAUSE = 284,
		MITHRIL_KEY_F1 = 290,
		MITHRIL_KEY_F2 = 291,
		MITHRIL_KEY_F3 = 292,
		MITHRIL_KEY_F4 = 293,
		MITHRIL_KEY_F5 = 294,
		MITHRIL_KEY_F6 = 295,
		MITHRIL_KEY_F7 = 296,
		MITHRIL_KEY_F8 = 297,
		MITHRIL_KEY_F9 = 298,
		MITHRIL_KEY_F10 = 299,
		MITHRIL_KEY_F11 = 300,
		MITHRIL_KEY_F12 = 301,
		MITHRIL_KEY_F13 = 302,
		MITHRIL_KEY_F14 = 303,
		MITHRIL_KEY_F15 = 304,
		MITHRIL_KEY_F16 = 305,
		MITHRIL_KEY_F17 = 306,
		MITHRIL_KEY_F18 = 307,
		MITHRIL_KEY_F19 = 308,
		MITHRIL_KEY_F20 = 309,
		MITHRIL_KEY_F21 = 310,
		MITHRIL_KEY_F22 = 311,
		MITHRIL_KEY_F23 = 312,
		MITHRIL_KEY_F24 = 313,
		MITHRIL_KEY_F25 = 314,
		MITHRIL_KEY_KP_0 = 320,
		MITHRIL_KEY_KP_1 = 321,
		MITHRIL_KEY_KP_2 = 322,
		MITHRIL_KEY_KP_3 = 323,
		MITHRIL_KEY_KP_4 = 324,
		MITHRIL_KEY_KP_5 = 325,
		MITHRIL_KEY_KP_6 = 326,
		MITHRIL_KEY_KP_7 = 327,
		MITHRIL_KEY_KP_8 = 328,
		MITHRIL_KEY_KP_9 = 329,
		MITHRIL_KEY_KP_DECIMAL = 330,
		MITHRIL_KEY_KP_DIVIDE = 331,
		MITHRIL_KEY_KP_MULTIPLY = 332,
		MITHRIL_KEY_KP_SUBTRACT = 333,
		MITHRIL_KEY_KP_ADD = 334,
		MITHRIL_KEY_KP_ENTER = 335,
		MITHRIL_KEY_KP_EQUAL = 336,
		MITHRIL_KEY_LEFT_SHIFT = 340,
		MITHRIL_KEY_LEFT_CONTROL = 341,
		MITHRIL_KEY_LEFT_ALT = 342,
		MITHRIL_KEY_LEFT_SUPER = 343,
		MITHRIL_KEY_RIGHT_SHIFT = 344,
		MITHRIL_KEY_RIGHT_CONTROL = 345,
		MITHRIL_KEY_RIGHT_ALT = 346,
		MITHRIL_KEY_RIGHT_SUPER = 347,
		MITHRIL_KEY_MENU = 348,

		MITHRIL_KEY_LAST = MITHRIL_KEY_MENU,
	};


	/*Defining Mouse values for GLFW Windowing API/*/
	enum class MOUSECODES : int
	{
		MITHRIL_MOUSE_BUTTON_NONE = -1,
		MITHRIL_MOUSE_BUTTON_1 = 0,
		MITHRIL_MOUSE_BUTTON_2 = 1,
		MITHRIL_MOUSE_BUTTON_3 = 2,
		MITHRIL_MOUSE_BUTTON_4 = 3,
		MITHRIL_MOUSE_BUTTON_5 = 4,
		MITHRIL_MOUSE_BUTTON_6 = 5,
		MITHRIL_MOUSE_BUTTON_7 = 6,
		MITHRIL_MOUSE_BUTTON_8 = 7,
		MITHRIL_MOUSE_BUTTON_LAST = MITHRIL_MOUSE_BUTTON_8,
		MITHRIL_MOUSE_BUTTON_LEFT = MITHRIL_MOUSE_BUTTON_1,
		MITHRIL_MOUSE_BUTTON_RIGHT = MITHRIL_MOUSE_BUTTON_2,
		MITHRIL_MOUSE_BUTTON_MIDDLE = MITHRIL_MOUSE_BUTTON_3
	};
}
#endif