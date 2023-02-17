CPP=g++
CPPFLAGS=-std=gnu++20

BIN_DIR=./bin
BUILD_DIR=./build
SRC_DIR=./src

# Link
$(BIN_DIR)/%:  $(BUILD_DIR)/main.o $(BUILD_DIR)/%.o
	$(CPP) $(CPPFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/%.o -o $(BIN_DIR)/%

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c $(SRC_DIR)/%.cpp

# Clean build
clean:
	rm $(BIN_DIR)/* $(BUILD_DIR)/*


# # Insertion Sort
# $(BIN_DIR)/insertion: $(BUILD_DIR)/insertion.o
# 	$(CPP) $(CPPFLAGS) $(BUILD_DIR)/insertion.o -o $(BIN_DIR)/insertion

# $(BUILD_DIR)/insertion.o: $(SRC_DIR)/insertion.cpp
# 	$(CPP) $(CPPFLAGS) -c $(SRC_DIR)/insertion.cpp

# # Merge Sort
# $(BIN_DIR)/merge: $(BUILD_DIR)/merge.o
# 	$(CPP) $(CPPFLAGS) $(BUILD_DIR)/merge.o -o $(BIN_DIR)/merge

# $(BUILD_DIR)/merge.o: $(SRC_DIR)/merge.cpp
# 	$(CPP) $(CPPFLAGS) -c $(SRC_DIR)/merge.cpp

# # Quicksort
# $(BIN_DIR)/quick: $(BUILD_DIR)/quick.o
# 	$(CPP) $(CPPFLAGS) $(BUILD_DIR)/quick.o -o $(BIN_DIR)/quick

# $(BUILD_DIR)/quick.o: $(SRC_DIR)/quick.cpp
# 	$(CPP) $(CPPFLAGS) -c $(SRC_DIR)/quick.cpp