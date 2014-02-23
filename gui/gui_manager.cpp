#include "gui_manager.h"

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

		_unregisterfonts();
		_setvideomode(_DEFAULTMODE);
	}
}
///////////////////////////////////////////////////////////////////////////////
void
GuiManager::run()
{
	if (this->is_initialized) {
		try {
			this->SCREEN->draw();
		} catch (...) {
			// TODO: show pop-up or something and quit
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
