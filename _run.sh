#!/bin/bash

if [[ $# -eq 0 ]]; then
    echo "Missing stdin file" 
    exit 1
fi

if ./bin/compiler < $1 > bin/cout.j; then
    if java -jar bin/jasmin.jar bin/cout.j; then
        java Test
    fi
else
    rm -f bin/cout.j
fi

