%{

    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char *s);
    int yylex();

%}

%token CHAR MALLOC SIZEOF FOR FREE ID NUM POINTER INC
%start cal


%%
cal: statements
    ;

statements: statement statements
            |
            ;

statement: 
        memory_declare
        | for_loop
        | value_assign
        | free_memory1
        | free_memory2
        ;

memory_declare: 
        CHAR POINTER ID '=' '(' CHAR POINTER ')' MALLOC '(' ID '*' SIZEOF '(' CHAR '*' ')' ')' ';'
        ;

for_loop: 
        FOR '(' ID '=' NUM ';' ID '<' ID ';' ID INC ')'
        ;

value_assign: 
        ID '[' ID ']' '=' '(' CHAR '*' ')' MALLOC '(' ID '*' SIZEOF '(' CHAR ')' ')' ';'
        ;

free_memory1: 
        FREE '(' ID '[' ID ']' ')' ';'
        ;
free_memory2:
        FREE '(' ID ')' ';'
%%


void yyerror(const char *s) 
{
    fprintf(stderr, "Syntax Error: %s\n", s);
}

int main() 
{
    if (yyparse() == 0) {
        printf("Statements parsed successfully!\n");
    }
    else
    {
        printf("Syntax Error.\n");
    }
    return 0;
}
