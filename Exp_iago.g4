grammar Exp;

/*--------------------------------------------------------------------*/
/*                            CABEÇALHO                               */
/*--------------------------------------------------------------------*/

@parser::header
{
symbol_table    = []
type_table      = []

stack_max   = 0
stack_cur   = 0
if_label    = 0
else_label  = 0
while_label = 0

def emit(text, stack_direction):
    print('    '+text)
    global stack_cur
    global stack_max
    stack_cur += stack_direction
    stack_max = stack_cur if stack_cur > stack_max else stack_max

def openIfLabel():
    global if_label
    if_label += 1
    return 'NOT_IF_'+str(if_label)

def closeIfLabel():
    global if_label
    if_label -= 1
    return 'NOT_IF_'+str(if_label + 1)+':'

def elseLabel():
    global else_label
    else_label += 1
    return 'ELSE_END_'+str(else_label - 1)+':'

def gotoElseLabel():
    global else_label
    return 'goto ELSE_END_'+str(else_label)

def openWhileLabel():
    global while_label
    return 'BEGIN_WHILE_'+str(while_label)+':'

def gotoWhileLabel():
    global while_label
    return 'goto BEGIN_WHILE_'+str(while_label)

def breakWhileLabel():
    global while_label
    return 'goto NOT_IF_'+str(if_label)

def continueWhileLabel():
    global while_label
    return 'goto BEGIN_WHILE_'+str(while_label)

def closeWhileLabel():
    global while_label
    while_label += 1

}



@parser::members
{
}

/*--------------------------------------------------------------------*/
/*                            REGRAS LÉXICAS                          */
/*--------------------------------------------------------------------*/
MLCOMMENT: '$' .*? '$'           -> skip ;
COMMENT  : '#' ~('\n')           -> skip ;
SPACE    : (' '|'\t'|'\r'|'\n')+ -> skip ;

PLUS  : '+' ;
MINUS : '-' ;
TIMES : '*' ;
OVER  : '/' ;
REM   : '%' ;
OP_PAR: '(' ;
CL_PAR: ')' ;
ATTRIB: '=' ;
COMMA:  ',' ;

OP_CUR: '{'   ;
CL_CUR: '}'   ;
EQ    : '=='  ;
NE    : '!='  ;
GT    : '>'   ;
GE    : '>='  ;
LT    : '<'   ;
LE    : '<='  ;

PRINT   : 'print'       ;
READ_INT: 'read_int'    ;
READ_STR: 'read_str'    ;
IF      : 'if'          ;
ELSE    : 'else'        ;
WHILE   : 'while'       ;
BREAK   : 'break'       ;
CONTINUE: 'continue'    ;

NUMBER: '0'..'9'+       ;
STRING: '"'~('"')*'"'   ;

NAME  : 'a'..'z'+ ;

/*--------------------------------------------------------------------*/
/*                            REGRAS SINTATICAS                       */
/*--------------------------------------------------------------------*/
program:
    {
print('.source Test.src')
print('.class  public Test')
print('.super  java/lang/Object\n')
print('.method public <init>()V')
print('    aload_0')
print('    invokenonvirtual java/lang/Object/<init>()V')
print('    return')
print('.end method\n')
    }
    main ;

main:
    {
print('.method public static main([Ljava/lang/String;)V\n')
symbol_table.append('args')
type_table.append('s')
    }
    ( statement )+
    {
print('    return')
print('.limit stack', stack_max)
print('.limit locals', len(symbol_table))
print('.end method')
print('\n; symbol_table:', symbol_table)
print('\n; type_table:', type_table)
    }
    ;

statement: st_print | st_attrib | st_if | st_while | st_break | st_cotinue;

/*--------------------------------------------------------------------*/
/*                            PRINT                                   */
/*--------------------------------------------------------------------*/
st_print: PRINT OP_PAR
    {
emit('getstatic java/lang/System/out Ljava/io/PrintStream;', +1)
    }
    e1 = expression
    {
if $e1.type == 'i':
    emit('invokevirtual java/io/PrintStream/print(I)V\n',      -2)
elif $e1.type == 's':
    emit('invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n',      -2)
else:
    print('ERRO NO COMPILADOR', file=sys.stderr)
    }
    ( COMMA 
    {
emit('getstatic java/lang/System/out Ljava/io/PrintStream;', +1)
    }
    e2 = expression
    {
if $e2.type == 'i':
    emit('invokevirtual java/io/PrintStream/print(I)V\n',      -2)
elif $e2.type == 's':
    emit('invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n',      -2)
else:
    print('ERRO NO COMPILADOR', file=sys.stderr)
    }
    )*
    CL_PAR
    {
emit('getstatic java/lang/System/out Ljava/io/PrintStream;', +1)
emit('invokevirtual java/io/PrintStream/println()V\n',       -1)
    }
    ;

