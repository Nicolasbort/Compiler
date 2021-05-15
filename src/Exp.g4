grammar Exp;

/*---------------- PARSER INTERNALS ----------------*/

@parser::header
{
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <stdlib.h>
    
    
    using namespace std;
}

@parser::members
{
    vector<string> symbol_table = {"args"};
    vector<char>   type_table = {'s'};
    vector<int>    list_while;
    int stackSize    = 0;
    int stackMax     = 0;

    int ifCounter    = 0;
    int whileCounter = 0;
    int whileGlobal  = 0;

    void calculateStack(string command, short value)
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
        cout << " return\n";
        cout << ".limit stack " << stackMax << "\n";
        cout << ".limit locals " << symbol_table.size() << "\n";
        cout << ".end method\n";
        cout << "\n; symbol_table: ";
        for (string& symbol : symbol_table)
            cout << symbol << " ";
        cout << "\n";
    }
    ;

statement: st_print | st_attrib | st_if | st_while | st_break | st_continue | str_array_create | st_array_push | st_array_set;


st_print: PRINT OP_PAR
    {
        calculateStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
    }
    expression
    {
        if ($expression.type == 'i') 
            calculateStack("invokevirtual java/io/PrintStream/print(I)V", -2);
        else if ($expression.type == 's') 
            calculateStack("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V", -2);
        else
            printFormat("\nExpression ST_PRINT type invalid\n\n");
    }
    ( COMMA 
    {
        calculateStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
    }
    expression
    {
        calculateStack("invokevirtual java/io/PrintStream/print(I)V", -2);
    }
    )*
    CL_PAR
    {
        calculateStack("getstatic java/lang/System/out Ljava/io/PrintStream;", +1);
        calculateStack("invokevirtual java/io/PrintStream/println()V", -1);
    };


st_attrib: NAME ATTRIB expression
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);

        if (it == symbol_table.end())
        {
            symbol_table.push_back($NAME.text);
            type_table.push_back($expression.type);
        }

        it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);
        int index = distance(symbol_table.begin(), it);
        char type = type_table[index];

        if (type == 'i')
            calculateStack("istore " + to_string(index), -1);
        else if (type == 's')
            calculateStack("astore " + to_string(index), -1);
        else
            printFormat("\nExpression ST_ATTRIB type invalid\n\n");
    };



st_if: IF comparision
    {
        int ifLocal   = ifCounter;
        ifCounter++;

        calculateStack("NOT_IF_" + to_string(ifLocal), -2);
    }
    OP_CUR ( statement )+ CL_CUR
    {
        printFormat("goto END_ELSE_" + to_string(ifLocal) + "\n");
        printFormat("NOT_IF_" + to_string(ifLocal) + ":\n");
    }
    (ELSE OP_CUR ( statement )+ CL_CUR)?
    {
        printFormat("END_ELSE_" + to_string(ifLocal) + ":\n");
    };



st_while: WHILE
    {
        whileCounter++;
        int whileLocal = whileCounter;
        list_while.push_back(whileCounter);

        printFormat("BEGIN_WHILE_" + to_string(whileLocal) + ":\n");
    }
    comparision
    {
        calculateStack("END_WHILE_" + to_string(whileLocal), -2);
    }
    OP_CUR ( statement )+ CL_CUR
    {
        printFormat("goto BEGIN_WHILE_" + to_string(whileLocal) + "\n");
        printFormat("END_WHILE_" + to_string(whileLocal) + ":\n");
        list_while.pop_back();
    };


st_break: BREAK
    {
        if (!list_while.empty())
            printFormat("goto END_WHILE_" + to_string(list_while[list_while.size() - 1]) + "\n");
        else
            cerr << "Error: Line " << $ctx->getStart()->getLine() << " - Ignoring break. Break needs to be used inside a while\n";
    };

st_continue: CONTINUE
    {
        if (!list_while.empty())
            printFormat("goto BEGIN_WHILE_" + to_string(list_while.size() - 1) + "\n");
        else {
            cerr << "Error: Line " << $ctx->getStart()->getLine() << " - Ignoring continue. Continue needs to be used inside a while\n";
        }
    };


str_array_create: NAME ATTRIB OP_BRA CL_BRA
    {
        symbol_table.push_back($NAME.text);
        type_table.push_back('a');
        int index = symbol_table.size() - 1;

        calculateStack("new Array", 1);
        calculateStack("dup", 1);
        calculateStack("invokespecial Array/<init>()V", -1);
        calculateStack("astore " + to_string(index), -1);
    };


