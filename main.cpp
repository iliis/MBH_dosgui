#include <stdlib.h>
#include <iostream.h>

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

#include "gui/window.h"
#include "tools/expression_noboost.h"

int main() {
	_setvideomode(_VRES256COLOR); // SVGA (640x480, 256 colors)

	char t[] = "hallo welt";

	Expression<int> eint1 = 123, eint2 = 1111, eint3 = 2432;

	eint1 = eint2.ref() + eint3.ref();

	cout << eint1 << endl;
	eint2 = 2222;
	cout << eint1 << endl;

	Window foo(100, 100, 400, 200);
	Window bar(110, 110, 300, 300);

	_setcolor(200);
	_rectangle(_GFILLINTERIOR, 0, 0, 640, 480);

	_outtext(t);

	foo.draw();
	bar.draw();

	cin.ignore();

	_setvideomode(_DEFAULTMODE);
	return EXIT_SUCCESS;
}
