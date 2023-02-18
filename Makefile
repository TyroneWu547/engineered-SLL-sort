CPP=clang++
CPPFLAGS=-std=c++20

BIN_DIR=./bin
BLD_DIR=./build
SRC_DIR=./src
INC_DIR=./include
LIB_DIR=./lib
DAT_DIR=./data

DEP=main.o LinkedList.o Time.o
DEP_ACT=$(BLD_DIR)/main.o $(BLD_DIR)/LinkedList.o $(BLD_DIR)/Time.o

COMPILE=$(CPP) $(CPPFLAGS)

SORT_100=< $(DAT_DIR)/n-100/input_b-100_s-1.txt 1> $(DAT_DIR)/n-100/output_b-100_s-1.txt
SORT_10000=< $(DAT_DIR)/n-10000/input_b-10000_s-1.txt 1> $(DAT_DIR)/n-10000/output_b-10000_s-1.txt
TEST_100=diff --strip-trailing-cr $(DAT_DIR)/n-100/expected.txt $(DAT_DIR)/n-100/output_b-100_s-1.txt
TEST_10000=diff --strip-trailing-cr $(DAT_DIR)/n-10000/expected.txt $(DAT_DIR)/n-10000/output_b-10000_s-1.txt

# Build sort executable
insertion: $(DEP) insertion.o
	$(COMPILE) $(DEP_ACT) $(BLD_DIR)/insertion.o -o $(BIN_DIR)/insertion

merge: $(DEP) merge.o
	$(COMPILE) $(DEP_ACT) $(BLD_DIR)/merge.o -o $(BIN_DIR)/merge

quick: $(DEP) quick.o
	$(COMPILE) $(DEP_ACT) $(BLD_DIR)/quick.o -o $(BIN_DIR)/quick

# Compile main
main.o: $(SRC_DIR)/main.cpp
	$(COMPILE) -c $< -o $(BLD_DIR)/$@

# Compile lib
%.o: $(LIB_DIR)/%.cpp $(INC_DIR)/%.h
	$(COMPILE) -c $< -o $(BLD_DIR)/$@

# Compile sort
%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/Sort.h
	$(COMPILE) -c $< -o $(BLD_DIR)/$@

# Test insertion
test-insertion:
	@echo "Running insertion sort with n = 100:"
	./run_sort.sh insertion $(SORT_100)
	$(TEST_100)

	@echo "\nRunning insertion sort with n = 10000:"
	./run_sort.sh insertion $(SORT_10000)
	$(TEST_10000)

# Test merge
test-merge:
	@echo "Running merge sort with n = 100:"
	./run_sort.sh merge $(SORT_100)
	$(TEST_100)

	@echo "\nRunning merge sort with n = 10000:"
	./run_sort.sh merge $(SORT_10000)
	$(TEST_10000)

# Test quick
test-quick:
	@echo "Running quick sort with n = 100:"
	./run_sort.sh quick $(SORT_100)
	$(TEST_100)

	@echo "\nRunning quick sort with n = 10000:"
	./run_sort.sh quick $(SORT_10000)
	$(TEST_10000)

# Clean build
clean:
	rm $(BIN_DIR)/* $(BLD_DIR)/*