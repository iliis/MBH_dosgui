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

///////////////////////////////////////////////////////////////////////////////
void gprintf(char * format, ...) {
	char buf[200];
	va_list args;

	va_start(args, format);
	vsnprintf(buf, sizeof(buf), format, args);
	va_end(args);

	_outgtext(buf);
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
	GuiManager gui;
	gui.init();
	gui.run();
	return EXIT_SUCCESS;
}
///////////////////////////////////////////////////////////////////////////////
