%{
#include<stdio.h>
%}
%token DIGIT LETTER
%%
stmt:A
     ;
A: LETTER B
 ;
B: LETTER B
 | DIGIT B
 | LETTER
 | DIGIT
 ;
%%
void main(){
printf("enter string \n");
yyparse();
printf("valid");
exit(0);
}
void yyerror()
{
printf("invalid");
exit(0);
}

