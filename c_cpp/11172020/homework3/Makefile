CC=g++
LINKERFLAG=-lm

STACK := stack.cpp
STACK += DictinStack.cpp

QUEUE := queue.cpp
QUEUE += DictinQueue.cpp

stackmake: $(STACK)
	@echo "Making stack implement dictionary..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

queuemake: $(QUEUE)
	@echo "Making stack implement dictionary..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

clean:
	rm -f stackmake queuemake
	@echo "Done"
