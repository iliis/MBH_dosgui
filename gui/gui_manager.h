#ifndef __GUI_MANAGER_H_INCLUDED__
#define __GUI_MANAGER_H_INCLUDED__

#include "tools/errorclass.h"
#include "widget.h"
#include "window.h"

///////////////////////////////////////////////////////////////////////////////
class GuiManager
{
	Widget* focus;
	Window* SCREEN;

	bool is_initialized;
public:
	GuiManager() : focus(NULL), SCREEN(NULL), is_initialized(NULL) {};
	~GuiManager();

	void init();
	void run();
};
///////////////////////////////////////////////////////////////////////////////

#endif
