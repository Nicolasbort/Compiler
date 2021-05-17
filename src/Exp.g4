grammar Exp;

/*---------------- PARSER INTERNALS ----------------*/

@parser::header
{
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <stdlib.h>
    
    #define RED 31
    #define YELLOW 33
    
    using namespace std;
}

@parser::members
{
    vector<string> symbol_table = {"args"};
    vector<char>   type_table = {'s'};
    vector<bool>   used_vars = {true};
    vector<int>    list_while;

    int stackSize    = 0;
    int stackMax     = 0;

    int ifCounter    = 0;
    int whileCounter = 0;

    void printAndChangeStack(string command, short value)
    {
        stackSize += value;

        if (stackSize > stackMax)
            stackMax = stackSize;
        
        cout << "   " << command << "\n";
    }

    void printFormat(string command)
    {
        cout << "   " << command;
    }

    void printError(string message, int line)
    {
        cerr << "Error: Line " << line << " - " << message << "\n";
    }

    void checkUnusedVars()
    {
        for (int i=0; i<used_vars.size(); i++)
        {
            if (!used_vars[i]) 
                printError("'" + symbol_table[i] + "' is defined but never used", -1);
        }
    }

    int getVarIndex(string varName)
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), varName);

        if (it == symbol_table.end())
            return -1;

        return distance(symbol_table.begin(), it);
    } 

    int addNewVariable(string name, char type)
    {
        symbol_table.push_back(name);
        type_table.push_back(type);
        used_vars.push_back(false);

        return symbol_table.size() - 1;
    }

}

/*---------------- LEXER RULES ----------------*/

MLCOMMENT: '#*' .*? '*#'      -> skip;
COMMENT: '#' ~('\n')*         -> skip;
SPACE : (' '|'\t'|'\r'|'\n')+ -> skip;

PLUS  : '+';
MINUS : '-';
TIMES : '*';
OVER  : '/';
REM   : '%';
OP_BRA: '[';
CL_BRA: ']';
OP_PAR: '(';
CL_PAR: ')';
OP_CUR: '{';
CL_CUR: '}';
ATTRIB: '=';
COMMA : ',';
DOT   : '.';

// if Tokens
EQ    : '==';
NE    : '!=';
GT    : '>';
GE    : '>=';
LT    : '<';
LE    : '<=';

NUMBER: '0'..'9'+ ;
STRING: '"'~('"')*'"';

PRINT    : 'print';
READ_INT : 'read_int';
READ_STR : 'read_str';
IF       : 'if';
ELSE     : 'else';
WHILE    : 'while';
BREAK    : 'break';
CONTINUE : 'continue';
PUSH     : 'push';
LENGTH   : 'length';
DEF      : 'def';

NAME     : 'a'..'z'+;

/*---------------- PARSER RULES ----------------*/

program:
    {
        cout << ".source Test.src\n";
        cout << ".class  public Test\n";
        cout << ".super  java/lang/Object\n\n";
        cout << ".method public <init>()V\n";
        cout << "    aload_0\n";
        cout << "    invokenonvirtual java/lang/Object/<init>()V\n";
        cout << "    return\n";
        cout << ".end method\n\n";
    }
    main ;

main:
    {
        cout << ".method public static main([Ljava/lang/String;)V\n\n";
    }
    ( statement )+ 
    {
        checkUnusedVars();
        cout << " return\n";
        cout << ".limit stack " << stackMax << "\n";
        cout << ".limit locals " << symbol_table.size() << "\n";
        cout << ".end method\n";
        cout << "\n; symbol_table: ";
        for (string& symbol : symbol_table)
            cout << symbol << " ";

        cout << "\n; type_table: ";
        for (char type : type_table)
            cout << type << " ";

        cout << "\n; used_vars: ";
        for (bool used : used_vars)
            cout << (used ? "True" : "False") << " ";
    }
    ;

statement: st_print | st_attrib | st_if | st_while | st_break | st_continue | str_array_create | st_array_push | st_array_set;


st_print: PRINT OP_PAR
    {
        printAndChangeStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
    }
    expression
    {
        if ($expression.type == 'i') 
            printAndChangeStack("invokevirtual java/io/PrintStream/print(I)V", -2);
        else if ($expression.type == 's') 
            printAndChangeStack("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V", -2);
        else
            cerr << "Error: Line " << $ctx->getStart()->getLine() << " - Type '" << $expression.type << "' is not valid\n";
    }
    ( COMMA 
    {
        printAndChangeStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
    }
    expression
    {
        if ($expression.type == 'i') 
            printAndChangeStack("invokevirtual java/io/PrintStream/print(I)V", -2);
        else if ($expression.type == 's') 
            printAndChangeStack("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V", -2);
        else
            cerr << "Error: Line " << $ctx->getStart()->getLine() << " - Type '" << $expression.type << "' is not valid\n";
    }
    )*
    CL_PAR
    {
        printAndChangeStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
        printAndChangeStack("invokevirtual java/io/PrintStream/println()V", -1);
    };


