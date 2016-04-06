%{
#include "y.tab.h"
#include<math.h>
%}
NUMBER [0-9]+|([0-9]*"."[0-9]+)
%%
{NUMBER} {yylval.dval=atof(yytext);
 return NUMBER;}
sin|SIN {return SIN;}
cos|COS {return COS;}

tan|TAN {return TAN;}
sqrt|SQRT {return SQRT;}
square|SQUARE {return SQUARE;}
exp|EXP {return EXP;}
reci|RECI {return RECI;}
cube|CUBE {return CUBE;}
fact|FACT {return FACT;}
LOG { return LOG;}
ln|LN {return LN;}
MOD|mod {return MOD;}
[\t]+ ;
\n|. return yytext[0];
%%
int yywrap(void)
{ return 1;
}

