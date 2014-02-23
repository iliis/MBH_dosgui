#include "keyboard.h"

///////////////////////////////////////////////////////////////////////////////
keycode Keyboard::get_keycode()
{
	int k = getch();

	if (k == 0) {
		// special key
		k = getch();
		switch (k) {
			case 59:	return KEY_F1;
			case 60:	return KEY_F2;
			case 61:	return KEY_F3;
			case 62:	return KEY_F4;
			case 63:	return KEY_F5;
			case 64:	return KEY_F6;
			case 65:	return KEY_F7;
			case 66:	return KEY_F8;
			case 67:	return KEY_F9;
			case 68:	return KEY_F10;
			case 133:	return KEY_F11;
			case 134:	return KEY_F12;
			case 72:	return KEY_UP;
			case 80:	return KEY_DOWN;
			case 75:	return KEY_LEFT;
			case 77:	return KEY_RIGHT;
		}
	}

	return k;
}
///////////////////////////////////////////////////////////////////////////////
