%{

    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char *s);
    int yylex();

%}

%token NUM ADD INT ELSE LP RP EQU ASSIGN ID LC RC SEMI IF 


%%
program: exps
        ;

exps: exp exps 
    |
    ;
exp: dec 
    |if_cond 
    |else_cond 
    ;

dec: INT ID ASSIGN NUM ADD NUM SEMI
    ;

if_cond: IF LP EQU NUM RP LC INT ID ASSIGN NUM SEMI RC
        ;
        
else_cond: ELSE LC INT ID ASSIGN NUM SEMI RC 
        ;

    /* ADD NUM  { $$=$1+$3; printf("%d+%d=%d\n",$1,$3,$$); }  
        | exp SUB NUM  { $$=$1-$3; printf("%d-%d=%d\n",$1,$3,$$); }
        | NUM
        ; */



%%


void yyerror(const char *s) 
{
    fprintf(stderr, "Syntax Error: %s\n", s);
}

int main() 
{
    /* printf("Enter the C++ statements to parse:\n"); */
    if (yyparse() == 0) {
        printf("Statements parsed successfully!\n");
    }
    return 0;
}
