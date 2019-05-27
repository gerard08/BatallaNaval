#ifndef __KEYBOARD_SDL_INCLUDED_
#define __KEYBOARD_SDL_INCLUDED_

#ifndef __NOT_GRAPHICS
#include "SDL.h"
#endif

#ifdef __NOT_GRAPHICS
typedef enum
{
	SDL_SCANCODE_UNKNOWN = 0,

	/**
	*  \name Usage page 0x07
	*
	*  These values are from usage page 0x07 (USB keyboard page).
	*/
	/* @{ */

	SDL_SCANCODE_A = 4,
	SDL_SCANCODE_B = 5,
	SDL_SCANCODE_C = 6,
	SDL_SCANCODE_D = 7,
	SDL_SCANCODE_E = 8,
	SDL_SCANCODE_F = 9,
	SDL_SCANCODE_G = 10,
	SDL_SCANCODE_H = 11,
	SDL_SCANCODE_I = 12,
	SDL_SCANCODE_J = 13,
	SDL_SCANCODE_K = 14,
	SDL_SCANCODE_L = 15,
	SDL_SCANCODE_M = 16,
	SDL_SCANCODE_N = 17,
	SDL_SCANCODE_O = 18,
	SDL_SCANCODE_P = 19,
	SDL_SCANCODE_Q = 20,
	SDL_SCANCODE_R = 21,
	SDL_SCANCODE_S = 22,
	SDL_SCANCODE_T = 23,
	SDL_SCANCODE_U = 24,
	SDL_SCANCODE_V = 25,
	SDL_SCANCODE_W = 26,
	SDL_SCANCODE_X = 27,
	SDL_SCANCODE_Y = 28,
	SDL_SCANCODE_Z = 29,

	SDL_SCANCODE_1 = 30,
	SDL_SCANCODE_2 = 31,
	SDL_SCANCODE_3 = 32,
	SDL_SCANCODE_4 = 33,
	SDL_SCANCODE_5 = 34,
	SDL_SCANCODE_6 = 35,
	SDL_SCANCODE_7 = 36,
	SDL_SCANCODE_8 = 37,
	SDL_SCANCODE_9 = 38,
	SDL_SCANCODE_0 = 39,

	SDL_SCANCODE_RETURN = 40,
	SDL_SCANCODE_ESCAPE = 41,
	SDL_SCANCODE_BACKSPACE = 42,
	SDL_SCANCODE_TAB = 43,
	SDL_SCANCODE_SPACE = 44,

	SDL_SCANCODE_MINUS = 45,
	SDL_SCANCODE_EQUALS = 46,
	SDL_SCANCODE_LEFTBRACKET = 47,
	SDL_SCANCODE_RIGHTBRACKET = 48,
	SDL_SCANCODE_BACKSLASH = 49, /**< Located at the lower left of the return
								 *   key on ISO keyboards and at the right end
								 *   of the QWERTY row on ANSI keyboards.
								 *   Produces REVERSE SOLIDUS (backslash) and
								 *   VERTICAL LINE in a US layout, REVERSE
								 *   SOLIDUS and VERTICAL LINE in a UK Mac
								 *   layout, NUMBER SIGN and TILDE in a UK
								 *   Windows layout, DOLLAR SIGN and POUND SIGN
								 *   in a Swiss German layout, NUMBER SIGN and
								 *   APOSTROPHE in a German layout, GRAVE
								 *   ACCENT and POUND SIGN in a French Mac
								 *   layout, and ASTERISK and MICRO SIGN in a
								 *   French Windows layout.
								 */
	SDL_SCANCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
								 *   instead of 49 for the same key, but all
								 *   OSes I've seen treat the two codes
								 *   identically. So, as an implementor, unless
								 *   your keyboard generates both of those
								 *   codes and your OS treats them differently,
								 *   you should generate SDL_SCANCODE_BACKSLASH
								 *   instead of this code. As a user, you
								 *   should not rely on this code because SDL
								 *   will never generate it with most (all?)
								 *   keyboards.
								 */
	SDL_SCANCODE_SEMICOLON = 51,
	SDL_SCANCODE_APOSTROPHE = 52,
	SDL_SCANCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
							 *   and ISO keyboards). Produces GRAVE ACCENT and
							 *   TILDE in a US Windows layout and in US and UK
							 *   Mac layouts on ANSI keyboards, GRAVE ACCENT
							 *   and NOT SIGN in a UK Windows layout, SECTION
							 *   SIGN and PLUS-MINUS SIGN in US and UK Mac
							 *   layouts on ISO keyboards, SECTION SIGN and
							 *   DEGREE SIGN in a Swiss German layout (Mac:
							 *   only on ISO keyboards), CIRCUMFLEX ACCENT and
							 *   DEGREE SIGN in a German layout (Mac: only on
							 *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
							 *   French Windows layout, COMMERCIAL AT and
							 *   NUMBER SIGN in a French Mac layout on ISO
							 *   keyboards, and LESS-THAN SIGN and GREATER-THAN
							 *   SIGN in a Swiss German, German, or French Mac
							 *   layout on ANSI keyboards.
							 */
	SDL_SCANCODE_COMMA = 54,
	SDL_SCANCODE_PERIOD = 55,
	SDL_SCANCODE_SLASH = 56,

	SDL_SCANCODE_CAPSLOCK = 57,

	SDL_SCANCODE_F1 = 58,
	SDL_SCANCODE_F2 = 59,
	SDL_SCANCODE_F3 = 60,
	SDL_SCANCODE_F4 = 61,
	SDL_SCANCODE_F5 = 62,
	SDL_SCANCODE_F6 = 63,
	SDL_SCANCODE_F7 = 64,
	SDL_SCANCODE_F8 = 65,
	SDL_SCANCODE_F9 = 66,
	SDL_SCANCODE_F10 = 67,
	SDL_SCANCODE_F11 = 68,
	SDL_SCANCODE_F12 = 69,

	SDL_SCANCODE_PRINTSCREEN = 70,
	SDL_SCANCODE_SCROLLLOCK = 71,
	SDL_SCANCODE_PAUSE = 72,
	SDL_SCANCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
							  does send code 73, not 117) */
	SDL_SCANCODE_HOME = 74,
	SDL_SCANCODE_PAGEUP = 75,
	SDL_SCANCODE_DELETE = 76,
	SDL_SCANCODE_END = 77,
	SDL_SCANCODE_PAGEDOWN = 78,
	SDL_SCANCODE_RIGHT = 79,
	SDL_SCANCODE_LEFT = 80,
	SDL_SCANCODE_DOWN = 81,
	SDL_SCANCODE_UP = 82,

	SDL_SCANCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
									*/
	SDL_SCANCODE_KP_DIVIDE = 84,
	SDL_SCANCODE_KP_MULTIPLY = 85,
	SDL_SCANCODE_KP_MINUS = 86,
	SDL_SCANCODE_KP_PLUS = 87,
	SDL_SCANCODE_KP_ENTER = 88,
	SDL_SCANCODE_KP_1 = 89,
	SDL_SCANCODE_KP_2 = 90,
	SDL_SCANCODE_KP_3 = 91,
	SDL_SCANCODE_KP_4 = 92,
	SDL_SCANCODE_KP_5 = 93,
	SDL_SCANCODE_KP_6 = 94,
	SDL_SCANCODE_KP_7 = 95,
	SDL_SCANCODE_KP_8 = 96,
	SDL_SCANCODE_KP_9 = 97,
	SDL_SCANCODE_KP_0 = 98,
	SDL_SCANCODE_KP_PERIOD = 99,

	SDL_SCANCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
									   *   keyboards have over ANSI ones,
									   *   located between left shift and Y.
									   *   Produces GRAVE ACCENT and TILDE in a
									   *   US or UK Mac layout, REVERSE SOLIDUS
									   *   (backslash) and VERTICAL LINE in a
									   *   US or UK Windows layout, and
									   *   LESS-THAN SIGN and GREATER-THAN SIGN
									   *   in a Swiss German, German, or French
									   *   layout. */
	SDL_SCANCODE_APPLICATION = 101, /**< windows contextual menu, compose */
	SDL_SCANCODE_POWER = 102, /**< The USB document says this is a status flag,
							  *   not a physical key - but some Mac keyboards
							  *   do have a power key. */
	SDL_SCANCODE_KP_EQUALS = 103,
	SDL_SCANCODE_F13 = 104,
	SDL_SCANCODE_F14 = 105,
	SDL_SCANCODE_F15 = 106,
	SDL_SCANCODE_F16 = 107,
	SDL_SCANCODE_F17 = 108,
	SDL_SCANCODE_F18 = 109,
	SDL_SCANCODE_F19 = 110,
	SDL_SCANCODE_F20 = 111,
	SDL_SCANCODE_F21 = 112,
	SDL_SCANCODE_F22 = 113,
	SDL_SCANCODE_F23 = 114,
	SDL_SCANCODE_F24 = 115,
	SDL_SCANCODE_EXECUTE = 116,
	SDL_SCANCODE_HELP = 117,
	SDL_SCANCODE_MENU = 118,
	SDL_SCANCODE_SELECT = 119,
	SDL_SCANCODE_STOP = 120,
	SDL_SCANCODE_AGAIN = 121,   /**< redo */
	SDL_SCANCODE_UNDO = 122,
	SDL_SCANCODE_CUT = 123,
	SDL_SCANCODE_COPY = 124,
	SDL_SCANCODE_PASTE = 125,
	SDL_SCANCODE_FIND = 126,
	SDL_SCANCODE_MUTE = 127,
	SDL_SCANCODE_VOLUMEUP = 128,
	SDL_SCANCODE_VOLUMEDOWN = 129,
	/* not sure whether there's a reason to enable these */
	/*     SDL_SCANCODE_LOCKINGCAPSLOCK = 130,  */
	/*     SDL_SCANCODE_LOCKINGNUMLOCK = 131, */
	/*     SDL_SCANCODE_LOCKINGSCROLLLOCK = 132, */
	SDL_SCANCODE_KP_COMMA = 133,
	SDL_SCANCODE_KP_EQUALSAS400 = 134,

	SDL_SCANCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
									   footnotes in USB doc */
	SDL_SCANCODE_INTERNATIONAL2 = 136,
	SDL_SCANCODE_INTERNATIONAL3 = 137, /**< Yen */
	SDL_SCANCODE_INTERNATIONAL4 = 138,
	SDL_SCANCODE_INTERNATIONAL5 = 139,
	SDL_SCANCODE_INTERNATIONAL6 = 140,
	SDL_SCANCODE_INTERNATIONAL7 = 141,
	SDL_SCANCODE_INTERNATIONAL8 = 142,
	SDL_SCANCODE_INTERNATIONAL9 = 143,
	SDL_SCANCODE_LANG1 = 144, /**< Hangul/English toggle */
	SDL_SCANCODE_LANG2 = 145, /**< Hanja conversion */
	SDL_SCANCODE_LANG3 = 146, /**< Katakana */
	SDL_SCANCODE_LANG4 = 147, /**< Hiragana */
	SDL_SCANCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
	SDL_SCANCODE_LANG6 = 149, /**< reserved */
	SDL_SCANCODE_LANG7 = 150, /**< reserved */
	SDL_SCANCODE_LANG8 = 151, /**< reserved */
	SDL_SCANCODE_LANG9 = 152, /**< reserved */

	SDL_SCANCODE_ALTERASE = 153, /**< Erase-Eaze */
	SDL_SCANCODE_SYSREQ = 154,
	SDL_SCANCODE_CANCEL = 155,
	SDL_SCANCODE_CLEAR = 156,
	SDL_SCANCODE_PRIOR = 157,
	SDL_SCANCODE_RETURN2 = 158,
	SDL_SCANCODE_SEPARATOR = 159,
	SDL_SCANCODE_OUT = 160,
	SDL_SCANCODE_OPER = 161,
	SDL_SCANCODE_CLEARAGAIN = 162,
	SDL_SCANCODE_CRSEL = 163,
	SDL_SCANCODE_EXSEL = 164,

	SDL_SCANCODE_KP_00 = 176,
	SDL_SCANCODE_KP_000 = 177,
	SDL_SCANCODE_THOUSANDSSEPARATOR = 178,
	SDL_SCANCODE_DECIMALSEPARATOR = 179,
	SDL_SCANCODE_CURRENCYUNIT = 180,
	SDL_SCANCODE_CURRENCYSUBUNIT = 181,
	SDL_SCANCODE_KP_LEFTPAREN = 182,
	SDL_SCANCODE_KP_RIGHTPAREN = 183,
	SDL_SCANCODE_KP_LEFTBRACE = 184,
	SDL_SCANCODE_KP_RIGHTBRACE = 185,
	SDL_SCANCODE_KP_TAB = 186,
	SDL_SCANCODE_KP_BACKSPACE = 187,
	SDL_SCANCODE_KP_A = 188,
	SDL_SCANCODE_KP_B = 189,
	SDL_SCANCODE_KP_C = 190,
	SDL_SCANCODE_KP_D = 191,
	SDL_SCANCODE_KP_E = 192,
	SDL_SCANCODE_KP_F = 193,
	SDL_SCANCODE_KP_XOR = 194,
	SDL_SCANCODE_KP_POWER = 195,
	SDL_SCANCODE_KP_PERCENT = 196,
	SDL_SCANCODE_KP_LESS = 197,
	SDL_SCANCODE_KP_GREATER = 198,
	SDL_SCANCODE_KP_AMPERSAND = 199,
	SDL_SCANCODE_KP_DBLAMPERSAND = 200,
	SDL_SCANCODE_KP_VERTICALBAR = 201,
	SDL_SCANCODE_KP_DBLVERTICALBAR = 202,
	SDL_SCANCODE_KP_COLON = 203,
	SDL_SCANCODE_KP_HASH = 204,
	SDL_SCANCODE_KP_SPACE = 205,
	SDL_SCANCODE_KP_AT = 206,
	SDL_SCANCODE_KP_EXCLAM = 207,
	SDL_SCANCODE_KP_MEMSTORE = 208,
	SDL_SCANCODE_KP_MEMRECALL = 209,
	SDL_SCANCODE_KP_MEMCLEAR = 210,
	SDL_SCANCODE_KP_MEMADD = 211,
	SDL_SCANCODE_KP_MEMSUBTRACT = 212,
	SDL_SCANCODE_KP_MEMMULTIPLY = 213,
	SDL_SCANCODE_KP_MEMDIVIDE = 214,
	SDL_SCANCODE_KP_PLUSMINUS = 215,
	SDL_SCANCODE_KP_CLEAR = 216,
	SDL_SCANCODE_KP_CLEARENTRY = 217,
	SDL_SCANCODE_KP_BINARY = 218,
	SDL_SCANCODE_KP_OCTAL = 219,
	SDL_SCANCODE_KP_DECIMAL = 220,
	SDL_SCANCODE_KP_HEXADECIMAL = 221,

	SDL_SCANCODE_LCTRL = 224,
	SDL_SCANCODE_LSHIFT = 225,
	SDL_SCANCODE_LALT = 226, /**< alt, option */
	SDL_SCANCODE_LGUI = 227, /**< windows, command (apple), meta */
	SDL_SCANCODE_RCTRL = 228,
	SDL_SCANCODE_RSHIFT = 229,
	SDL_SCANCODE_RALT = 230, /**< alt gr, option */
	SDL_SCANCODE_RGUI = 231, /**< windows, command (apple), meta */

	SDL_SCANCODE_MODE = 257,    /**< I'm not sure if this is really not covered
								*   by any of the above, but since there's a
								*   special KMOD_MODE for it I'm adding it here
								*/

								/* @} *//* Usage page 0x07 */

										/**
										*  \name Usage page 0x0C
										*
										*  These values are mapped from usage page 0x0C (USB consumer page).
										*/
										/* @{ */

										SDL_SCANCODE_AUDIONEXT = 258,
										SDL_SCANCODE_AUDIOPREV = 259,
										SDL_SCANCODE_AUDIOSTOP = 260,
										SDL_SCANCODE_AUDIOPLAY = 261,
										SDL_SCANCODE_AUDIOMUTE = 262,
										SDL_SCANCODE_MEDIASELECT = 263,
										SDL_SCANCODE_WWW = 264,
										SDL_SCANCODE_MAIL = 265,
										SDL_SCANCODE_CALCULATOR = 266,
										SDL_SCANCODE_COMPUTER = 267,
										SDL_SCANCODE_AC_SEARCH = 268,
										SDL_SCANCODE_AC_HOME = 269,
										SDL_SCANCODE_AC_BACK = 270,
										SDL_SCANCODE_AC_FORWARD = 271,
										SDL_SCANCODE_AC_STOP = 272,
										SDL_SCANCODE_AC_REFRESH = 273,
										SDL_SCANCODE_AC_BOOKMARKS = 274,

										/* @} *//* Usage page 0x0C */

												/**
												*  \name Walther keys
												*
												*  These are values that Christian Walther added (for mac keyboard?).
												*/
												/* @{ */

												SDL_SCANCODE_BRIGHTNESSDOWN = 275,
												SDL_SCANCODE_BRIGHTNESSUP = 276,
												SDL_SCANCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
																				  switch, video mode switch */
	SDL_SCANCODE_KBDILLUMTOGGLE = 278,
	SDL_SCANCODE_KBDILLUMDOWN = 279,
	SDL_SCANCODE_KBDILLUMUP = 280,
	SDL_SCANCODE_EJECT = 281,
	SDL_SCANCODE_SLEEP = 282,

	SDL_SCANCODE_APP1 = 283,
	SDL_SCANCODE_APP2 = 284,

	/* @} *//* Walther keys */

			/* Add any other keys here. */

			SDL_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
									for array bounds */
} SDL_Scancode;


