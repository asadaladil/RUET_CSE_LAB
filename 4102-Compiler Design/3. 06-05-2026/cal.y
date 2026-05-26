%{
    #include<stdio.h>
    void yyerror(char *s);
    int yylex();
%}

/* %token SUM NUM SUB VAR */
%token VAR KEY ASSIGN NUM SEMICOLON
%start cal

%%
/* cal: cal SUM NUM | cal SUB NUM | NUM | */
/* cal: VAR */
cal: KEY VAR ASSIGN NUM SEMICOLON
    ;
%%
int main()
{
    int x=yyparse();
    printf("Parsing is succcessful\n");
}

void yyerror(char *s)
{
    fprintf(stderr,"Error: %s",s);
}