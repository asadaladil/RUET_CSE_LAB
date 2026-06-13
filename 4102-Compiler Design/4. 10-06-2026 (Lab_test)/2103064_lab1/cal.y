%{

    #include <stdio.h>
    // #include <stdlib.h>

    void yyerror(const char *s);
    int yylex();

%}

%token CHAR MALLOC SIZEOF FOR FREE POINTER INC LP RP LT EQUAL LS RS SEMI MUL ID NUM
%start cal

%%
cal: statements
    ;

statements: statement statements
            |
            ;

statement:  declaration
            | for_loop
            | value_assign
            | free1
            | free2
        
        ;
/* char ** names = ( char ** ) malloc ( n * sizeof ( char * ) ) ; */
declaration:
        CHAR POINTER ID EQUAL LP CHAR POINTER RP MALLOC LP ID MUL SIZEOF LP CHAR MUL RP RP SEMI
        ;
/* for ( i = 0 ; i < n ; i++ ) */
for_loop:
        FOR LP ID EQUAL NUM SEMI ID LT ID SEMI ID INC RP
        ;

/* names [ i ] = ( char * ) malloc ( size * sizeof ( char ) ) ; */
value_assign:
        ID LS ID RS EQUAL LP CHAR MUL RP MALLOC LP ID MUL SIZEOF LP CHAR RP RP SEMI
        ;

/* free ( names [ i ] ) ;  */
free1:
        FREE LP ID LS ID RS RP SEMI
        ;

/* free ( names ) ; */
free2:
        FREE LP ID RP SEMI
        ;

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
    return 0;
}
