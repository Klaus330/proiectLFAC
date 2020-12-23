%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID OP ASIGN COM PAR INTNR ARR FLOATNR DOUBLENR BOOLEAN CALL INT FLOAT BOOL DOUBLE CHAR
%token FOR WHILE
%token IF ELSE print
%token CLASS
%token INCLUDE
%start start
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%%
start: function 
      | declaration
      ;
/* Declarations */
declaration: type assignment ';'
          | assignment ';'
          | functionCall ';'
          | arrayUsage ';'
          | type arrayUsage ';'
          | error
          ;
        
/* assignments */
assignment: ID '=' assignment
        | ID '=' functionCall
        | ID ',' assignment
        | NR ',' assignment
        | ID '+' assignment
        | ID '-' assignment
        | ID '*' assignment
        | ID '/' assignment
        | NR '+' assignment
        | NR '-' assignment
        | NR '*' assignment
        | NR '/' assignment
        | '(' assignment ')'
        | '-' '(' assignment ')'
        | '-' NR
        | '-' ID
        | NR
        | ID
        ;


/* function calls*/
functionCall: ID'('')'
          | ID'('assignment')'
          ;

/* array ussage */
arrayUsage: ID'['assignment']'
        ;

/* functions */
function: TIP ID '('arglistopt ')'
      ;

arglistopt: arglist 
        ;

arglist: arglist ',' arg 
      | arg   
      ;

arg: TIP ID 
  ;

compooundStatement: '{'statementList'}'
                ;
statementList: statementList statement
          ;

statement: whileStatement
        | declaration
        | forStatement
        | ifStatement
        | printFunction
        ;

/* type identifier block */
TIP: INT  
  | FLOAT
  | CHAR
  | DOUBLE
  | VOID
  ;

/* loop blocks */
whileStatement: WHILE '('exp')' statement
            | WHILE '('exp')' compooundStatement
            ;


/* for statement block */
forStatement: FOR '(' exp ';' exp ';' exp ')' statement
          | FOR '(' exp ';' exp ';' exp ')' compooundStatement
          | FOR '(' exp ')' statement
          | FOR '(' exp ')' compooundStatement
          ;

/* if statement block */
ifStatement: IF '(' exp ')' statement
          ;

/* print function */
printFunction: print '(' exp ')' ';'
            ;

/* expression blocks */           

exp:
  | exp LE exp
  | exp GE exp
  | exp NE exp
  | exp EQ exp
  | exp GT exp
  | exp LT exp
  | assignment
  | arrayUsage
  ;

%%
#include"lex.yy.c"
#include<ctype.h>
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
