main: cal.y cal.l
	bison -d cal.y
	flex cal.l
	gcc cal.tab.c lex.yy.c
	a < input1.txt > output.txt
# 	a < input2.txt >> output.txt
# 	a < input3.txt >> output.txt
# 	a < input4.txt >> output.txt
# 	a < input5.txt >> output.txt