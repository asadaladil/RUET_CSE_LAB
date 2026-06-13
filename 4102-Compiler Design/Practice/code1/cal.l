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

"class" { return CLASS; }
"public" { return PUBLIC; }
"virtual" { return VIRTUAL;}
"void"    { return VOID; }
"new"     { return NEW; }
"printf"  { return PRINTF; }

{id} { return ID; }
{number} { return NUM; }
\"[^\"]*\" { return STRING_LITERAL; }
"->" { return ARROW; }
[ \t\n]+ { }
. { return yytext[0];}
%%

/* int yywrap() {
    return 1;
} */
