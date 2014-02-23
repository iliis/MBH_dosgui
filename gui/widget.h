#ifndef __WIDGET_H_INCLUDED__
#define __WIDGET_H_INCLUDED__

const short COLOR_BG = 0; // black
const short COLOR_BORDER = 44; // yellow

// Basically just an object which can be drawn
class Widget
{
public:
	virtual void draw() = 0;
};

#endif
