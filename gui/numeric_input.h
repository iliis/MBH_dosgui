#ifndef __NUMERIC_INPUT_H_INCLUDED__
#define __NUMERIC_INPUT_H_INCLUDED__

#include "gui/label.h"
#include "gui/gui_manager.h"
#include "tools/stringhelpers.h"

///////////////////////////////////////////////////////////////////////////////
class NumericInput : public Label
{
	int cursor_pos, digits;
public:
	Expression<int> value;

	NumericInput(int digits)
		: Label(string(digits, '0')), cursor_pos(0), digits(digits) {assert(digits>0);};

	void draw();

	void incrementCursor();
	void decrementCursor();

	bool keyListener(Key k);
};
///////////////////////////////////////////////////////////////////////////////

#endif
