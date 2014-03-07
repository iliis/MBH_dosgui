#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdarg.h>

// notes on compiling pcurses with watcom on linux
// owsetenv.sh:
/*
 
#!/bin/sh
echo Open Watcom Build Environment
export WATCOM=/home/samuel/programme/watcom
export PATH=/home/samuel/programme/watcom/binl:$PATH
# h and NOT lh !
export INCLUDE=/home/samuel/programme/watcom/h:$INCLUDE
export EDPATH=/home/samuel/programme/watcom/eddat
export WIPFC=/home/samuel/programme/watcom/wipfc
export LIB=/home/samuel/programme/watcom/lib286/dos:$LIB

*/
// makefile: replace / with - in parameters, replace copy/del with cp/rm


// OpenWatcom graphics library
#include <graph.h>

#include "gui/gui_manager.h"
#include "gui/menu.h"

///////////////////////////////////////////////////////////////////////////////
FILE* err_logfile = NULL;
///////////////////////////////////////////////////////////////////////////////
void debug_printf(const char * format, ...) {
	char buf[200];
	va_list args;

	va_start(args, format);
	vsnprintf(buf, sizeof(buf), format, args);
	va_end(args);

	// print to screen
	_outtext(buf);

	// print into logfile
	if (err_logfile) {
		fprintf(err_logfile, buf);
	}
}
///////////////////////////////////////////////////////////////////////////////
void open_logfile() {
	err_logfile = fopen("logfile.err", "w");
}
///////////////////////////////////////////////////////////////////////////////
void close_logfile() {
	if (err_logfile) {
		if (fclose(err_logfile) != 0) {
			debug_printf("ERROR: couldn't close logfile.\n");
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void draw_color_table() {
	_clearscreen(_GCLEARSCREEN);

	for (unsigned int c = 0; c < 256; ++c) {
		_setcolor(c);
		int x = (c % 16) * 10;
		int y = (c >> 4) * 10;
		_rectangle(_GFILLINTERIOR, x, y, x+10, y+10);
	}
}
///////////////////////////////////////////////////////////////////////////////
int main() {
	open_logfile();

	try {
		GuiManager& gui = GuiManager::getInstance();
		gui.init();

		Menu* m = new Menu();
		m->addEntry("hallo");
		m->addEntry("welt");
		m->addEntry("asdfasdfasdf asdfasdf");

		gui.getScreen().addWidget(m);
		gui.setFocusTo(m->getEntries().front());

		debug_printf("starting gui\n");
		gui.run();

		debug_printf("done\n");
		close_logfile();
		return EXIT_SUCCESS;
	} catch (Error &e) {
		// non-critical error during init -> quit anyway
		_setvideomode(_DEFAULTMODE);
		debug_printf("ERROR:\n");
		debug_printf(e.what());
		debug_printf("\naborting ...\n");
	}
	catch (CriticalError& e) {
		_setvideomode(_DEFAULTMODE);
		debug_printf("CRITICAL ERROR:\n");
		debug_printf(e.what());
		debug_printf("\naborting ...\n");
	}
	catch (std::runtime_error& e) {
		_setvideomode(_DEFAULTMODE);
		debug_printf("CRITICAL ERROR:\nUnhandled runtime exception:\n");
		debug_printf(e.what());
		debug_printf("\naborting ...\n");
	}
	catch (...) {
		_setvideomode(_DEFAULTMODE);
		debug_printf("CRITICAL ERROR:\nUnknown exception.\naborting ...\n");
	}

	debug_printf("press enter to quit\n");
	getchar();

	close_logfile();
	return EXIT_FAILURE;
}
///////////////////////////////////////////////////////////////////////////////
