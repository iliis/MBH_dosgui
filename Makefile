CC=wcl
CFLAGS=-l=dos -cc++

.PHONY: clean all cleantest

all:	main.c
	$(CC) $(CFLAGS) main.c

test:	test.c
	$(CC) $(CFLAGS) test.c

clean:	cleantest

cleantest:
	-@rm -f test.o test.exe
