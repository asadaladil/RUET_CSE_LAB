%{
    #include <stdio.h>
    #include <stdlib.h>

    #define YYSTYPE int

    void yyerror(char *s);
    int yylex();
%}

%token INT ID NUM ASSIGN SEMI LP RP LB RB ADD SUB MUL DIV
%token IF ELSE WHILE FOR EQ

/* Precedence rules for arithmetic and basic comparison */
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
    ;

declaration:
      INT ID ASSIGN exp SEMI    
      { 
          printf("[Parse] Variable Declaration (Initial Value = %d)\n", $4);
      }
    ;

assignment:
      ID ASSIGN exp SEMI        
      { 
          printf("[Parse] Variable Assignment (Value = %d)\n", $3);
      }
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
   | NUM         { $$ = $1; }
   | ID          { $$ = 8;  } /* Fallback mock value for variables */
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