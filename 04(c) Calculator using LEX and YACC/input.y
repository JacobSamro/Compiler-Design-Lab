%{
#include "y.tab.h"
#include <stdio.h>
#include <math.h>
#define PI 3.141592
int i,j;
%}
%union
{
double dval;
}
%token <dval> NUMBER
%token SIN COS TAN SQRT SQUARE RECI EXP MOD CUBE FACT
%left LN LOG
%left '+''-''*''/'
%right '^'
%nonassoc NEG
%type <dval> E
%%
SL : S '\n'
| SL S '\n'
;
S : E {printf("=%g\n",$1);}
;

E : E '+' E {$$=$1+$3;
printf("Addition is");}
|E '-' E {$$=$1-$3;
printf("substraction is");
}
|E '*' E {$$=$1*$3;
printf("Multiplication is");
}
|E '/' E {
if($3==0)
printf("Error! Divide by zero!!");
else
$$=$1/$3;
printf("Division is");
}
|E '^' E {$$=pow($1,$3);
printf("Power is=");
}
|SIN '(' E ')' {$$=sin($3/180*PI);
printf("SIN is=");
}
|COS '(' E ')' {$$=cos($3/180*PI);
printf("COS is");
}
|TAN '(' E ')' { if($3==90)
printf("Undefined (Infinity)");
 else
$$=tan($3/180*PI);
printf("TAN is");
}
|SQRT '(' E ')' {$$=sqrt($3);
 printf("Square Root is");
 }
|SQUARE '(' E ')' {$$=$3*$3;
 printf("square is=");
}
|EXP '(' E ')' {$$=exp($3);
printf("EXPONENTIAL is");
}
|RECI '(' E ')' {$$=1/($3);
printf("Reciprocal is");}
|CUBE '(' E ')' {$$=$3*$3*$3;
printf("Cube is");}
|FACT '(' E ')' {
$$=1;
for(j=1;j<=$3;j++)

$$=$$*j;
printf("Factorial is");
}
|'(' E ')' {$$=$2;
printf("The simple number is");}
|'-' E %prec NEG {$$=-$2;
printf("The number with Negative sign is ");
}
|LOG E {$$=log($2)/log(10);
printf("LOG of base 10 is");
}
|LN E { $$=log($2);
printf("LOG with base 2 is");
}
|MOD '(' E','E')' {$$=fmod($3,$5);
}
|NUMBER
;
%%
extern FILE*yyin;
int main()
{
do{
yyparse();
}while(!feof(yyin));
}
yyerror(char*a)
{
fprintf(stderr,"parse error!!!");
}
