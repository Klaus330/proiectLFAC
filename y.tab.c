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
    char value[50];
    char name[50];
    char type[50];
    char scope[50];
    int valoare_int;
    float valoare_float;
}var[100];

struct functions {
    char name[50];
    char type[50];
    char params[200];
}fun[100];


int nr_var = 0;
int nr_functii = 0;

int asignare_numar(char* nume, char *valoare){
    int found=0, index;
    for(int i=0; i<nr_var; i++){
        if(strcmp(var[i].name,nume)==0){
            found=1;
            index=i;
        }
    }

    if(found==0){
        perror("\e[1;33m Eroare: nu exista nicio variabila cu acest nume\e[0m \n");
        exit(1);
    }

    if(strstr(var[index].type,"int"))
    {   var[index].valoare_int = atoi(var[index].value);
        return var[index].valoare_int;
    }
    else if (strstr(var[index].type,"float")|| strstr(var[index].type,"double")){
        var[index].valoare_float = atof(var[index].value);
        return var[index].valoare_float;
    }
}


float asignare_expresie(char* nume, char *valoare){
    int found=0, index;
    for(int i=0; i<nr_var; i++){
        if(strcmp(var[i].name,nume)==0){
            found=1;
            index=i;
        }
    }

    if(found==0){
        perror("\e[1;33m Eroare: nu exista nicio variabila cu acest nume\e[0m \n");
        exit(1);
    }

    if(strstr(var[index].type,"int"))
    {   var[index].valoare_int = atoi(var[index].value);
        return var[index].valoare_int;
    }
    else if (strstr(var[index].type,"float")|| strstr(var[index].type,"double")){
        var[index].valoare_float = atof(var[index].value);
        return var[index].valoare_float;
    }
}

int evaluare_id(char* id, char *scope){
    int found=0, index;
    for(int i=0; i<nr_var; i++){
        if(strcmp(var[i].name,id)==0){
            found=1;
            index=i;
        }
    }

    if(found==0){
        perror("\e[1;33m Eroare: nu exista nicio variabila cu acest nume\e[0m \n");
        exit(1);
    }

    printf("Am id-ul %s scopul %s \n",id,scope);
    if(strcmp(scope,"eval") ==0 ){
        if(strstr(var[index].type,"int")){
            printf("Sunt variabila %s si am valoare %s\n",var[index].name,var[index].value);
            return atoi(var[index].value);
        }
        else{
            perror("\e[1;33m Eroare: toti parametrii pentru functia Eval trebuie sa fie de tip int\e[0m \n");
            exit(1);
        }
    }

   printf("Sunt variabila %s si am valoare %s\n",var[index].name,var[index].value);
   if(strstr(var[index].type,"int")){
        return atoi(var[index].value);
   }else if (strstr(var[index].type,"float") || strstr(var[index].type,"double") ){
       return atof(var[index].value);
   }
  
}

