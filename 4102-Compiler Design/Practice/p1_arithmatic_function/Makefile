all:
	bison -Wcounterexamples -d parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c -o compiler
	./compiler < input.txt > output.txt