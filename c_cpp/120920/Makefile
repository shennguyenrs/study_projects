CC=g++
LINKERFLAG=-lm

DEFAULT := default.cpp

FORK := fork.cpp

THREAD := thread.cpp

default: $(DEFAULT)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

fork: $(FORK)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

thread: $(THREAD)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f default fork thread
	@echo "Done"