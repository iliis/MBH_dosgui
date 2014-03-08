#include "selectable_label.h"

///////////////////////////////////////////////////////////////////////////////
void
SelectableLabel::draw()
{
	if (GuiManager::getInstance().getFocus() == this) {
		_rectangle(_GBORDER, x, y, x+width, y+height);
	} 

	Label::draw();
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
