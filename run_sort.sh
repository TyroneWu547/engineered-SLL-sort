#!/bin/bash

function error_exit() {
    echo "error: $1"
    echo 
    echo "usage:   ./run_sort.sh [insertion|merge|quick|engineered] < [file_path]"
    echo
    echo "Performs a benchmark using the specified sorting algorithm on an input from STDIN"
    echo 
    echo "arguments:"
    echo "  [insertion|merge|quick|engineered]       Sorting algorithm to use"
    echo "    - insertion                            Insertion sort"
    echo "    - merge                                Merge sort"
    echo "    - quick                                Quicksort"
    echo "    - engineered                           Engineered sort"
    echo "  file_path                     File that contains the contents to sort"
    echo 
    echo "example: ./run_sort.sh merge < ./data/input_01.txt"
    exit 1
}

# Error checking
if [ -z "$1" ]
then
    error_exit "First arg is empty."
elif [ "$1" != "insertion" ] && [ "$1" != "merge" ] && [ "$1" != "quick" ] && [ "$1" != "engineered" ]
then
    error_exit "Invalid first arg: $1"
elif [ ! -e "./bin/$1" ]
then
    # error_exit "executable file ./bin/$1 does not exist."
    echo "Generating the executable file: $1"
    make "$1"
fi

# Executing sorting algorithm
if [ "$1" == "engineered" ]
then
    ./bin/"$1" 10
else
    ./bin/"$1"
fi
