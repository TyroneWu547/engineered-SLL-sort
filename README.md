# 🧰 Engineered Singly Linked List Sort 

Project for NCSU CSC 505: Design and Analysis Of Algorithms  
Modeled after the [Engineered quicksort](https://www.sciencedirect.com/science/article/pii/0096055196000057) paper. 

---

## Environment Setup 💻 

1. Ensure you have installed: 
    - [VSCode](https://go.microsoft.com/fwlink/?linkid=830387)
    - [Docker](https://www.docker.com/) (and enabled) 

2. Install the VSCode extension [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers). 

3. Open VSCode inside the repo and select the green icon in the bottom-left corner. 

    <img src="./.assets/open_remote_window.png" width="230">

4. Select `Reopen in Container` to download and/or open the development container in VSCode. 

    <img src="./.assets/remote_window.png" width="550">

---

## Usage 🛠️ 

### Compiling the program

```sh
# example: make merge
$ make [insertion|merge|quick]

# output:
# clang++ -std=c++20 -c src/main.cpp -o ./build/main.o
# clang++ -std=c++20 -c lib/LinkedList.cpp -o ./build/LinkedList.o
# clang++ -std=c++20 -c lib/Time.cpp -o ./build/Time.o
# clang++ -std=c++20 -c src/merge.cpp -o ./build/merge.o
# clang++ -std=c++20 ./build/main.o ./build/LinkedList.o ./build/Time.o ./build/merge.o -o ./bin/merge
```

### Running the script

Before execution: 
```sh
# May need to convert Windows line ending to Unix
$ sed -i -e 's/\r$//' run_sort.sh

# Make the script executable
$ chmod +x run_sort.sh
```

Script execution: 
```sh
# Execute script
# example: `./run_sort.sh merge < ./data/input_01.txt`
$ ./run_sort.sh [insertion|merge|quick] < [file_path]

# full output:
# 1
# 2
# ...
# 100
# runtime     SECONDS
# comparisons NUMBER_OF_COMPARISONS
```

For filtered output: 
```sh
# Sorted input is printed onto standard output
$ ./run_sort.sh merge < ./data/input_01.txt 2> /dev/null
# output:
# 1
# 2
# ...
# 100

# Benchmark is printed onto standard error
$ ./run_sort.sh merge < ./data/input_01.txt 1> /dev/null
# output:
# runtime     SECONDS
# comparisons NUMBER_OF_COMPARISONS
```

### Run test cases

```sh
# example: make test-insertion
$ make [test-insertion|test-merge|test-quick]

# output:
# ...
# Running insertion sort with b = 100:
# runtime     1.5e-05
# comparisons TODO
# Test case b = 100 passed. :)

# Running insertion sort with b = 10000:
# runtime     0.231602
# comparisons TODO
# Test case b = 10000 passed. :)
```

### Generate input data

Generate unsorted input data on 5 fixed seeds for each input of size n: 
```sh
$ make generate-input

# output:
# ./scripts/generate_data.sh
# generating ./data/n-100/input_s-1.txt
# ...
# generating ./data/n-100000/input_s-611.txt
```
