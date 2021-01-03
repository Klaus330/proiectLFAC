%{
#include <stdio.h>
#include<ctype.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

struct vars {
    char value[50];
    char name[50];
    char type[50];
    char scope[50];
}var[100];

int nr_var = 0;

void initializare_tip_id (char *scope, char *type, char *name){
        strcpy(var[nr_var].name,name);
        strcpy(var[nr_var].type,type);
        strcpy(var[nr_var].scope,scope);
        printf("\e[1;34m %s - %s - %s \e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope); 
        nr_var++; 
}

void initializare_id_nr (char *scope, char *type, char *name, char *value){
        strcpy(var[nr_var].name,name);
        strcpy(var[nr_var].type,type);
        strcpy(var[nr_var].scope,scope);
        strcpy(var[nr_var].value,value);
        printf("\e[1;34m %s - %s - %s - %s\e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope,var[nr_var].value); 
        nr_var++; 
}
%}
%token  ID OP PAR INTNR ARR FLOATNR DOUBLENR BOOLEAN CALL 
%token  INT FLOAT BOOL DOUBLE CHAR VOID CONST STRING STRINGVAL
%token FOR WHILE
%token IF ELSE print
%token CLASS
%token INCLUDE START_MAIN END_MAIN
%start start
%left '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%union 
{
   char* textt;
}
%type <textt> ID OP PAR ARR INT FLOAT BOOL DOUBLE CHAR VOID CONST STRING STRINGVAL tip nr

%%

start : main {printf("Program corect\n");}
       | globals main {printf("Program corect\n");}
       | globals {printf("Program corect\n");}
       ;

globals : global
        | globals global
       ;

global : declaratie_g ';'
       | asignare ';'
       ;

main : START_MAIN bloc_main END_MAIN
     ;

bloc_main : cod_main 
          | bloc_main cod_main
          ;

cod_main : declaratie_main ';'
         | asignare ';'
          ;

declaratie_g : tip ID { initializare_tip_id ("global", $1, $2); }
           | tip ID '=' nr {initializare_id_nr("global", $1, $2, $4);}
           | tip ID '=' ID
           | tip ID '=' BOOLEAN
           | tip ID '=' STRINGVAL
           ;

declaratie_main : tip ID {initializare_tip_id ("main",$1, $2); }
           | tip ID '=' nr {initializare_id_nr("main", $1, $2, $4);}
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
