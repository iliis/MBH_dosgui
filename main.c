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

int main() {
	_setvideomode(_VRES16COLOR);
	_rectangle(_GFILLINTERIOR, 100, 100, 540, 380);

	cin.ignore();

	_setviewport(200,200,440,280);
	_clearscreen(_GVIEWPORT);

	cin.ignore();

	_setvideomode(_DEFAULTMODE);

	return EXIT_SUCCESS;
}
