#!/bin/bash

GEN_CMD=python3\ ./lib/random_permutation.py
DATA_DIR=./data
EXPR_DIR=$DATA_DIR/experiment

BLOCKS=( 1 )
SEEDS=( 1 101 611 )
SORTS=( merge )

function benchmark() {
    tokens=$($GEN_CMD -b "$3" -s "$4" "$2" | ./bin/"$1" 2>&1 > /dev/null)
    tokens=( $tokens )

    echo -n ",${tokens[1]}" >> $EXPR_DIR/"$1"-runtimes.csv
    echo -n ",${tokens[3]}" >> $EXPR_DIR/"$1"-compares.csv
}

function benchmark_seed() {
    block_size=$(( $2 / $3 ))
    echo -n "$2,$block_size" >> $EXPR_DIR/"$1"-runtimes.csv
    echo -n "$2,$block_size" >> $EXPR_DIR/"$1"-compares.csv

    for seed in "${SEEDS[@]}"
    do
        benchmark "$1" "$2" $block_size "$seed"
    done

    echo "" >> $EXPR_DIR/"$1"-runtimes.csv
    echo "" >> $EXPR_DIR/"$1"-compares.csv
}

function benchmark_block() {
    echo "$1 benchmark: input size = $2"

    benchmark_seed "$1" "$2" "$2"
    for block in "${BLOCKS[@]}"
    do
        benchmark_seed "$1" "$2" "$block"
    done
}

function benchmark_input() {
    for (( size = 38400000; size <= 200000000; size *= 2 ))
    do
        benchmark_block "$1" $size
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

    benchmark_input "$sort"
done

echo "finished"
