%{

    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char *s);
    int yylex();

%}

%token CLASS PUBLIC VIRTUAL VOID NEW PRINTF ID NUM STRING_LITERAL ARROW


%%
program: statements
    ;

statements: statement statements
            |
            ;

statement: 
        base_class_decl
        | derived_class_decl
        | object_instantiation
        | method_call
        ;

base_class_decl: 
        CLASS ID '{' PUBLIC ':' VIRTUAL VOID ID '(' ')' '=' NUM ';' '}' ';'
        ;

derived_class_decl: 
        CLASS ID ':' PUBLIC ID '{' PUBLIC ':' VOID ID '(' ')' '{' PRINTF '(' STRING_LITERAL ')' ';' '}' '}' ';'
        ;

object_instantiation: 
        ID '*' ID '=' NEW ID '(' ')' ';'
        ;

method_call: 
        ID ARROW ID '(' ')' ';'
        ;
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
