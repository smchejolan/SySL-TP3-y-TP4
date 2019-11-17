
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "TP4.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int lines = 1;

int flag_error=0;
extern FILE *yyout;
extern FILE *yyin;


struct nodoId *punteroId=NULL;
struct nodoFuncion *punteroFunc=NULL;
struct nodoVariable *punteroVariables=NULL;
struct nodoFuncion *funcionActual=NULL;
struct nodoVariable *parametros=NULL;
struct nodoVariable *actualDeclaracion = NULL;
struct nodoId *actualId  = NULL;
struct nodoVariable *ultimoVar;
struct nodoId *ultimoId;
int funciones=0;


/* Line 189 of yacc.c  */
#line 100 "TP4.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     LCADENA = 259,
     ID = 260,
     TIPODATO = 261,
     PRESERVADA = 262,
     MODALIDAD = 263,
     AND = 264,
     PUNTUACION = 265,
     INCREMENTO = 266,
     DECREMENTO = 267,
     SUMADIRECTA = 268,
     RESTADIRECTA = 269,
     OR = 270,
     VOID = 271,
     MAYORIGUAL = 272,
     MENORIGUAL = 273,
     PERTENECE = 274,
     DESIGUALDAD = 275,
     IGUALDAD = 276,
     RETURN = 277,
     IF = 278,
     DO = 279,
     WHILE = 280,
     ELSE = 281,
     FOR = 282,
     TYPEDEF = 283,
     STRUCT = 284,
     SIZEOF = 285,
     SWITCH = 286,
     CASE = 287,
     BREAK = 288,
     CONTINUE = 289,
     CONTROLOTRA = 290,
     OPERADOR = 291,
     CONDICION = 292,
     DEFAULT = 293,
     NEG = 294,
     POS = 295,
     PUNT = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "TP4.y"

    struct{
    char cadena[50];
    double valor;
    int tipo;
  }s; 



