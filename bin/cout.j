.source Test.src
.class  public Test
.super  java/lang/Object

.method public <init>()V
    aload_0
    invokenonvirtual java/lang/Object/<init>()V
    return
.end method

.method public static main([Ljava/lang/String;)V

   ldc 10
   istore 1
   BEGIN_WHILE_1:
   iload 1
   ldc 1
   if_icmple   END_WHILE_1
   BEGIN_WHILE_2:
   iload 1
   ldc 1
   if_icmple   END_WHILE_2
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Primeiro while nivel 2"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   goto END_WHILE_2
   goto BEGIN_WHILE_2
   END_WHILE_2:
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Primeiro while nivel 1"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   goto END_WHILE_1
   goto BEGIN_WHILE_1
   END_WHILE_1:
   BEGIN_WHILE_3:
   iload 1
   ldc 1
   if_icmple   END_WHILE_3
   BEGIN_WHILE_4:
   iload 1
   ldc 1
   if_icmple   END_WHILE_4
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Segundo while nivel 2"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   goto END_WHILE_4
   goto BEGIN_WHILE_4
   END_WHILE_4:
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Segundo while nivel 1"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   goto END_WHILE_3
   goto BEGIN_WHILE_3
   END_WHILE_3:
 return
.limit stack 2
.limit locals 2
.end method

; symbol_table: args a 
