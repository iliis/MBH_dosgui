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




#include <curses.h>

int main() {
	cout << "foobar" << endl;
	cin.ignore();

	initscr();
	printw("Hallo Welt2");
	refresh();

	cin.ignore();
	endwin();

	return EXIT_SUCCESS;
}
