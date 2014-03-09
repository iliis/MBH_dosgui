#ifndef __WIDGET_H_INCLUDED__
#define __WIDGET_H_INCLUDED__

#include "keyboard.h"

const short COLOR_BG = 0; // black
const short COLOR_BORDER = 8; // grey
const short COLOR_NORMAL = 15; // white

// Basically just an object which can be drawn and which can receive input
class Widget
{
public:
	Widget* focus_next_left;
	Widget* focus_next_right;
	Widget* focus_next_up;
	Widget* focus_next_down;


	Widget() : focus_next_left(NULL), focus_next_right(NULL), focus_next_up(NULL), focus_next_down(NULL) {};
	virtual ~Widget();
	virtual void draw() = 0;

	// implement functionality here, return if keypress was handled
	virtual bool keyListener(Key k) {k=k; return false;}
};

#endif
