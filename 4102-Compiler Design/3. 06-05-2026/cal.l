%option noyywrap
%{

%}

%{
    // definition
    #include "cal.tab.h"
%}

digit [0-9]
number {digit}+
sp [ \n\t]
ws {sp}+
ltr [A-Za-z]
us [_]
id ({us}|{ltr})({us}|{ltr}|{digit})*


%%
    /* {ws} { }
    {number} {printf("%s Num\n",yytext);}
    "+" {printf("%s Sum\n",yytext);} */
    /* {ws} { }
    {number} {return(NUM);}
    "+" {return(SUM);}
    "-" {return(SUB);} */
{ws} { }
"int" {return(KEY);}
{id} {return(VAR);}
"=" {return(ASSIGN);}
{number} {return(NUM);}
";" {return(SEMICOLON);}
%%


/* int main()
{
    // built-in function
    yylex();
    return 0;
} */