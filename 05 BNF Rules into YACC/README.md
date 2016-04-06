## Compiling this Program

```sh
lex lex.l
yacc –d yacc.y
gcc lex.yy.c y.tab.c –ll –lm
./a.out

```
