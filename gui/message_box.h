#ifndef __MESSAGE_BOX_H_INCLUDED__
#define __MESSAGE_BOX_H_INCLUDED__

#include "window.h"
#include "gui_manager.h"

class MessageBox : public Window {
	string message;
	virtual void _draw();
public:
	MessageBox(Window* parent, string text);
};

#endif
