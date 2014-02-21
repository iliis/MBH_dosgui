
CC=wpp
CFLAGS=-wx -ml -q -i=.
LDFLAGS=-l=dos -wx -ml -q
HEADERS=gui/window.h gui/widget.h heater/temperature_sensor.h heater/temperature_controller.h heater/printer.h tools/errorclass.h
SOURCES=$(HEADERS:.h=.cpp) main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

# check if specified files exist (e.g. warn on typo)
# not sure if this actually works
ifeq (,$(wildcard $(HEADERS)))
	$(error some file does not exist!)
endif

.PHONY: clean cleantest

all:	main

main:	$(OBJECTS)
	wcl $(LDFLAGS) $(OBJECTS) -fe=main.exe

%.o: %.cpp $(HEADERS)
	@echo "foobar"
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
