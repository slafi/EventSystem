## A Makefile to build the EventSystem project
## By Sabeur Lafi, Jan. 2020
## Github repository at: https://github.com/slafi/EventSystem
##
## Header and source files in EventSystem/src
## Output: EventSystem/build/main
##

PROG = main
CC = g++
FLAGS = -g -Wall

SOURCEDIR = EventSystem/src
BUILDDIR = EventSystem/build

OBJS = main.o event.o event_handler.o event_args.o utils.o
_OBJS :=$(patsubst %.o,$(BUILDDIR)/%.o, $(OBJS))

all: dir $(PROG)

dir:
	mkdir -p $(BUILDDIR)

$(PROG): $(OBJS)
	$(CC) -o $(BUILDDIR)/$(PROG) $(_OBJS)
	chmod +x $(BUILDDIR)/$(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c EventSystem/main.cpp -o $(BUILDDIR)/main.o

event.o:
	$(CC) $(CPPFLAGS) -c $(SOURCEDIR)/event.cpp -o $(BUILDDIR)/event.o

event_handler.o:
	$(CC) $(CPPFLAGS) -c $(SOURCEDIR)/event_handler.cpp -o $(BUILDDIR)/event_handler.o

event_args.o:
	$(CC) $(CPPFLAGS) -c $(SOURCEDIR)/event_args.cpp -o $(BUILDDIR)/event_args.o

utils.o:
	$(CC) $(CPPFLAGS) -c $(SOURCEDIR)/utils.cpp -o $(BUILDDIR)/utils.o

clean:
	rm -f -v $(BUILDDIR)/*.o $(BUILDDIR)/$(PROG)
	rmdir $(BUILDDIR)