CC=g++
LINKERFLAG=-lm

STACK := stack.cpp
STACK += StackDict.cpp

QUEUE := queue.cpp
QUEUE += QueueDict.cpp

stack: $(STACK)
	@echo "Making stack implement dictionary..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

queue: $(QUEUE)
	@echo "Making stack implement dictionary..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f stackmake queuemake
	@echo "Done"
