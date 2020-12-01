CC=gcc
CP=g++

LINKERFLAG=-lm
PTHREAD=-l pthread

TEST := test.c

TEST2:= test2.c

TEST3:= test3.c

TEST4:= test4.cpp

TEST5:= test5.cpp

TEST6:= test6.cpp

TEST7:= test7.cpp

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

test4: $(TEST4)
	@echo "Making excutable file..."
	$(CP) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

test5: $(TEST5)
	@echo "Making excutable file..."
	$(CP) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

test6: $(TEST6)
	@echo "Making excutable file..."
	$(CP) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

test7: $(TEST7)
	@echo "Making excutable file..."
	$(CP) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

clean:
	rm -f test test2 test3 test4 test5
	@echo "Done"
