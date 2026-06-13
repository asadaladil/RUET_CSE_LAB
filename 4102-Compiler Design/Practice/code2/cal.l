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

"char" { printf("CHAR: %s\n",yytext); return CHAR; }
"malloc" { printf("MALLOC: %s\n",yytext); return MALLOC; }
"sizeof" { printf("SIZEOF: %s\n",yytext); return SIZEOF;}
"for"    { printf("FOR: %s\n",yytext); return FOR; }
"free"     { printf("FREE: %s\n",yytext); return FREE; }
"**" {printf("POINTER: %s\n",yytext); return POINTER;}
"++" {printf("INC: %s\n",yytext); return INC;}

{id} { return ID; }
{number} { return NUM; }
    /* \"[^\"]*\" { return STRING_LITERAL; } */
[ \t\n]+ { }
. { return yytext[0];}
%%

/* int yywrap() {
    return 1;
} */
