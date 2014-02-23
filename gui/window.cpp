#include "window.h"

///////////////////////////////////////////////////////////////////////////////
void
Window::draw() {
	float x = this->getAbsX();
	float y = this->getAbsY();

	_setcliprgn(x, y, x+this->width-1, y+this->height-1); // clip away outside of window
	_setvieworg(x, y); // set origin of view coordinates to topleft of window

	// clear window
	_setcolor(COLOR_BG);
	_rectangle(_GFILLINTERIOR, 0, 0, this->width-1, this->height-1);
	// draw border
	_setcolor(COLOR_BORDER);
	_rectangle(_GBORDER,       0, 0, this->width-1, this->height-1);

	_setcolor(COLOR_NORMAL);

	// draw actual content
	this->_draw();

	for (std::list<Widget*>::iterator it = this->children.begin();
		 it != this->children.end();
		 ++it) {
		(*it)->draw();
	}

	// no need to reset/clear clipping/view regions, no drawing outside windows
}
///////////////////////////////////////////////////////////////////////////////
void
Window::setParent(Window* p)
{
	if (this->parent) {
		this->parent->children.remove(this);
		this->parent = NULL;
	}

	this->parent = p;
	p->children.push_back(this);
}
///////////////////////////////////////////////////////////////////////////////
void
Window::centerInsideParent()
{
	if (this->parent) {
		this->rel_x = this->parent->width.ref()  / 2 - this->width.ref()  / 2;
		this->rel_y = this->parent->height.ref() / 2 - this->height.ref() / 2;
	}
}
///////////////////////////////////////////////////////////////////////////////