st_attrib: NAME ATTRIB ex = expression
    {
        int index = getVarIndex($NAME.text);

        if (index == -1)
            index = addNewVariable($NAME.text, $ex.type);

        // used_vars[index] = true;
        char type = type_table[index];

        if ($ex.type != type) {
            switch (type) {
                case 's':
                    cerr << "Error: Line " << $ctx->getStart()->getLine() << " - '" << $NAME.text << "' is a string\n";
                    break;
                case 'i':
                    cerr << "Error: Line " << $ctx->getStart()->getLine() << " - '" << $NAME.text << "' is an integer\n";
                    break;
                case 'a':
                    cerr << "Error: Line " << $ctx->getStart()->getLine() << " - '" << $NAME.text << "' is an array\n";
                    break;
            }
        }
        else {
        
            if (type == 'i')
                printAndChangeStack("istore " + to_string(index), -1);
            else if (type == 's')
                printAndChangeStack("astore " + to_string(index), -1);
            else
                cerr << "Error: Line " << $ctx->getStart()->getLine() << " - Type '" << type << "' is not valid\n"; 
        }
    };



st_if: IF comparision
    {
        int ifLocal   = ifCounter;
        if ($comparision.isValid) {
            ifCounter++;

            printAndChangeStack("NOT_IF_" + to_string(ifLocal), -2);
        }
    }
    OP_CUR ( statement )+ CL_CUR
    {
        if ($comparision.isValid) {
            printFormat("goto END_ELSE_" + to_string(ifLocal) + "\n");
            cout << "NOT_IF_" << to_string(ifLocal) << ":\n";
        }
    }
    (ELSE OP_CUR ( statement )+ CL_CUR)?
    {
        if ($comparision.isValid) 
            cout << "END_ELSE_" << to_string(ifLocal) << ":\n";
    };



st_while: WHILE
    {
        whileCounter++;
        int whileLocal = whileCounter;
        list_while.push_back(whileCounter);

        cout << "BEGIN_WHILE_" << to_string(whileLocal) << ":\n";
    }
    comparision
    {
        if ($comparision.isValid)
            printAndChangeStack("END_WHILE_" + to_string(whileLocal), -2);
    }
    OP_CUR ( statement )+ CL_CUR
    {
        if ($comparision.isValid){
            printFormat("goto BEGIN_WHILE_" + to_string(whileLocal) + "\n");
            cout << "END_WHILE_" << to_string(whileLocal) << ":\n";
            list_while.pop_back();
        }
    };


st_break: BREAK
    {
        if (!list_while.empty())
            printFormat("goto END_WHILE_" + to_string(list_while[list_while.size() - 1]) + "\n");
        else
            printError("Ignoring 'break'. 'break' needs to be inside a while", $ctx->getStart()->getLine());
    };

st_continue: CONTINUE
    {
        if (!list_while.empty())
            printFormat("goto BEGIN_WHILE_" + to_string(list_while[list_while.size() - 1]) + "\n");
        else 
            printError("Ignoring 'continue'. 'continue' needs to be inside a while", $ctx->getStart()->getLine());
        
    };


str_array_create: NAME ATTRIB OP_BRA CL_BRA
    {
        int index = getVarIndex($NAME.text);

        if (index == -1)
        {
            index = addNewVariable($NAME.text, 'a');

            printAndChangeStack("new Array", 1);
            printAndChangeStack("dup", 1);
            printAndChangeStack("invokespecial Array/<init>()V", -1);
            printAndChangeStack("astore " + to_string(index), -1);
        }
        else
            printError("'" + $NAME.text + "' is already declared", $ctx->getStart()->getLine());

    };


st_array_push: NAME DOT PUSH OP_PAR expression CL_PAR
    {
        int index = getVarIndex($NAME.text);

        if (index == -1)
            printError("'" + $NAME.text + "' is not defined", $ctx->getStart()->getLine());
        else {
            char type = type_table[index];

            if (type != 'a') 
                printError("'" + $NAME.text + "' is not an array", $ctx->getStart()->getLine());
            else if ($expression.type != 'i')
                printError("'" + $expression.text + "' must be an integer", $ctx->getStart()->getLine());
            else {
                printAndChangeStack("aload " + to_string(index), 1);
                printAndChangeStack("invokevirtual Array/push(I)V", -2);
            }
        }
    };


st_array_set: NAME OP_BRA ex1 = expression CL_BRA ATTRIB ex2 = expression
    {
        int index = getVarIndex($NAME.text);

        if (index == -1)
            printError("'" + $NAME.text + "' is not defined", $ctx->getStart()->getLine());
        else
        {
            char type = type_table[index]; 

            if (type != 'a')
                printError("'" + $NAME.text + "' is not array", $ctx->getStart()->getLine());
            else {
                if ($ex1.type != 'i')
                    printError("Array index must be an integer", $ctx->getStart()->getLine());
                else if ($ex2.type != 'i')
                    printError("'" + $ex2.text + "' must be an integer", $ctx->getStart()->getLine());
                else {
                    printAndChangeStack("invokevirtual Array/set(II)V", -3);            
                    printAndChangeStack("aload " + to_string(index), 1);
                }
            }
        }
    
    };

