%{
    // definition  
%}

%%
    /* // 01[3-9][0-9]{8} {printf("Valid Mobile Number");}  */
[0-9]*|[0-9]*.[0-9]*+ {printf("valid Number");}
[a-z_A-Z_._0-9]* {}
%%

int yywrap()
{

}

int main()
{
    // built-in function
    yylex();
    return 0;
}