/* Line 214 of yacc.c  */
#line 187 "TP4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "TP4.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,     2,    44,     2,
      53,    54,    39,    41,    43,    42,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    56,
      58,    48,    57,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    18,    19,
      22,    24,    26,    28,    30,    32,    34,    36,    39,    42,
      48,    54,    61,    68,    69,    71,    75,    78,    81,    83,
      87,    89,    91,    94,   102,   108,   114,   120,   128,   138,
     141,   144,   148,   149,   151,   153,   155,   159,   161,   163,
     165,   167,   173,   175,   179,   181,   185,   187,   191,   194,
     196,   200,   202,   204,   206,   208,   210,   214,   218,   220,
     224,   228,   230,   233,   236,   239,   242,   245,   248,   250,
     252,   254,   259,   264,   266,   270,   272,   274
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    -1,    63,    64,    -1,    55,    -1,    67,
      -1,    67,    55,    -1,    49,    66,    50,    -1,    -1,    64,
      66,    -1,    65,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    68,    -1,    70,    -1,    73,    56,    -1,    69,
      56,    -1,     6,     5,    53,    71,    54,    -1,    16,     5,
      53,    71,    54,    -1,     6,     5,    53,    71,    54,    65,
      -1,    16,     5,    53,    71,    54,    65,    -1,    -1,    72,
      -1,    71,    43,    72,    -1,     6,     5,    -1,     6,    74,
      -1,    75,    -1,    75,    43,    74,    -1,     5,    -1,    56,
      -1,    81,    56,    -1,    23,    53,    81,    54,    67,    26,
      67,    -1,    23,    53,    81,    54,    67,    -1,    31,    53,
      81,    54,    67,    -1,    25,    53,    81,    54,    67,    -1,
      24,    67,    25,    53,    81,    54,    56,    -1,    27,    53,
      80,    56,    80,    56,    80,    54,    65,    -1,    34,    56,
      -1,    33,    56,    -1,    22,    81,    56,    -1,    -1,    81,
      -1,    82,    -1,    84,    -1,    93,    83,    82,    -1,    48,
      -1,    13,    -1,    14,    -1,    85,    -1,    85,    47,    81,
      46,    81,    -1,    86,    -1,    85,    15,    86,    -1,    87,
      -1,    86,     9,    87,    -1,    89,    -1,    87,    88,    89,
      -1,    21,    20,    -1,    91,    -1,    89,    90,    91,    -1,
      57,    -1,    58,    -1,    18,    -1,    17,    -1,    92,    -1,
      91,    41,    92,    -1,    91,    42,    92,    -1,    93,    -1,
      92,    39,    93,    -1,    92,    40,    93,    -1,    95,    -1,
      93,    11,    -1,    93,    12,    -1,    94,    93,    -1,    42,
      93,    -1,    41,    93,    -1,    39,    93,    -1,    44,    -1,
      45,    -1,    97,    -1,    95,    51,    81,    52,    -1,    95,
      53,    96,    54,    -1,    82,    -1,    96,    43,    82,    -1,
       3,    -1,     5,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    58,    59,    60,    63,    65,    66,
      72,    73,    74,    75,    76,    77,    78,    81,    84,    86,
      96,   107,   117,   129,   130,   131,   133,   135,   151,   152,
     154,   162,   163,   165,   166,   167,   169,   170,   171,   173,
     174,   175,   177,   178,   180,   183,   184,   195,   196,   197,
     199,   200,   202,   203,   209,   210,   216,   217,   224,   226,
     227,   234,   234,   234,   234,   236,   237,   243,   250,   251,
     257,   264,   265,   271,   277,   278,   279,   280,   282,   282,
     284,   285,   286,   288,   289,   291,   292,   293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "LCADENA", "ID", "TIPODATO",
  "PRESERVADA", "MODALIDAD", "AND", "PUNTUACION", "INCREMENTO",
  "DECREMENTO", "SUMADIRECTA", "RESTADIRECTA", "OR", "VOID", "MAYORIGUAL",
  "MENORIGUAL", "PERTENECE", "DESIGUALDAD", "IGUALDAD", "RETURN", "IF",
  "DO", "WHILE", "ELSE", "FOR", "TYPEDEF", "STRUCT", "SIZEOF", "SWITCH",
  "CASE", "BREAK", "CONTINUE", "CONTROLOTRA", "OPERADOR", "CONDICION",
  "DEFAULT", "'*'", "'/'", "'+'", "'-'", "','", "'&'", "'!'", "':'", "'?'",
  "'='", "'{'", "'}'", "'['", "']'", "'('", "')'", "'\\n'", "';'", "'>'",
  "'<'", "NEG", "POS", "PUNT", "$accept", "input", "line",
  "sentenciaCompuesta", "listaCompuesta", "sentencia", "declaracion",
  "declaracionFuncion", "definicionFuncion", "listaDeParametros",
  "parametro", "declaracionVariable", "listaDeVariables", "variable",
  "sentenciaExpresion", "sentenciaSeleccion", "sentenciaIteracion",
  "sentenciaSalto", "expresionOP", "expresion", "expresionAsignacion",
  "operacionAsignacion", "expresionCondicional", "expresionOr",
  "expresionAnd", "expresionIgualdad", "operadorComparacion",
  "expresionRelacional", "operadorRelacional", "expresionAditiva",
  "expresionMultiplicativa", "expresionUnaria", "operadorUnario",
  "expresionPostfijo", "listaDeArgumentos", "expresionPrimaria", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    42,
      47,    43,    45,    44,    38,    33,    58,    63,    61,   123,
     125,    91,    93,    40,    41,    10,    59,    62,    60,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    72,    73,    74,    74,
      75,    76,    76,    77,    77,    77,    78,    78,    78,    79,
      79,    79,    80,    80,    81,    82,    82,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    97,    97,    97
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     5,
       5,     6,     6,     0,     1,     3,     2,     2,     1,     3,
       1,     1,     2,     7,     5,     5,     5,     7,     9,     2,
       2,     3,     0,     1,     1,     1,     3,     1,     1,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     2,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     4,     4,     1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    85,    87,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     8,     4,    31,     3,    10,     5,    15,     0,    16,
       0,    11,    12,    13,    14,     0,    44,    45,    50,    52,
      54,    56,    59,    65,    68,     0,    71,    80,    30,    27,
      28,     0,     0,     0,     0,     0,    42,     0,    40,    39,
      77,    76,    75,     8,     0,     6,    18,    17,    32,     0,
       0,     0,     0,     0,    64,    63,    61,    62,     0,     0,
       0,     0,     0,    72,    73,    48,    49,    47,     0,    74,
       0,     0,    23,     0,    23,    41,     0,     0,     0,     0,
      43,     0,     9,     7,    53,    68,     0,    55,    58,    57,
      60,    66,    67,    69,    70,    46,     0,    83,     0,     0,
       0,    24,    30,    29,     0,     0,     0,     0,    42,     0,
       0,    81,     0,    82,    26,     0,    19,    20,    34,     0,
      36,     0,    35,    51,    84,    25,    21,    22,     0,     0,
      42,    33,    37,     0,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    63,    25,    64,    26,    27,    28,    29,   120,
     121,    30,    49,    50,    31,    32,    33,    34,    99,    35,
      36,    88,    37,    38,    39,    40,    73,    41,    78,    42,
      43,    44,    45,    46,   118,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -129
