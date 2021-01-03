%{
#include <stdio.h>
#include<ctype.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID OP PAR INTNR ARR FLOATNR DOUBLENR BOOLEAN CALL 
%token INT FLOAT BOOL DOUBLE CHAR VOID CONST STRING STRINGVAL
%token FOR WHILE
%token IF ELSE print
%token CLASS
%token INCLUDE START_MAIN END_MAIN
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
       | asignare ';'
       ;

main : START_MAIN bloc_main END_MAIN
     ;

bloc_main : cod_main 
          | bloc_main cod_main
          ;

cod_main : declaratie ';'
         | asignare ';'
          ;


declaratie : tip ID
           | tip ID '=' nr
           | tip ID '=' ID
           | tip ID '=' BOOLEAN
           | tip ID '=' STRINGVAL
           ;

asignare : ID '=' ID
         | ID '=' nr
         | ID '=' STRINGVAL
         | ID '=' BOOLEAN
         ;


tip : INT {$$ = "int";} 
    | FLOAT {$$ = "float";}
    | BOOL {$$ = "bool";}
    | DOUBLE {$$ = "double";}
    | CHAR {$$ = "char";}
    | VOID {$$ = "void";}
    | STRING {$$ = "string";}
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
