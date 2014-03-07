
CC=wpp
CFLAGS=-wx -ml -q -i=. -xs
# -k8K : stack size of 8KB
LDFLAGS=-l=dos -wx -ml -q -k8K
HEADERS= \
		 gui/window.h \
		 gui/label.h \
		 gui/selectable_label.h \
		 gui/menu.h \
		 gui/message_box.h \
		 gui/widget.h \
		 gui/gui_manager.h \
		 gui/keyboard.h \
		 heater/temperature_sensor.h \
		 heater/temperature_controller.h \
		 heater/printer.h \
		 tools/errorclass.h \
		 tools/stringhelpers.h

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
