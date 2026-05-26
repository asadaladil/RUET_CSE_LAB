%{
// definition section-> header file and variables
#include <stdio.h>
%}


%%
    /* rule or pattern section
    we write regular expression here + action of that pattern */
[0-9]+  { printf("Found a number: %s\n", yytext); }
[a-zA-Z]+ { printf("Found a word: %s\n", yytext); }
.|\n    { /* Ignore everything else */ }
%%

// user code section 
int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}