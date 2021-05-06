#!/bin/bash

if java -jar src/antlr-4.9.1-complete.jar -Dlanguage=Cpp -no-listener src/Exp.g4; then
    echo Build Success!
    cd build && make
else
    rm -f Exp*.java Exp*.class Exp.tokens
fi

