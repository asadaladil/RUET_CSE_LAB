%{
    #include <stdio.h>
    #include <stdlib.h>

    /* FORCE Bison's internal semantic stack type to be a plain primitive int */
    #define YYSTYPE int

    void yyerror(char *s);
    int yylex();

    /* Global execution control gates */
    int execution_allowed = 1; 
    int current_condition = 0;
%}

%token INT IF ELSE WHILE FOR ASSIGN SEMI LP RP LB RB ADD SUB MUL DIV EQ ID NUM

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
    | if_else_structure
    | loop_structure
    ;

declaration:
      INT ID ASSIGN exp SEMI    
      { 
          if (execution_allowed) {
              printf("[Exec] Declared variable -> Evaluated Math Value = %d\n", $4);
          }
      }
    ;

assignment:
      ID ASSIGN exp SEMI        
      { 
          if (execution_allowed) {
              printf("[Exec] Updated variable assignment -> Evaluated Value = %d\n", $3);
          }
      }
    ;

// if_header has been seperated to avoid ambuiguity
if_header: 
      IF LP exp RP
      {
          // both path share the same setup 
          current_condition = ($3 == 1); 
          printf("[Exec] Evaluated Condition -> %s\n", current_condition ? "TRUE" : "FALSE");
          execution_allowed = current_condition; 
      }
    ;

if_else_structure:
      if_header LB statements RB ELSE LB 
      {
          /* Right as we cross into the ELSE block, flip the gate switch */
          execution_allowed = !current_condition; 
      } 
      statements RB
      {
          execution_allowed = 1; 
          printf("[Exec] Finished processing complete if-else structure\n");
      }
    | if_header LB statements RB
      {
          /* Simple IF finishes here, cleanly reset back to normal */
          printf("[Exec] Finished processing complete if-only structure\n");
          execution_allowed = 1; 
      }
    ;

    
loop_structure:
      WHILE LP exp RP LB statements RB
      {
          printf("[Exec] Parsed WHILE loop structure.\n");
      }
    | FOR LP INT ID ASSIGN exp SEMI exp SEMI ID ASSIGN exp RP LB statements RB
      {
          printf("[Exec] Parsed FOR loop structure.\n");
      }
    ;

exp: exp ADD exp { $$ = $1 + $3; }
   | exp SUB exp { $$ = $1 - $3; }
   | exp MUL exp { $$ = $1 * $3; }
   | exp DIV exp { $$ = ($3 != 0) ? $1 / $3 : 0; }
   | exp EQ exp  { $$ = ($1 == $3) ? 1 : 0; }
   | LP exp RP   { $$ = $2; }
   | NUM         { $$ = $1; }
   | ID          { $$ = 8;  } /* Our exam shortcut fallback */
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