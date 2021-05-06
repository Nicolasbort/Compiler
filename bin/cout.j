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
   ldc "abc"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokestatic Runtime/readString()Ljava/lang/String;
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
   ldc "def"
   astore 1
   getstatic java/lang/System/out Ljava/io/PrintStream;
   aload 1
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   invokevirtual java/io/PrintStream/println()V
 return
.limit stack 2
.limit locals 2
.end method

; symbol_table: args x 
