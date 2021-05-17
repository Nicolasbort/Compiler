#!/bin/bash

if [[ $# -eq 0 ]]; then
    echo "Missing stdin file" 
    exit 1
fi

if ./bin/compiler < $1 > bin/cout.j; then
    if java -jar bin/jasmin.jar bin/cout.j; then
        java Test
    else
        rm -f Test.class
    fi
else
    rm -f bin/cout.j
fi