#define SDLK_SCANCODE_MASK (1<<30)
#define SDL_SCANCODE_TO_KEYCODE(X)  (X | SDLK_SCANCODE_MASK)
enum
{
	SDLK_UNKNOWN = 0,

	SDLK_RETURN = '\r',
	SDLK_ESCAPE = '\033',
	SDLK_BACKSPACE = '\b',
	SDLK_TAB = '\t',
	SDLK_SPACE = ' ',
	SDLK_EXCLAIM = '!',
	SDLK_QUOTEDBL = '"',
	SDLK_HASH = '#',
	SDLK_PERCENT = '%',
	SDLK_DOLLAR = '$',
	SDLK_AMPERSAND = '&',
	SDLK_QUOTE = '\'',
	SDLK_LEFTPAREN = '(',
	SDLK_RIGHTPAREN = ')',
	SDLK_ASTERISK = '*',
	SDLK_PLUS = '+',
	SDLK_COMMA = ',',
	SDLK_MINUS = '-',
	SDLK_PERIOD = '.',
	SDLK_SLASH = '/',
	SDLK_0 = '0',
	SDLK_1 = '1',
	SDLK_2 = '2',
	SDLK_3 = '3',
	SDLK_4 = '4',
	SDLK_5 = '5',
	SDLK_6 = '6',
	SDLK_7 = '7',
	SDLK_8 = '8',
	SDLK_9 = '9',
	SDLK_COLON = ':',
	SDLK_SEMICOLON = ';',
	SDLK_LESS = '<',
	SDLK_EQUALS = '=',
	SDLK_GREATER = '>',
	SDLK_QUESTION = '?',
	SDLK_AT = '@',
	/*
	Skip uppercase letters
	*/
	SDLK_LEFTBRACKET = '[',
	SDLK_BACKSLASH = '\\',
	SDLK_RIGHTBRACKET = ']',
	SDLK_CARET = '^',
	SDLK_UNDERSCORE = '_',
	SDLK_BACKQUOTE = '`',
	SDLK_a = 'a',
	SDLK_b = 'b',
	SDLK_c = 'c',
	SDLK_d = 'd',
	SDLK_e = 'e',
	SDLK_f = 'f',
	SDLK_g = 'g',
	SDLK_h = 'h',
	SDLK_i = 'i',
	SDLK_j = 'j',
	SDLK_k = 'k',
	SDLK_l = 'l',
	SDLK_m = 'm',
	SDLK_n = 'n',
	SDLK_o = 'o',
	SDLK_p = 'p',
	SDLK_q = 'q',
	SDLK_r = 'r',
	SDLK_s = 's',
	SDLK_t = 't',
	SDLK_u = 'u',
	SDLK_v = 'v',
	SDLK_w = 'w',
	SDLK_x = 'x',
	SDLK_y = 'y',
	SDLK_z = 'z',

