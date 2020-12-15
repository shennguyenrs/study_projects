CC=g++
LINKERFLAG=-lm

BFS := bfs.cpp
BFS += BfsDict/BfsDict.cpp
BFS += BfsDict/Node.cpp

DFS := dfs.cpp
DFS += DfsDict/DfsDict.cpp
DFS += DfsDict/Node.cpp

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
