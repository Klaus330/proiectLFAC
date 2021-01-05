%{
#include<stdio.h>
#include "y.tab.h"
%}
%option noyywrap
cifra           [0-9]
numar           [1-9]{cifra}+|{cifra}
semn            [+-]
litera          [a-zA-Z]
spatiu          ['\t'' ']
float_num       {numar}\.{cifra}+f
double_num      {numar}\.{cifra}+
identifier      {litera}+{cifra}*
bool            true|false
string_val      ["]([^"\\\n]|\\.|\\\n)*["] 
%%

"if"       {printf("%s cuvant rezervat\n",yytext); return IF;}
"else"     {printf("%s cuvant rezervat\n",yytext); return ELSE;}
"while"    {printf("%s cuvant rezervat\n",yytext); return WHILE;} 
"print"    {return print;}
"start_main" {printf ("Am intrat in main %s\n",yytext); return START_MAIN;}
"end_main" {return END_MAIN;}
"Eval"     {return EVAL;}
"for"      {return FOR;}

"int"    {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return INT;}
"float"  {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return FLOAT;}
"double" {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return DOUBLE;}
"string" {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return STRING;};
"char"   {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return CHAR;}
"bool"   {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return BOOL;}
"const"  {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return CONST;}
"void"   {printf("%s tip\n",yytext); yylval.textt = strdup(yytext); return VOID;}
"struct" {printf("%s structura\n",yytext); yylval.textt = strdup(yytext); return STRUCT;}
"<="     {return LE;}
"=>"     {return GE;}
"=="     {return EQ;}
"!="     {return NE;}
"<"      {return GT;}
">"      {return LT;}
"&&"     {return AND;}
"||"     {return OR;}
"!"      {return  NOT;}

{bool}             {printf("%s bool\n",yytext); yylval.textt = strdup(yytext); return BOOLEAN;}
{identifier}       {printf("%s identificator\n",yytext); yylval.textt = strdup(yytext); return ID;}
{numar}            {printf("%s numar intreg\n",yytext);yylval.textt = strdup(yytext); return INTNR;}
{float_num}        {printf("%s float number\n",yytext); yylval.textt = strdup(yytext); return FLOATNR;}
{double_num}       {printf("%s double number\n",yytext); yylval.textt = strdup(yytext); return DOUBLENR;}
\-{numar}          {printf("%s numar negativ\n",yytext);}
{string_val}       {printf("%s string value\n",yytext); yylval.textt = strdup(yytext); return STRINGVAL;}

{spatiu} ;
[\n] {yylineno++;}
.    {printf("%s\n",yytext);
        return yytext[0];}
%%
