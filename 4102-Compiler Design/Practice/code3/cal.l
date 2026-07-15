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

" " {}
"int" { printf("INT: %s\n", yytext); return INT;}
"for" { printf("FOR: %s\n", yytext); return FOR;}
"while" { printf("WHILE: %s\n", yytext); return WHILE;}
"if" { printf("IF: %s\n", yytext); return IF;}
"else" { printf("ELSE: %s\n", yytext); return ELSE;}
"print" { printf("PRINT: %s\n", yytext); return PRINT;}
"start" { printf("START: %s\n", yytext); return START;}
"end" { printf("END: %s\n", yytext); return END;}
"key" { printf("KEY: %s\n", yytext); return KEY;}
"return" { printf("RETURN: %s\n", yytext); return RETURN;}
"float" { printf("FLOAT: %s\n", yytext); return FLOAT;}

"(" { printf("LP: %s\n", yytext); return LP;}
")" { printf("RP: %s\n", yytext); return RP;}
"{" { printf("LC: %s\n", yytext); return LC;}
"}" { printf("RC: %s\n", yytext); return RC;}
"[" { printf("LS: %s\n", yytext); return LS;}
"]" { printf("RS: %s\n", yytext); return RS;}
"," { printf("COMMA: %s\n", yytext); return COMMA;}

"+" { printf("ADD: %s\n", yytext); return ADD;}
"-" { printf("SUB: %s\n", yytext); return SUB;}
"*" { printf("MUL: %s\n", yytext); return MUL;}
"/" { printf("DIV: %s\n", yytext); return DIV;}
"%" { printf("MOD: %s\n", yytext); return MOD;}

"=" { printf("ASSIGN: %s\n", yytext); return ASSIGN;}
"==" { printf("EQU: %s\n", yytext); return EQU;}
";" { printf("SEMI: %s\n", yytext); return SEMI;}
"<" { printf("LT: %s\n", yytext); return LT;}
">" { printf("GT: %s\n", yytext); return GT;}
"<=" { printf("LE: %s\n", yytext); return LE;}
">=" { printf("GE: %s\n", yytext); return GE;}
"!=" { printf("NE: %s\n", yytext); return NE;}
"++" { printf("INC: %s\n", yytext); return INC;}
"--" { printf("DEC: %s\n", yytext); return DEC;}

{id} { printf("ID: %s\n", yytext); yylval.sval = strdup(yytext); return ID; }
{number} { printf("NUM: %s\n", yytext); yylval.ival=atoi(yytext); return NUM; }
\"[^\"]*\" { printf("STRING_LITERAL: %s\n", yytext); yylval.sval = strdup(yytext); return STRING_LITERAL; }

%%

/* int yywrap() {
    return 1;
} */
