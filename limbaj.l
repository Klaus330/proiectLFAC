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

"if"       {return IF;}
"else"     {return ELSE;}
"while"    {return WHILE;} 
"print"    {return print;}
"start_main" {return START_MAIN;}
"end_main" {return END_MAIN;}
"Eval"     {return EVAL;}
"for"      {return FOR;}

"int"    {yylval.textt = strdup(yytext); return INT;}
"float"  {yylval.textt = strdup(yytext); return FLOAT;}
"double" {yylval.textt = strdup(yytext); return DOUBLE;}
"string" {yylval.textt = strdup(yytext); return STRING;};
"char"   {yylval.textt = strdup(yytext); return CHAR;}
"bool"   {yylval.textt = strdup(yytext); return BOOL;}
"const"  {yylval.textt = strdup(yytext); return CONST;}
"void"   {yylval.textt = strdup(yytext); return VOID;}
"struct" {yylval.textt = strdup(yytext); return STRUCT;}
"<="     {return LE;}
"=>"     {return GE;}
"=="     {return EQ;}
"!="     {return NE;}
"<"      {return GT;}
">"      {return LT;}
"&&"     {return AND;}
"||"     {return OR;}
"!"      {return  NOT;}

{bool}             { yylval.textt = strdup(yytext); return BOOLEAN;}
{identifier}       { yylval.textt = strdup(yytext); return ID;}
{numar}            {yylval.textt = strdup(yytext); return INTNR;}
{float_num}        { yylval.textt = strdup(yytext); return FLOATNR;}
{double_num}       { yylval.textt = strdup(yytext); return DOUBLENR;}
{string_val}       {  yylval.textt = strdup(yytext); return STRINGVAL;}

{spatiu} ;
[\n] {yylineno++;}
.    {
        return yytext[0];}
%%
