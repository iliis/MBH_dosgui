#include "message_box.h"

///////////////////////////////////////////////////////////////////////////////
MessageBox::MessageBox(Window* parent, string text)
{
	assert(parent);
	this->message = text;
	this->setParent(parent);
	this->centerInsideParent();
	this->width  = GuiManager::get_text_width(text) + 4;
	this->height = GuiManager::get_text_height(text) + 4;
}
///////////////////////////////////////////////////////////////////////////////
void
MessageBox::_draw()
{
	GuiManager::print(2, 2, this->message.c_str());
}
///////////////////////////////////////////////////////////////////////////////
