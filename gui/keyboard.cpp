#include "keyboard.h"

///////////////////////////////////////////////////////////////////////////////
const Key Keyboard::KEY_ENTER ("ENTER",		 13);
const Key Keyboard::KEY_ESCAPE("ESCAPE",	 27);
const Key Keyboard::KEY_F1    ("F1",		300);
const Key Keyboard::KEY_F2    ("F2",		301);
const Key Keyboard::KEY_F3    ("F3",		302);
const Key Keyboard::KEY_F4    ("F4",		303);
const Key Keyboard::KEY_F5    ("F5",		304);
const Key Keyboard::KEY_F6    ("F6",		305);
const Key Keyboard::KEY_F7    ("F7",		306);
const Key Keyboard::KEY_F8    ("F8",		307);
const Key Keyboard::KEY_F9    ("F9",		308);
const Key Keyboard::KEY_F10   ("F10",		309);
const Key Keyboard::KEY_F11   ("F11",		310);
const Key Keyboard::KEY_F12   ("F12",		311);
const Key Keyboard::KEY_UP    ("UP",		312);
const Key Keyboard::KEY_DOWN  ("DOWN",		313);
const Key Keyboard::KEY_LEFT  ("LEFT",		314);
const Key Keyboard::KEY_RIGHT ("RIGHT",		315);
///////////////////////////////////////////////////////////////////////////////
const Key Keyboard::get_key()
{
	// TODO: set shift flag
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

	return Key(std::string(1, (char) k), k);
}
///////////////////////////////////////////////////////////////////////////////
