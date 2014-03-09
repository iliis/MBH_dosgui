#include "numeric_input.h"

///////////////////////////////////////////////////////////////////////////////
void
NumericInput::draw()
{
	GuiManager& gui = GuiManager::getInstance();

	if (gui.getFocus() == this)
	{
		assert(cursor_pos >= 0);
		assert(cursor_pos < this->text.length());

		string first = this->text.substr(0, cursor_pos);
		string curs  = this->text.substr(cursor_pos, 1);
		string last  = this->text.substr(cursor_pos+1);

		//debug_printf("first = '%s'\n", first.c_str());
		//debug_printf("curs  = '%s'\n", curs.c_str());
		//debug_printf("last  = '%s'\n", last.c_str());

		// draw first part
		_setcolor(COLOR_NORMAL);
		GuiManager::print_line(this->x, this->y, first);
		float xpos = GuiManager::get_text_width(first);

		// draw highlighted char
		_setcolor(4);
		GuiManager::print_line(this->x+xpos, this->y, curs);
		xpos += GuiManager::get_text_width(curs);

		// draw last part
		_setcolor(COLOR_NORMAL);
		GuiManager::print_line(this->x+xpos, this->y, last);
	}
	else
	{
		cursor_pos = 0;
		Label::draw();
	}
}
///////////////////////////////////////////////////////////////////////////////
void
NumericInput::incrementCursor()
{
	if (cursor_pos == digits-1)
		cursor_pos = 0;
	else
		cursor_pos++;
}
///////////////////////////////////////////////////////////////////////////////
void
NumericInput::decrementCursor()
{
	if (cursor_pos == 0)
		cursor_pos = digits-1;
	else
		cursor_pos--;
}
///////////////////////////////////////////////////////////////////////////////
bool
NumericInput::keyListener(Key k)
{
	if (k == Keyboard::KEY_LEFT) {
		this->decrementCursor();
		return true;
	}

	if (k == Keyboard::KEY_RIGHT) {
		this->incrementCursor();
		return true;
	}

	if (k.keycode >= '0' && k.keycode <= '9') {
		this->text[cursor_pos] = k.keycode;
		this->incrementCursor();
		this->value = ToInt(this->text);
	}

	return false;
}
///////////////////////////////////////////////////////////////////////////////