	SDLK_CAPSLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK),

	SDLK_F1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1),
	SDLK_F2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2),
	SDLK_F3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3),
	SDLK_F4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4),
	SDLK_F5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5),
	SDLK_F6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6),
	SDLK_F7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7),
	SDLK_F8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8),
	SDLK_F9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9),
	SDLK_F10 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10),
	SDLK_F11 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11),
	SDLK_F12 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12),

	SDLK_PRINTSCREEN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN),
	SDLK_SCROLLLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK),
	SDLK_PAUSE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE),
	SDLK_INSERT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT),
	SDLK_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME),
	SDLK_PAGEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP),
	SDLK_DELETE = '\177',
	SDLK_END = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END),
	SDLK_PAGEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN),
	SDLK_RIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT),
	SDLK_LEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT),
	SDLK_DOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN),
	SDLK_UP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP),

	SDLK_NUMLOCKCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR),
	SDLK_KP_DIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE),
	SDLK_KP_MULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY),
	SDLK_KP_MINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS),
	SDLK_KP_PLUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS),
	SDLK_KP_ENTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER),
	SDLK_KP_1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1),
	SDLK_KP_2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2),
	SDLK_KP_3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3),
	SDLK_KP_4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4),
	SDLK_KP_5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5),
	SDLK_KP_6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6),
	SDLK_KP_7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7),
	SDLK_KP_8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8),
	SDLK_KP_9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9),
	SDLK_KP_0 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0),
	SDLK_KP_PERIOD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD),

	SDLK_APPLICATION = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION),
	SDLK_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER),
	SDLK_KP_EQUALS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS),
	SDLK_F13 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13),
	SDLK_F14 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14),
	SDLK_F15 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15),
	SDLK_F16 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16),
	SDLK_F17 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17),
	SDLK_F18 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18),
	SDLK_F19 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19),
	SDLK_F20 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20),
	SDLK_F21 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21),
	SDLK_F22 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22),
	SDLK_F23 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23),
	SDLK_F24 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24),
	SDLK_EXECUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE),
	SDLK_HELP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP),
	SDLK_MENU = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU),
	SDLK_SELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT),
	SDLK_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP),
	SDLK_AGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN),
	SDLK_UNDO = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO),
	SDLK_CUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT),
	SDLK_COPY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY),
	SDLK_PASTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE),
	SDLK_FIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND),
	SDLK_MUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE),
	SDLK_VOLUMEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP),
	SDLK_VOLUMEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN),
	SDLK_KP_COMMA = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA),
	SDLK_KP_EQUALSAS400 =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400),

	SDLK_ALTERASE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE),
	SDLK_SYSREQ = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ),
	SDLK_CANCEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL),
	SDLK_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR),
	SDLK_PRIOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR),
	SDLK_RETURN2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2),
	SDLK_SEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR),
	SDLK_OUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT),
	SDLK_OPER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER),
	SDLK_CLEARAGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN),
	SDLK_CRSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL),
	SDLK_EXSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL),

	SDLK_KP_00 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00),
	SDLK_KP_000 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000),
	SDLK_THOUSANDSSEPARATOR =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR),
	SDLK_DECIMALSEPARATOR =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR),
	SDLK_CURRENCYUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT),
	SDLK_CURRENCYSUBUNIT =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT),
	SDLK_KP_LEFTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN),
	SDLK_KP_RIGHTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN),
	SDLK_KP_LEFTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE),
	SDLK_KP_RIGHTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE),
	SDLK_KP_TAB = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB),
	SDLK_KP_BACKSPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE),
	SDLK_KP_A = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A),
	SDLK_KP_B = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B),
	SDLK_KP_C = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C),
	SDLK_KP_D = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D),
	SDLK_KP_E = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E),
	SDLK_KP_F = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F),
	SDLK_KP_XOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR),
	SDLK_KP_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER),
	SDLK_KP_PERCENT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT),
	SDLK_KP_LESS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS),
	SDLK_KP_GREATER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER),
	SDLK_KP_AMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND),
	SDLK_KP_DBLAMPERSAND =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND),
	SDLK_KP_VERTICALBAR =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR),
	SDLK_KP_DBLVERTICALBAR =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR),
	SDLK_KP_COLON = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON),
	SDLK_KP_HASH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH),
	SDLK_KP_SPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE),
	SDLK_KP_AT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT),
	SDLK_KP_EXCLAM = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM),
	SDLK_KP_MEMSTORE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE),
	SDLK_KP_MEMRECALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL),
	SDLK_KP_MEMCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR),
	SDLK_KP_MEMADD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD),
	SDLK_KP_MEMSUBTRACT =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT),
	SDLK_KP_MEMMULTIPLY =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY),
	SDLK_KP_MEMDIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE),
	SDLK_KP_PLUSMINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS),
	SDLK_KP_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR),
	SDLK_KP_CLEARENTRY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY),
	SDLK_KP_BINARY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY),
	SDLK_KP_OCTAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL),
	SDLK_KP_DECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL),
	SDLK_KP_HEXADECIMAL =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL),

	SDLK_LCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL),
	SDLK_LSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT),
	SDLK_LALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT),
	SDLK_LGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI),
	SDLK_RCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL),
	SDLK_RSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT),
	SDLK_RALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT),
	SDLK_RGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI),

	SDLK_MODE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE),

	SDLK_AUDIONEXT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT),
	SDLK_AUDIOPREV = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV),
	SDLK_AUDIOSTOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP),
	SDLK_AUDIOPLAY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY),
	SDLK_AUDIOMUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE),
	SDLK_MEDIASELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT),
	SDLK_WWW = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW),
	SDLK_MAIL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL),
	SDLK_CALCULATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR),
	SDLK_COMPUTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER),
	SDLK_AC_SEARCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH),
	SDLK_AC_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME),
	SDLK_AC_BACK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK),
	SDLK_AC_FORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD),
	SDLK_AC_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP),
	SDLK_AC_REFRESH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH),
	SDLK_AC_BOOKMARKS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS),

	SDLK_BRIGHTNESSDOWN =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN),
	SDLK_BRIGHTNESSUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP),
	SDLK_DISPLAYSWITCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH),
	SDLK_KBDILLUMTOGGLE =
	SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE),
	SDLK_KBDILLUMDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN),
	SDLK_KBDILLUMUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP),
	SDLK_EJECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT),
	SDLK_SLEEP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP)
};
#endif


