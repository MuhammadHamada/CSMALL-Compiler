del csmall.tab.h
del lex.yy.c
del csmall-parser.tab.c
del y.tab.h
del csmall.exe
flex csmall-scanner.l
bison -d csmall-parser.y
rename csmall-parser.tab.h y.tab.h
g++ -o csmall.exe csmall-parser.tab.c lex.yy.c


