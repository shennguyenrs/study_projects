CC=g++
LINKERFLAG=-lm

STACK := stack.cpp
STACK += StackHeader/StackDict.cpp

QUEUE := queue.cpp
QUEUE += QueueHeader/QueueDict.cpp

stack: $(STACK)
	@echo "Making stack implement dictionary..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

queue: $(QUEUE)
	@echo "Making queue implement dictionary..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f stackmake queuemake
	@echo "Done"
