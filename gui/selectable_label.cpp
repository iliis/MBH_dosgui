#include "selectable_label.h"

///////////////////////////////////////////////////////////////////////////////
void
SelectableLabel::draw()
{
	if (GuiManager::getInstance().getFocus() == this) {
		//_rectangle(_GBORDER, x, y, x+width, y+height);
		_setcolor(4);
	} else
		_setcolor(COLOR_NORMAL);

	Label::draw();
	_setcolor(COLOR_NORMAL);
}
///////////////////////////////////////////////////////////////////////////////
bool
SelectableLabel::keyListener(Key k)
{
	if (k == Keyboard::KEY_ENTER) {
		GuiManager::getInstance().showPopup("selected Entry: "+this->text);
		return true;
	}

	return false;
}
///////////////////////////////////////////////////////////////////////////////