void initializare_tip_id (char *scope, char *type, char *name){
        for(int i=0 ; i<nr_var;++i)
        {
            if(strcmp(var[i].name,name) == 0 && strcmp(var[i].scope,scope)==0){
                perror("\e[1;33m Eroare: nu pot exista doua variabile identice \e[0m \n");
                exit(1);
            }
        }
        strcat(var[nr_var].name,name);
        strcat(var[nr_var].type,type);
        strcat(var[nr_var].scope,scope);
        printf("\e[1;34m %s - %s - %s \e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope); 
        nr_var++; 
}

void initializare_id (char *scope, char *type, char *name, char *value){

      for(int i=0 ; i<nr_var;++i)
        {
            if(strcmp(var[i].name,name) == 0 && strcmp(var[i].scope,scope)==0){
                perror("\e[1;33m Eroare: nu pot exista doua variabile identice \e[0m \n");
                exit(1);
            }
        }
        strcpy(var[nr_var].name,name);
        strcpy(var[nr_var].type,type);
        strcpy(var[nr_var].scope,scope);
        strcpy(var[nr_var].value,value);
 printf("\e[1;34m %s - %s - %s - %s\e[0m \n", var[nr_var].type, var[nr_var].name, var[nr_var].scope,var[nr_var].value); 
   
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


#line 230 "y.tab.c" /* yacc.c:339  */

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
#line 176 "limbaj.y" /* yacc.c:355  */

   char* textt;
   int int_number;

#line 345 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 362 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   613

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

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
       2,     2,     2,     2,     2,    52,     2,     2,     2,     2,
      44,    45,    41,    39,    48,    40,    53,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,    51,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    33,    34,    35,    36,    37,
      38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   185,   186,   189,   190,   191,   192,   193,
     196,   197,   198,   199,   202,   205,   209,   210,   211,   214,
     215,   216,   217,   218,   219,   220,   223,   224,   225,   226,
     227,   228,   229,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   246,   247,   250,   251,   252,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   269,   272,   273,   276,   277,   278,   279,   280,   283,
     284,   285,   288,   291,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   306,   307,   308,   311,   312,   315,   318,
     322,   323,   326,   327,   328,   331,   332,   335,   336,   337,
     338,   339,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   381,   382,   385,   386,   389,
     395,   396,   399,   400,   403,   404,   405,   406,   407,   408,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   425,   428,   432,   433,   434,   435,   436,   437,
     438,   441,   442,   443
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
  "'='", "'<'", "'>'", "LE", "GE", "EQ", "NE", "LT", "GT", "'+'", "'-'",
  "'*'", "'/'", "';'", "'('", "')'", "'{'", "'}'", "','", "'['", "']'",
  "'_'", "'#'", "'.'", "$accept", "start", "global", "params_eval",
  "bloc_eval", "structura", "bloc_structura", "expresie_matematica",
  "expresie_eval", "expresie_bool", "expresie_string", "expresie",
  "declaratie_structura", "main", "bloc_main", "cod_main", "apel",
  "apel_eval", "parametri_eval_apel", "parametri_apel", "statements",
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
      61,    60,    62,   285,   286,   287,   288,   289,   290,    43,
      45,    42,    47,    59,    40,    41,   123,   125,    44,    91,
      93,    95,    35,    46
};
# endif

#define YYPACT_NINF -245

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-245)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -245,   454,  -245,    -9,  -245,  -245,  -245,  -245,    50,   -24,
    -245,  -245,  -245,  -245,  -245,  -245,   383,  -245,    -6,    21,
    -245,    91,  -245,  -245,   329,  -245,  -245,   537,  -245,     9,
    -245,    33,  -245,    78,    82,  -245,   317,    84,  -245,  -245,
      75,  -245,    52,     8,   130,  -245,  -245,    -6,   246,    44,
     537,  -245,    25,    25,    25,    25,    91,    91,    91,    91,
      91,    91,    91,    91,  -245,  -245,    63,    60,  -245,  -245,
      -6,   537,  -245,    66,    97,    56,  -245,  -245,  -245,  -245,
      -8,    59,    67,    72,   104,    74,  -245,   125,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,    86,    88,   136,   137,  -245,
    -245,    25,    18,    18,  -245,  -245,   321,   321,  -245,  -245,
    -245,  -245,  -245,  -245,   158,   203,   250,   152,   164,   109,
     112,   235,     6,    12,   520,    91,   157,    91,   119,  -245,
    -245,   139,    -7,   246,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,   134,   -27,  -245,   173,   142,   184,  -245,    75,
     589,   190,  -245,   141,  -245,   192,   195,    28,   169,   181,
     149,   175,   171,  -245,  -245,    12,   371,   176,   224,   180,
    -245,  -245,   226,   229,   189,  -245,   191,   194,   359,   401,
     231,  -245,   199,   383,  -245,  -245,   237,  -245,   253,   210,
     217,   266,  -245,   241,    61,    71,  -245,    71,    71,   230,
      71,   273,    12,    12,    12,    12,   233,   269,    91,   247,
       0,   232,   238,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,   272,   473,  -245,  -245,  -245,   278,  -245,  -245,
    -245,   443,   545,   279,  -245,  -245,  -245,  -245,  -245,  -245,
      42,    42,  -245,  -245,  -245,  -245,   248,   555,   574,   315,
    -245,  -245,  -245,   323,  -245,  -245,   284,   297,   326,   498,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   310,
     361,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   332,
     286,   328,   399,  -245,  -245,   376,  -245,  -245,   143,   379,
    -245,  -245,  -245,  -245,  -245,   396,   402,   416,  -245,   580,
     441,   409,   413,   406,  -245,  -245,   437,  -245,  -245,  -245,
    -245,   446,  -245,  -245,  -245,  -245,   452,   370,   412,  -245,
    -245,  -245
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,    25,   171,   172,   173,    34,     0,     0,
     164,   165,   166,   167,   168,   169,     0,   170,   157,     0,
      63,     0,     2,     8,    47,    48,    49,   160,     3,     0,
       7,     0,   154,     0,     0,    24,     0,     0,    33,    35,
      13,   163,     0,     0,     0,    25,    34,     0,    47,    48,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     0,   114,    25,    34,
     152,   159,    24,     0,     0,     0,    45,    46,   119,    18,
      25,     0,     0,     0,     0,     0,    61,     0,    62,    67,
      68,    66,    83,    84,    85,     0,     0,     0,     0,    23,
      38,     0,    19,    20,    21,    22,    36,    37,    40,    39,
      41,    42,    44,    43,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,     0,   124,     0,   121,   123,   122,   120,   116,   117,
     118,   115,     0,     0,   137,     0,     0,     0,   162,    13,
       0,     0,    15,     0,    17,     0,     0,    25,     0,    80,
      78,     0,    24,    32,    31,     0,    73,     0,     0,     0,
      90,    91,     0,     0,    48,   130,    48,     0,     0,     0,
       0,   141,     0,     0,   139,   113,     0,    10,     0,     0,
       0,     0,    16,     0,    51,    82,    69,    82,    82,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,    71,   132,   134,   133,   131,   126,   127,
     128,   125,     0,     0,   141,   138,   161,     0,     9,    14,
      56,     0,     0,     0,    75,    81,    79,    70,    77,    30,
      26,    27,    28,    29,    72,   108,    48,     0,     0,     0,
      96,    96,   129,     0,   136,   140,     0,     0,     0,     0,
     108,    58,    60,    59,    57,    53,    54,    55,    52,     0,
       0,   110,   112,   111,   109,   105,   106,   107,   104,     0,
       0,     0,     0,   142,   143,   144,   135,    50,     0,     0,
     102,    89,    99,    98,    95,     0,     0,    86,   149,     0,
       0,     0,     0,     0,    97,   100,     0,   146,   147,   148,
     145,     0,    92,    93,    96,    96,     0,     0,     0,    94,
      88,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,  -245,   343,  -245,  -245,  -245,   -15,    39,   -19,
    -245,     5,  -245,  -245,  -245,  -245,   -43,  -245,  -245,   243,
     451,  -245,  -245,  -245,  -245,  -245,  -244,  -245,  -116,  -245,
    -245,   375,  -245,   316,   276,  -245,  -245,     2,  -245,     4,
       3,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    22,    75,   189,    23,   121,    24,   166,    25,
      26,    27,   153,    28,    44,    88,   160,    90,   167,   161,
     293,    92,    93,    94,   169,   289,   280,   294,   295,    29,
      95,    30,   143,   144,   223,   255,   256,   296,    32,   172,
     173,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      35,    89,    49,    31,    34,    33,    48,   281,   170,   157,
       4,    78,     5,     6,    46,   163,   164,     8,   182,    41,
      40,    36,    36,   179,    43,   183,    50,    47,    45,     4,
     248,     5,     6,    42,   190,    72,   122,   102,   103,   104,
     105,    71,   180,    35,    37,    37,    96,    98,    97,   249,
      21,   158,    64,    38,    79,    76,   165,    87,    39,    54,
      55,   106,   107,   108,   109,   110,   111,   112,   113,   101,
     317,   318,   122,    77,   157,     4,    65,     5,     6,    46,
     195,    66,     8,   204,   205,    67,   133,    73,    74,   100,
     115,   232,    47,   114,    45,     4,   118,     5,     6,    46,
     119,   120,     8,   123,   116,   116,   174,   126,   176,   117,
     233,   124,    47,   137,   141,    21,   125,    35,   127,   145,
     148,   162,    87,    35,   156,   155,   171,   159,   128,   129,
      50,   130,    50,    80,     4,    21,     5,     6,     7,   131,
     132,     8,    81,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    82,    83,    84,    85,   146,   149,   150,    86,
     175,   134,     4,   177,     5,     6,   135,     3,     4,   178,
       5,     6,     7,   300,    21,     8,   184,   217,   221,   136,
     181,    87,   301,   302,   192,    18,   145,   186,   147,   246,
      56,    57,   185,   191,   162,   193,   162,   162,   194,   162,
     159,   198,   159,   159,   201,   159,   138,     4,    21,     5,
       6,   139,   196,    50,    58,    59,    60,    61,    62,    63,
     199,   206,    35,   200,   140,   257,   258,   207,   208,   209,
     264,   268,   210,   197,   211,   222,   212,   292,   292,   213,
     226,   240,   241,   242,   243,   224,   274,   278,    10,    11,
      12,    13,    14,    15,    16,    17,   227,   228,    35,   151,
     229,   257,   258,    10,    11,    12,    13,    14,    15,   230,
      17,   231,   245,   237,   292,   292,   244,   247,   250,    35,
      35,   260,   152,   269,   251,    52,    53,    54,    55,    80,
       4,    99,     5,     6,     7,   142,   270,     8,   310,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    82,    83,
     168,    85,   202,   203,   204,   205,    35,    35,   239,   279,
      68,     4,   252,     5,     6,    69,   282,   283,     8,   285,
      21,    80,     4,   291,     5,     6,     7,    87,    70,     8,
     284,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      82,    83,   168,    85,    58,    59,    60,    61,    62,    63,
     287,    21,   214,     4,   288,     5,     6,   215,    52,    53,
      54,    55,    21,    80,     4,   297,     5,     6,     7,    87,
     216,     8,   290,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    82,    83,   168,    85,    10,    11,    12,    13,
      14,    15,   298,    17,   218,     4,   299,     5,     6,   219,
     202,   203,   204,   205,    21,    80,     4,   320,     5,     6,
       7,    87,   220,     8,   303,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    82,    83,   168,    85,   234,   304,
     235,   236,   306,   238,   311,   305,   261,     4,   312,     5,
       6,   262,   314,   313,     2,   319,    21,     3,     4,   321,
       5,     6,     7,    87,   263,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     3,     4,    19,     5,
       6,     7,    20,   315,     8,   316,    10,    11,    12,    13,
      14,    15,   187,    17,    18,    91,   154,   253,    21,   225,
     259,     3,     4,     0,     5,     6,     7,     0,     0,     8,
       0,    10,    11,    12,    13,    14,    15,    21,    17,    18,
     254,     0,   253,     3,     4,     0,     5,     6,     7,     0,
       0,     8,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    21,     0,   168,   286,    56,    57,   265,     4,
       0,     5,     6,   266,     0,     0,     0,     0,   271,     4,
       0,     5,     6,   272,    21,     0,   267,     0,     0,     0,
      58,    59,    60,    61,    62,    63,   273,   275,     4,     0,
       5,     6,   276,   307,     4,     0,     5,     6,   308,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
       0,   309,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,   188
};

