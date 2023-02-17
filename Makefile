CPP=clang++
CPPFLAGS=-std=c++20

BIN_DIR=./bin
BLD_DIR=./build
SRC_DIR=./src
INC_DIR=./include

CMD=$(CPP) $(CPPFLAGS)

# Build sort executable
insertion: main.o insertion.o
	$(CMD) $(BLD_DIR)/main.o $(BLD_DIR)/insertion.o -o $(BIN_DIR)/insertion

merge: main.o merge.o
	$(CMD) $(BLD_DIR)/main.o $(BLD_DIR)/merge.o -o $(BIN_DIR)/merge

quick: main.o quick.o
	$(CMD) $(BLD_DIR)/main.o $(BLD_DIR)/quick.o -o $(BIN_DIR)/quick

# Compile main
main.o: $(SRC_DIR)/main.cpp
	$(CMD) -c $< -o $(BLD_DIR)/$@

# Compile sort
%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/Sort.h
	$(CMD) -c $< -o $(BLD_DIR)/$@

# Clean build
clean:
	rm $(BIN_DIR)/* $(BLD_DIR)/*