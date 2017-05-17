#!/bin/bash
rm *.yy.c *.tab.c *.tab.h
flex plp5.l
bison -d plp5_Marcos.y
g++ -o plp5 plp5.tab.c lex.yy.c
