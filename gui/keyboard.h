#ifndef __KEYBOARD_H_INCLUDED__
#define __KEYBOARD_H_INCLUDED__

#include <conio.h>

typedef int keycode;

class Keyboard {
public:
	static const keycode KEY_ENTER	=  13;
	static const keycode KEY_ESCAPE	=  27;
	static const keycode KEY_F1		= 300;
	static const keycode KEY_F2		= 301;
	static const keycode KEY_F3		= 302;
	static const keycode KEY_F4		= 303;
	static const keycode KEY_F5		= 304;
	static const keycode KEY_F6		= 305;
	static const keycode KEY_F7		= 306;
	static const keycode KEY_F8		= 307;
	static const keycode KEY_F9		= 308;
	static const keycode KEY_F10	= 309;
	static const keycode KEY_F11	= 310;
	static const keycode KEY_F12	= 311;
	static const keycode KEY_UP		= 312;
	static const keycode KEY_DOWN	= 313;
	static const keycode KEY_LEFT	= 314;
	static const keycode KEY_RIGHT	= 315;

	// TODO: SHIFT-F keys

	static keycode get_keycode();
};

#endif
