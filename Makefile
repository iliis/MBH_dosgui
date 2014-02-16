CC=wpp
CFLAGS=-wx -ml -q
LDFLAGS=-l=dos -wx -ml -q
HEADERS=gui/window.h gui/widget.h heater/temperature_sensor.h heater/temperature_controller.h heater/printer.h
SOURCES=$(HEADERS:.h=.cpp) main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

.PHONY: clean cleantest

all:	main.exe

main.exe:	$(OBJECTS)
	wcl $(LDFLAGS) $(OBJECTS) -fe=main.exe

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -fo=$@

test:	test.c
	$(CC) $(CFLAGS) test.c

clean:	cleantest
	rm -f main.o main.exe
	rm -f *.o
	# @echo headers: $(HEADERS)
	# @echo sources: $(SOURCES)
	# @echo objects: $(OBJECTS)
	rm -f $(OBJECTS)

cleantest:
	-@rm -f test.o test.exe
