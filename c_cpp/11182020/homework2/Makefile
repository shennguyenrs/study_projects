CC=gcc
LINKERFLAG=-lm
PTHREAD=-l pthread

TEST := test.c

TEST2:= test2.c

TEST3:= test3.c

test: $(TEST)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

test2: $(TEST2)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG) $(PTHREAD)
	@echo "Done"

test3: $(TEST3)
	@echo "Making excutable file..."
	$(CC) -o $@ $^ $(LINKERFLAG) $(PTHREAD)
	@echo "Done"

clean:
	rm -f test test2
	@echo "Done"
