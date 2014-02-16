CC=wcl
CFLAGS=-l=dos -cc++ -i=pdcurses -wx -ml

.PHONY: clean all cleantest

all:	main.c
	$(CC) $(CFLAGS) pdcurses/pdcurses.lib main.c

test:	test.c
	$(CC) $(CFLAGS) test.c

clean:	cleantest
	-@rm -f main.o main.exe

cleantest:
	-@rm -f test.o test.exe
