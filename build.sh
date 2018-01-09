#!/bin/bash

function usage() {
    echo "USAGE: $0 <exercise-to-compile>"
}

if [ "$#" -ne  1 ]; then
    usage
    exit 1
fi

infile=$1
outfile="${infile%.*}"

mkdir -p ./build
gcc -Wall -Werror -o "build/$outfile" "$infile"