st_array_push: NAME DOT PUSH OP_PAR
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);
        int index = distance(symbol_table.begin(), it);
        char type = type_table[index];


        if (type == 'a') 
            calculateStack("aload " + to_string(index), 1);
        else {
            cerr << $NAME.text << " is not an array\n";
            // printFormat("invokevirtual Array/exit()V\n");
            // exit(0);
        }
    }
    expression CL_PAR
    {
        if ($expression.type == 'i')
            calculateStack("invokevirtual Array/push(I)V", -2);
        else
            printFormat("expression CL_PAR type not valid!\n");
    };


st_array_set: NAME OP_BRA
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);
        int index = distance(symbol_table.begin(), it);
        char type = type_table[index]; 

        calculateStack("aload " + to_string(index), 1);
    }
    ex1 = expression CL_BRA ATTRIB ex2 = expression
    {
        if ($ex1.type == 'i' && $ex2.type == 'i')
            calculateStack("invokevirtual Array/set(II)V", -3);
        else
            printFormat("\ninvalid st_array_set type\n");
    };


comparision: expression op = ( EQ | NE | GT | GE | LT | LE ) expression
    {
        if ($op.type == EQ) printFormat("if_icmpne");
        if ($op.type == NE) printFormat("if_icmpeq");
        if ($op.type == GT) printFormat("if_icmple");
        if ($op.type == GE) printFormat("if_icmplt");
        if ($op.type == LT) printFormat("if_icmpge");
        if ($op.type == LE) printFormat("if_icmpgt");
    };

expression returns [char type]:
    t1 = term ( op = (PLUS | MINUS) term
    {
        if ($op.type == PLUS) calculateStack("iadd", -1);
        if ($op.type == MINUS) calculateStack("isub", -1);
    }
    )*
    {
        $type = $t1.type;
    };

term returns [char type]: 
    f1 = factor ( op = (TIMES | OVER | REM ) factor
    {
        if ($op.type == TIMES) calculateStack("imul", -1);
        if ($op.type == OVER) calculateStack("idiv", -1);
        if ($op.type == REM) calculateStack("irem", -1);
    }
    )*
    {
        $type = $f1.type;
    } ;

factor returns [char type]: NUMBER
    {
        calculateStack("ldc " + $NUMBER.text, +1);
        $type = 'i';
    }
    | STRING
    {
        calculateStack("ldc " + $STRING.text, +1);
        $type = 's';
    }
    | OP_PAR expression CL_PAR
    {
        $type = $expression.type;
    }
    | NAME
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);
        int index = distance(symbol_table.begin(), it);
        char type = type_table[index];

        if (type == 'i')
            calculateStack("iload " + to_string(index), +1);
        else if (type == 's')
            calculateStack("aload " + to_string(index), +1);
        else if (type == 'a'){
            calculateStack("aload " + to_string(index), +1);
            printFormat("invokevirtual Array/string()Ljava/lang/String;\n");
            type = 's';
        }else
            printFormat("\nExpression NAME type invalid\n\n");
        
        $type = type;
    }
    | NAME OP_BRA
    {
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);
        int index = distance(symbol_table.begin(), it);
        char type = type_table[index];

        if (type == 'a') {
            calculateStack("aload " + to_string(index), +1);
        } else {
            printFormat("\nExpression NAME OP_BRA type invalid\n\n");
        }

    } expression CL_BRA
    {
        calculateStack("invokevirtual Array/get(I)I", -1);
        $type = 'i';
    }
    | NAME DOT LENGTH
    {
        printFormat("ENTROU NO LENGTH\n");
        auto it = find(symbol_table.begin(), symbol_table.end(), $NAME.text);
        int index = distance(symbol_table.begin(), it);
        char type = type_table[index];

        if (type == 'a') {
            calculateStack("aload " + to_string(index), 1);
            printFormat("invokevirtual Array/length()I\n");
            $type = 'i';
        } else {
            // printFormat("\nNAME DOT LENGTH invalid type\n");
            cerr << $NAME.text << " is not an array";
        }
        
    }
    | READ_INT OP_PAR CL_PAR
    {
        calculateStack("invokestatic Runtime/readInt()I", +1);
        $type = 'i';
    }
    | READ_STR OP_PAR CL_PAR
    {
        printFormat("invokestatic Runtime/readString()Ljava/lang/String;\n");
        $type = 's';
    };