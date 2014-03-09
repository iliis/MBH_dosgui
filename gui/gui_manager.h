#ifndef __GUI_MANAGER_H_INCLUDED__
#define __GUI_MANAGER_H_INCLUDED__

#include "tools/errorclass.h"
#include "widget.h"
#include "window.h"
#include "message_box.h"
#include "keyboard.h"
#include "tools/debug_printf.h"

///////////////////////////////////////////////////////////////////////////////
class GuiManager
{
	Widget* focus;
	Window* SCREEN;

	bool is_initialized;
	bool is_running;

public:
	~GuiManager();

	void init();
	void run();
	inline void stop() { this->is_running = false; debug_printf("gui::stop() called\n"); }

	void show_exception(Error& e);
	void showPopup(string message);
	bool showOkCancelDialog(string message, string ok_text = "OK", string cancel_text = "CANCEL");

	static void print_line(float x, float y, std::string t);
	static void print(float x, float y, std::string t);
	static int get_text_width(string t);
	static int get_text_height(string t);

	void keyListener(Key k);

	void addWindow(Window* w);
	void setFocusTo(Widget* w) { this->focus = w; }
	const Widget* getFocus() { return this->focus; }

	Window& getScreen() { assert(SCREEN); return *this->SCREEN; }

	void printVideoConfig();

	///////////////////////////////////////////////////////////////////////////
	// SINGLETON
	static GuiManager& getInstance() {
		static GuiManager instance;
		return instance;
	}

private:
	// somehow, this constructor is called twice, even tough it is private!?
	GuiManager() /* : focus(NULL), SCREEN(NULL), is_initialized(false), is_running(false) */ {};

	GuiManager(const GuiManager&); // no copy-constructor
	void operator=(const GuiManager&); // no assignment
};
///////////////////////////////////////////////////////////////////////////////

#endif
