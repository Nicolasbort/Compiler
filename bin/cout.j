.source Test.src
.class  public Test
.super  java/lang/Object

.method public <init>()V
    aload_0
    invokenonvirtual java/lang/Object/<init>()V
    return
.end method

.method public static main([Ljava/lang/String;)V

   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Enter array size:"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   invokestatic Runtime/readInt()I
   istore 1
   new Array
   dup
   invokespecial Array/<init>()V
   astore 1
   ldc 0
   istore 3
   BEGIN_WHILE_1:
   iload 3
   iload 1
   if_icmpge   END_WHILE_1
   goto END_WHILE_1
   goto BEGIN_WHILE_1
   END_WHILE_1:
 return
.limit stack 2
.limit locals 4
.end method

; symbol_table: args n a i 
