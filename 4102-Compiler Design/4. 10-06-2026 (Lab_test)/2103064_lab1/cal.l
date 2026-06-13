%option noyywrap

%{
    #include "cal.tab.h"
%}

letter [A-Za-z]
digit [0-9]
us [_]
id ({us}|{letter})({us}|{digit}|{letter})*
number {digit}+

%%

"char" { printf("CHAR: %s\n",yytext); return CHAR;}
"malloc" { printf("MALLOC: %s\n",yytext); return MALLOC;}
"sizeof" { printf("SIZEOF: %s\n",yytext); return SIZEOF;}
"for" { printf("FOR: %s\n",yytext); return FOR;}
"free" { printf("FREE: %s\n",yytext); return FREE;}
"**" { printf("POINTER: %s\n",yytext); return POINTER;}
"++" { printf("INC: %s\n", yytext); return INC;}
"(" { printf("LP: %s\n", yytext); return LP;}
")" { printf("RP: %s\n", yytext); return RP;}
"<" { printf("LT: %s\n", yytext); return LT;}
"=" { printf("EQUAL: %s\n", yytext); return EQUAL;}
"[" { printf("LS: %s\n", yytext); return LS;}
"]" { printf("RS: %s\n", yytext); return RS;}
";" { printf("SEMI: %s\n", yytext); return SEMI;}
"*" { printf("MUL: %s\n", yytext); return MUL;}





{id} { printf("ID: %s\n", yytext); return ID; }
{number} { printf("NUM: %s\n", yytext); return NUM; }

[ \t\n]+ { }
    
%%
