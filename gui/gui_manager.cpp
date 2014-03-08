#include "gui_manager.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
void
GuiManager::init()
{
	// SVGA (640x480, 256 colors)
	_setvideomode(_VRES256COLOR);
	_registerfonts("fonts/*.fon");

	this->SCREEN = new Window(0, 0, 640, 480);
	this->focus  = SCREEN;

	this->is_initialized = true;
}
///////////////////////////////////////////////////////////////////////////////
GuiManager::~GuiManager()
{
	if (this->is_initialized) {

		delete this->SCREEN;
		this->focus = NULL;

		_unregisterfonts();
		_setvideomode(_DEFAULTMODE);
	}
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::run()
{
	if (this->is_initialized) {
		this->is_running = true;

		while (this->is_running) {
			try {
				this->SCREEN->draw();
				this->keyListener(Keyboard::get_key());
			}
			catch (Error& e) {
				// non-critical error, just show message and continue program
				this->show_exception(e);

				// exceptions seem to be buggy in Watcom, stop anyway
				this->stop();
			}
			catch (CriticalError& e) {
				_setvideomode(_DEFAULTMODE);
				printf("CRITICAL ERROR:\n");
				printf(e.what());
				printf("\naborting ...\n");
				this->stop();
			}
			catch (std::runtime_error& e) {
				_setvideomode(_DEFAULTMODE);
				printf("CRITICAL ERROR:\nUnhandled runtime exception:\n");
				printf(e.what());
				printf("\naborting ...\n");
				this->stop();
			}
			catch (...) {
				_setvideomode(_DEFAULTMODE);
				printf("CRITICAL ERROR:\nUnknown exception.\naborting ...\n");
				this->stop();
			}
		} // end while

		this->is_running = false;
	}
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::keyListener(Key k)
{
	if (focus) {
		if (focus->keyListener(k))
			return; // Widget handled input
	}

	// handle key ourselfs
	if (k == Keyboard::KEY_LEFT  && focus->focus_next_left)  focus = focus->focus_next_left;
	if (k == Keyboard::KEY_RIGHT && focus->focus_next_right) focus = focus->focus_next_right;
	if (k == Keyboard::KEY_UP    && focus->focus_next_up)    focus = focus->focus_next_up;
	if (k == Keyboard::KEY_DOWN  && focus->focus_next_down)  focus = focus->focus_next_down;

	// if key == ESC: show quit dialog or something
	if (k == Keyboard::KEY_ESCAPE || k.keycode == 'q')
		this->stop();
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::addWindow(Window* w)
{
	SCREEN->addWindow(w);
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::show_exception(Error& e)
{
	MessageBox err_box(SCREEN, string(e.what()) + "\n\nPress any key to continue or press F1 to quit.");
	err_box.draw();
	Key k = Keyboard::get_key();

	if (k == Keyboard::KEY_F1)
		this->stop();
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::showPopup(string message)
{
	MessageBox msg(SCREEN, message);
	//msg.draw();

	//Keyboard::get_key();
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::print_line(float x, float y, string t)
{
	// basically just to cast a away a 'const' for _outgtext
	_moveto(x,y);
	// char buf[500];
	// strncpy(buf, t.c_str(), sizeof(buf));
	_outgtext((char*)t.c_str());
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::print(float x, float y, string t)
{
	list<string> lines = stringToLines(t);
	float h = GuiManager::get_text_height(""); // height is constant

	for (list<string>::iterator l_iter = lines.begin(); l_iter != lines.end(); ++l_iter) {
		print_line(x, y, *l_iter);
		y += h;
	}
}
///////////////////////////////////////////////////////////////////////////////
static int
GuiManager::get_text_width(string t)
{
	list<string> lines = stringToLines(t);

	int width = 0;
	for (list<string>::iterator l_iter = lines.begin(); l_iter != lines.end(); ++l_iter) {
		int w = _getgtextextent((char*) l_iter->c_str());
		if (w > width)
			width = w;
	}
	return width;
}
///////////////////////////////////////////////////////////////////////////////
static int
GuiManager::get_text_height(string t)
{
	struct _fontinfo info;
	assert(_getfontinfo(&info) == 0);
	return stringToLines(t).size() * info.pixheight;
}
///////////////////////////////////////////////////////////////////////////////
