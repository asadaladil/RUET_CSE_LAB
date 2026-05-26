%{
// Declaration

%}

digit [0-9]
letter [a-zA-Z]
string ({letter})+

%%

{string} | ({string}" "{string})* {printf("String\n");}
{digit}*("1"|"3"|"5"|"7"|"9") {printf("Odd\n");}
{digit}*("2"|"4"|"6"|"8"|"0") {printf("Even\n");}

%%

int yywrap()
{

}

int main()
{
    yylex();
    return 0;
}

