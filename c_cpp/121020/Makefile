CC=g++
LINKERFLAG=-lm

BFS := bsf.cpp
BFS += BfsDict/BfsDict.cpp

bfs: $(BFS)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

dfs: $(DFS)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

tag:
	@echo "Making tags file..."
	ctags --recurse=yes -h .cpp.hpp.c.h
	@echo "Done"

clean:
	rm -f bfs dfs
	@echo "Done"
