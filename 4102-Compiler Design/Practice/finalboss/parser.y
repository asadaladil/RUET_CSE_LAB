%{
    #include <stdio.h>
    #include <stdlib.h>

    #define YYSTYPE int

    void yyerror(const char *s);
    int yylex();

    extern char* yytext;
%}

%define parse.error verbose

%token INT ID NUM ASSIGN SEMI LP RP LB RB ADD SUB MUL DIV FLOAT RET
%token IF ELSE WHILE FOR EQ LTB RTB COMMA

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
    | arr_declaration
    | arr_assignment
    | if_structure
    | loop_structure
    | func
    | return_stmt
    | func_call_direct
    ;

func_call_direct:
        ID LP arglist RP SEMI {printf("Recognized an direct function call\n");}
        ;

return_stmt:
        RET ID SEMI {printf("Returned %d\n", $2);}  //tokenize RET
        | RET NUM SEMI {printf("Returned %d\n", $2);}

type: 
        INT
        | FLOAT {printf("AHA GOT A FLOAT");}
        ;


declaration:
      type ID ASSIGN exp SEMI    
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

arr_declaration:
        type ID LTB exp RTB ASSIGN LB arrlist RB SEMI
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
        ID LTB exp RTB ASSIGN exp SEMI
        {
            printf("array assignment at position %d = %d\n", $3, $6); 
        }
        ;

func: 
        type ID LP arglist RP LB statements RB {printf("Parsed a function");}
        ;

/*
arglist: 
        arglist COMMA ID 
        | arglist COMMA NUM
        | arglist COMMA exp
        |
        ;
        // dont write  ID | NUM| exp here, bison won't know to go through recursion and eventually to blank case or directly through them
    // BUT NOW HOW DO YOU parse the very first argument which can be a ID, NUM or exp?
    // also isn't ID, NUM, exp just exp??
*/

/*
arglist:
    arglist COMMA exp
    | exp
    |
    ;
    // reduce reduce conflict
*/

// seperate void from non-void
arglist:
      arg_elements
    | /* empty */
    ;

arg_elements:
      arg_elements COMMA exp
    | exp
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
    | FOR LP type ID ASSIGN exp SEMI exp SEMI ID ASSIGN exp RP LB statements RB
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
   | ID LP arglist RP { $$ = 0;}
   | NUM         { $$ = $1; }
   | ID          { $$ = 8;  } /* Fallback mock value for variables */
   ;

%%

void yyerror(const char *s) {
    printf("\n[Parser Error] %s at or near the token: '%s'\n", s, yytext);
}

int main() {
    printf("--- Starting Execution ---\n");
    yyparse();
    printf("--- Finished Execution ---\n");
    return 0;
}