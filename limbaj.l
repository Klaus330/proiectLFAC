%{
#include<stdio.h>
#include "y.tab.h"
%}
%option noyywrap
cifra [0-9]
numar[1-9]{cifra}+|{cifra}
operator [+=*&/<>-]
comentariu //
semn [+-]
litera [a-zA-Z]
spatiu ['\t'' ']
float_num {numar}\.{cifra}+f
double_num {numar}\.{cifra}+
array {litera}+\[{numar}\]
identifier {litera}+{cifra}*
function {identifier}\(\)\{.\}
function_call {identifier}\(\)

bool [true|false]
%%

"if" {printf("%s cuvant rezervat\n",yytext);}
"else" {printf("%s cuvant rezervat\n",yytext);}
"while" {printf("%s cuvant rezervat\n",yytext);} 
"switch" {printf("%s cuvant rezervat\n",yytext);} 
"return" {printf("%s cuvant rezervat\n",yytext);} 
"break" {printf("%s cuvant rezervat\n",yytext);} 
"class" {printf("%s cuvant rezervat\n",yytext);} 
"#include" {printf("%s cuvant rezervat\n",yytext);}

"int" {printf("%s tip\n",yytext); return INT;}
"float" {printf("%s tip\n",yytext); return FLOAT;}
"double" {printf("%s tip\n",yytext); return DOUBLE;}
"char" {printf("%s tip\n",yytext); return CHAR;}
"bool" {printf("%s tip\n",yytext); return BOOL;}

{function}  {printf("%s function\n",yytext);}
{identifier} {printf("%s identificator\n",yytext); return ID;}
{operator} {printf("%s operator\n",yytext); return OP;}
\:\= {printf("%s asignare\n",yytext); return ASIGN;}
(\()|(\)) {printf("%s paranteze\n",yytext); return PAR;}
{numar}   {printf("%s numar intreg\n",yytext); return INTNR;}
{array} {printf("%s array\n",yytext); return ARR;}
{float_num} {printf("%s float number\n",yytext); return FLOATNR;}
{double_num} {printf("%s double number\n",yytext); return DOUBLENR;}
{bool} {printf("%s bool\n",yytext); return BOOLEAN;}
{function_call} {printf("%s function call\n",yytext); return CALL;}
\-{numar} {printf("%s numar negativ\n",yytext);}


\n {yylineno++;}
. {printf("%s caracter ilegal\n",yytext);}
%%