comparision returns [bool isValid]: ex1 = expression op = ( EQ | NE | GT | GE | LT | LE ) ex2 = expression
    {
        if ($ex1.type != $ex2.type || $ex1.type == 'a' || $ex2.type == 'a')
        {
            printError("Cannot mix types", $ctx->getStart()->getLine());
            $isValid = false;
        }
        else
        {
            if ($op.type == EQ) printFormat("if_icmpne");
            if ($op.type == NE) printFormat("if_icmpeq");
            if ($op.type == GT) printFormat("if_icmple");
            if ($op.type == GE) printFormat("if_icmplt");
            if ($op.type == LT) printFormat("if_icmpge");
            if ($op.type == LE) printFormat("if_icmpgt");
            $isValid = true;
        }
    };

expression returns [char type]:
    t1 = term ( op = (PLUS | MINUS) t2 = term
    {
        if ($t1.type != 'u' && $t2.type != 'u'){
            if ($t1.type == 's' || $t2.type == 's' || $t1.type != $t2.type) 
                printError("Cannot mix types", $ctx->getStart()->getLine());
            else {
                if ($op.type == PLUS) printAndChangeStack("iadd", -1);
                if ($op.type == MINUS) printAndChangeStack("isub", -1);
            }
        }
    }
    )*
    {
        $type = $t1.type;
    };

term returns [char type]: 
    f1 = factor ( op = (TIMES | OVER | REM ) f2 = factor
    {
        if ($f1.type != 'i' || $f2.type != 'i')
            printError("Cannot mix types", $ctx->getStart()->getLine());
        else {
            if ($op.type == TIMES) printAndChangeStack("imul", -1);
            if ($op.type == OVER) printAndChangeStack("idiv", -1);
            if ($op.type == REM) printAndChangeStack("irem", -1);
        }
    }
    )*
    {
        $type = $f1.type;
    } ;

factor returns [char type]: NUMBER
    {
        printAndChangeStack("ldc " + $NUMBER.text, +1);
        $type = 'i';
    }
    | STRING
    {
        printAndChangeStack("ldc " + $STRING.text, +1);
        $type = 's';
    }
    | OP_PAR expression CL_PAR
    {
        $type = $expression.type;
    }
    | NAME
    {
        int index = getVarIndex($NAME.text);

        if (index != -1) {
            used_vars[index] = true;
            char type = type_table[index];

            if (type == 'i')
                printAndChangeStack("iload " + to_string(index), +1);
            else if (type == 's')
                printAndChangeStack("aload " + to_string(index), +1);
            else if (type == 'a'){
                printAndChangeStack("aload " + to_string(index), +1);
                printFormat("invokevirtual Array/string()Ljava/lang/String;\n");
                type = 's';
            }else
                printError("Type error", $ctx->getStart()->getLine());
            
            $type = type;
        } 
        else {
            printError("'" + $NAME.text + "' is not defined", $ctx->getStart()->getLine());
            $type = 'u';
        }
    }
    | NAME OP_BRA expression CL_BRA
    {
        $type = 'i';

        int index = getVarIndex($NAME.text);

        if (index == -1) 
            printError("'" + $NAME.text + "' is not defined", $ctx->getStart()->getLine());
        else
        {
            if ($expression.type != 'i')
                printError("'" + $expression.text + "' must be an integer", $ctx->getStart()->getLine());
            else {
                
                used_vars[index] = true;
                char type = type_table[index];

                if (type == 'a')  {
                    printAndChangeStack("aload " + to_string(index), +1);
                    printAndChangeStack("invokevirtual Array/get(I)I", -1);
                }
                else 
                    printError("'" + $NAME.text  + "' must be array", $ctx->getStart()->getLine());
                
            }
        }
        
    }
    | NAME DOT LENGTH
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);

        if (it == symbol_table.end()) {
            cerr << "Error: Line " << $ctx->getStart()->getLine() << " - '" << $NAME.text << "' is not defined\n";
        } else {

            int index = distance(symbol_table.begin(), it);
            char type = type_table[index];

            if (type == 'a') {
                printAndChangeStack("aload " + to_string(index), 1);
                printFormat("invokevirtual Array/length()I\n");
            } else 
                cerr << "Error: Line " << $ctx->getStart()->getLine() << " - '" << $NAME.text << "' must be array\n";
        }

        $type = 'i';
    }
    | READ_INT OP_PAR CL_PAR
    {
        printAndChangeStack("invokestatic Runtime/readInt()I", +1);
        $type = 'i';
    }
    | READ_STR OP_PAR CL_PAR
    {
        printFormat("invokestatic Runtime/readString()Ljava/lang/String;\n");
        $type = 's';
    };