#define NUM_KEYBOARD_KEY_CODES                           SDL_NUM_SCANCODES

#define KEYBOARD_NONE                                    SDLK_UNKNOWN


#define KEYBOARD_RETURN                                  SDLK_RETURN
#define KEYBOARD_ESCAPE                                  SDLK_ESCAPE
#define KEYBOARD_BACKSPACE                               SDLK_BACKSPACE
#define KEYBOARD_TAB                                     SDLK_TAB
#define KEYBOARD_SPACE                                   SDLK_SPACE
#define KEYBOARD_EXCLAIM                                 SDLK_EXCLAIM
#define KEYBOARD_QUOTEDBL                                SDLK_QUOTEDBL
#define KEYBOARD_HASH                                    SDLK_HASH
#define KEYBOARD_PERCENT                                 SDLK_PERCENT
#define KEYBOARD_DOLLAR                                  SDLK_DOLLAR
#define KEYBOARD_AMPERSAND                               SDLK_AMPERSAND
#define KEYBOARD_QUOTE                                   SDLK_QUOTE
#define KEYBOARD_LEFTPAREN                               SDLK_LEFTPAREN
#define KEYBOARD_RIGHTPAREN                              SDLK_RIGHTPAREN
#define KEYBOARD_ASTERISK                                SDLK_ASTERISK
#define KEYBOARD_PLUS                                    SDLK_PLUS
#define KEYBOARD_COMMA                                   SDLK_COMMA
#define KEYBOARD_MINUS                                   SDLK_MINUS
#define KEYBOARD_PERIOD                                  SDLK_PERIOD
#define KEYBOARD_SLASH                                   SDLK_SLASH
#define KEYBOARD_0                                       SDLK_0
#define KEYBOARD_1                                       SDLK_1
#define KEYBOARD_2                                       SDLK_2
#define KEYBOARD_3                                       SDLK_3
#define KEYBOARD_4                                       SDLK_4
#define KEYBOARD_5                                       SDLK_5
#define KEYBOARD_6                                       SDLK_6
#define KEYBOARD_7                                       SDLK_7
#define KEYBOARD_8                                       SDLK_8
#define KEYBOARD_9                                       SDLK_9
#define KEYBOARD_COLON                                   SDLK_COLON
#define KEYBOARD_SEMICOLON                               SDLK_SEMICOLON
#define KEYBOARD_LESS                                    SDLK_LESS
#define KEYBOARD_EQUALS                                  SDLK_EQUALS
#define KEYBOARD_GREATER                                 SDLK_GREATER
#define KEYBOARD_QUESTION                                SDLK_QUESTION
#define KEYBOARD_AT                                      SDLK_AT

