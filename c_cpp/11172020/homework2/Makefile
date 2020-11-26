CC=g++
LINKERFLAG=-lm

MAIN := main.cpp

main: $(MAIN)
	@echo "Making output file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f stackmake queuemake
	@echo "Done"
