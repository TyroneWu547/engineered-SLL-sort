#!/bin/bash

GEN_CMD=python3\ ./lib/random_permutation.py
DATA_DIR=./data
SIZES=( 100 10000 )

if [ ! -e "./bin/$1" ]
then
    make "$1"
fi

# Generate expected output
for size in "${SIZES[@]}"
do
    mkdir -p $DATA_DIR/n-"$size"/
    if [ ! -e "$DATA_DIR/n-$size/input_s-1.txt" ]
    then
        $GEN_CMD -s 1 "$size" > $DATA_DIR/n-"$size"/input_s-1.txt
    fi

    if [ ! -e "$DATA_DIR/n-$size/expected.txt" ]
    then
        $GEN_CMD -b 1 -s 1 "$size" > $DATA_DIR/n-"$size"/expected.txt
    fi

    echo
    echo "🧪 Running $1 sort with b = $size:"

    if [ "$1" == "engineered" ]
    then
        ./bin/"$1" 10 < $DATA_DIR/n-"$size"/input_s-1.txt 1> $DATA_DIR/n-"$size"/output.txt
    else
        ./bin/"$1" < $DATA_DIR/n-"$size"/input_s-1.txt 1> $DATA_DIR/n-"$size"/output.txt
    fi

    if ! diff -q --strip-trailing-cr $DATA_DIR/n-"$size"/expected.txt $DATA_DIR/n-"$size"/output.txt &> /dev/null
    then
        echo "Test case b = $size failed. ❌ :("
        exit 1
    fi

    echo "Test case b = $size passed. ✅ :)"
done