#define KEYBOARD_LEFTBRACKET                             SDLK_LEFTBRACKET
#define KEYBOARD_BACKSLASH                               SDLK_BACKSLASH
#define KEYBOARD_RIGHTBRACKET                            SDLK_RIGHTBRACKET
#define KEYBOARD_CARET                                   SDLK_CARET
#define KEYBOARD_UNDERSCORE                              SDLK_UNDERSCORE
#define KEYBOARD_BACKQUOTE                               SDLK_BACKQUOTE
#define KEYBOARD_A                                       SDLK_a
#define KEYBOARD_B                                       SDLK_b
#define KEYBOARD_C                                       SDLK_c
#define KEYBOARD_D                                       SDLK_d
#define KEYBOARD_E                                       SDLK_e
#define KEYBOARD_F                                       SDLK_f
#define KEYBOARD_G                                       SDLK_g
#define KEYBOARD_H                                       SDLK_h
#define KEYBOARD_I                                       SDLK_i
#define KEYBOARD_J                                       SDLK_j
#define KEYBOARD_K                                       SDLK_k
#define KEYBOARD_L                                       SDLK_l
#define KEYBOARD_M                                       SDLK_m
#define KEYBOARD_N                                       SDLK_n
#define KEYBOARD_O                                       SDLK_o
#define KEYBOARD_P                                       SDLK_p
#define KEYBOARD_Q                                       SDLK_q
#define KEYBOARD_R                                       SDLK_r
#define KEYBOARD_S                                       SDLK_s
#define KEYBOARD_T                                       SDLK_t
#define KEYBOARD_U                                       SDLK_u
#define KEYBOARD_V                                       SDLK_v
#define KEYBOARD_W                                       SDLK_w
#define KEYBOARD_X                                       SDLK_x
#define KEYBOARD_Y                                       SDLK_y
#define KEYBOARD_Z                                       SDLK_z