static const yytype_int16 yycheck[] =
{
       1,    44,    21,     1,     1,     1,    21,   251,   124,     3,
       4,     3,     6,     7,     8,     3,     4,    11,    45,    16,
      44,    30,    30,    30,     3,    52,    21,    21,     3,     4,
      30,     6,     7,    39,   150,    36,    44,    52,    53,    54,
      55,    36,    49,    44,    53,    53,    44,    44,    44,    49,
      44,    45,    43,     3,    46,     3,    44,    51,     8,    41,
      42,    56,    57,    58,    59,    60,    61,    62,    63,    44,
     314,   315,    44,    21,     3,     4,    43,     6,     7,     8,
      52,     3,    11,    41,    42,     3,   101,     3,    13,    45,
      30,    30,    21,    30,     3,     4,    30,     6,     7,     8,
       3,    45,    11,    44,    44,    44,   125,     3,   127,    49,
      49,    44,    21,   114,   115,    44,    44,   118,    44,   116,
     118,   122,    51,   124,   121,   121,   124,   122,     3,    43,
     125,    43,   127,     3,     4,    44,     6,     7,     8,     3,
       3,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     4,    48,    46,    29,
       3,     3,     4,    44,     6,     7,     8,     3,     4,    30,
       6,     7,     8,    30,    44,    11,     3,   178,   179,    21,
      46,    51,    39,    40,    43,    21,   183,     3,    24,   208,
       9,    10,    50,     3,   195,     3,   197,   198,     3,   200,
     195,    52,   197,   198,   165,   200,     3,     4,    44,     6,
       7,     8,    43,   208,    33,    34,    35,    36,    37,    38,
      45,    45,   223,    52,    21,   223,   223,     3,    48,     3,
     231,   232,     3,    52,    45,     4,    45,   280,   281,    45,
       3,   202,   203,   204,   205,    46,   247,   248,    13,    14,
      15,    16,    17,    18,    19,    20,     3,    47,   259,    24,
      43,   259,   259,    13,    14,    15,    16,    17,    18,     3,
      20,    30,     3,    43,   317,   318,    43,    30,    46,   280,
     281,     3,    47,     4,    46,    39,    40,    41,    42,     3,
       4,    45,     6,     7,     8,    45,    48,    11,   299,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    39,    40,    41,    42,   317,   318,    45,     4,
       3,     4,    50,     6,     7,     8,     3,    43,    11,     3,
      44,     3,     4,    47,     6,     7,     8,    51,    21,    11,
      43,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    33,    34,    35,    36,    37,    38,
      50,    44,     3,     4,     3,     6,     7,     8,    39,    40,
      41,    42,    44,     3,     4,    47,     6,     7,     8,    51,
      21,    11,    50,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    13,    14,    15,    16,
      17,    18,     3,    20,     3,     4,    30,     6,     7,     8,
      39,    40,    41,    42,    44,     3,     4,    47,     6,     7,
       8,    51,    21,    11,    45,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   195,    43,
     197,   198,    26,   200,     3,    43,     3,     4,    39,     6,
       7,     8,    46,    40,     0,     3,    44,     3,     4,    47,
       6,     7,     8,    51,    21,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     3,     4,    24,     6,
       7,     8,    28,    46,    11,    39,    13,    14,    15,    16,
      17,    18,   149,    20,    21,    44,   121,    24,    44,   183,
     224,     3,     4,    -1,     6,     7,     8,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    44,    20,    21,
      47,    -1,    24,     3,     4,    -1,     6,     7,     8,    -1,
      -1,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    44,    -1,    24,    47,     9,    10,     3,     4,
      -1,     6,     7,     8,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,     7,     8,    44,    -1,    21,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    21,     3,     4,    -1,
       6,     7,     8,     3,     4,    -1,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    21,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     3,     4,     6,     7,     8,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    24,
      28,    44,    56,    59,    61,    63,    64,    65,    67,    83,
      85,    91,    92,    93,    94,    95,    30,    53,     3,     8,
      44,    94,    39,     3,    68,     3,     8,    21,    61,    63,
      65,    95,    39,    40,    41,    42,     9,    10,    33,    34,
      35,    36,    37,    38,    43,    43,     3,     3,     3,     8,
      21,    65,    95,     3,    13,    57,     3,    21,     3,    46,
       3,    12,    22,    23,    24,    25,    29,    51,    69,    70,
      71,    74,    75,    76,    77,    84,    91,    93,    94,    45,
      45,    44,    61,    61,    61,    61,    65,    65,    65,    65,
      65,    65,    65,    65,    30,    30,    44,    49,    30,     3,
      45,    60,    44,    44,    44,    44,     3,    44,     3,    43,
      43,     3,     3,    61,     3,     8,    21,    95,     3,     8,
      21,    95,    45,    86,    87,    94,     4,    24,    91,    48,
      46,    24,    47,    66,    85,    93,    94,     3,    45,    65,
      70,    73,    95,     3,     4,    44,    62,    72,    24,    78,
      82,    91,    93,    94,    63,     3,    63,    44,    30,    30,
      49,    46,    45,    52,     3,    50,     3,    57,    24,    58,
      82,     3,    43,     3,     3,    52,    43,    52,    52,    45,
      52,    62,    39,    40,    41,    42,    45,     3,    48,     3,
       3,    45,    45,    45,     3,     8,    21,    95,     3,     8,
      21,    95,     4,    88,    46,    87,     3,     3,    47,    43,
       3,    30,    30,    49,    73,    73,    73,    43,    73,    45,
      62,    62,    62,    62,    43,     3,    63,    30,    30,    49,
      46,    46,    50,    24,    47,    89,    90,    91,    94,    88,
       3,     3,     8,    21,    95,     3,     8,    21,    95,     4,
      48,     3,     8,    21,    95,     3,     8,    21,    95,     4,
      80,    80,     3,    43,    43,     3,    47,    50,     3,    79,
      50,    47,    70,    74,    81,    82,    91,    47,     3,    30,
      30,    39,    40,    45,    43,    43,    26,     3,     8,    21,
      95,     3,    39,    40,    46,    46,    39,    80,    80,     3,
      47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    58,    59,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    70,    71,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    76,    77,
      78,    78,    79,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    86,    86,    87,
      88,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     1,     1,     7,
       4,     2,     1,     0,     2,     5,     3,     2,     0,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       5,     2,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     3,     2,     0,     2,     2,     1,     1,     1,     4,
       5,     4,     5,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     0,     1,     1,     1,     7,    11,    11,     7,
       1,     1,     3,     3,     5,     2,     0,     2,     1,     1,
       2,     0,     5,     2,     4,     4,     4,     4,     3,     4,
       4,     4,     4,     5,     2,     4,     4,     4,     4,     3,
       4,     4,     4,     4,     2,     4,     4,     4,     4,     5,
       3,     4,     4,     4,     4,     8,     7,     1,     3,     2,
       2,     0,     2,     2,     2,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
        case 19:
#line 214 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)+(yyvsp[0].int_number);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 215 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)-(yyvsp[0].int_number);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 216 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)*(yyvsp[0].int_number);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 217 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)/(yyvsp[0].int_number);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 218 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = (yyvsp[-1].int_number);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 219 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = atoi((yyvsp[0].textt));}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 220 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = evaluare_id((yyvsp[0].textt),"");}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 223 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)+(yyvsp[0].int_number);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)-(yyvsp[0].int_number);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 225 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)*(yyvsp[0].int_number);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 226 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=(yyvsp[-2].int_number)/(yyvsp[0].int_number);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = (yyvsp[-1].int_number);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "limbaj.y" /* yacc.c:1646  */
    { (yyval.int_number) = atoi((yyvsp[0].textt));}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 229 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = evaluare_id((yyvsp[0].textt),"eval");}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 257 "limbaj.y" /* yacc.c:1646  */
    { initializare_tip_id ("structura", (yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 258 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 259 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 260 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 261 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 262 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("structura",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 263 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 264 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 265 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 266 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("structura", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 288 "limbaj.y" /* yacc.c:1646  */
    { printf("\e[1;33mEval A returnat:%d\e[0m\n",(yyvsp[-2].int_number));}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 291 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number) = (yyvsp[0].int_number);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 343 "limbaj.y" /* yacc.c:1646  */
    { initializare_tip_id ("local", (yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 344 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 345 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 346 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 347 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 348 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("local",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 349 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 350 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 351 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 352 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("local", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 356 "limbaj.y" /* yacc.c:1646  */
    { initializare_tip_id ("global", (yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 357 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 358 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 359 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 360 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 361 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("global",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 362 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 363 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 364 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 365 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("global", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 368 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id ("main",(yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 369 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 370 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 371 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 372 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 374 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("main",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 375 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 376 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 377 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 378 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("main", (yyvsp[-3].textt), (yyvsp[-2].textt), (yyvsp[0].textt));}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 381 "limbaj.y" /* yacc.c:1646  */
    {initializare_functie((yyvsp[-7].textt),(yyvsp[-6].textt),(yyvsp[-4].textt));}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 382 "limbaj.y" /* yacc.c:1646  */
    {initializare_functie((yyvsp[-6].textt),(yyvsp[-5].textt),""); printf("Declarare de functie\n");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 385 "limbaj.y" /* yacc.c:1646  */
    {strcpy(params_list,(yyvsp[0].textt)); (yyval.textt)=params_list; }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 386 "limbaj.y" /* yacc.c:1646  */
    {strcat(params_list," "); strcat(params_list,(yyvsp[0].textt)); (yyval.textt)=params_list; }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 403 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id ("functie",(yyvsp[-1].textt), (yyvsp[0].textt)); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 404 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 405 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 406 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 407 "limbaj.y" /* yacc.c:1646  */
    {initializare_id("functie", (yyvsp[-3].textt), (yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 408 "limbaj.y" /* yacc.c:1646  */
    {initializare_tip_id("functie",(yyvsp[-1].textt), (yyvsp[0].textt));}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 412 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=asignare_numar((yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 420 "limbaj.y" /* yacc.c:1646  */
    {(yyval.int_number)=asignare_expresie((yyvsp[-2].textt),(yyvsp[0].textt));}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 428 "limbaj.y" /* yacc.c:1646  */
    {char c[30]; strcpy(c,(yyvsp[-1].textt)); strcat(c," "); strcat(c,(yyvsp[0].textt)); (yyval.textt) = c;}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 432 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "int";}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 433 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "float";}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 434 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "bool";}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 435 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "double";}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 436 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "char";}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 437 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "void";}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 438 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt) = "string";}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 441 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 442 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 443 "limbaj.y" /* yacc.c:1646  */
    {(yyval.textt)=(yyvsp[0].textt);}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2199 "y.tab.c" /* yacc.c:1646  */
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
#line 446 "limbaj.y" /* yacc.c:1906  */

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
