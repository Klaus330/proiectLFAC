%{
#include<stdio.h>
#include "y.tab.h"
%}
%option noyywrap
cifra           [0-9]
numar           [1-9]{cifra}+|{cifra}
operator        [+*&/<>-]
semn            [+-]
litera          [a-zA-Z]
spatiu          ['\t'' ']
float_num       {numar}\.{cifra}+f
double_num      {numar}\.{cifra}+
array           {litera}+\[{numar}\]
identifier      {litera}+{cifra}*
bool            true|false
string_val      ["]([^"\\\n]|\\.|\\\n)*["] 
%%

"if"       {printf("%s cuvant rezervat\n",yytext); return IF;}
"else"     {printf("%s cuvant rezervat\n",yytext); return ELSE;}
"while"    {printf("%s cuvant rezervat\n",yytext); return WHILE;} 
"class"    {printf("%s cuvant rezervat\n",yytext); return CLASS;} 
\#include. {printf("%s cuvant rezervat\n",yytext); return INCLUDE;}
"print"    {return print;}
"start_main" {printf ("Am intrat in main %s\n",yytext); return START_MAIN;}
"end_main" {return END_MAIN;}

"int"    {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return INT;}
"float"  {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return FLOAT;}
"double" {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return DOUBLE;}
"string" {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return STRING;};
"char"   {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return CHAR;}
"bool"   {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return BOOL;}
"const"  {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return CONST;}
"void"   {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return VOID;}
"<="     {return LE;}
"=>"     {return GE;}
"=="     {return EQ;}
"!="     {return NE;}
"<"      {return GT;}
">"      {return LT;}


{bool}             {printf("%s bool\n",yytext); yylval.textt = strdup(yytext); return BOOLEAN;}
{identifier}       {printf("%s identificator\n",yytext); yylval.textt = strdup(yytext); return ID;}
{operator}         {printf("%s operator\n",yytext); return OP;}
{numar}            {printf("%s numar intreg\n",yytext);yylval.textt = strdup(yytext); return INTNR;}
{array}            {printf("%s array\n",yytext); yylval.textt = strdup(yytext); return ARR;}
{float_num}        {printf("%s float number\n",yytext); yylval.textt = strdup(yytext); return FLOATNR;}
{double_num}       {printf("%s double number\n",yytext); yylval.textt = strdup(yytext); return DOUBLENR;}
\-{numar}          {printf("%s numar negativ\n",yytext);}
{string_val}       {printf("%s string value\n",yytext); yylval.textt = strdup(yytext); return STRINGVAL;}

{spatiu} ;
[\n] {yylineno++;}
.    {printf("%s\n",yytext);
        return yytext[0];}
%%
