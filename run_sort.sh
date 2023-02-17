#!/bin/bash

function error_exit() {
    echo "error - $1"
    echo 
    echo "usage:   ./run_sort.sh [insertion|merge|quick] < [file_path]"
    echo
    echo "Performs a benchmark using the specified sorting algorithm on an input from STDIN"
    echo 
    echo "arguments:"
    echo "  [insertion|merge|quick]       Sorting algorithm to use"
    echo "    - insertion                     Insertion sort"
    echo "    - merge                         Merge sort"
    echo "    - quick                         Quicksort"
    echo "  file_path                     File that contains the contents to sort"
    echo 
    echo "example: ./run_sort.sh merge < ./data/input_01.txt"
    exit 1
}

# Error checking

# 1st arg
if [ -z "$1" ]
then
    error_exit "First arg is empty."
elif [ "$1" != "insertion" ] && [ "$1" != "merge" ] && [ "$1" != "quick" ]
then
    error_exit "Invalid first arg: $1"
elif [ ! -e "$1" ]
then
    error_exit "Executable file does not exist: ./bin/$1"
fi

# Build 
echo "success $1"

# ./bin/$1 < ./data/$2