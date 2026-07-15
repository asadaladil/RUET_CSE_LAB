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

%token MAIN SHURU OF TYPE INT JOTOKKHON PRINT UNIT INCREASE SHESH
%token LP RP ASSIGN LT ADD DIV SUB MUL NUM ID STRING_LITERAL



%%

Program: MAIN SHURU statements MAIN SHESH
        ;

statements: statements statement
        |
        ;

statement: ID ASSIGN NUM OF TYPE INT
        | JOTOKKHON ID LT NUM
        | PRINT ASSIGN STRING_LITERAL
        | ID OF TYPE INT ASSIGN exp { printf("Result-> %d\n", $6);}
        | UNIT INCREASE NUM
        ;

exp:  exp ADD exp { $$=$1+$3; }
    | exp SUB exp { $$=$1-$3; }
    | exp MUL exp { $$=$1*$3; }
    | exp DIV exp { $$=$1/$3; }
    | LP exp RP { $$=$2; }
    | NUM { $$= $1; }

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
