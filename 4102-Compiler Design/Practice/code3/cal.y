%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    int yylex();

    /* Symbol Table (memory) */
    char sym_names[100][50]; // store 100 variables
    int sym_values[100];
    int sym_count = 0;
    int temp_arr[100];
    int idx = 0;

    /* Get the variable */
    int get_variable(char* name) {
        for(int i = 0; i < sym_count; i++) {
            if(strcmp(sym_names[i], name) == 0) {
                return sym_values[i];
            }
        }
        return 0; // in not found case
    }

    /* set a new variable */
    void set_variable(char* name, int val) {
        // First check already prsent or not
        for(int i = 0; i < sym_count; i++) {
            if(strcmp(sym_names[i], name) == 0) {
                sym_values[i] = val;
                return;
            }
        }
        // O/W add new variable
        strcpy(sym_names[sym_count], name);
        sym_values[sym_count] = val;
        sym_count++;
    }

%}

%union {
    int ival;
    char* sval;
}

%token INT FOR IF ELSE PRINT INC DEC START END KEY RETURN LS RS COMMA FLOAT WHILE
%token LP RP LC RC ADD SUB MUL DIV MOD ASSIGN EQU SEMI LT GT LE GE NE


%token <sval> ID STRING_LITERAL
%token <ival> NUM 
%type <ival> exp
%type <ival> arrlist  update

/* Precidence Rule Low to High*/
%right ASSIGN             
%left EQU NE             
%left LT LE GT GE         
%left ADD SUB            
%left MUL DIV MOD
%left INC DEC   


%%
program: START statements END
    ;

statements: statements statement
          | 
          ;
statement: KEY ID LP RP LC statements RC { set_variable($2, 0); }
         | RETURN exp SEMI { printf("Return value: %d\n", $2); }
         | INT ID SEMI
         | ID LS exp RS ASSIGN exp SEMI 
         {
            char temp_name[60];
            sprintf(temp_name, "%s[%d]", $1, $3);
            set_variable(temp_name, $6);       
            printf("Updated %s to %d\n", temp_name, $6);
         }
         | INT ID LP RP LC statements RC
         | exp SEMI
         | FLOAT ID LP ID COMMA ID COMMA NUM RP LC statements RC
         | INT ID LS exp RS SEMI { set_variable($2, $4); }
         | INT ID LS exp RS ASSIGN LC arrlist RC SEMI { set_variable($2, $8); }
         | ID ASSIGN exp SEMI { set_variable($1, $3); }
         | INT ID ASSIGN exp SEMI { set_variable($2, $4); }
         | PRINT LP exp RP SEMI { printf("Output-> %d\n", $3); }
         | IF LP exp RP LC statements RC
         | IF LP exp RP LC statements RC ELSE LC statements RC
         | FOR LP statement exp SEMI update RP LC statements RC
         | WHILE LP exp RP LC statements RC
         | PRINT LP STRING_LITERAL RP SEMI { printf("String literal-> %s\n", $3); }
         ;
update: exp { $$ = $1; }
      | ID ASSIGN exp { set_variable($1, $3); $$ = $3; }
      ;

func_call:ID LP NUM COMMA NUM COMMA NUM RP
        ;

arrlist: arrlist COMMA exp { temp_arr[idx++] = $3; }
       | exp { idx = 0; temp_arr[idx++] = $1; }
       ;

exp: exp ADD exp { $$ = $1 + $3;}
    | exp SUB exp { $$ = $1 - $3;}
    | exp MUL exp { $$ = $1 * $3;}
    | exp DIV exp  { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    | exp MOD exp { 
        if ($3 == 0) {
            yyerror("Modulo by zero");
            $$ = 0;
        } else {
            $$ = $1 % $3;
        }
        }
    | func_call
    | exp EQU exp { $$ = $1 == $3; }
    | exp NE exp { $$ = $1 != $3; }
    | exp LT exp { $$ = $1 < $3; }
    | exp LE exp { $$ = $1 <= $3; }
    | exp GT exp { $$ = $1 > $3; }
    | exp GE exp { $$ = $1 >= $3; }
    | ID LP RP { $$ = get_variable($1); }
    | ID LS exp RS { $$ = get_variable($1); } 
    | ID INC { $$ = get_variable($1) + 1; set_variable($1, $$); }
    | ID DEC { $$ = get_variable($1) - 1; set_variable($1, $$); }
    | LP exp RP { $$ = $2; }
    | NUM { $$ = $1; }
    | ID  { $$ = get_variable($1);  }
    | STRING_LITERAL { printf("String literal: %s\n", $1); $$ = 0; }
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