static const yytype_int16 yypact[] =
{
    -129,   124,  -129,  -129,  -129,  -129,    32,    33,    39,   -14,
      70,   -13,   -12,    -7,    -6,     1,    39,    39,    39,  -129,
    -129,   171,  -129,  -129,  -129,  -129,     4,  -129,     5,  -129,
      12,  -129,  -129,  -129,  -129,    13,  -129,  -129,   -11,    51,
      49,    -5,   -18,   -24,     7,    39,   -22,  -129,    18,  -129,
      29,    24,    23,    39,    60,    39,    39,    39,  -129,  -129,
      21,    21,    21,   171,    37,  -129,  -129,  -129,  -129,    39,
      39,    39,    68,    39,  -129,  -129,  -129,  -129,    39,    39,
      39,    39,    39,  -129,  -129,  -129,  -129,  -129,    39,    21,
      39,    39,    83,    85,    83,  -129,    42,    38,    44,    43,
    -129,    46,  -129,  -129,    51,    21,    56,    49,  -129,    -5,
     -18,   -24,   -24,    21,    21,  -129,    53,  -129,   -32,   101,
     -29,  -129,  -129,  -129,   -26,    70,    39,    70,    39,    70,
      39,  -129,    39,  -129,  -129,    83,    58,    58,    82,    59,
    -129,    54,  -129,  -129,  -129,  -129,  -129,  -129,    70,    61,
      39,  -129,  -129,    62,    58,  -129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   130,  -128,    69,    -4,  -129,  -129,  -129,    40,
      -2,  -129,    45,  -129,  -129,  -129,  -129,  -129,  -123,    -8,
     -81,  -129,  -129,  -129,    66,    65,  -129,    64,  -129,    63,
     -45,   -15,  -129,  -129,  -129,  -129
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    60,    61,    62,    69,   141,    54,   115,   146,   147,
     117,   132,    74,    75,   135,    81,    82,   135,    83,    84,
      85,    86,   133,    79,    80,   136,   155,   153,   137,    90,
      89,    91,    83,    84,   111,   112,    70,    48,    51,    53,
      55,    56,     3,     4,     5,    96,    57,    98,   100,   101,
      58,   144,    76,    77,   105,    87,   105,    59,   105,    65,
      71,    66,   106,   105,   105,   105,   113,   114,    67,    68,
      72,    92,    93,     3,     4,     5,     6,    94,    16,    95,
      17,    18,   116,    19,    20,    97,     7,   103,   108,   119,
     122,   126,     8,     9,    10,    11,   125,    12,   127,   128,
     129,    13,   130,    14,    15,   131,   134,    21,   148,    16,
     150,    17,    18,   149,    19,    20,   154,   152,   139,    21,
     100,   138,   143,   140,     2,   142,    23,     3,     4,     5,
       6,    24,   102,   145,   124,   104,   107,   109,   123,     0,
       7,   110,   100,     0,   151,     0,     8,     9,    10,    11,
       0,    12,     0,     0,     0,    13,     0,    14,    15,     0,
       0,     0,     0,    16,     0,    17,    18,     0,    19,    20,
       0,     0,     0,    21,     3,     4,     5,     6,     0,    22,
      23,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     8,     9,    10,    11,     0,    12,     0,
       0,     0,    13,     0,    14,    15,     0,     0,     0,     0,
      16,     0,    17,    18,     0,    19,    20,     0,     0,     0,
      21,     0,     0,     0,     0,     0,    22,    23
};

