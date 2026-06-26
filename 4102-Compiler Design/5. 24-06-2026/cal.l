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

    /* "class" { return CLASS; }
    "public" { return PUBLIC; }
    "virtual" { return VIRTUAL;}
    "void"    { return VOID; }
    "new"     { return NEW; }
    "printf"  { return PRINTF; } */

" " {}
"int" {return INT;}
"if" {return IF;}
"else" {return ELSE;}
"(" {return LP;}
")" {return RP;}
"{" {return LC;}
"}" {return RC;}

"+" {return ADD;}
    /* "-" {return SUB;}
    "*" {return MUL;}
    "/" {return DIV;} */
"=" {return ASSIGN;}
"==" {return EQU;}
";" {return SEMI;}
    /* {number} { yylval=atoi(yytext); return NUM; } */
{id} { return ID; }
{number} { return NUM; }


    /* \"[^\"]*\" { return STRING_LITERAL; } */
    /* "->" { return ARROW; } */
    /* [ \t\n]+ { } */
    /* . { return yytext[0];} */
%%

/* int yywrap() {
    return 1;
} */
