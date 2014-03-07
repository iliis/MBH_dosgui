#include "menu.h"


///////////////////////////////////////////////////////////////////////////////
void
Menu::addEntry(string text)
{
	SelectableLabel* label = new SelectableLabel(text);

	label->y = this->y.ref();

	if (entries.empty()) {
		label->focus_next_up   = label;
		label->focus_next_down = label;
		label->x = this->x.ref();
		this->width  = label->width.ref();
		this->height = label->height.ref();
	} else {
		SelectableLabel* first = entries.front();
		SelectableLabel* last  = entries.back();

		first->focus_next_up   = label;
		last->focus_next_down  = label;

		label->focus_next_up   = last;
		label->focus_next_down = first;

		//this->height = this->height.ref() + label->height.ref();
		//this->width  = Expression<float>::ExpressionRefPtr(new Expression<float>::ExprMaxRef(width.ref(), label->width.ref()));
		//this->width = MAX(this->width.ref(), label->width.ref());
	}

	entries.push_back(label);
}
///////////////////////////////////////////////////////////////////////////////
void
Menu::draw()
{
	_rectangle(_GBORDER, x, y, x+width, y+height);

	for(list<SelectableLabel*>::iterator it = entries.begin();
		it != entries.end();
		it++) {
		(*it)->draw();
	}
}
///////////////////////////////////////////////////////////////////////////////
Menu::~Menu()
{
	for(list<SelectableLabel*>::iterator it = entries.begin();
		it != entries.end();
		it++) {
		delete *it;
	}
}
///////////////////////////////////////////////////////////////////////////////
