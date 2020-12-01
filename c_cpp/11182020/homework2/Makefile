CC=g++

LINKERFLAG=-lm
PTHREAD=-l pthread

MAIN := main.cpp
MAIN += CatWc.cpp

catwc: $(MAIN)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f test test2 test3 test4 test5
	@echo "Done"
