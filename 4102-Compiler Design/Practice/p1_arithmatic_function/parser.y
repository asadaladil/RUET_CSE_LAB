%{
    #include <stdio.h>
    #include <stdlib.h>

    #define YYSTYPE int

    void yyerror(char *s);
    int yylex();
%}

/* Added tokens for functions and arrays: COMMA, and square brackets LSB/RSB */
%token INT ID NUM ASSIGN SEMI LP RP LB RB LSB RSB COMMA
%token IF ELSE WHILE FOR EQ

/* Precedence rules */
%left EQ
%left ADD SUB
%left MUL DIV

%%

BLOCK: statements ;

statements: statements statement
          | 
          ;

statement:
      declaration
    | assignment
    | if_structure
    | loop_structure
    | function_definition
    | function_call SEMI    { printf("[Parse] Function call statement processed.\n"); }
    ;

declaration:
      INT ID ASSIGN exp SEMI    
      { 
          printf("[Parse] Variable Declaration (Initial Value = %d)\n", $4);
      }
    | INT ID LSB NUM RSB SEMI
      {
          printf("[Parse] Array Declaration: %s with size %d\n", "array", $4);
      }
    ;

assignment:
      ID ASSIGN exp SEMI        
      { 
          printf("[Parse] Variable Assignment (Value = %d)\n", $3);
      }
    | ID LSB exp RSB ASSIGN exp SEMI
      {
          printf("[Parse] Array Element Assignment (Index = %d, Value = %d)\n", $3, $6);
      }
    ;

/* New: Function Definition Rule */
function_definition:
      INT ID LP parameter_list RP LB statements RB
      {
          printf("[Parse] Successfully parsed Function Definition.\n");
      }
    ;

parameter_list:
      parameter_list COMMA parameter
    | parameter
    | /* empty parameter list */
    ;

parameter:
      INT ID
    ;

/* New: Function Call Rule */
function_call:
      ID LP argument_list RP
      {
          $$ = 42; /* Mock return value for function execution in expressions */
      }
    ;

argument_list:
      argument_list COMMA exp
    | exp
    | /* empty argument list */
    ;

if_structure:
      IF LP exp RP LB statements RB ELSE LB statements RB
      {
          printf("[Parse] Successfully parsed an IF-ELSE block.\n");
      }
    | IF LP exp RP LB statements RB
      {
          printf("[Parse] Successfully parsed an IF-ONLY block.\n");
      }
    ;
    
loop_structure:
      WHILE LP exp RP LB statements RB
      {
          printf("[Parse] Successfully parsed a WHILE loop.\n");
      }
    | FOR LP INT ID ASSIGN exp SEMI exp SEMI ID ASSIGN exp RP LB statements RB
      {
          printf("[Parse] Successfully parsed a FOR loop.\n");
      }
    ;

exp: exp ADD exp { $$ = $1 + $3; }
   | exp SUB exp { $$ = $1 - $3; }
   | exp MUL exp { $$ = $1 * $3; }
   | exp DIV exp { $$ = ($3 != 0) ? $1 / $3 : 0; }
   | exp EQ exp  { $$ = ($1 == $3) ? 1 : 0; }
   | LP exp RP   { $$ = $2; }
   | function_call { $$ = $1; }             /* Allows functions inside math: x = myFunc(2) + 5; */
   | ID LSB exp RSB { $$ = 12; }             /* Allows arrays inside math: x = arr[2] + 1; (Mock value 12) */
   | NUM         { $$ = $1; }
   | ID          { $$ = 8;  }                /* Fallback mock value for variables */
   ;

%%

void yyerror(char *s) {
    printf("Parser Error: %s\n", s);
}

int main() {
    printf("--- Starting Execution ---\n");
    yyparse();
    printf("--- Finished Execution ---\n");
    return 0;
}