#define KEYBOARD_CAPSLOCK                                SDLK_CAPSLOCK

#define KEYBOARD_F1                                      SDLK_F1
#define KEYBOARD_F2                                      SDLK_F2
#define KEYBOARD_F3                                      SDLK_F3
#define KEYBOARD_F4                                      SDLK_F4
#define KEYBOARD_F5                                      SDLK_F5
#define KEYBOARD_F6                                      SDLK_F6
#define KEYBOARD_F7                                      SDLK_F7
#define KEYBOARD_F8                                      SDLK_F8
#define KEYBOARD_F9                                      SDLK_F9
#define KEYBOARD_F10                                     SDLK_F10
#define KEYBOARD_F11                                     SDLK_F11
#define KEYBOARD_F12                                     SDLK_F12

#define KEYBOARD_PRINTSCREEN                             SDLK_PRINTSCREEN
#define KEYBOARD_SCROLLLOCK                              SDLK_SCROLLLOCK
#define KEYBOARD_PAUSE                                   SDLK_PAUSE
#define KEYBOARD_INSERT                                  SDLK_INSERT
#define KEYBOARD_HOME                                    SDLK_HOME
#define KEYBOARD_PAGEUP                                  SDLK_PAGEUP
#define KEYBOARD_DELETE                                  SDLK_DELETE
#define KEYBOARD_END                                     SDLK_END
#define KEYBOARD_PAGEDOWN                                SDLK_PAGEDOWN
#define KEYBOARD_RIGHT                                   SDLK_RIGHT
#define KEYBOARD_LEFT                                    SDLK_LEFT
#define KEYBOARD_DOWN                                    SDLK_DOWN
#define KEYBOARD_UP                                      SDLK_UP

