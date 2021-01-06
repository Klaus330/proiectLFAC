/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "limbaj.y" /* yacc.c:339  */

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

int checkIfVarAlreadyExists(char *nume){
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
    
    int index = checkIfVarAlreadyExists(nume);
    int idIndex = -1;
    idIndex =  getIndexIfIndentifier(valoare);
    if(idIndex !=-1){
        
        strcpy(var[index].value,var[idIndex].value);
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
    int index = checkIfVarAlreadyExists(id);

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


#line 258 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INTNR = 259,
    ARR = 260,
    FLOATNR = 261,
    DOUBLENR = 262,
    BOOLEAN = 263,
    AND = 264,
    OR = 265,
    NOT = 266,
    EVAL = 267,
    INT = 268,
    FLOAT = 269,
    BOOL = 270,
    DOUBLE = 271,
    CHAR = 272,
    VOID = 273,
    CONST = 274,
    STRING = 275,
    STRINGVAL = 276,
    FOR = 277,
    WHILE = 278,
    STRUCT = 279,
    IF = 280,
    ELSE = 281,
    print = 282,
    START_MAIN = 283,
    END_MAIN = 284,
    LE = 285,
    GE = 286,
    EQ = 287,
    NE = 288,
    LT = 289,
    GT = 290
  };
#endif
/* Tokens.  */
#define ID 258
#define INTNR 259
#define ARR 260
#define FLOATNR 261
#define DOUBLENR 262
#define BOOLEAN 263
#define AND 264
#define OR 265
#define NOT 266
#define EVAL 267
#define INT 268
#define FLOAT 269
#define BOOL 270
#define DOUBLE 271
#define CHAR 272
#define VOID 273
#define CONST 274
#define STRING 275
#define STRINGVAL 276
#define FOR 277
#define WHILE 278
#define STRUCT 279
#define IF 280
#define ELSE 281
#define print 282
#define START_MAIN 283
#define END_MAIN 284
#define LE 285
#define GE 286
#define EQ 287
#define NE 288
#define LT 289
#define GT 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 204 "limbaj.y" /* yacc.c:355  */

   char* textt;
   int int_number;

#line 373 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 390 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    48,     2,     2,     2,     2,
      42,    43,    39,    37,    50,    38,    51,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,    49,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    31,    32,    33,    34,    35,
      36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   212,   212,   213,   214,   217,   218,   219,   220,   221,
     224,   227,   230,   234,   235,   236,   238,   239,   240,   241,
     242,   243,   244,   248,   249,   250,   251,   252,   253,   254,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   271,   272,   275,   276,   277,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   294,   297,
     298,   301,   302,   303,   304,   305,   308,   311,   314,   317,
     318,   320,   321,   324,   325,   326,   329,   330,   333,   336,
     340,   341,   344,   345,   346,   349,   350,   353,   354,   355,
     356,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   398,   399,   402,   403,   406,   409,
     410,   413,   414,   417,   418,   419,   420,   421,   422,   425,
     426,   429,   432,   436,   437,   438,   439,   440,   441,   442,
     445,   446,   447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTNR", "ARR", "FLOATNR",
  "DOUBLENR", "BOOLEAN", "AND", "OR", "NOT", "EVAL", "INT", "FLOAT",
  "BOOL", "DOUBLE", "CHAR", "VOID", "CONST", "STRING", "STRINGVAL", "FOR",
  "WHILE", "STRUCT", "IF", "ELSE", "print", "START_MAIN", "END_MAIN",
  "'='", "LE", "GE", "EQ", "NE", "LT", "GT", "'+'", "'-'", "'*'", "'/'",
  "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'#'", "'_'", "','",
  "'.'", "$accept", "start", "global", "parametru_eval", "bloc_eval",
  "structura", "bloc_structura", "expresie_eval", "expresie_matematica",
  "expresie_bool", "expresie_string", "expresie", "declaratie_structura",
  "main", "bloc_main", "cod_main", "apel", "apel_eval",
  "parametri_eval_apel", "parametri_apel", "parametru_apel", "statements",
  "ifstatement", "forstatement", "whilestatement", "asignare_for",
  "operatie", "cod_bloc", "instructiune_bloc", "declaratii_locale",
  "declaratie_g", "declaratie_main", "declaratie_functie", "params",
  "param", "bloc_functie", "cod_functie", "declaratie_var_f", "asignare",
  "asignare_structura", "constant", "tip", "nr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      61,   285,   286,   287,   288,   289,   290,    43,    45,    42,
      47,    59,    40,    41,   123,   125,    91,    93,    35,    95,
      44,    46
};
# endif

