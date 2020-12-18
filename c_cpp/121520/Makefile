CC=g++
LINKERFLAG=-lm
PTHREAD=-pthread

FORK := fork.cpp

THREAD := thread.cpp

fork: $(FORK)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

thread: $(THREAD)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG) $(PTHREAD)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f fork thread
	@echo "Done"
