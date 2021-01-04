%{
#include <stdio.h>
#include<ctype.h>

int yydebug = 1;

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
        strcat(var[nr_var].name,name);
        strcat(var[nr_var].type,type);
        strcat(var[nr_var].scope,scope);
        printf("\e[1;34m %s - %s - %s \e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope); 
        nr_var++; 
}

void initializare_id (char *scope, char *type, char *name, char *value){
        strcat(var[nr_var].name,name);
        strcat(var[nr_var].type,type);
        strcat(var[nr_var].scope,scope);
        strcat(var[nr_var].value,value);
        printf("\e[1;34m %s - %s - %s - %s\e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope,var[nr_var].value); 
        nr_var++; 
}
%}
%token  ID INTNR ARR FLOATNR DOUBLENR BOOLEAN AND OR NOT
%token  INT FLOAT BOOL DOUBLE CHAR VOID CONST STRING STRINGVAL 
%token FOR WHILE STRUCT
%token IF ELSE print
%token START_MAIN END_MAIN
%start start
%left '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%left '+' '-' 
%left '*' '/' 
%union 
{
   char* textt;
}
%type <textt> ID ARR INT FLOAT BOOL DOUBLE CHAR VOID STRUCT CONST STRING STRINGVAL tip nr BOOLEAN

%%

start : start global  {printf("Program corect\n");}
      | start main {printf("Program corect\n");}
      |
      ;

global : declaratie_g ';'
       | asignare ';'
       | declaratie_functie
       | CONST declaratie_g ';' {strcat(var[nr_var].type,"const ");}
       | structura
       ;

structura : STRUCT ID '{' bloc_structura '}'
          ;


bloc_structura : bloc_structura declaratie_structura ';'
                |
                ;

expresie : expresie '+' expresie
         | expresie '-' expresie
         | expresie '*' expresie
         | expresie '/' expresie
         | '(' expresie ')'
         | nr
         | ID
         | NOT ID
         | NOT BOOLEAN
         | BOOLEAN
        ;

declaratie_structura : tip ID '[' INTNR ']'
           |tip ID { initializare_tip_id ("structura", $1, $2); }
           | tip ID '=' nr {initializare_id("structura", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("structura", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("structura", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("structura", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("structura",$2, $3);}
           ;

main : START_MAIN bloc_main END_MAIN
     ;

bloc_main : bloc_main cod_main
          |
          ;

cod_main : declaratie_main ';'
         | asignare ';'
         | statements
         | apel
         | CONST declaratie_main ';' {strcat(var[nr_var].type,"const ");}
         ;

apel : ID '(' ')' ';'
     | ID '(' parametri_apel ')' ';'
     | '_' ID '(' ')' 
     ;


parametri_apel :  ID 
               | ID '#' parametri_apel
               | nr 
               | nr '#' parametri_apel
               | apel 
               | apel '#' parametri_apel
               | 
                ;


statements : ifstatement 
           | forstatement
           | whilestatement
           ;

ifstatement : IF '(' conditie ')' '{' cod_bloc '}'
            | IF '(' conditie ')' '{' cod_bloc '}' ELSE '{' cod_bloc '}'
            ;

forstatement : FOR '(' asignare_for ',' conditie ',' operatie ')' '{' cod_bloc '}'
             ;

whilestatement : WHILE '(' conditie ')' '{' cod_bloc '}'
                ;

conditie : term GE term
         | term LE term
         | term EQ term
         | term NE term
         | term GT term
         | term LT term
         ;

term : ID
      | nr
      | '(' expresie ')'
      ;

asignare_for : declaratii_locale
              | asignare
              ;

operatie :
         ;

cod_bloc : cod_bloc instructiune_bloc
         |
         ;
 
instructiune_bloc : declaratii_locale ';'
                  | statements
                  | CONST declaratii_locale ';' {strcat(var[nr_var].type,"const ");}
                  | apel
                  | asignare ';'
                  |
                  ;

declaratii_locale :  tip ID '[' INTNR ']'
           |tip ID { initializare_tip_id ("local", $1, $2); }
           | tip ID '=' nr {initializare_id("local", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("local", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("local", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("local", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("local",$2, $3);}
           ;

declaratie_g :tip ID '[' INTNR ']'
            |tip ID { initializare_tip_id ("global", $1, $2); }
           | tip ID '=' nr {initializare_id("global", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("global", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("global", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("global", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("global",$2, $3);}
            ;

declaratie_main : tip ID {initializare_tip_id ("main",$1, $2); }
           | tip ID '=' nr {initializare_id("main", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("main", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("main", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("main", $1, $2, $4);}
           |  tip ID '[' INTNR ']' 
           | STRUCT ID ID  {initializare_tip_id("main",$2, $3);}
            ;

declaratie_functie : tip ID '(' params ')' '{' bloc_functie '}'
                   | tip ID '(' ')' '{' bloc_functie '}'
                   ;

params : param
          | params '#' param
          ;

param : tip ID
    | expresie
    ;

vec : tip ID '[' INTNR ']'
    ;

bloc_functie :  bloc_functie cod_functie
              |
              ;

cod_functie : declaratie_var_f ';'
            // | CONST declaractie_var_f ';' {strcat(var[nr_var].type,"const ");}
            | asignare ';'
            ;

declaratie_var_f : tip ID {initializare_tip_id ("functie",$1, $2); }
           | tip ID '=' nr {initializare_id("functie", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("functie", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("functie", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("functie", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("functie",$2, $3);}
           ;

asignare : ID '=' ID
         | ID '=' nr
         | ID '=' STRINGVAL
         | ID '=' BOOLEAN
         | asignare_structura
         | ID
         | nr
         | STRINGVAL
         | BOOLEAN
         | ID '=' expresie
         | expresie
         | STRUCT ID ID
         ;

asignare_structura : ID '.' ID '=' asignare
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
    FILE *f = fopen("symbols.txt","w");
   if(!yyparse())
        printf("\nParsing complete\n");
    else
        printf("\nParsing failed\n");
    fprintf(f, "Variabile declarate :\n");
    for(int i=0; i<nr_var; ++i){
        if(var[i].value){
            fprintf(f, " %s - %s - %s - %s\n", var[i].type, var[i].name, var[i].scope,var[i].value); 
        }
else
 fprintf(f,"%s - %s - %s\n", var[i].type, var[i].name, var[i].scope); 
    
    }

    fclose(yyin);
    return 0;
}
