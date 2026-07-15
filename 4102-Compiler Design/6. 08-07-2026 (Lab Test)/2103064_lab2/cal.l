%option noyywrap

%{
    #include "cal.tab.h"
    #include <stdlib.h>
    #include <string.h>
%}

letter [A-Za-z]
digit [0-9]
us [_]
id ({us}|{letter})({us}|{digit}|{letter})*
number {digit}+

%%
" " { }
"main" { printf("MAIN: %s\n",yytext); return MAIN;  }
"shuru" { printf("SHURU: %s\n",yytext); return SHURU; }
"of" { printf("OF: %s\n", yytext); return OF; }
"type" { printf("TYPE: %s\n",yytext); return TYPE; }
"int"  { printf("INT: %s\n", yytext); return INT; }
"jotokkhon" { printf("JOTOKKHON: %s\n",yytext); return JOTOKKHON; }
"print" { printf("PRINT: %s\n",yytext); return PRINT; }
"unit" { printf("UNIT: %s\n", yytext); return UNIT; }
"increase" { printf("INCREASE: %s\n",yytext); return INCREASE; }
"shesh" { printf("SHESH: %s\n",yytext); return SHESH; }

"(" { printf("LP: %s\n",yytext); return LP; }
")" { printf("RP: %s\n",yytext); return RP; }
"=" { printf("ASSIGN: %s\n",yytext); return ASSIGN; }
"<" { printf("LT: %s\n",yytext); return LT; }
"+" { printf("ADD: %s\n",yytext); return ADD; }
"/" { printf("DIV: %s\n",yytext); return DIV; }
"-" { printf("SUB: %s\n",yytext); return SUB; }
"*" { printf("MUL: %s\n",yytext); return MUL; }

{number} { printf("NUM: %s\n",yytext); yylval=atoi(yytext); return NUM;}
{id} { printf("ID: %s\n",yytext); return ID; }
\"[^\"]*\" { printf("STRING_LITERAL: %s\n", yytext); return STRING_LITERAL; }
%%


