main: cal.y cal.l
	bison -d cal.y
	flex cal.l
	gcc cal.tab.c lex.yy.c
	a < input2.txt > output.txt