#define YYPACT_NINF -213

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-213)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -213,   248,  -213,   -16,   -23,  -213,  -213,  -213,  -213,  -213,
    -213,   386,  -213,    28,  -213,  -213,  -213,  -213,    -3,  -213,
       3,  -213,    69,    82,   141,    86,    95,  -213,    13,   272,
    -213,  -213,    83,   -12,  -213,  -213,  -213,  -213,  -213,    19,
     102,   141,   147,  -213,  -213,   247,  -213,    89,   139,   100,
    -213,  -213,   -19,   104,   108,   109,   153,   121,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,   123,   124,   164,   165,
     309,   315,   227,   190,  -213,  -213,     5,   338,   126,   247,
     117,   117,   117,   117,   141,   141,   141,   141,   141,   141,
     141,   141,   141,  -213,   152,   210,    76,   111,   290,   141,
     195,   141,  -213,  -213,   173,   -10,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,   160,   -36,  -213,   202,   168,  -213,
    -213,  -213,  -213,   117,    53,    53,  -213,  -213,   383,   383,
    -213,  -213,  -213,  -213,  -213,  -213,   247,   374,   218,  -213,
     181,  -213,   228,   243,   246,   247,    43,  -213,  -213,  -213,
     111,   198,   207,   249,   203,  -213,  -213,   251,   255,   216,
    -213,   226,   321,   331,   267,  -213,   229,   386,  -213,  -213,
     338,   232,   233,   295,  -213,   269,    92,   258,   261,    76,
     370,   111,   111,   111,   111,   270,   317,   141,   296,    -9,
     287,   288,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
     286,   113,  -213,  -213,  -213,  -213,  -213,   337,   343,   344,
     310,  -213,  -213,  -213,    96,    96,  -213,  -213,  -213,  -213,
     304,   353,   359,   351,  -213,  -213,  -213,   367,  -213,  -213,
     341,   342,   376,   175,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,   348,  -213,   381,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,   349,    36,    87,   382,  -213,  -213,   375,
    -213,  -213,   -13,   354,  -213,  -213,  -213,  -213,  -213,   371,
     379,   385,  -213,   365,   418,   387,   384,   388,  -213,  -213,
     389,  -213,  -213,  -213,  -213,   390,  -213,  -213,  -213,  -213,
     420,   157,   194,  -213,  -213,  -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,     0,     0,   143,   144,   145,   146,   147,
     148,     0,   149,     0,    60,     2,     8,     3,     0,     7,
       0,   140,     0,     0,     0,     0,     0,   142,     0,     0,
       5,     6,     0,   103,    29,   150,   151,   152,    31,     0,
       0,     0,    44,    45,    46,   139,    28,     0,     0,     0,
     108,    15,     0,     0,     0,     0,     0,     0,    58,    59,
      64,    65,    63,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    32,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,     0,   113,   110,   112,   111,   109,
     105,   106,   107,   104,     0,     0,   126,     0,     0,    42,
      43,    27,    35,     0,    23,    24,    25,    26,    33,    34,
      37,    36,    38,    39,    41,    40,   141,     0,     0,    12,
       0,    14,     0,     0,     0,    71,     0,    69,    22,    21,
       0,    68,     0,     0,     0,    80,    81,     0,     0,    45,
     119,    45,     0,     0,     0,   130,     0,     0,   128,   102,
       0,     0,     0,     0,    13,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,   121,   123,   122,   120,   115,   116,   117,   114,
       0,     0,   130,   127,     9,    11,    53,     0,     0,     0,
       0,    66,    70,    20,    16,    17,    18,    19,    67,    97,
      45,     0,     0,     0,    86,    86,   118,     0,   125,   129,
       0,     0,     0,     0,    55,    57,    56,    54,    50,    51,
      52,    49,     0,    72,     0,    99,   101,   100,    98,    94,
      95,    96,    93,     0,     0,     0,     0,   131,   132,   133,
     124,    47,     0,     0,    91,    79,    89,    88,    85,     0,
       0,    76,   138,     0,     0,     0,     0,     0,    87,    90,
       0,   135,   136,   137,   134,     0,    82,    83,    86,    86,
       0,     0,     0,    84,    78,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -141,   -35,   -26,
    -213,   -22,  -213,  -213,  -213,  -213,   396,  -213,  -213,  -213,
     250,   397,  -213,  -213,  -213,  -213,  -213,  -212,  -213,   -20,
    -213,  -213,   333,  -213,   263,   234,  -213,  -213,     0,  -213,
       4,    -1,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,    49,   171,    16,    95,   151,    42,    43,
      44,    79,   140,    17,    29,    59,   266,    61,   152,   146,
     147,   267,    63,    64,    65,   154,   263,   254,   268,   269,
      18,    66,    19,   115,   116,   201,   229,   230,   270,    21,
     157,   158,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      23,    20,    45,   109,   113,    22,    77,   166,   119,   180,
      27,    24,   167,   255,    24,    78,    50,   274,    71,    26,
     163,   222,    74,    96,   275,   276,   120,    75,    69,    67,
      72,    28,    25,    68,    73,    25,   164,   223,    30,    52,
     214,   215,   216,   217,    31,   124,   125,   126,   127,     5,
       6,     7,     8,     9,    10,    11,    12,    51,    54,    55,
     153,    57,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   117,    32,   159,   145,   161,   291,   292,   155,    34,
      35,   265,    36,    37,    38,    33,   178,    39,   170,    47,
      52,   179,    82,    83,   143,   195,   199,    40,   156,   142,
       5,     6,     7,     8,     9,    10,    11,    12,    48,    54,
      55,   153,    57,    70,   148,   149,     3,   172,    41,    92,
      34,    35,   208,    36,    37,   144,     5,     6,     7,     8,
       9,    10,   271,    12,    72,   183,   184,   227,   209,    76,
     237,   241,    93,    94,    34,    35,    97,    36,    37,    38,
      98,    99,    39,   150,   248,   252,   100,   145,   228,   123,
      52,   220,    40,   101,   102,   103,   117,   104,   105,   122,
       5,     6,     7,     8,     9,    10,    11,    12,     3,    54,
      55,   153,    57,    41,    80,    81,    82,    83,     5,     6,
       7,     8,     9,    10,   118,    12,   137,    52,   160,   227,
     232,   231,   294,   162,   165,   168,   284,     5,     6,     7,
       8,     9,    10,    11,    12,   169,    54,    55,   153,    57,
     260,   173,   174,     5,     6,     7,     8,     9,    10,    11,
      12,   175,   232,   231,   138,   181,   182,   183,   184,   295,
       5,     6,     7,     8,     9,    10,   176,    12,     2,   177,
     185,     3,   186,   187,   188,   139,    84,    85,   189,   190,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   191,
     114,   200,    13,   202,   205,    52,    14,   204,    86,    87,
      88,    89,    90,    91,    53,     5,     6,     7,     8,     9,
      10,    11,    12,     3,    54,    55,    56,    57,   206,   207,
     210,    58,   211,     5,     6,     7,     8,     9,    10,    11,
      12,   218,   106,    35,   153,    36,    37,   107,   110,    35,
     219,    36,    37,   111,   192,    35,   221,    36,    37,   193,
     108,   224,   225,   226,   196,    35,   112,    36,    37,   197,
     234,    35,   194,    36,    37,   235,   238,    35,   242,    36,
      37,   239,   198,   243,   244,   253,   245,    35,   236,    36,
      37,   246,   249,    35,   240,    36,    37,   250,   281,    35,
     256,    36,    37,   282,   247,    80,    81,    82,    83,   259,
     251,   121,   257,   258,   262,   272,   283,     5,     6,     7,
       8,     9,    10,    11,    12,   261,   264,   277,   153,     5,
       6,     7,     8,     9,    10,   273,    12,   181,   182,   183,
     184,   280,   278,   213,    86,    87,    88,    89,    90,    91,
     279,   285,   287,   293,   286,    60,    62,   290,   141,   212,
     203,     0,   288,   289,     0,     0,   233
};

