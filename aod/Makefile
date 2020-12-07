CC=g++
LINKERFLAG=-lm

ONE := day1.cpp
TWO := day2.cpp
THREE := day3.cpp

one: $(ONE)
	@echo "Make excutable file for day1..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

two: $(TWO)
	@echo "Make excutable file for day2..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

three: $(THREE)
	@echo "Make excutable file for day3..."
	$(CC) -o $@ $^ $(LINKERFLAG)
	@echo "Done"

clean:
	@echo "Remove files..."
	rm -f one two three four five six seven eight nine
	@echo "Done"
