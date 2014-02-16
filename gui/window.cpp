#include "window.h"

///////////////////////////////////////////////////////////////////////////////
void
Window::draw() {
	float x = this->getAbsX();
	float y = this->getAbsY();

	_setcliprgn(x, y, x+this->width, y+this->height); // clip away outside of window
	_setvieworg(x, y); // set origin of view coordinates to topleft of window

	// clear window
	_setcolor(COLOR_BG);
	_rectangle(_GFILLINTERIOR, 0, 0, this->width, this->height);
	// draw border
	_setcolor(COLOR_BORDER);
	_rectangle(_GBORDER,       1, 1, this->width-1, this->height-1);

	for (std::list<Widget*>::iterator it = this->children.begin();
		 it != this->children.end();
		 ++it) {
		(*it)->draw();
	}

	// no need to reset/clear clipping/view regions, no drawing outside windows
}
///////////////////////////////////////////////////////////////////////////////