static const yytype_int16 yycheck[] =
{
       1,     1,    24,    70,    71,     1,    41,    43,     3,   150,
      11,    30,    48,   225,    30,    41,     3,    30,    30,    42,
      30,    30,     3,    42,    37,    38,    21,     8,    29,    29,
      42,     3,    51,    29,    46,    51,    46,    46,    41,     3,
     181,   182,   183,   184,    41,    80,    81,    82,    83,    13,
      14,    15,    16,    17,    18,    19,    20,    44,    22,    23,
      24,    25,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    72,     3,    99,    96,   101,   288,   289,    98,     3,
       4,    45,     6,     7,     8,     3,    43,    11,   123,     3,
       3,    48,    39,    40,    95,   162,   163,    21,    98,    95,
      13,    14,    15,    16,    17,    18,    19,    20,    13,    22,
      23,    24,    25,    30,     3,     4,     3,   137,    42,    30,
       3,     4,    30,     6,     7,    49,    13,    14,    15,    16,
      17,    18,    45,    20,    42,    39,    40,    24,    46,    37,
     207,   208,     3,    43,     3,     4,    42,     6,     7,     8,
      42,    42,    11,    42,   221,   222,     3,   179,    45,    42,
       3,   187,    21,    42,    41,    41,   167,     3,     3,    43,
      13,    14,    15,    16,    17,    18,    19,    20,     3,    22,
      23,    24,    25,    42,    37,    38,    39,    40,    13,    14,
      15,    16,    17,    18,     4,    20,    44,     3,     3,    24,
     201,   201,    45,    30,    44,     3,   273,    13,    14,    15,
      16,    17,    18,    19,    20,    47,    22,    23,    24,    25,
      45,     3,    41,    13,    14,    15,    16,    17,    18,    19,
      20,     3,   233,   233,    24,    37,    38,    39,    40,    45,
      13,    14,    15,    16,    17,    18,     3,    20,     0,     3,
      43,     3,     3,    50,     3,    45,     9,    10,     3,    43,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    43,
      43,     4,    24,    44,    41,     3,    28,    45,    31,    32,
      33,    34,    35,    36,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     3,    22,    23,    24,    25,     3,    30,
      42,    29,    41,    13,    14,    15,    16,    17,    18,    19,
      20,    41,     3,     4,    24,     6,     7,     8,     3,     4,
       3,     6,     7,     8,     3,     4,    30,     6,     7,     8,
      21,    44,    44,    47,     3,     4,    21,     6,     7,     8,
       3,     4,    21,     6,     7,     8,     3,     4,     4,     6,
       7,     8,    21,    43,    50,     4,     3,     4,    21,     6,
       7,     8,     3,     4,    21,     6,     7,     8,     3,     4,
       3,     6,     7,     8,    21,    37,    38,    39,    40,     3,
      21,    43,    41,    41,     3,     3,    21,    13,    14,    15,
      16,    17,    18,    19,    20,    47,    47,    43,    24,    13,
      14,    15,    16,    17,    18,    30,    20,    37,    38,    39,
      40,    26,    41,    43,    31,    32,    33,    34,    35,    36,
      41,     3,    38,     3,    37,    29,    29,    37,    95,   179,
     167,    -1,    44,    44,    -1,    -1,   202
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     3,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    24,    28,    54,    57,    65,    82,    84,
      90,    91,    92,    93,    30,    51,    42,    93,     3,    66,
      41,    41,     3,     3,     3,     4,     6,     7,     8,    11,
      21,    42,    60,    61,    62,    63,    94,     3,    13,    55,
       3,    44,     3,    12,    22,    23,    24,    25,    29,    67,
      68,    69,    73,    74,    75,    76,    83,    90,    92,    93,
      30,    30,    42,    46,     3,     8,    37,    60,    61,    63,
      37,    38,    39,    40,     9,    10,    31,    32,    33,    34,
      35,    36,    30,     3,    43,    58,    42,    42,    42,    42,
       3,    42,    41,    41,     3,     3,     3,     8,    21,    94,
       3,     8,    21,    94,    43,    85,    86,    93,     4,     3,
      21,    43,    43,    42,    60,    60,    60,    60,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    44,    24,    45,
      64,    84,    92,    93,    49,    63,    71,    72,     3,     4,
      42,    59,    70,    24,    77,    81,    90,    92,    93,    61,
       3,    61,    30,    30,    46,    44,    43,    48,     3,    47,
      60,    56,    81,     3,    41,     3,     3,     3,    43,    48,
      59,    37,    38,    39,    40,    43,     3,    50,     3,     3,
      43,    43,     3,     8,    21,    94,     3,     8,    21,    94,
       4,    87,    44,    86,    45,    41,     3,    30,    30,    46,
      42,    41,    72,    43,    59,    59,    59,    59,    41,     3,
      61,    30,    30,    46,    44,    44,    47,    24,    45,    88,
      89,    90,    93,    87,     3,     8,    21,    94,     3,     8,
      21,    94,     4,    43,    50,     3,     8,    21,    94,     3,
       8,    21,    94,     4,    79,    79,     3,    41,    41,     3,
      45,    47,     3,    78,    47,    45,    68,    73,    80,    81,
      90,    45,     3,    30,    30,    37,    38,    43,    41,    41,
      26,     3,     8,    21,    94,     3,    37,    38,    44,    44,
      37,    79,    79,     3,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    54,    54,    54,    54,    54,
      55,    56,    57,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    66,
      66,    67,    67,    67,    67,    67,    68,    69,    70,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    75,    76,
      77,    77,    78,    78,    78,    79,    79,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    92,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     1,     1,     7,
       2,     2,     5,     3,     2,     0,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     5,     2,     4,
       4,     4,     4,     3,     4,     4,     4,     4,     3,     2,
       0,     2,     2,     1,     1,     1,     5,     5,     1,     1,
       3,     1,     4,     1,     1,     1,     7,    11,    11,     7,
       1,     1,     3,     3,     5,     2,     0,     2,     1,     1,
       2,     5,     2,     4,     4,     4,     4,     3,     4,     4,
       4,     4,     5,     2,     4,     4,     4,     4,     3,     4,
       4,     4,     4,     2,     4,     4,     4,     4,     5,     3,
       4,     4,     4,     4,     8,     7,     1,     3,     2,     2,
       0,     2,     2,     2,     4,     4,     4,     4,     3,     3,
       1,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 16:
#line 238 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)+(yyvsp[0].int_number);}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 239 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)-(yyvsp[0].int_number);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 240 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)*(yyvsp[0].int_number);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 241 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)/(yyvsp[0].int_number);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 242 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = (yyvsp[-1].int_number);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 243 "limbaj.y" /* yacc.c:1646  */
    { (yyval.int_number) = atoi((yyvsp[0].textt));}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = evaluare_id((yyvsp[0].textt),"eval");}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 248 "limbaj.y" /* yacc.c:1646  */
    {sprintf((yyvsp[-2].textt), "%d", atoi((yyvsp[-2].textt))+atoi((yyvsp[0].textt))); (yyval.textt)=(yyvsp[-2].textt);}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "limbaj.y" /* yacc.c:1646  */
    {sprintf((yyvsp[-2].textt), "%d", atoi((yyvsp[-2].textt))-atoi((yyvsp[0].textt))); (yyval.textt)=(yyvsp[-2].textt);}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 250 "limbaj.y" /* yacc.c:1646  */
    {sprintf((yyvsp[-2].textt), "%d", atoi((yyvsp[-2].textt))*atoi((yyvsp[0].textt))); (yyval.textt)=(yyvsp[-2].textt);}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 251 "limbaj.y" /* yacc.c:1646  */
    {sprintf((yyvsp[-2].textt), "%d", atoi((yyvsp[-2].textt))/atoi((yyvsp[0].textt))); (yyval.textt)=(yyvsp[-2].textt);}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 252 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = (yyvsp[-1].textt);}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 253 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = (yyvsp[0].textt);}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 254 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = (yyvsp[0].textt); checkIfVarAlreadyExists((yyvsp[0].textt));}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 257 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt); checkIfVarAlreadyExists((yyvsp[0].textt));}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 258 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 259 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=!(yyvsp[0].textt);}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 260 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)&&(yyvsp[0].textt);}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 261 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)||(yyvsp[0].textt);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 262 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-1].textt);}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 263 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt) >= (yyvsp[0].textt);}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 264 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)<=(yyvsp[0].textt);}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 265 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)==(yyvsp[0].textt);}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 266 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)<=(yyvsp[0].textt);}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 267 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)>(yyvsp[0].textt);}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 268 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt)<(yyvsp[0].textt);}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 271 "limbaj.y" /* yacc.c:1646  */
    {strcat((yyvsp[-2].textt),(yyvsp[0].textt));(yyval.textt)=(yyvsp[-2].textt); checkIfVarAlreadyExists((yyvsp[0].textt));}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 272 "limbaj.y" /* yacc.c:1646  */
    {strcat((yyvsp[-2].textt),(yyvsp[0].textt));(yyval.textt)=(yyvsp[-2].textt);}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 275 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 276 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 277 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 282 "limbaj.y" /* yacc.c:1646  */
    { initializare_tip_id ("structura", (yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 283 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 284 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 285 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 286 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 287 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("structura",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 288 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 291 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 308 "limbaj.y" /* yacc.c:1646  */
    {checkIfFunctionExists((yyvsp[-4].textt));}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 311 "limbaj.y" /* yacc.c:1646  */
    { printf("\e[1;33mEval A returnat:%d\e[0m\n",(yyvsp[-2].int_number));}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 314 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = (yyvsp[0].int_number);}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 317 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 318 "limbaj.y" /* yacc.c:1646  */
    {strcat((yyvsp[-2].textt)," "); strcat((yyvsp[-2].textt),(yyvsp[0].textt));(yyval.textt)=(yyvsp[-2].textt);}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 320 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 321 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[-2].textt);}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 360 "limbaj.y" /* yacc.c:1646  */
    { initializare_tip_id ("local", (yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 361 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 362 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 363 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 364 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 365 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("local",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 366 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 367 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 368 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 369 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 373 "limbaj.y" /* yacc.c:1646  */
    { initializare_tip_id ("global", (yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 374 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 375 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 376 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 377 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 378 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("global",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 379 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 380 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 381 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 382 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 385 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id ("main",(yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 386 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 387 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 388 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 389 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 390 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("main", (yyvsp[-4].textt), (yyvsp[-3].textt));}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 391 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("main",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 392 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 393 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 394 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 395 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 398 "limbaj.y" /* yacc.c:1646  */
    {initializare_functie((yyvsp[-7].textt),(yyvsp[-6].textt),(yyvsp[-4].textt));}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 399 "limbaj.y" /* yacc.c:1646  */
    {initializare_functie((yyvsp[-6].textt),(yyvsp[-5].textt),"");}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 402 "limbaj.y" /* yacc.c:1646  */
    {strcpy(params_list,(yyvsp[0].textt)); (yyval.textt)=params_list; }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 403 "limbaj.y" /* yacc.c:1646  */
    {strcat(params_list," "); strcat(params_list,(yyvsp[0].textt)); (yyval.textt)=params_list; }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 417 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id ("functie",(yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 418 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 419 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 420 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 421 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 422 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("functie",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 425 "limbaj.y" /* yacc.c:1646  */
    {asignare((yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 429 "limbaj.y" /* yacc.c:1646  */
    {asignare((yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 432 "limbaj.y" /* yacc.c:1646  */
    {char c[30]; strcpy(c,(yyvsp[-1].textt)); strcat(c," "); strcat(c,(yyvsp[0].textt)); (yyval.textt) = c;}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 436 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "int";}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 437 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "float";}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 438 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "bool";}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 439 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "double";}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 440 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "char";}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 441 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "void";}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 442 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "string";}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 445 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 446 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 447 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2314 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 450 "limbaj.y" /* yacc.c:1906  */

int count=0;
yyerror(char *s) {
    printf("%d : %s %s\n", yylineno, s, yytext );
}

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
    FILE *f = fopen("symbols.txt","w");
   if(!yyparse())
        printf("\nParsing complete\nProgram corect sintactic\n");
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