#define KEYBOARD_NUMLOCKCLEAR                            SDLK_NUMLOCKCLEAR
#define KEYBOARD_KEYPAD_DIVIDE                           SDLK_KP_DIVIDE
#define KEYBOARD_KEYPAD_MULTIPLY                         SDLK_KP_MULTIPLY
#define KEYBOARD_KEYPAD_MINUS                            SDLK_KP_MINUS
#define KEYBOARD_KEYPAD_PLUS                             SDLK_KP_PLUS
#define KEYBOARD_KEYPAD_ENTER                            SDLK_KP_ENTER
#define KEYBOARD_KEYPAD_1                                SDLK_KP_1
#define KEYBOARD_KEYPAD_2                                SDLK_KP_2
#define KEYBOARD_KEYPAD_3                                SDLK_KP_3
#define KEYBOARD_KEYPAD_4                                SDLK_KP_4
#define KEYBOARD_KEYPAD_5                                SDLK_KP_5
#define KEYBOARD_KEYPAD_6                                SDLK_KP_6
#define KEYBOARD_KEYPAD_7                                SDLK_KP_7
#define KEYBOARD_KEYPAD_8                                SDLK_KP_8
#define KEYBOARD_KEYPAD_9                                SDLK_KP_9
#define KEYBOARD_KEYPAD_0                                SDLK_KP_0
#define KEYBOARD_KEYPAD_PERIOD                           SDLK_KP_PERIOD

#define KEYBOARD_APPLICATION                             SDLK_APPLICATION
#define KEYBOARD_POWER                                   SDLK_POWER
#define KEYBOARD_KEYPAD_EQUALS                           SDLK_KP_EQUALS
#define KEYBOARD_F13                                     SDLK_F13
#define KEYBOARD_F14                                     SDLK_F14
#define KEYBOARD_F15                                     SDLK_F15
#define KEYBOARD_F16                                     SDLK_F16
#define KEYBOARD_F17                                     SDLK_F17
#define KEYBOARD_F18                                     SDLK_F18
#define KEYBOARD_F19                                     SDLK_F19
#define KEYBOARD_F20                                     SDLK_F20
#define KEYBOARD_F21                                     SDLK_F21
#define KEYBOARD_F22                                     SDLK_F22
#define KEYBOARD_F23                                     SDLK_F23
#define KEYBOARD_F24                                     SDLK_F24
#define KEYBOARD_EXECUTE                                 SDLK_EXECUTE
#define KEYBOARD_HELP                                    SDLK_HELP
#define KEYBOARD_MENU                                    SDLK_MENU
#define KEYBOARD_SELECT                                  SDLK_SELECT
#define KEYBOARD_STOP                                    SDLK_STOP
#define KEYBOARD_AGAIN                                   SDLK_AGAIN
#define KEYBOARD_UNDO                                    SDLK_UNDO
#define KEYBOARD_CUT                                     SDLK_CUT
#define KEYBOARD_COPY                                    SDLK_COPY
#define KEYBOARD_PASTE                                   SDLK_PASTE
#define KEYBOARD_FIND                                    SDLK_FIND
#define KEYBOARD_MUTE                                    SDLK_MUTE
#define KEYBOARD_VOLUMEUP                                SDLK_VOLUMEUP
#define KEYBOARD_VOLUMEDOWN                              SDLK_VOLUMEDOWN
#define KEYBOARD_KEYPAD_COMMA                            SDLK_KP_COMMA
#define KEYBOARD_KEYPAD_EQUALSAS400                      SDLK_KP_EQUALSAS400


#define KEYBOARD_ALTERASE                                SDLK_ALTERASE
#define KEYBOARD_SYSREQ                                  SDLK_SYSREQ
#define KEYBOARD_CANCEL                                  SDLK_CANCEL
#define KEYBOARD_CLEAR                                   SDLK_CLEAR
#define KEYBOARD_PRIOR                                   SDLK_PRIOR
#define KEYBOARD_RETURN2                                 SDLK_RETURN2
#define KEYBOARD_SEPARATOR                               SDLK_SEPARATOR
#define KEYBOARD_OUT                                     SDLK_OUT
#define KEYBOARD_OPER                                    SDLK_OPER
#define KEYBOARD_CLEARAGAIN                              SDLK_CLEARAGAIN
#define KEYBOARD_CRSEL                                   SDLK_CRSEL
#define KEYBOARD_EXSEL                                   SDLK_EXSEL

#define KEYBOARD_KEYPAD_00                               SDLK_KP_00
#define KEYBOARD_KEYPAD_000                              SDLK_KP_000
#define KEYBOARD_THOUSANDSSEPARATOR                      SDLK_THOUSANDSSEPARATOR

#define KEYBOARD_DECIMALSEPARATOR                        SDLK_DECIMALSEPARATOR

#define KEYBOARD_CURRENCYUNIT                            SDLK_CURRENCYUNIT
#define KEYBOARD_CURRENCYSUBUNIT                         SDLK_CURRENCYSUBUNIT

#define KEYBOARD_KEYPAD_LEFTPAREN                        SDLK_KP_LEFTPAREN
#define KEYBOARD_KEYPAD_RIGHTPAREN                       SDLK_KP_RIGHTPAREN
#define KEYBOARD_KEYPAD_LEFTBRACE                        SDLK_KP_LEFTBRACE
#define KEYBOARD_KEYPAD_RIGHTBRACE                       SDLK_KP_RIGHTBRACE
#define KEYBOARD_KEYPAD_TAB                              SDLK_KP_TAB
#define KEYBOARD_KEYPAD_BACKSPACE                        SDLK_KP_BACKSPACE
#define KEYBOARD_KEYPAD_A                                SDLK_KP_A
#define KEYBOARD_KEYPAD_B                                SDLK_KP_B
#define KEYBOARD_KEYPAD_C                                SDLK_KP_C
#define KEYBOARD_KEYPAD_D                                SDLK_KP_D
#define KEYBOARD_KEYPAD_E                                SDLK_KP_E
#define KEYBOARD_KEYPAD_F                                SDLK_KP_F
#define KEYBOARD_KEYPAD_XOR                              SDLK_KP_XOR
#define KEYBOARD_KEYPAD_POWER                            SDLK_KP_POWER
#define KEYBOARD_KEYPAD_PERCENT                          SDLK_KP_PERCENT
#define KEYBOARD_KEYPAD_LESS                             SDLK_KP_LESS
#define KEYBOARD_KEYPAD_GREATER                          SDLK_KP_GREATER
#define KEYBOARD_KEYPAD_AMPERSAND                        SDLK_KP_AMPERSAND
#define KEYBOARD_KEYPAD_DBLAMPERSAND                     SDLK_KP_DBLAMPERSAND

