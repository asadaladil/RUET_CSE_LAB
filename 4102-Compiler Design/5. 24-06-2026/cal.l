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

    /* "class" { return CLASS; }
    "public" { return PUBLIC; }
    "virtual" { return VIRTUAL;}
    "void"    { return VOID; }
    "new"     { return NEW; }
    "printf"  { return PRINTF; } */

" " {}
"int" { printf("INT: %s\n", yytext); return INT;}
"float" { printf("FLOAT: %s\n", yytext); return FLOAT;}
"for" { printf("FOR: %s\n", yytext); return FOR;}
"while" { printf("WHILE: %s\n", yytext); return WHILE;}
"if" { printf("IF: %s\n", yytext); return IF;}
"else" { printf("ELSE: %s\n", yytext); return ELSE;}
"return" { printf("RETURN: %s\n", yytext); return RETURN;}
"struct" { printf("STRUCT: %s\n", yytext); return STRUCT;}
"void" { printf("VOID: %s\n", yytext); return VOID;}
"print" { printf("PRINTF: %s\n", yytext); return PRINTF;}

"(" { printf("LP: %s\n", yytext); return LP;}
")" { printf("RP: %s\n", yytext); return RP;}
"{" { printf("LC: %s\n", yytext); return LC;}
"}" { printf("RC: %s\n", yytext); return RC;}
"[" { printf("LS: %s\n", yytext); return LS;}
"]" { printf("RS: %s\n", yytext); return RS;}
":" { printf("COLON: %s\n",yytext); return COLON;}

"+" { printf("ADD: %s\n", yytext); return ADD;}
"-" { printf("SUB: %s\n", yytext); return SUB;}
"*" { printf("MUL: %s\n", yytext); return MUL;}
"/" { printf("DIV: %s\n", yytext); return DIV;}
"%" { printf("MOD: %s\n", yytext); return MOD;}
"!=" { printf("NE: %s\n", yytext); return NE;}
"&&" { printf("AND: %s\n", yytext); return AND;}
"||" { printf("OR: %s\n", yytext); return OR;}
"!" { printf("NOT: %s\n", yytext); return NOT;}

"=" { printf("ASSIGN: %s\n", yytext); return ASSIGN;}
"==" { printf("EQU: %s\n", yytext); return EQU;}
";" { printf("SEMI: %s\n", yytext); return SEMI;}
"<" { printf("LT: %s\n", yytext); return LT;}
">" { printf("GT: %s\n", yytext); return GT;}
"<=" { printf("LE: %s\n", yytext); return LE;}
">=" { printf("GE: %s\n", yytext); return GE;}
"," { printf("COMMA: %s\n", yytext); return COMMA;}
"?" { printf("QUES: %s\n", yytext); return QUES;}

{id} { printf("ID: %s\n", yytext); yylval.sval = strdup(yytext); return ID; }
{number} { printf("NUM: %s\n", yytext); yylval.ival=atoi(yytext); return NUM; }
{number}"."{number} { printf("FLOAT_NUM: %s\n", yytext); yylval.ival=atof(yytext); return FLOAT_NUM; }


\"[^\"]*\" { printf("STRING_LITERAL: %s\n", yytext); yylval.sval = strdup(yytext); return STRING_LITERAL; }
    /* "->" { return ARROW; } */
    /* [ \t\n]+ { } */
    /* . { return yytext[0];} */
%%

/* int yywrap() {
    return 1;
} */
