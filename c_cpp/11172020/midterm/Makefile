CC=g++
LINKERFLAG=-lm

ARR := mainArray.cpp
ARR += ArrayHeader.cpp

LKL := mainLinked.cpp
LKL += LinkedlistHeader.cpp

array: $(ARR)
	@echo "Making excutable file for array database..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

linked: $(LKL)
	@echo "Making excutable file for linkedlist database..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f array linked
	@echo "Done"
