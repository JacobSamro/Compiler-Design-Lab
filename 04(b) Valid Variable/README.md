## Compiling this Program

```sh
lex file.l
yacc -d file.y
gcc lex.yy.c y.tab.c -ll -ly
./a.out
```
