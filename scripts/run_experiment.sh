#!/bin/bash

GEN_CMD=python3\ ./lib/random_permutation.py
DATA_DIR=./data
EXPR_DIR=$DATA_DIR/experiment

BLOCKS=( 20 10 5 2 )
SEEDS=( 1 22 57 101 611 )
SORTS=( insertion merge quick )

function benchmark() {
    echo "$1 benchmark: input size = $2"

    for block in "${BLOCKS[@]}"
    do
        block_size=$(( $2 / block ))
        echo -n "$2,$block_size" >> $EXPR_DIR/"$1"-runtimes.csv
        echo -n "$2,$block_size" >> $EXPR_DIR/"$1"-compares.csv

        for seed in "${SEEDS[@]}"
        do
            tokens=$($GEN_CMD -b "$block_size" -s "$seed" "$2" | ./bin/"$1" 2>&1 > /dev/null)
            tokens=( $tokens )

            echo -n ",${tokens[1]}" >> $EXPR_DIR/"$1"-runtimes.csv
            echo -n ",${tokens[3]}" >> $EXPR_DIR/"$1"-compares.csv
        done

        echo "" >> $EXPR_DIR/"$1"-runtimes.csv
        echo "" >> $EXPR_DIR/"$1"-compares.csv
    done
}

if [ ! -e "./bin/$1" ]
then
    make "$1"
fi

mkdir -p $EXPR_DIR

for sort in "${SORTS[@]}"
do
    touch $EXPR_DIR/"$sort"-runtimes.csv
    touch $EXPR_DIR/"$sort"-compares.csv
    echo -n "input_size,block_size" > $EXPR_DIR/"$sort"-runtimes.csv
    echo -n "input_size,block_size" > $EXPR_DIR/"$sort"-compares.csv

    for seed in "${SEEDS[@]}"
    do
        echo -n ",${sort}_s-${seed}" >> $EXPR_DIR/"$sort"-runtimes.csv
        echo -n ",${sort}_s-${seed}" >> $EXPR_DIR/"$sort"-compares.csv
    done

    echo "" >> $EXPR_DIR/"$sort"-runtimes.csv
    echo "" >> $EXPR_DIR/"$sort"-compares.csv
done

for (( size = 5000; size <= 150000; size += 10000 ))
do
    benchmark insertion $size
    benchmark merge $size
    benchmark quick $size

    echo
done

for (( size = 150000; size <= 20000000; size *= 2 ))
do
    benchmark merge $size
    benchmark quick $size

    echo
done