/*--------------------------------------------------------------------*/
/*                            ATRIBUIÇÃO                              */
/*--------------------------------------------------------------------*/
st_attrib: NAME ATTRIB expression 
    {
if $NAME.text not in symbol_table:
    symbol_table.append($NAME.text)
    type_table.append($expression.type)

index = symbol_table.index($NAME.text)
type  = type_table[index]
if(type == 'i'):
    emit('    istore ' + str(index) + '\n', -1)
elif(type == 's'):
    emit('    astore ' + str(index) + '\n', -1)
else:
    print('ERRO NO COMPILADOR', file=sys.stderr)
    }
    ;

/*--------------------------------------------------------------------*/
/*                              IF                                    */
/*--------------------------------------------------------------------*/
st_if: IF condition OP_CUR ( statement )+ CL_CUR
    {
emit(gotoElseLabel(), 0)
emit(closeIfLabel(), 0)
    }
    ( ELSE OP_CUR ( statement )+ CL_CUR
    {
emit(elseLabel(), 0)
    })?
    ;

/*--------------------------------------------------------------------*/
/*                              WHILE                                 */
/*--------------------------------------------------------------------*/
st_while: WHILE 
    {
emit(openWhileLabel(), 0)
    }
    condition OP_CUR ( statement )+ CL_CUR
    {
emit(gotoWhileLabel(), 0)
emit(closeIfLabel(), 0)
    }
    ;

/*--------------------------------------------------------------------*/
/*                              BREAK                                 */
/*--------------------------------------------------------------------*/
st_break: BREAK
    {
emit(breakWhileLabel(), 0)
    }
    ;

/*--------------------------------------------------------------------*/
/*                             CONTINUE                               */
/*--------------------------------------------------------------------*/
st_cotinue: CONTINUE
    {
emit(cotinueWhileLabel(), 0)
    }
    ;

/*--------------------------------------------------------------------*/
/*                            COMPARAÇÃO                              */
/*--------------------------------------------------------------------*/
condition: expression op = ( EQ | NE | GT | GE | LT | LE ) expression
    {
if $op.type == ExpParser.EQ: emit('if_icmpne '+openIfLabel(), -2)
if $op.type == ExpParser.NE: emit('if_icmpeq '+openIfLabel(), -2)
if $op.type == ExpParser.GT: emit('if_icmple '+openIfLabel(), -2)
if $op.type == ExpParser.GE: emit('if_icmplt '+openIfLabel(), -2)
if $op.type == ExpParser.LT: emit('if_icmpge '+openIfLabel(), -2)
if $op.type == ExpParser.LE: emit('if_icmpgt '+openIfLabel(), -2)
    }
    ;

/*--------------------------------------------------------------------*/
/*                            EXPRESSÃO                               */
/*--------------------------------------------------------------------*/
expression returns [type]: t1 = term ( op = ( PLUS | MINUS ) term
    {
if $op.type == ExpParser.PLUS:  emit('iadd', -1)
if $op.type == ExpParser.MINUS: emit('isub', -1)
    }
    )* 
    {
$type = $t1.type
    } ;

/*--------------------------------------------------------------------*/
/*                            TERMO                                   */
/*--------------------------------------------------------------------*/
term returns [type]: f1 = factor ( op = ( TIMES | OVER | REM ) factor
    {
if $op.type == ExpParser.TIMES: emit('imul',     -1)
if $op.type == ExpParser.OVER:  emit('idiv',     -1)
if $op.type == ExpParser.REM:   emit('irem',     -1)
    }
    )*
    {
$type = $f1.type
    } ;

/*--------------------------------------------------------------------*/
/*                            FATOR                                   */
/*--------------------------------------------------------------------*/
factor returns [type]: NUMBER
    {
emit('ldc ' + $NUMBER.text, +1)
$type = 'i'
    } 
    | STRING
    {
emit('ldc ' + $STRING.text, +1)
$type = 's'
    }
    | OP_PAR expression CL_PAR 
    {
$type = $expression.type
    }
    | NAME
    {
index = symbol_table.index($NAME.text)
type  = type_table[index]
if type == 'i':
    emit('iload ' + str(index), +1)
elif type == 's':
    emit('aload ' + str(index), +1)
else:
    print('ERRO NO COMPILADOR', file=sys.stderr)
$type = type
    }
    | READ_INT OP_PAR CL_PAR
    {
emit('invokestatic Runtime/readInt()I', +1)
$type = 'i'
    }
    | READ_STR OP_PAR CL_PAR
    {
emit('invokestatic Runtime/readString()Ljava/lang/String;', +1)
$type = 's'
    }
    ;

