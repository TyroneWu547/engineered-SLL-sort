CPP=clang++
CPPFLAGS=-std=c++20

BIN_DIR=./bin
BLD_DIR=./build
SRC_DIR=./src
INC_DIR=./include
LIB_DIR=./lib

DEP=main.o LinkedList.o
DEP_ACT=$(BLD_DIR)/main.o $(BLD_DIR)/LinkedList.o
CMD=$(CPP) $(CPPFLAGS)

# Build sort executable
insertion: $(DEP) insertion.o
	$(CMD) $(DEP_ACT) $(BLD_DIR)/insertion.o -o $(BIN_DIR)/insertion

merge: $(DEP) merge.o
	$(CMD) $(DEP_ACT) $(BLD_DIR)/merge.o -o $(BIN_DIR)/merge

quick: $(DEP) quick.o
	$(CMD) $(DEP_ACT) $(BLD_DIR)/quick.o -o $(BIN_DIR)/quick

# Compile main
main.o: $(SRC_DIR)/main.cpp
	$(CMD) -c $< -o $(BLD_DIR)/$@

# Compile Linked List data structure
LinkedList.o: $(LIB_DIR)/LinkedList.cpp
	$(CMD) -c $< -o $(BLD_DIR)/$@

# Compile sort
%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/Sort.h
	$(CMD) -c $< -o $(BLD_DIR)/$@

# Clean build
clean:
	rm $(BIN_DIR)/* $(BLD_DIR)/*