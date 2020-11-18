CC=g++
LINKERFLAG=-lm

OBJ := main.cpp

main: $(OBJ)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

clean:
	rm -f main
	@echo "Done"
