#!/bin/bash

GEN_CMD=python3\ ./lib/random_permutation.py
DATA_DIR=./data
EXPR_DIR=$DATA_DIR/experiment

BLOCKS=( 1 )
K_s=( 5 10 20 40 100 )
SEEDS=( 1 101 611 )

function benchmark() {
    tokens=$($GEN_CMD -b "$3" -s "$5" "$2" | ./bin/"$1" "$4" 2>&1 > /dev/null)
    tokens=( $tokens )

    echo -n ",${tokens[1]}" >> $EXPR_DIR/"$1"-runtimes.csv
    echo -n ",${tokens[3]}" >> $EXPR_DIR/"$1"-compares.csv
}

function benchmark_seed() {
    echo -n "$2,$3,$4" >> $EXPR_DIR/"$1"-runtimes.csv
    echo -n "$2,$3,$4" >> $EXPR_DIR/"$1"-compares.csv

    for seed in "${SEEDS[@]}"
    do
        benchmark "$1" "$2" "$3" "$4" "$seed"
    done

    echo "" >> $EXPR_DIR/"$1"-runtimes.csv
    echo "" >> $EXPR_DIR/"$1"-compares.csv
}

function benchmark_k() {
    block_size=$(( $2 / $3 ))

    for k in "${K_s[@]}"
    do
        benchmark_seed "$1" "$2" $block_size "$k"
    done
}

function benchmark_block() {
    echo "$1 benchmark: input size = $2"

    benchmark_k "$1" "$2" "$2"
    for block in "${BLOCKS[@]}"
    do
        benchmark_k "$1" "$2" "$block"
    done
}

function benchmark_sort() {
    for (( size = 19200000; size <= 200000000; size *= 2 ))
    do
        benchmark_block "$1" $size
    done
}

if [ ! -e "./bin/$1" ]
then
    make "$1"
fi

mkdir -p $EXPR_DIR

sort=engineered

touch $EXPR_DIR/"$sort"-runtimes.csv
touch $EXPR_DIR/"$sort"-compares.csv
echo -n "input_size,block_size,k" > $EXPR_DIR/"$sort"-runtimes.csv
echo -n "input_size,block_size,k" > $EXPR_DIR/"$sort"-compares.csv

for seed in "${SEEDS[@]}"
do
    echo -n ",${sort}_s-${seed}" >> $EXPR_DIR/"$sort"-runtimes.csv
    echo -n ",${sort}_s-${seed}" >> $EXPR_DIR/"$sort"-compares.csv
done

echo "" >> $EXPR_DIR/"$sort"-runtimes.csv
echo "" >> $EXPR_DIR/"$sort"-compares.csv

benchmark_sort "$sort"

echo "finished"
