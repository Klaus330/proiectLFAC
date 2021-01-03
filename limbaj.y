%{
#include <stdio.h>
#include<ctype.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID OP PAR INTNR ARR FLOATNR DOUBLENR BOOLEAN CALL INT FLOAT BOOL DOUBLE CHAR VOID CONST
%token FOR WHILE
%token IF ELSE print
%token CLASS
%token INCLUDE
%start start
%left '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%%

start : main {printf("Program corect\n");}
       | globals main {printf("Program corect\n");}
       | globals {printf("Program corect\n");}
       ;

globals : global
        | globals global
       ;

global : declaratie ';'
       ;

main : declaratie ';'
     ;


declaratie : tip ID
           | tip ID '=' nr
           ;


tip : INT {$$ = "int";} 
    | FLOAT {$$ = "float";}
    | BOOL {$$ = "bool";}
    | DOUBLE {$$ = "double";}
    | CHAR {$$ = "char";}
    | VOID {$$ = "void";}
    ;

nr : INTNR
    | FLOATNR
    | DOUBLENR
    ;

%%
int count=0;
yyerror(char *s) {
    printf("%d : %s %s\n", yylineno, s, yytext );
}

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");

   if(!yyparse())
        printf("\nParsing complete\n");
    else
        printf("\nParsing failed\n");

    fclose(yyin);
    return 0;
}