static const yytype_int16 yycheck[] =
{
       8,    16,    17,    18,    15,   128,    10,    88,   136,   137,
      91,    43,    17,    18,    43,    39,    40,    43,    11,    12,
      13,    14,    54,    41,    42,    54,   154,   150,    54,    51,
      45,    53,    11,    12,    79,    80,    47,     5,     5,    53,
      53,    53,     3,     4,     5,    53,    53,    55,    56,    57,
      56,   132,    57,    58,    69,    48,    71,    56,    73,    55,
       9,    56,    70,    78,    79,    80,    81,    82,    56,    56,
      21,    53,    43,     3,     4,     5,     6,    53,    39,    56,
      41,    42,    90,    44,    45,    25,    16,    50,    20,     6,
       5,    53,    22,    23,    24,    25,    54,    27,    54,    56,
      54,    31,    46,    33,    34,    52,     5,    49,    26,    39,
      56,    41,    42,    54,    44,    45,    54,    56,   126,    49,
     128,   125,   130,   127,     0,   129,    56,     3,     4,     5,
       6,     1,    63,   135,    94,    69,    71,    73,    93,    -1,
      16,    78,   150,    -1,   148,    -1,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,    39,    -1,    41,    42,    -1,    44,    45,
      -1,    -1,    -1,    49,     3,     4,     5,     6,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    31,    -1,    33,    34,    -1,    -1,    -1,    -1,
      39,    -1,    41,    42,    -1,    44,    45,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     3,     4,     5,     6,    16,    22,    23,
      24,    25,    27,    31,    33,    34,    39,    41,    42,    44,
      45,    49,    55,    56,    64,    65,    67,    68,    69,    70,
      73,    76,    77,    78,    79,    81,    82,    84,    85,    86,
      87,    89,    91,    92,    93,    94,    95,    97,     5,    74,
      75,     5,    81,    53,    67,    53,    53,    53,    56,    56,
      93,    93,    93,    64,    66,    55,    56,    56,    56,    15,
      47,     9,    21,    88,    17,    18,    57,    58,    90,    41,
      42,    39,    40,    11,    12,    13,    14,    48,    83,    93,
      51,    53,    53,    43,    53,    56,    81,    25,    81,    80,
      81,    81,    66,    50,    86,    93,    81,    87,    20,    89,
      91,    92,    92,    93,    93,    82,    81,    82,    96,     6,
      71,    72,     5,    74,    71,    54,    53,    54,    56,    54,
      46,    52,    43,    54,     5,    43,    54,    54,    67,    81,
      67,    80,    67,    81,    82,    72,    65,    65,    26,    54,
      56,    67,    56,    80,    54,    65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 58 "TP4.y"
    {lines++;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 60 "TP4.y"
    {lines ++;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 72 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (1)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (1)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (1)].s.tipo);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 73 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (1)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (1)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (1)].s.tipo);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 74 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (1)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (1)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (1)].s.tipo);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 75 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (1)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (1)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (1)].s.tipo);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 76 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (1)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (1)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (1)].s.tipo);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 77 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (1)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (1)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (1)].s.tipo);}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 81 "TP4.y"
    {
                                                  actualId = NULL;
                                                  actualDeclaracion = NULL;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 84 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (2)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (2)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (2)].s.tipo);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 86 "TP4.y"
    {
                                                                        if(controlId(punteroId,(yyvsp[(2) - (5)].s.cadena))){
                                                                        punteroId=agregarId(punteroId,(yyvsp[(2) - (5)].s.cadena),tipoDeDato((yyvsp[(1) - (5)].s.cadena)));
                                                                        punteroFunc=agregarFuncion(punteroFunc,(yyvsp[(2) - (5)].s.cadena),(yyvsp[(1) - (5)].s.cadena));
                                                                        funcionActual=ultimoDeLaLista(punteroFunc);
                                                                        funcionActual->parametros=asignar(parametros);
                                                                        parametros=NULL;
                                                                        }else{
                                                                          yyerror("Ya existe la variable");
                                                                        flag_error==1;};}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 96 "TP4.y"
    {
                                                                        if(controlId(punteroId,(yyvsp[(2) - (5)].s.cadena))){
                                                                        punteroId=agregarId(punteroId,(yyvsp[(2) - (5)].s.cadena),tipoDeDato((yyvsp[(1) - (5)].s.cadena)));
                                                                        punteroFunc=agregarFuncion(punteroFunc,(yyvsp[(2) - (5)].s.cadena),(yyvsp[(1) - (5)].s.cadena));
                                                                        funcionActual=ultimoDeLaLista(punteroFunc);
                                                                        funcionActual->parametros=asignar(parametros);
                                                                        parametros=NULL;
                                                                        }else{
                                                                          yyerror("Ya existe la variable");
                                                                          flag_error==1;};}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 107 "TP4.y"
    {
                                                                            if(controlId(punteroId,(yyvsp[(2) - (6)].s.cadena))){
                                                                            punteroId=agregarId(punteroId,(yyvsp[(2) - (6)].s.cadena),tipoDeDato((yyvsp[(1) - (6)].s.cadena)));
                                                                            punteroFunc=agregarFuncion(punteroFunc,(yyvsp[(2) - (6)].s.cadena),(yyvsp[(1) - (6)].s.cadena));
                                                                            funcionActual=ultimoDeLaLista(punteroFunc);
                                                                            funcionActual->parametros=asignar(parametros);
                                                                            parametros=NULL;
                                                                            }else{
                                                                              yyerror("Ya existe la variable");
                                                                              flag_error==1;};}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 117 "TP4.y"
    {
                                                                        if(controlId(punteroId,(yyvsp[(2) - (6)].s.cadena))){
                                                                        punteroId=agregarId(punteroId,(yyvsp[(2) - (6)].s.cadena),tipoDeDato((yyvsp[(1) - (6)].s.cadena)));
                                                                        punteroFunc=agregarFuncion(punteroFunc,(yyvsp[(2) - (6)].s.cadena),(yyvsp[(1) - (6)].s.cadena));
                                                                        funcionActual=ultimoDeLaLista(punteroFunc);
                                                                        funcionActual->parametros=asignar(parametros);
                                                                        parametros=NULL;
                                                                        }else{
                                                                          yyerror("Ya existe la variable");
                                                                          flag_error==1;};}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 133 "TP4.y"
    {parametros=agregarVariable(parametros,(yyvsp[(2) - (2)].s.cadena),(yyvsp[(1) - (2)].s.cadena));/*mostrarListaVariables(parametros);*/;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 135 "TP4.y"
    { 
                                                aplicarTipoVar(actualDeclaracion,(yyvsp[(1) - (2)].s.cadena));
                                                aplicarTipoId(actualId,tipoDeDato((yyvsp[(1) - (2)].s.cadena)));
                                                ultimoId=ultimoDeLaListaId(punteroId);
                                                ultimoVar=ultimoDeLaListaVar(punteroVariables);
                                                if(ultimoId==NULL){
                                                  punteroId = actualId;
                                                }else{;
                                                  ultimoId->next = actualId;
                                                }
                                                if(ultimoVar == NULL){
                                                  punteroVariables = actualDeclaracion;
                                                }else{
                                                 ultimoVar->next = actualDeclaracion;
                                                };}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 154 "TP4.y"
    {  
                                if(controlId(punteroId,(yyvsp[(1) - (1)].s.cadena)) && controlId(actualId,(yyvsp[(1) - (1)].s.cadena))){
                                  actualDeclaracion=agregarVariable(actualDeclaracion,(yyvsp[(1) - (1)].s.cadena),"");
                                  actualId=agregarId(actualId,(yyvsp[(1) - (1)].s.cadena),0);
                                }else{
                                  yyerror("Ya existe la variable");
                                  flag_error==1;};}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 163 "TP4.y"
    {(yyval.s.tipo) = (yyvsp[(1) - (2)].s.tipo); strcpy((yyval.s.cadena),(yyvsp[(1) - (2)].s.cadena));(yyval.s.tipo)=(yyvsp[(1) - (2)].s.tipo);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 184 "TP4.y"
    { 
                                                                                  if(lvalueError((yyvsp[(1) - (3)].s.cadena))){
                                                                                  printf("Error de lValue");
                                                                                  }else{
                                                                                  if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                                    (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo); 
                                                                                    strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                                  }else{
                                                                                    printf("Error de tipos");
                                                                                    flag_error=1;YYERROR;}};}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 203 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 210 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 217 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          (yyval.s.tipo)=(yyvsp[(1) - (3)].s.tipo);
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 227 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          (yyval.s.tipo)=(yyvsp[(1) - (3)].s.tipo);
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 237 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          (yyval.s.tipo)=(yyvsp[(1) - (3)].s.tipo);
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 243 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          (yyval.s.tipo)=(yyvsp[(1) - (3)].s.tipo);
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 251 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          (yyval.s.tipo)=(yyvsp[(1) - (3)].s.tipo);
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 257 "TP4.y"
    {if(controlOperacion(punteroId,(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena),(yyvsp[(1) - (3)].s.tipo),(yyvsp[(3) - (3)].s.tipo))){
                                                                          (yyval.s.tipo) = (yyvsp[(1) - (3)].s.tipo);
                                                                          strcpy((yyval.s.cadena),(yyvsp[(1) - (3)].s.cadena));
                                                                          (yyval.s.tipo)=(yyvsp[(1) - (3)].s.tipo);
                                                                          }else{
                                                                          flag_error=1;YYERROR;};}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 265 "TP4.y"
    {  if(!lvalueError((yyvsp[(1) - (2)].s.cadena))){
                                                  (yyval.s.tipo) = (yyvsp[(1) - (2)].s.tipo);
                                                  strcpy((yyval.s.cadena),(yyvsp[(1) - (2)].s.cadena));
                                                  }else{
                                                    printf("Error de lValue");
                                                    flag_error=1;YYERROR;};}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 271 "TP4.y"
    {  if(!lvalueError((yyvsp[(1) - (2)].s.cadena))){
                                                  (yyval.s.tipo) = (yyvsp[(1) - (2)].s.tipo);
                                                  strcpy((yyval.s.cadena),(yyvsp[(1) - (2)].s.cadena));
                                                  }else{
                                                    printf("Error de lValue");
                                                    flag_error=1;YYERROR;};}
    break;



/* Line 1455 of yacc.c  */
#line 1875 "TP4.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 299 "TP4.y"


yyerror (s)  
{
   printf ("Hubo un error en la linea %d",lines);
}

int main ()
{
  yyout = fopen("salida.txt","w");
  yyin = fopen("entrada.txt","r+");
  yyparse ();
 	printf("-------------Variables-------------\n");
  mostrarListaVariables(punteroVariables);
	printf("-------------Funciones-------------\n");
  mostrarListaFuncion(punteroFunc);
}

