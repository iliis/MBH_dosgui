#ifndef __KEYBOARD_H_INCLUDED__
#define __KEYBOARD_H_INCLUDED__

#include <conio.h>
#include <string>

class Key {
public:
	std::string name;
	int keycode;
	bool shift;

	Key(std::string name, int keycode)
		: name(name), keycode(keycode), shift(false) {};

	Key(std::string name, int keycode, bool shift)
		: name(name), keycode(keycode), shift(shift) {};

	// copy/assignment as we can't initalize a const array of Keys otherwise

	Key(const Key& k)
		: name(k.name), keycode(k.keycode), shift(k.shift) {};

	Key& operator=(const Key& k) 
	{
		if (&k != this)
		{
			this->name    = k.name;
			this->keycode = k.keycode;
			this->shift   = k.shift;
		}

		return *this;
	}

	bool operator==(const Key& k)
	{
		return this->keycode == k.keycode;
	}
};

class Keyboard {
public:
	static const Key KEY_ENTER ;
	static const Key KEY_ESCAPE;
	static const Key KEY_F1    ;
	static const Key KEY_F2    ;
	static const Key KEY_F3    ;
	static const Key KEY_F4    ;
	static const Key KEY_F5    ;
	static const Key KEY_F6    ;
	static const Key KEY_F7    ;
	static const Key KEY_F8    ;
	static const Key KEY_F9    ;
	static const Key KEY_F10   ;
	static const Key KEY_F11   ;
	static const Key KEY_F12   ;
	static const Key KEY_UP    ;
	static const Key KEY_DOWN  ;
	static const Key KEY_LEFT  ;
	static const Key KEY_RIGHT ;

	// TODO: SHIFT-F keys

	static const Key get_key();
};


#endif
