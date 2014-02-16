#ifndef __WINDOW_H_INCLUDED__
#define __WINDOW_H_INCLUDED__

#include <graph.h>
#include <list>

#include "widget.h"

class Window : public Widget {
	float rel_x, rel_y;
	float width, height;

	Window* parent;
	std::list<Widget*> children;
public:
	Window()
	   : rel_x(0), rel_y(0), width(0), height(0), parent(NULL) {};
	Window(float x, float y)
	   : rel_x(x), rel_y(y), parent(NULL) {};
	Window(float x, float y, float w, float h)
	   : rel_x(x), rel_y(y), width(w), height(h) {};

	float getAbsX() { if (parent) return parent->getAbsX() + rel_x; else return rel_x; }
	float getAbsY() { if (parent) return parent->getAbsY() + rel_y; else return rel_y; }

	void draw();
};

#endif
