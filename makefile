lex limbaj.l
yacc -d limbaj.y
gcc lex.yy.c y.tab.c -o out -w
./out program.txt
