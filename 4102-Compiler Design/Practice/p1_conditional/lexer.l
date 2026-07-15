%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

    // longest match and then rules written above have precedence. 

%}

%%

[ \t\r\n]+      { /* Ignore whitespace */ }

"int"           { return INT; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }

"+"             { return ADD; }
"-"             { return SUB; }
"*"             { return MUL; }
"/"             { return DIV; }
"=="            { return EQ; }
"="             { return ASSIGN; }
";"             { return SEMI; }
"("             { return LP; }
")"             { return RP; }
"{"             { return LB; }
"}"             { return RB; }

[0-9]+          { yylval = atoi(yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; } /* Matches variables natively */

.               { printf("Lexical Error\n"); }

%%