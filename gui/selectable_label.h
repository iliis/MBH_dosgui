#ifndef __SELECTABLE_LABEL_H_INCLUDED__
#define __SELECTABLE_LABEL_H_INCLUDED__

#include "label.h"
#include "tools/debug_printf.h"

///////////////////////////////////////////////////////////////////////////////

class SelectableLabel : public Label
{
public:
	SelectableLabel(std::string text)
		: Label(text) {};
	virtual void draw();
};

///////////////////////////////////////////////////////////////////////////////

#endif
