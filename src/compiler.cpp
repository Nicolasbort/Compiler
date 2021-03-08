#include <iostream>

#include "antlr4-runtime.h"
#include "ExpLexer.h"
#include "ExpParser.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {    
    ANTLRInputStream input(std::cin);
    ExpLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ExpParser parser(&tokens);

    parser.program();
 
    return 0;
}
