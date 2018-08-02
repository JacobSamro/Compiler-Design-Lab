%{
int COMMENT=0;
%}
identifier[a-z][A-Z0-9]*
digit[0-9]
%%
#.* {printf("\n%s is a peprocessor diective",yytext);}
"int" |
"float" |
"char" |
"double" |
"for" |
"do" |
"if" |
"else" |
"break" |
"continue" |
"void" |
"case" |
"long" |
"struct" |
"typedef" |
"goto" |
"const" |
"while" |
"printf" |
"scanf" |
"switch" |
"main()" |
"return" {printf("\n\t%s is a keyword",yytext);}
"\*" {COMMENT=1;}
"*/" {COMMENT=0;}
\{ {if(!COMMENT) printf("\nblocks starts");}
\} {if(!COMMENT) printf("\n block end");}
{identifier} {if(!COMMENT) printf("\n\t%s is an identifier",yytext);}
\".*\" {if(!COMMENT) printf("\n\t%s is a string",yytext);}
{digit} {if(!COMMENT) printf("\n\t%s is a number",yytext);}
\)(\;)? {if(!COMMENT) printf("\n\t"); ECHO; printf("\n");}
\ECHO;
= {if(!COMMENT) printf("\n\t= is an assignment operator");}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n\t%s is an relational operator",yytext);}
%%
int main(int argc,char **argv)
{
if(argc>1)
{
FILE *f1;
f1=fopen("file.c","r");
if(!f1)
{
printf("could not open%s\n",argv[1]);
exit(0);
}
yyin=f1;
}
yylex();
printf("\n");
return 1;
}
int yywrap()
{
return 0;
}
