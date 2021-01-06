%{
#include <stdio.h>
#include<ctype.h>

int yydebug = 1;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
char params_list[200];

struct vars {
    char value[70];
    char name[70];
    char type[70];
    char scope[70];
    int valoare_int;
    float valoare_float;
}var[100];

struct functions {
    char name[80];
    char type[80];
    char params[200];
}fun[100];


int nr_var = 0;
int nr_functii = 0;

int checkIfAlreadyExists(char *nume){
    int found=0, index;
    for(int i=0; i<=nr_var; i++){
        if(strcmp(var[i].name,nume)==0){
            found=1;
            index=i;
            
        }
    }

    if(found==0){
        perror("\e[1;33m Eroare: nu exista nicio variabila cu acest nume\e[0m \n");
        exit(1);
    }

    return index;
}

int getIndexIfIndentifier(char *id){
    int found=0, index=-1;
    for(int i=0; i<=nr_var; i++){
        if(strcmp(var[i].name,id)==0){
            found=1;
            index=i;
            
        }
    }
    return index;
}

void asignare(char *nume, char *valoare){
    
    int index = checkIfAlreadyExists(nume);
    int idIndex = -1;
    idIndex =  getIndexIfIndentifier(valoare);
    if(idIndex !=-1){
        
        strcpy(var[index].value,var[idIndex].value);
        printf("\n%s %s\n",var[idIndex].type,var[index].type );
        if(strstr(var[idIndex].type,var[index].type)==0){
           perror("\e[1;33m Eroare: variabilele nu au acelasi tip\e[0m \n");
           exit(1);     
        }

        if(strstr(var[index].type,"int"))
        {   
            var[index].valoare_int = atoi(var[idIndex].value);
        }
        if (strstr(var[index].type,"float")){
            var[index].valoare_float = atof(var[idIndex].value);
        }

        if( strstr(var[index].type,"double")){
            var[index].valoare_float = atof(var[idIndex].value);
        }
    }else{

        printf("\n%d %s %s\n",index, var[index].type,valoare);
        strcpy(var[index].value,valoare);
        if(strstr(var[index].type,"int"))
        {   var[index].valoare_int = atoi(valoare);
        }
        if (strstr(var[index].type,"float")){
            var[index].valoare_float = atof(valoare);
        }

        if( strstr(var[index].type,"double")){
            var[index].valoare_float = atof(valoare);
        }
    }
}

int evaluare_id(char* id, char *scope){
    int index = checkIfAlreadyExists(id);

    printf("Am id-ul %s scopul %s \n",id,scope);
    if(strcmp(scope,"eval") ==0 ){
        if(strstr(var[index].type,"int")){
          
            return atoi(var[index].value);
        }
        else{
            perror("\e[1;33m Eroare: toti parametrii pentru functia Eval trebuie sa fie de tip int\e[0m \n");
            exit(1);
        }
    }

   if(strstr(var[index].type,"int")){
        return atoi(var[index].value);
   }else if (strstr(var[index].type,"float") || strstr(var[index].type,"double") ){
       return atof(var[index].value);
   }
  
}
void checkIfIsInScope(char *scope, char *name){
    for(int i=0 ; i<nr_var;++i)
    {
        if(strcmp(var[i].name,name) == 0 && strcmp(var[i].scope,scope)==0){
            perror("\e[1;33m Eroare: nu pot exista doua variabile identice \e[0m \n");
            exit(1);
        }
    }
}

void checkIfFunctionExists(char *name){
    int found = 0 ;
    for(int i=0; i<nr_functii; ++i){
        if(strcmp(fun[i].name,name) == 0)
        {
            found = 1;
        }
    }
    if(found == 0){
        perror("\e[1;33m Eroare: nu exista nicio functie cu acest nume \e[0m \n");
        exit(1);
    }
}

void initializare_tip_id (char *scope, char *type, char *name){
       checkIfIsInScope(scope,name);
        strcpy(var[nr_var].name,name);
        strcpy(var[nr_var].type,type);
        strcpy(var[nr_var].scope,scope);
        printf("\e[1;34m %s - %s - %s \e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope); 
        nr_var++; 
}

void initializare_id (char *scope, char *type, char *name, char *value){

        checkIfIsInScope(scope,name);

        strcpy(var[nr_var].name,name);
        strcpy(var[nr_var].type,type);
        strcpy(var[nr_var].scope,scope);
        strcpy(var[nr_var].value,value);
        printf("\e[1;34m %s - %s - %s - %s\e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope,var[nr_var].value); 
        
        if(strstr(var[nr_var].type,"int"))
        {   var[nr_var].valoare_int = atoi(var[nr_var].value);
        }
        if (strstr(var[nr_var].type,"float")){
            var[nr_var].valoare_float = atof(var[nr_var].value);
        }
        if ( strstr(var[nr_var].type,"double")){
            var[nr_var].valoare_float = atof(var[nr_var].value);
        }
        nr_var++; 
}

void initializare_functie (char *type, char *name, char* params){
    for(int i=0 ; i<nr_functii ; ++i)
        if(strcmp(fun[i].name,name) == 0 && strcmp(fun[i].type,type) ==0 ){

            perror("\e[1;33m Eroare: nu pot exista mai mult de doua functii cu aceeasi signatura \e[0m \n");
            exit(1);
        }

    strcat(fun[nr_functii].name,name);
    strcat(fun[nr_functii].type,type);
    strcat(fun[nr_functii].params,params);
    printf("\e[1;35m %s - %s - %s \e[0m \n", fun[nr_functii].type, fun[nr_functii].name, fun[nr_functii].params);
    nr_functii ++ ;
}

%}
%token  ID INTNR ARR FLOATNR DOUBLENR BOOLEAN AND OR NOT EVAL
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
   int int_number;
}
%type <int_number>  expresie_eval parametri_eval_apel  
%type <textt> ID nr ARR INT FLOAT BOOL DOUBLE expresie parametri_apel parametru_apel CHAR VOID STRUCT FLOATNR DOUBLENR INTNR CONST constant BOOLEAN STRING STRINGVAL tip  param params asignare_structura asignare expresie_string expresie_bool expresie_matematica
%%

start : start global
      | start main 
      | %empty
      ;

global : declaratie_g ';'
       | asignare ';'
       | declaratie_functie
       | structura
       | EVAL '(' parametru_eval ')' '{' bloc_eval '}' 
       ;

parametru_eval: INT ID
                ;

bloc_eval : declaratii_locale ';'
          ;

structura : STRUCT ID '{' bloc_structura '}'
          ;


bloc_structura : bloc_structura declaratie_structura ';'
                | bloc_structura declaratie_functie 
                | %empty
                ;
expresie_eval : expresie_eval '+' expresie_eval {$$=$1+$3;}
         | expresie_eval '-' expresie_eval {$$=$1-$3;}
         | expresie_eval '*' expresie_eval {$$=$1*$3;}
         | expresie_eval '/' expresie_eval {$$=$1/$3;}
         | '(' expresie_eval ')' {$$ = $2;}
         | INTNR { $$ = atoi($1);}
         | ID {$$ = evaluare_id($1,"eval");}
         ;


expresie_matematica : expresie_matematica '+' expresie_matematica {sprintf($1, "%d", atoi($1)+atoi($3)); $$=$1;}
         | expresie_matematica '-' expresie_matematica {sprintf($1, "%d", atoi($1)-atoi($3)); $$=$1;}
         | expresie_matematica '*' expresie_matematica {sprintf($1, "%d", atoi($1)*atoi($3)); $$=$1;}
         | expresie_matematica '/' expresie_matematica {sprintf($1, "%d", atoi($1)/atoi($3)); $$=$1;}
         | '(' expresie_matematica ')' {$$ = $2;}
         | nr {$$ = $1;}
         | ID {$$ = $1; checkIfAlreadyExists($1);}
        ;

expresie_bool : NOT ID {$$=$2; checkIfAlreadyExists($2);}
              | BOOLEAN {$$=$1;}
              | NOT BOOLEAN {$$=!$2;}
              | expresie AND expresie {$$=$1&&$3;}
              | expresie OR expresie  {$$=$1||$3;}
              | '(' expresie_bool ')'  {$$=$2;}
              | expresie GE expresie  {$$=$1 >= $3;}
              | expresie LE expresie   {$$=$1<=$3;}
              | expresie EQ expresie    {$$=$1==$3;}
              | expresie NE expresie    {$$=$1<=$3;}
              | expresie GT expresie    {$$=$1>$3;}
              | expresie LT expresie    {$$=$1<$3;}
              ;

expresie_string : STRINGVAL '+' ID {strcat($1,$3);$$=$1; checkIfAlreadyExists($3);}
                | STRINGVAL '+' STRINGVAL {strcat($1,$3);$$=$1;}
                ;

expresie : expresie_matematica {$$=$1;}
        | expresie_bool {$$=$1;}
        | expresie_string {$$=$1;}
        ;


declaratie_structura : tip ID '[' INTNR ']'
           |tip ID { initializare_tip_id ("structura", $1, $2); }
           | tip ID '=' nr {initializare_id("structura", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("structura", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("structura", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("structura", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("structura",$2, $3);}
           | constant ID '=' nr {initializare_id("structura", $1, $2, $4);}
           | constant ID '=' ID {initializare_id("structura", $1, $2, $4);}
           | constant ID '=' STRINGVAL {initializare_id("structura", $1, $2, $4);}
           | constant ID '=' BOOLEAN {initializare_id("structura", $1, $2, $4);}
           ;

main : START_MAIN bloc_main END_MAIN
     ;

bloc_main : bloc_main cod_main
          | %empty
          ;

cod_main : declaratie_main ';'
         | asignare ';'
         | statements
         | apel
         | apel_eval
         ;

apel : ID '(' parametri_apel ')' ';' {checkIfFunctionExists($1);}
     ;

apel_eval : EVAL '(' parametri_eval_apel ')' ';' { printf("\e[1;33mEval A returnat:%d\e[0m\n",$3);}
          ;

parametri_eval_apel: expresie_eval {$$ = $1;}
                    ;

parametri_apel : parametru_apel {$$=$1;}
                | parametri_apel '#' parametru_apel {strcat($1," "); strcat($1,$3);$$=$1;}
                ;
parametru_apel: expresie {$$=$1;}
                | '_' ID '(' ')' {$$=$2;}
                ;

statements : ifstatement 
           | forstatement
           | whilestatement
           ;

ifstatement : IF '(' expresie_bool ')' '{' cod_bloc '}'
            | IF '(' expresie_bool ')' '{' cod_bloc '}' ELSE '{' cod_bloc '}'
            ;

forstatement : FOR '(' asignare_for ',' expresie_bool ',' operatie ')' '{' cod_bloc '}'
             ;

whilestatement : WHILE '(' expresie_bool ')' '{' cod_bloc '}'
                ;


asignare_for : declaratii_locale
              | asignare
              ;

operatie : ID '+''+'
        | ID '-''-'
        | ID '=' ID '+' ID
        ;

cod_bloc : cod_bloc instructiune_bloc
         | %empty
         ;
 
instructiune_bloc : declaratii_locale ';'
                  | statements
                  | apel
                  | asignare ';'
                  ;

declaratii_locale :  tip ID '[' INTNR ']'
           |tip ID { initializare_tip_id ("local", $1, $2); }
           | tip ID '=' nr {initializare_id("local", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("local", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("local", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("local", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("local",$2, $3);}
           | constant ID '=' nr {initializare_id("local", $1, $2, $4);}
           | constant ID '=' ID {initializare_id("local", $1, $2, $4);}
           | constant ID '=' STRINGVAL {initializare_id("local", $1, $2, $4);}
           | constant ID '=' BOOLEAN {initializare_id("local", $1, $2, $4);}
           ;

declaratie_g :tip ID '[' INTNR ']'
            |tip ID { initializare_tip_id ("global", $1, $2); }
           | tip ID '=' nr {initializare_id("global", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("global", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("global", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("global", $1, $2, $4);}
           | STRUCT ID ID  {initializare_tip_id("global",$2, $3);}
           | constant ID '=' nr {initializare_id("global", $1, $2, $4);}
           | constant ID '=' ID {initializare_id("global", $1, $2, $4);}
           | constant ID '=' STRINGVAL {initializare_id("global", $1, $2, $4);}
           | constant ID '=' BOOLEAN {initializare_id("global", $1, $2, $4);}
            ;

declaratie_main : tip ID {initializare_tip_id ("main",$1, $2); }
           | tip ID '=' nr {initializare_id("main", $1, $2, $4);}
           | tip ID '=' ID {initializare_id("main", $1, $2, $4);}
           | tip ID '=' BOOLEAN {initializare_id("main", $1, $2, $4);}
           | tip ID '=' STRINGVAL {initializare_id("main", $1, $2, $4);}
           |  tip ID '[' INTNR ']'  {initializare_tip_id("main", $1, $2);}
           | STRUCT ID ID  {initializare_tip_id("main",$2, $3);}
           | constant ID '=' nr {initializare_id("main", $1, $2, $4);}
           | constant ID '=' ID {initializare_id("main", $1, $2, $4);}
           | constant ID '=' STRINGVAL {initializare_id("main", $1, $2, $4);}
           | constant ID '=' BOOLEAN {initializare_id("main", $1, $2, $4);}
            ;

declaratie_functie : tip ID '(' params ')' '{' bloc_functie '}' {initializare_functie($1,$2,$4);}
                   | tip ID '(' ')' '{' bloc_functie '}' {initializare_functie($1,$2,""); printf("Declarare de functie\n");}
                   ;

params : param {strcpy(params_list,$1); $$=params_list; }
          | params '#' param {strcat(params_list," "); strcat(params_list,$3); $$=params_list; }
          ;

param : tip ID
    ;

bloc_functie :  bloc_functie cod_functie
              | %empty
              ;

cod_functie : declaratie_var_f ';'
            | asignare ';'
            ;

declaratie_var_f : tip ID {initializare_tip_id ("functie",$1, $2); }
           | tip ID '=' nr {initializare_id("functie", $1, $2,$4);}
           | tip ID '=' ID {initializare_id("functie", $1, $2,$4);}
           | tip ID '=' BOOLEAN {initializare_id("functie", $1, $2,$4);}
           | tip ID '=' STRINGVAL {initializare_id("functie", $1, $2,$4);}
           | STRUCT ID ID  {initializare_tip_id("functie",$2, $3);}
           ;

asignare : ID '=' expresie   {printf("ID:%s", $1);asignare($1, $3);}     
         | asignare_structura
         ;

asignare_structura : ID '.' ID '=' expresie {asignare($3, $5);}
                   ;

constant : CONST tip {char c[30]; strcpy(c,$1); strcat(c," "); strcat(c,$2); $$ = c;}
      ;


tip : INT {$$ = "int";} 
    | FLOAT {$$ = "float";}
    | BOOL {$$ = "bool";}
    | DOUBLE {$$ = "double";}
    | CHAR {$$ = "char";}
    | VOID {$$ = "void";}
    | STRING {$$ = "string";}
    ;

nr : INTNR {$$=$1;}
    | FLOATNR {$$=$1;}
    | DOUBLENR {$$=$1;}
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


    fprintf(f, "Functiile declarate :\n");
    for(int i=0 ;i<nr_functii; ++i) {
        fprintf(f, "%s - %s - %s \n", fun[i].type, fun[i].name, fun[i].params);
    }
    

    fclose(yyin);
    return 0;
}
