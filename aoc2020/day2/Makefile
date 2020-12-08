CC=g++
LINKERFLAG=-lm

MAIN := day2.cpp

main: $(MAIN)
	@echo "Make excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	@echo "Remove files..."
	rm -f main
	@echo "Done"
