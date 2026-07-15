%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    int yylex();
    
    /* --- MINIMAL SYMBOL TABLE (MEMORY) --- */
    char sym_names[100][50]; // Stores up to 100 variable names
    int sym_values[100];     // Stores their values
    int sym_count = 0;

    /* Function to retrieve a variable's value */
    int get_variable(char* name) {
        for(int i = 0; i < sym_count; i++) {
            if(strcmp(sym_names[i], name) == 0) {
                return sym_values[i];
            }
        }
        return 0; // If variable isn't found, default to 0
    }

    /* Function to save a variable's value */
    void set_variable(char* name, int val) {
        // Check if it already exists to update it
        for(int i = 0; i < sym_count; i++) {
            if(strcmp(sym_names[i], name) == 0) {
                sym_values[i] = val;
                return;
            }
        }
        // Otherwise, save as a new variable
        strcpy(sym_names[sym_count], name);
        sym_values[sym_count] = val;
        sym_count++;
    }
%}

/* --- ADDED: %union to handle strings and ints correctly --- */
%union {
    int ival;
    char* sval;
}

%token INT FLOAT FOR WHILE IF ELSE RETURN STRUCT VOID COLON PRINTF
%token LP RP LC RC LS RS
%token ADD SUB MUL DIV MOD NE AND OR NOT 
%token ASSIGN EQU SEMI GT LT GE LE COMMA QUES

/* --- ADDED: Connect tokens to their union types --- */
%token <sval> ID STRING_LITERAL
%token <ival> NUM FLOAT_NUM
%type <ival> exp

/* Precidence Rule Low to High*/
%right ASSIGN QUES COLON            
%left OR                  
%left AND                 
%left EQU NE             
%left LT LE GT GE         
%left ADD SUB            
%left MUL DIV             
%right NOT                                

%%
BLOCK: statements ;

statements: statements statement
          | 
          ;
statement:
      declaration
    | assignment
    | arr_declaration
    | arr_assignment
    | if_structure
    | loop_structure
    | func
    | return_stmt
    | func_call_direct
    | print_stmt
    ;
    
print_stmt:             
        PRINTF LP exp RP SEMI { printf("OUTPUT-> %d \n",$3);}
        ;

declaration:
      type ID ASSIGN exp SEMI    
      { 
          set_variable($2, $4); /* <--- ADDED: Save to memory */
          printf("Declaration (Initial Value = %d)\n", $4);
      }
    ;

assignment:
      ID ASSIGN exp SEMI        
      { 
          set_variable($1, $3); /* <--- ADDED: Update memory */
          printf("Assignment (Value = %d)\n", $3);
      }
    ;

arr_declaration:
        type ID LS exp RS ASSIGN LC arrlist RC SEMI
        {
            printf("Recognized an array declaration\n");
        }
        ;
arrlist:
        arrelements 
        | {printf("Reduced blank arrlist\n");}
        ;

arrelements:
        arrelements COMMA NUM {printf("Reduced recursive arrlist\n");}
        | NUM {printf("Reduced num arrlist\n");}
        ;

arr_assignment:
        ID LS exp RS ASSIGN exp SEMI
        {
            printf("array assignment at position %d = %d\n", $3, $6); 
        }
        ;

if_structure:
      IF LP exp RP LC statements RC ELSE LC statements RC
      {
          printf("IF-ELSE block.\n");
      }
    | IF LP exp RP LC statements RC
      {
          printf("Only-IF block.\n");
      }
    ;

loop_structure:
      WHILE LP exp RP LC statements RC
      {
          printf("WHILE loop.\n");
      }
    | FOR LP type ID ASSIGN exp SEMI exp SEMI ID ASSIGN exp RP LC statements RC
      {
          printf("FOR loop.\n");
      }
    ;

func_call_direct:
        ID LP arglist RP SEMI {printf("Recognized an direct function call\n");}
        ;

return_stmt:
        RETURN ID SEMI {printf("Returned %d\n", get_variable($2));}  
        | RETURN NUM SEMI {printf("Returned %d\n", $2);}
        ;


func: 
        type ID LP arglist RP LC statements RC {printf("Parsed a function");}
        ;

arglist:
      arg_elements
    | /* empty */
    ;

arg_elements:
      arg_elements COMMA exp
    | exp
    ;

type: INT
    | FLOAT
        ;

exp: exp ADD exp { $$ = $1 + $3; }
   | exp SUB exp { $$ = $1 - $3; }
   | exp MUL exp { $$ = $1 * $3; }
   | exp MOD exp { $$ = ($3 != 0) ? $1 % $3 : 0; }
   | exp DIV exp { $$ = ($3 != 0) ? $1 / $3 : 0; }
   | exp EQU exp  { $$ = ($1 == $3) ? 1 : 0; }
   | exp NE exp   { $$ = ($1 != $3) ? 1 : 0; }
   | exp GT exp   { $$ = ($1 > $3) ? 1 : 0; }
   | exp LT exp   { $$ = ($1 < $3) ? 1 : 0; }
   | exp GE exp   { $$ = ($1 >= $3) ? 1 : 0; }
   | exp LE exp   { $$ = ($1 <= $3) ? 1 : 0; }
   | exp AND exp  { $$ = ($1 && $3) ? 1 : 0; }
   | exp OR exp   { $$ = ($1 || $3) ? 1 : 0; }
   | NOT exp      { $$ = (!$2) ? 1 : 0; }
   | LP exp RP   { $$ = $2; }
   | exp QUES exp COLON exp { $$ = ($1) ? $3 : $5; }
   | ID LP arglist RP { $$ = 0;}
   | FLOAT_NUM   { $$ = $1; }
   | NUM         { $$ = $1; }
   | ID          { $$ = get_variable($1);  }
   | STRING_LITERAL { printf("String literal: %s\n", $1); $$ = 0; }
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