#define KEYBOARD_KEYPAD_VERTICALBAR                      SDLK_KP_VERTICALBAR

#define KEYBOARD_KEYPAD_DBLVERTICALBAR                   SDLK_KP_DBLVERTICALBAR

#define KEYBOARD_KEYPAD_COLON                            SDLK_KP_COLON
#define KEYBOARD_KEYPAD_HASH                             SDLK_KP_HASH
#define KEYBOARD_KEYPAD_SPACE                            SDLK_KP_SPACE
#define KEYBOARD_KEYPAD_AT                               SDLK_KP_AT
#define KEYBOARD_KEYPAD_EXCLAM                           SDLK_KP_EXCLAM
#define KEYBOARD_KEYPAD_MEMSTORE                         SDLK_KP_MEMSTORE
#define KEYBOARD_KEYPAD_MEMRECALL                        SDLK_KP_MEMRECALL
#define KEYBOARD_KEYPAD_MEMCLEAR                         SDLK_KP_MEMCLEAR
#define KEYBOARD_KEYPAD_MEMADD                           SDLK_KP_MEMADD
#define KEYBOARD_KEYPAD_MEMSUBTRACT                      SDLK_KP_MEMSUBTRACT

#define KEYBOARD_KEYPAD_MEMMULTIPLY                      SDLK_KP_MEMMULTIPLY

#define KEYBOARD_KEYPAD_MEMDIVIDE                        SDLK_KP_MEMDIVIDE
#define KEYBOARD_KEYPAD_PLUSMINUS                        SDLK_KP_PLUSMINUS
#define KEYBOARD_KEYPAD_CLEAR                            SDLK_KP_CLEAR
#define KEYBOARD_KEYPAD_CLEARENTRY                       SDLK_KP_CLEARENTRY
#define KEYBOARD_KEYPAD_BINARY                           SDLK_KP_BINARY
#define KEYBOARD_KEYPAD_OCTAL                            SDLK_KP_OCTAL
#define KEYBOARD_KEYPAD_DECIMAL                          SDLK_KP_DECIMAL
#define KEYBOARD_KEYPAD_HEXADECIMAL                      SDLK_KP_HEXADECIMAL


#define KEYBOARD_LCTRL                                   SDLK_LCTRL
#define KEYBOARD_LSHIFT                                  SDLK_LSHIFT
#define KEYBOARD_LALT                                    SDLK_LALT
#define KEYBOARD_LGUI                                    SDLK_LGUI
#define KEYBOARD_RCTRL                                   SDLK_RCTRL
#define KEYBOARD_RSHIFT                                  SDLK_RSHIFT
#define KEYBOARD_RALT                                    SDLK_RALT
#define KEYBOARD_RGUI                                    SDLK_RGUI

#define KEYBOARD_MODE                                    SDLK_MODE

#define KEYBOARD_AUDIONEXT                               SDLK_AUDIONEXT
#define KEYBOARD_AUDIOPREV                               SDLK_AUDIOPREV
#define KEYBOARD_AUDIOSTOP                               SDLK_AUDIOSTOP
#define KEYBOARD_AUDIOPLAY                               SDLK_AUDIOPLAY
#define KEYBOARD_AUDIOMUTE                               SDLK_AUDIOMUTE
#define KEYBOARD_MEDIASELECT                             SDLK_MEDIASELECT
#define KEYBOARD_WWW                                     SDLK_WWW
#define KEYBOARD_MAIL                                    SDLK_MAIL
#define KEYBOARD_CALCULATOR                              SDLK_CALCULATOR
#define KEYBOARD_COMPUTER                                SDLK_COMPUTER
#define KEYBOARD_AC_SEARCH                               SDLK_AC_SEARCH
#define KEYBOARD_AC_HOME                                 SDLK_AC_HOME
#define KEYBOARD_AC_BACK                                 SDLK_AC_BACK
#define KEYBOARD_AC_FORWARD                              SDLK_AC_FORWARD
#define KEYBOARD_AC_STOP                                 SDLK_AC_STOP
#define KEYBOARD_AC_REFRESH                              SDLK_AC_REFRESH
#define KEYBOARD_AC_BOOKMARKS                            SDLK_AC_BOOKMARKS

#define KEYBOARD_BRIGHTNESSDOWN                          SDLK_BRIGHTNESSDOWN

#define KEYBOARD_BRIGHTNESSUP                            SDLK_BRIGHTNESSUP
#define KEYBOARD_DISPLAYSWITCH                           SDLK_DISPLAYSWITCH
#define KEYBOARD_KBDILLUMTOGGLE                          SDLK_KBDILLUMTOGGLE

#define KEYBOARD_KBDILLUMDOWN                            SDLK_KBDILLUMDOWN
#define KEYBOARD_KBDILLUMUP                              SDLK_KBDILLUMUP
#define KEYBOARD_EJECT                                   SDLK_EJECT
#define KEYBOARD_SLEEP                                   SDLK_SLEEP


#endif
