%{
#include<stdio.h>
#include<ctype.h>
%}
%token LETTER DIGIT
%left '+' '-'
%left '*' '/'
%%
st:st expr '\n' {
    printf("\n valid expression \n");
}
| st '\n'
|
;
expr:expr '+' expr
|expr '-' expr
|expr '*' expr
|expr '/' expr
|'(' expr ')'
| NUM
| LETTER
;
NUM: DIGIT
|NUM DIGIT
;
%%

int yylex()
{
char c;
while((c=getchar())==' ');
if(isalpha(c)) return LETTER;
if(isdigit(c)) return DIGIT;
return(c);
}
int main()
{
    printf("\n enter an expression\n");
    yyparse();
}

int yyerror()
{
    printf("invalid\n");
    return 0;
}
