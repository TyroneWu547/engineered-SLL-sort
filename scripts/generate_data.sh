#!/bin/bash

GEN_CMD=python3\ ./lib/random_permutation.py
DATA_DIR=./data
SEEDS=( 1 22 57 101 611 )

# Generate sample input
for (( size = 100; size <= 100000; size *= 10 ))
do
    mkdir -p $DATA_DIR/n-$size/
    for seed in "${SEEDS[@]}"
    do
        if [ ! -e "$DATA_DIR/n-$size/input_s-$seed.txt" ]
        then
            echo "generating $DATA_DIR/n-$size/input_s-$seed.txt"
            $GEN_CMD -s "$seed" $size > $DATA_DIR/n-$size/input_s-"$seed".txt
        fi
    done
done
