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
#include "gui/numeric_input.h"
#include "tools/debug_printf.h"
#include "tools/serial.h"

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

		debug_printf("number of com ports: %d\n", SerialPort::countPorts());
		getchar();

		SerialPort com1(1, 9600, NONE, 8, 1);

		while (1) {
			//com1.printStatus(com1.getStatus());
			debug_printf("-------------\n");
			com1.write(0x42);
			debug_printf(".............\n");
			char d = com1.waitForData();
			if (d != 0)
				debug_printf("read from UART: %X\n", d);
		}

		GuiManager& gui = GuiManager::getInstance();
		gui.init();

		Menu m;
		m.addEntry("hallo");
		m.addEntry("welt");
		m.addEntry("asdfasdfasdf asdfasdf");
		m.addEntry("yet another one");
		m.addEntry("this");
		m.addEntry("or that");
		m.addEntry("or not?");
		m.addEntry("and the last one");

		NumericInput inp(4);
		inp.y = m.y.ref() + m.height.ref();

		gui.getScreen().addWidget(&m);
		gui.getScreen().addWidget(&inp);
		//gui.setFocusTo(m.getEntries().front());
		gui.setFocusTo(&inp);


		Label l("flub");
		l.setInt(inp.value);
		gui.getScreen().addWidget(&l);
		l.x = 200;
		l.y = 20;

		inp.focus_next_up = m.getEntries().back();
		inp.focus_next_down = m.getEntries().front();

		debug_printf("starting gui\n");
		gui.run();

		debug_printf("done, exiting\n");
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
