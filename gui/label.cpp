#include "label.h"

///////////////////////////////////////////////////////////////////////////////
void
Label::setText(std::string text)
{
	int_val.unlink();
	float_val.unlink();

	if (text != this->text)
	{
		// calculate new size
		this->width  = GuiManager::get_text_width (text);
		this->height = GuiManager::get_text_height(text);
		this->text   = text;
	}
}
///////////////////////////////////////////////////////////////////////////////
void
Label::setInt(Expression<int>& val)
{
	float_val.unlink();
	int_val = val.ref();
}
///////////////////////////////////////////////////////////////////////////////
void
Label::setFloat(Expression<float>& val)
{
	int_val.unlink();
	float_val = val.ref();
}
///////////////////////////////////////////////////////////////////////////////
void
Label::draw()
{
	if (int_val.isLinked()) {
		this->text = ToString(int_val);
	}
	else if (float_val.isLinked()) {
		this->text = ToString(float_val);
	}

	GuiManager::print(this->x, this->y, this->text.c_str());
}
///////////////////////////////////////////////////////////////////////////////
