grammar Exp;

/*---------------- PARSER INTERNALS ----------------*/

@parser::header
{
    #include <iostream>
    // #include <vector>
    
    using namespace std;
}

@parser::members
{
    // vector<string> symbol_table;
}

/*---------------- LEXER RULES ----------------*/

COMMENT: '#' ~('\n')*         -> skip;
SPACE : (' '|'\t'|'\r'|'\n')+ -> skip ;

PLUS  : '+';
MINUS : '-';
TIMES : '*';
OVER  : '/';
REM   : '%';
OP_PAR: '(';
CL_PAR: ')';

NUMBER: '0'..'9'+ ;


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
        cout << "    getstatic java/lang/System/out Ljava/io/PrintStream;\n";
    }
    expression
    {
        cout << "    invokevirtual java/io/PrintStream/println(I)V\n\n";
        cout << "    return\n";
        cout << ".limit stack 10\n";
        cout << ".end method\n";
        // cout << "\n; symbol_table: ";
        // for (vector<string>::const_iterator i = symbol_table.begin(); i != symbol_table.end(); i++) {
        //     cout << *i << ' ';
        // }
        // cout << "\n";
    }
    ;

expression:
    term ( op = (PLUS | MINUS) term
    {
        if ($op.type == PLUS) cout << "    iadd\n";
        if ($op.type == MINUS) cout << "    isub\n";
    }
    )* ;

term:
    factor ( op = (TIMES | OVER | REM ) factor
    {
        if ($op.type == TIMES) cout << "    imul\n";
        if ($op.type == OVER) cout << "    idiv\n";
        if ($op.type == REM) cout << "    irem\n";
    }
    )* ;

factor:
    NUMBER
    {
        cout << "    ldc " << $NUMBER.text << "\n";
        // symbol_table.push_back($NUMBER.text);
    }
    | OP_PAR expression CL_PAR ;

