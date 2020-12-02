CC=g++

LINKERFLAG=-lm
PTHREAD=-l pthread

MAIN := main.cpp
MAIN += CatWc.cpp

catwc: $(MAIN)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG) $(PTHREAD)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f catwc
	@echo "Done"
