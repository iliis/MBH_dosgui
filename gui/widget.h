#ifndef __WIDGET_H_INCLUDED__
#define __WIDGET_H_INCLUDED__

const short COLOR_BG = 0; // black
const short COLOR_BORDER = 8; // grey
const short COLOR_NORMAL = 15; // white

// Basically just an object which can be drawn
class Widget
{
public:
	virtual ~Widget() {};
	virtual void draw() = 0;
};

#endif
