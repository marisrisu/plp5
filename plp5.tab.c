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
#line 45 "plp5.y" /* yacc.c:339  */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "comun.h"
#include <sstream>


using namespace std;

// variables y funciones del A. Léxico
extern int ncol,nlin,findefichero;

int nTempMin = 16000;
int nTempMax = 16384;
int nVarActual = 0;
int nTempActual = 16000;
//extern int tmp;
extern int yylex();
extern char *yytext;
extern FILE *yyin;

int contIdType = 4;
int yyerror(char *s);


int ptr_mem = 0;
int ptr_mem_temp = MAX_MEM+1;
int ptr_label = 0;

string operador, s1, s2;  // string auxiliares

typedef struct simbolo_t {
  string  lexema;
  int   dir;
  bool  esArray;
  int   idTipo;
  int   lin,col;
}simbolo;

typedef struct tipo_t {
    int tipo;
    int size;
    int tipo_base;
    tipo_t() : tipo(0), size(0)
    {}
}tipo;

struct find_simbolo : std::unary_function<simbolo_t, bool>
{
  std::string lexema;
  find_simbolo(std::string l):lexema(l){}
  bool operator()(simbolo_t const& s) const
  { return s.lexema == lexema; }
};

typedef struct tabla_simbolos_t 
{
  const char* nombre;
  struct tabla_simbolos_t* ts_padre;
  std::vector<simbolo_t> simbolos;      
}tabla_simbolos;

bool lexema_existe(const char* lexema);
void print_tabla_simbolos();
void crear_ambito(const char* nombre);
void destruir_ambito_actual();
void destroy();
int NTemp();
int getDir();
std::string relopToM2R(const char *relop, int tipo);
std::string addopToM2R(const char *relop, int tipo);
std::string mulopToM2R(const char *relop, int tipo);
// Variables globales
struct tabla_simbolos_t* ambito;

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

// tabla simbolos
std::vector<simbolo_t> simbolos;
// tabla de tipos
vector<tipo> tabla_tipos;
// añadir simbolo a la tabla actual
void nuevoSimbolo(char* lexema,bool esArray, int idTipo,int nlin,int ncol);
//void nuevoSimbolo(simbolo_t& s, const int& tipo);
// recuperar simbolo por lexema (simbolo debe contener lexema al llamar a la funcion)
bool buscarSimbolo(simbolo_t& simbolo); 
// True si el simbolo ya esta declarado
bool existeSimbolo(const char* simbolo);

int NTemp();
// Devuelve el struct de un tipo
//bool buscarTipo(int tipo_buscado, tipo_t& t);

int buscarTipoSimbolo(const char* lexema);
bool buscarTipo(int, tipo_t&);
int tipoBase(int tipo);

// Inicializa tabla tipos con los basicos
void inicializarTablaTipos();
// añade un tipo array la tabla de tipos
int nuevoTipo(int tam,int tipo);

bool esBase(int tipo);

int buscarDir(const char* lexema);
void print_tabla_tipos();

#line 185 "plp5.tab.c" /* yacc.c:339  */

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
   by #include "plp5.tab.h".  */
#ifndef YY_YY_PLP5_TAB_H_INCLUDED
# define YY_YY_PLP5_TAB_H_INCLUDED
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
    boolean_ = 258,
    int_ = 259,
    double_ = 260,
    main_ = 261,
    system_ = 262,
    out_ = 263,
    in_ = 264,
    println_ = 265,
    print_ = 266,
    string_ = 267,
    class_ = 268,
    import_ = 269,
    new_ = 270,
    public_ = 271,
    static_ = 272,
    void_ = 273,
    scanner_ = 274,
    nextInt_ = 275,
    nextDouble_ = 276,
    if_ = 277,
    else_ = 278,
    while_ = 279,
    true_ = 280,
    false_ = 281,
    coma_ = 282,
    pyc_ = 283,
    punto_ = 284,
    pari_ = 285,
    pard_ = 286,
    relop_ = 287,
    addop_ = 288,
    mulop_ = 289,
    asig_ = 290,
    cori_ = 291,
    cord_ = 292,
    llavei_ = 293,
    llaved_ = 294,
    and_ = 295,
    or_ = 296,
    not_ = 297,
    nentero = 298,
    nreal = 299,
    id = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PLP5_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "plp5.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   175,   180,   185,   189,   194,   199,   205,
     211,   220,   228,   238,   243,   247,   252,   252,   259,   259,
     271,   280,   284,   289,   289,   297,   307,   316,   316,   324,
     334,   339,   343,   347,   353,   365,   375,   384,   388,   392,
     397,   397,   406,   413,   413,   422,   429,   429,   468,   475,
     475,   509,   516,   516,   550,   557,   564,   576,   588,   595,
     602,   609,   616,   622,   632,   632,   681,   699,   699
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "boolean_", "int_", "double_", "main_",
  "system_", "out_", "in_", "println_", "print_", "string_", "class_",
  "import_", "new_", "public_", "static_", "void_", "scanner_", "nextInt_",
  "nextDouble_", "if_", "else_", "while_", "true_", "false_", "coma_",
  "pyc_", "punto_", "pari_", "pard_", "relop_", "addop_", "mulop_",
  "asig_", "cori_", "cord_", "llavei_", "llaved_", "and_", "or_", "not_",
  "nentero", "nreal", "id", "$accept", "S", "Import", "SecImp", "Class",
  "Main", "Tipo", "Bloque", "BDecl", "DVar", "@1", "@2", "DimSN",
  "Dimensiones", "@3", "LIdent", "@4", "Variable", "SeqInstr", "Instr",
  "Expr", "$@5", "EConj", "$@6", "ERel", "$@7", "Esimple", "$@8", "Term",
  "$@9", "Factor", "$@10", "Ref", "$@11", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -90,    20,    64,   -90,    -1,    41,   -90,   -90,    53,    12,
     -90,   -14,   -10,   -90,   -90,    45,    62,    44,    71,   -90,
      91,    68,    87,    65,    63,    57,    73,    67,   -90,   -90,
      13,   -90,   -90,   -90,    58,    70,   -90,    -3,    74,    76,
     -90,     5,    78,    80,    81,   -90,   -90,   -90,   -90,   -90,
      50,    93,   -90,    60,    69,    79,    77,   107,    26,    26,
      26,   -90,    98,    69,   -90,   -90,   -90,   -90,   103,    90,
     -90,   -90,     4,    26,   -90,   -90,    92,   -17,    82,   -90,
      59,    86,   -90,    88,    -8,   -15,    26,    95,   -90,    72,
      83,   -90,    31,   -90,    75,    15,   -90,   -90,   -90,   -90,
     -90,    15,   -90,    22,   116,   -90,    96,    97,    99,   -90,
     101,   102,   105,    26,    26,    26,    26,    26,   -90,   -90,
     100,   104,    26,    26,    26,   106,   108,    15,    82,   -90,
     109,    86,   -90,   124,   110,   113,    32,    43,    94,   -90,
     -90,   -90,   112,   111,   -90,   117,   118,   119,   121,   -90,
     -90,   -90,   104,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     2,     7,     0,     0,
       3,     0,     0,     6,     5,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     9,
      31,    12,    10,    11,     0,    16,    14,     0,     0,     0,
      27,     0,     0,     0,     0,    32,    13,    66,    33,    30,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    17,    29,    28,    21,     0,     0,
      60,    61,     0,     0,    58,    59,    66,     0,    42,    45,
      48,    51,    54,    55,     0,     0,     0,     0,    26,     0,
       0,    64,     0,    63,     0,     0,    40,    43,    46,    49,
      52,     0,    34,     0,     0,    18,     0,     0,     0,    62,
       0,     0,    37,     0,     0,     0,     0,     0,    39,    68,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    44,
      47,    50,    53,     0,     0,     0,     0,     0,    65,    56,
      57,    38,     0,     0,    19,     0,     0,     0,    23,    35,
      36,    20,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -90,   -90,   -62,   123,   -90,   -90,
     -90,   -90,   -90,   -18,   -90,   -90,   -90,    89,   -90,   -89,
     -57,   -90,    23,   -90,    24,   -90,   -75,   -90,    28,   -90,
     -72,   -90,   -37,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     6,    17,    35,    48,    30,    36,
      40,   121,    41,   135,   152,    53,    54,    66,    37,    49,
      77,   113,    78,   114,    79,   115,    80,   116,    81,   117,
      82,   108,    83,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    93,    84,    85,    42,    13,   112,    31,    32,    33,
      91,   103,   118,   102,    95,    92,    31,    32,    33,    43,
       3,    44,    42,   101,    96,    45,    96,   105,    15,    70,
      71,    14,    34,    96,    72,    28,    46,    43,   141,    44,
     130,    55,    47,    45,     7,   132,    73,    74,    75,    76,
      56,    70,    71,    28,     9,    99,    72,    12,    50,   119,
      47,    16,   109,   145,    50,   136,   137,   138,    73,    74,
      75,    76,    96,    96,   146,    31,    32,    33,     4,    18,
       5,    10,    11,    19,    96,    60,    61,    63,    64,    20,
      50,    98,    99,   106,   107,   110,   111,    21,    22,    23,
      25,    24,    26,    38,    27,    28,    39,    57,    62,    51,
      58,    59,    68,    52,    65,    69,    67,    87,    89,    90,
     100,    94,    97,   120,    61,   104,   122,   123,   127,   133,
     124,   125,   126,   142,   153,    96,   128,   139,   129,   140,
     134,   144,    99,   147,   131,   149,   150,   151,   148,   -25,
      29,     0,    88,   143
};

static const yytype_int16 yycheck[] =
{
      37,    73,    59,    60,     7,    19,    95,     3,     4,     5,
      72,    86,   101,    28,    31,    72,     3,     4,     5,    22,
       0,    24,     7,    31,    41,    28,    41,    89,    38,    25,
      26,    45,    19,    41,    30,    38,    39,    22,   127,    24,
     115,    36,    45,    28,    45,   117,    42,    43,    44,    45,
      45,    25,    26,    38,    13,    33,    30,    45,    95,    37,
      45,    16,    31,    31,   101,   122,   123,   124,    42,    43,
      44,    45,    41,    41,    31,     3,     4,     5,    14,    17,
      16,    28,    29,    39,    41,    35,    36,    27,    28,    18,
     127,    32,    33,    10,    11,    20,    21,     6,    30,    12,
      37,    36,    45,    45,    31,    38,    36,    29,    15,    35,
      30,    30,    35,    37,    45,     8,    37,    19,    15,    29,
      34,    29,    40,     7,    36,    30,    30,    30,    23,    29,
      31,    30,    30,     9,   152,    41,   113,    31,   114,    31,
      36,    28,    33,    31,   116,    28,    28,    28,    37,    28,
      27,    -1,    63,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,    14,    16,    50,    45,    49,    13,
      28,    29,    45,    19,    45,    38,    16,    51,    17,    39,
      18,     6,    30,    12,    36,    37,    45,    31,    38,    53,
      54,     3,     4,     5,    19,    52,    55,    64,    45,    36,
      56,    58,     7,    22,    24,    28,    39,    45,    53,    65,
      78,    35,    37,    61,    62,    36,    45,    29,    30,    30,
      35,    36,    15,    27,    28,    45,    63,    37,    35,     8,
      25,    26,    30,    42,    43,    44,    45,    66,    68,    70,
      72,    74,    76,    78,    66,    66,    79,    19,    63,    15,
      29,    52,    66,    76,    29,    31,    41,    40,    32,    33,
      34,    31,    28,    72,    30,    52,    10,    11,    77,    31,
      20,    21,    65,    67,    69,    71,    73,    75,    65,    37,
       7,    57,    30,    30,    31,    30,    30,    23,    68,    70,
      72,    74,    76,    29,    36,    59,    66,    66,    66,    31,
      31,    65,     9,    43,    28,    31,    31,    31,    37,    28,
      28,    28,    60,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    51,
      52,    52,    52,    53,    54,    54,    56,    55,    57,    55,
      55,    58,    58,    60,    59,    59,    61,    62,    61,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      67,    66,    66,    69,    68,    68,    71,    70,    70,    73,
      72,    72,    75,    74,    74,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    76,    78,    79,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     0,     3,     3,     1,     6,    11,
       1,     1,     1,     4,     2,     0,     0,     4,     0,     9,
      11,     3,     2,     0,     5,     3,     3,     0,     2,     1,
       2,     0,     1,     1,     4,     9,     9,     5,     7,     5,
       0,     4,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     1,     1,     5,     5,     1,     1,
       1,     1,     3,     2,     0,     5,     1,     0,     5
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
        case 2:
#line 166 "plp5.y" /* yacc.c:1646  */
    {
	if(DEBUG) std::cout << " - Leído S...\n";
	(yyval).cod =(yyvsp[0]).cod + "halt";

			int tk = yylex();
            if (tk != 0) yyerror("");
            cout << (yyval).cod << endl;
}
#line 1471 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 175 "plp5.y" /* yacc.c:1646  */
    {
	if(DEBUG) std::cout << " - Leído Import 1...\n";
	(yyval).cod = (yyvsp[-3]).cod + (yyvsp[-1]).cod;
	//No hace nada?
}
#line 1481 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 180 "plp5.y" /* yacc.c:1646  */
    {
	//No hace nada?
	    	if(DEBUG) std::cout << " - Leído Import 2...\n";
	   }
#line 1490 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 185 "plp5.y" /* yacc.c:1646  */
    {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído SecImp 1...\n";
	}
#line 1499 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 189 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SecImp 2...\n";
	    	//$$.cod = $1.cod;
	//No hace nada?
	   }
#line 1509 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SecImp 3...\n";
	//No hace nada?
	   }
#line 1518 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 199 "plp5.y" /* yacc.c:1646  */
    {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído Class...\n";
		(yyval).cod = (yyvsp[-1]).cod;
}
#line 1528 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 205 "plp5.y" /* yacc.c:1646  */
    {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído Main...\n";
		(yyval).cod = (yyvsp[0]).cod;
}
#line 1538 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Tipo 1...\n";
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).nlin = nlin;
		(yyval).ncol = ncol;
		(yyval).tipo = ENTERO;

	}
#line 1552 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 220 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Tipo 2...\n";
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).tipo = REAL;
		(yyval).nlin = nlin;
		(yyval).ncol = ncol;
	 }
#line 1565 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 228 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Tipo 3...\n";
	  	ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).tipo = BOOLEANO;
		(yyval).nlin = nlin;
		(yyval).ncol = ncol;

	 }
#line 1579 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 238 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Bloque...\n";
		(yyval).cod = (yyvsp[-1]).cod;
}
#line 1588 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 243 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído BDecl 1...\n";

}
#line 1597 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 247 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído BDecl 2...\n";
	  
	  }
#line 1606 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 252 "plp5.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo;}
#line 1612 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 252 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DVar 1...\n";
	    ptr_label = NTemp();
	    (yyval).dir = ptr_label;
	    (yyval).tipo = (yyvsp[-3]).tipo;

    }
#line 1624 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 259 "plp5.y" /* yacc.c:1646  */
    {if((yyvsp[-5]).tipo != (yyvsp[0]).tipo) msgError(ERR_TIPOSDECLARRAY, nlin,ncol,(yyvsp[-5]).lexema); (yyval).tipo = (yyvsp[-5]).tipo;}
#line 1630 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DVar 2...\n";
		cout << (yyvsp[-7]).dir << " dimsm"<<endl;
		cout << (yyvsp[-1]).dBase << " dimensiones"<<endl;
		if((yyvsp[-7]).dir != (yyvsp[-1]).dBase) msgError(ERR_DIMSDECLARRAY,nlin,ncol, (yyvsp[-6]).lexema);
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).tipo = (yyvsp[-8]).tipo;
		nuevoSimbolo((yyvsp[-6]).lexema, true, (yyvsp[-1]).tipo, nlin, ncol-strlen(yytext));


   }
#line 1647 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 271 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DVar 3...\n";
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).tipo = SCANNER;
		nuevoSimbolo((yyvsp[-9]).lexema, false, SCANNER, nlin, ncol);

   }
#line 1660 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 280 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DimSN 1...\n";
		(yyval).dir +=1;
}
#line 1669 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 284 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DimSN 2...\n";
		(yyval).dir = 1;
    }
#line 1678 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 289 "plp5.y" /* yacc.c:1646  */
    {(yyval).dBase =1; (yyval).tipo = (yyvsp[-3]).tipo; }
#line 1684 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 289 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Dimensiones 1...\n";
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).tipo = nuevoTipo(std::atoi((yyvsp[-3]).lexema), (yyvsp[0]).tipo);
		(yyval).dBase =(yyvsp[0]).dBase + 1;

	}
#line 1697 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 297 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Dimensiones 2...\n";
        ptr_label = NTemp();
        (yyval).dir = ptr_label;
        (yyval).tipo = nuevoTipo(std::atoi((yyvsp[-1]).lexema), (yyvsp[-3]).tipo);
        (yyval).dBase = 1;

      }
#line 1710 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 307 "plp5.y" /* yacc.c:1646  */
    {

		if(DEBUG) std::cout << " - Leído LIdent 1...\n";
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).lexema = (yyvsp[0]).lexema;
		nuevoSimbolo((yyvsp[0]).lexema,false, (yyvsp[-3]).tipo,nlin,ncol );

	}
#line 1724 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 316 "plp5.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo;}
#line 1730 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 316 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído LIdent 2...\n";
		ptr_label = NTemp();
		(yyval).dir = ptr_label;
		(yyval).lexema = (yyvsp[0]).lexema;
		nuevoSimbolo((yyval).lexema, false, (yyvsp[-2]).tipo, nlin,ncol);
	}
#line 1742 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 324 "plp5.y" /* yacc.c:1646  */
    {
	if(DEBUG) std::cout << " - Leído Variable...\n";

	ptr_label = NTemp();
	(yyval).dir = ptr_label;
	(yyval).lexema = (yyvsp[0]).lexema;
}
#line 1754 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 334 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SeqInstr 1...\n";
		(yyval).cod = (yyvsp[-1]).cod + (yyvsp[0]).cod;
		
	}
#line 1764 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 339 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SeqInstr 2...\n";
	}
#line 1772 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 343 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 1...\n";	

	}
#line 1781 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 347 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 2...\n";	
		(yyval).dir = (yyvsp[0]).dir;
		(yyval).cod = (yyvsp[0]).cod;
		(yyval).tipo = (yyvsp[0]).tipo;
	}
#line 1792 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 353 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 3...\n";	
		if((yyvsp[-3]).tipo == ENTERO && (yyvsp[-1]).tipo == REAL)	msgError(ERR_TIPOSASIG,nlin,ncol,"");
		if((yyvsp[-3]).tipo == SCANNER)						msgError(ERR_SCVAR, nlin,ncol,(yyvsp[-3]).lexema);
		else{
			(yyval).cod = (yyvsp[-1]).cod;
			if((yyvsp[-3]).tipo == REAL && (yyvsp[-1]).tipo == ENTERO)
				(yyval).cod += "itor\n";
			(yyval).cod += "mov A " + IntToString((yyvsp[-3]).dir) + "\n";
			(yyval).dir = (yyvsp[-1]).dir;
		}
	}
#line 1809 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 365 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 4...\n";	
		(yyval).tipo = (yyvsp[-2]).tipo;
		(yyval).dir = (yyvsp[-2]).dir;
		if((yyvsp[-2]).tipo == ENTERO)
			(yyval).cod =(yyvsp[-2]).cod + "wri A \n";
		else
			(yyval).cod =(yyvsp[-2]).cod + "wrr A \n";
		(yyval).cod += "wrl\n";
	}
#line 1824 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 375 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 5...\n";	
		(yyval).tipo = (yyvsp[-2]).tipo;
		(yyval).dir = (yyvsp[-2]).dir;
		if((yyvsp[-2]).tipo == ENTERO)
			(yyval).cod =(yyvsp[-2]).cod +"wri A \n";
		else
			(yyval).cod =(yyvsp[-2]).cod +"wrr A \n";
	}
#line 1838 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 384 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 6...\n";	
		(yyval).cod = (yyvsp[-2]).cod + "mov " + IntToString((yyvsp[-2]).dir) + " A\njz " + IntToString((yyvsp[0]).dir) + "\n" + (yyvsp[0]).cod;
	}
#line 1847 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 388 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 7...\n";	
		(yyval).cod = (yyvsp[-4]).cod + "mov " + IntToString((yyvsp[-4]).dir) + " A\njz " + IntToString((yyvsp[-2]).dir) + "\n" + (yyvsp[-2]).cod + "jmp " + IntToString((yyvsp[0]).dir) + (yyvsp[0]).cod;
	}
#line 1856 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 392 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 8...\n";	
		(yyval).cod = (yyvsp[-2]).cod + "mov " + IntToString((yyvsp[-2]).dir) + " A\njz " + IntToString((yyvsp[0]).dir) + "\n" + (yyvsp[0]).cod + "jmp " + IntToString((yyvsp[-2]).dir);
}
#line 1865 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 397 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, (yyvsp[0]).lexema); }
#line 1871 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 397 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Expr 1...\n";	
		if((yyvsp[0]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, (yyvsp[-2]).lexema);
		ptr_label = NTemp();
		(yyval).dir 	= ptr_label;
		(yyval).cod = (yyvsp[-3]).cod
					+ "ori " + IntToString((yyvsp[0]).dir) + "\n"
					+ "mov A " + IntToString(ptr_label) + "\n";
	}
#line 1885 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 406 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Expr 2...\n";
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= (yyvsp[0]).dir;
		(yyval).cod 	= (yyvsp[0]).cod;
	}
#line 1896 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 413 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, (yyvsp[0]).lexema); }
#line 1902 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 413 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído EConj 1...\n";
		if((yyvsp[0]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, (yyvsp[-2]).lexema);
		ptr_label = NTemp();
		(yyval).dir 	= ptr_label;
		(yyval).cod = (yyvsp[-3]).cod
					+ "andi " + IntToString((yyvsp[0]).dir) + "\n"
					+ "mov A " + IntToString(ptr_label) + "\n";
	}
#line 1916 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 422 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído EConj 2...\n";
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= (yyvsp[0]).dir;
		(yyval).cod 	= (yyvsp[0]).cod;
	}
#line 1927 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 429 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != ENTERO && (yyvsp[-1]).tipo != REAL && (yyvsp[-1]).tipo != BOOLEANO) msgError(ERR_NUM, nlin, ncol, (yyvsp[0]).lexema); }
#line 1933 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 429 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído ERel 1...\n";
		if((yyvsp[0]).tipo != ENTERO && (yyvsp[0]).tipo != REAL && (yyvsp[-3]).tipo != BOOLEANO) msgError(ERR_NUM, nlin, ncol, (yyvsp[-2]).lexema);
		ptr_label = NTemp();
		(yyval).dir 	= ptr_label;

		if((yyvsp[-3]).tipo = (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[-3]).cod
							+ relopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else if((yyvsp[-3]).tipo == REAL) {
				(yyval).cod = (yyvsp[-3]).cod
							+ relopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else {
				(yyval).cod = (yyvsp[-3]).cod
							+ relopToM2R((yyvsp[-2]).lexema, BOOLEANO) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			}
		} else if((yyvsp[-3]).tipo != BOOLEANO && (yyvsp[0]).tipo != BOOLEANO) {
			(yyval).tipo = REAL;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[-3]).cod
							+ "itor\n"
							+ relopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
							+ "itor\n"
							+ relopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[-3]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			}
		} else 
			msgError(ERR_TIPOS, nlin, ncol, (yyvsp[-2]).lexema);
	}
#line 1977 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 468 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído ERel 2...\n";
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= (yyvsp[0]).dir;
		(yyval).cod 	= (yyvsp[0]).cod;
	}
#line 1988 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 475 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != ENTERO && (yyvsp[-1]).tipo != REAL) msgError(ERR_NUM, nlin, ncol, (yyvsp[0]).lexema); }
#line 1994 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 475 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Esimple 1...\n";
		if((yyvsp[0]).tipo != ENTERO && (yyvsp[0]).tipo != REAL) msgError(ERR_NUM, nlin, ncol, (yyvsp[-2]).lexema);
		ptr_label = NTemp();
		(yyval).dir 	= ptr_label;

		if((yyvsp[-3]).tipo = (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[-3]).cod
							+ addopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else {
				(yyval).cod = (yyvsp[-3]).cod
							+ addopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			}
		} else {
			(yyval).tipo = REAL;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[-3]).cod
							+ "itor\n"
							+ addopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
							+ "itor\n"
							+ addopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[-3]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			}
		}
	}
#line 2033 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 509 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Esimple 2...\n";
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= (yyvsp[0]).dir;
		(yyval).cod 	= (yyvsp[0]).cod;
	}
#line 2044 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 516 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != ENTERO && (yyvsp[-1]).tipo != REAL) msgError(ERR_NUM, nlin, ncol, (yyvsp[0]).lexema); }
#line 2050 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 516 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Term 1...\n";
		if((yyvsp[0]).tipo != ENTERO && (yyvsp[0]).tipo != REAL) msgError(ERR_NUM, nlin, ncol, (yyvsp[-2]).lexema);
		ptr_label = NTemp();
		(yyval).dir 	= ptr_label;

		if((yyvsp[-3]).tipo = (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[-3]).cod
							+ mulopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else {
				(yyval).cod = (yyvsp[-3]).cod
							+ mulopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			}
		} else {
			(yyval).tipo = REAL;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[-3]).cod
							+ "itor\n"
							+ mulopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
							+ "itor\n"
							+ mulopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[-3]).dir) + "\n"
							+ "mov A " + IntToString(ptr_label) + "\n";
			}
		}
	}
#line 2089 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 550 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Term 2...\n";
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= (yyvsp[0]).dir;
		(yyval).cod 	= (yyvsp[0]).cod;
	}
#line 2100 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 557 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 1...\n";
		(yyval).tipo 	= (yyvsp[0]).tipo;
		(yyval).dir 		= (yyvsp[0]).dir;
		(yyval).cod 		= (yyvsp[0]).cod;
		(yyval).dBase 	= (yyvsp[0]).dBase;
	}
#line 2112 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 564 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 2...\n";
		simbolo_t simbolo;
		simbolo.lexema = (yyvsp[-4]).lexema;
		buscarSimbolo(simbolo);
		if(simbolo.idTipo != SCANNER) msgError(ERR_NOSC,nlin,ncol,(yyvsp[-4]).lexema);

		ptr_label = NTemp();
		(yyval).tipo = ENTERO;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= "rdi " + IntToString(ptr_label) + "\n";
	}
#line 2129 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 576 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 3...\n";
		simbolo_t simbolo;
		simbolo.lexema = (yyvsp[-4]).lexema;
		buscarSimbolo(simbolo);
		if(simbolo.idTipo != SCANNER) msgError(ERR_NOSC,nlin,ncol,(yyvsp[-4]).lexema);

		ptr_label = NTemp();
		(yyval).tipo = REAL;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= "rdr " + IntToString(ptr_label) + "\n";
	}
#line 2146 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 588 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 4...\n";
		ptr_label = NTemp();
		(yyval).tipo = ENTERO;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= std::string("mov #") + (yyvsp[0]).lexema + " A\n";
	}
#line 2158 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 595 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 5...\n";
		ptr_label = NTemp();
		(yyval).tipo = REAL;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= std::string("mov #") + (yyvsp[0]).lexema + " A\n";
	}
#line 2170 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 602 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 6...\n";
		ptr_label = NTemp();
		(yyval).tipo = BOOLEANO;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= "mov #0 A\n";
	}
#line 2182 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 609 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 7...\n";
		ptr_label = NTemp();
		(yyval).tipo = BOOLEANO;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= "mov #1 A\n";
	}
#line 2194 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 616 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 8...\n";
		(yyval).tipo = (yyvsp[-1]).tipo;
		(yyval).dir 	= (yyvsp[-1]).dir;
		(yyval).cod 	= (yyvsp[-1]).cod;
	}
#line 2205 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 622 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 9...\n";
		if((yyvsp[0]).tipo == BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, (yyvsp[-1]).lexema);
		ptr_label = NTemp();
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= ptr_label;
		(yyval).cod 	= (yyvsp[0]).cod
					+ "noti\n"
					+ "mov A " + IntToString(ptr_label) + "\n";
	}
#line 2220 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 632 "plp5.y" /* yacc.c:1646  */
    { if(!esBase((yyvsp[0]).tipo)) msgError(ERR_TIPOS,nlin,ncol,(yyvsp[0]).lexema); }
#line 2226 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 632 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 10...\n";

		if(!esBase((yyvsp[0]).tipo)) msgError(ERR_TIPOS,nlin,ncol,(yyvsp[0]).lexema);

		if((yyvsp[-3]).tipo == (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;
			(yyval).dir 	= (yyvsp[0]).dir;
			(yyval).cod 	= (yyvsp[0]).cod;
		} else {
			ptr_label = NTemp();
			(yyval).tipo = (yyvsp[-3]).tipo;
			(yyval).dir 	= ptr_label;

			if((yyvsp[0]).tipo == BOOLEANO) {
				if((yyvsp[-3]).tipo == ENTERO) {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "ori #0\n"
								+ "mov A " + IntToString(ptr_label) + "\n";
				} else {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "orr #0\n"
								+ "mov A " + IntToString(ptr_label) + "\n";
				}
			} else if((yyvsp[0]).tipo == ENTERO) {
				if((yyvsp[-3]).tipo == BOOLEANO) {
						(yyval).cod 	= (yyvsp[0]).cod
									+ "andi #1\n"
									+ "mov A " + IntToString(ptr_label) + "\n";
				} else {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "itor\n"
								+ "mov A " + IntToString(ptr_label) + "\n";
				}
			} else {
				if((yyvsp[-3]).tipo == BOOLEANO) {
						(yyval).cod 	= (yyvsp[0]).cod
									+ "andr #1\n"
									+ "mov A " + IntToString(ptr_label) + "\n";
				} else {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "rtoi\n"
								+ "mov A " + IntToString(ptr_label) + "\n";
				}
			}
		}
	}
#line 2278 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 681 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Ref 1...\n";
		simbolo_t s;
		s.lexema = (yyvsp[0]).lexema;
		if(!buscarSimbolo(s))
			msgError(ERRNODECL,nlin,ncol, (yyvsp[0]).lexema);
		else{
			(yyval).dir = 	s.dir;
			(yyval).tipo = s.idTipo;
			if(s.esArray) {
				ptr_label 	= NTemp();
				(yyval).dBase	= ptr_label;
				(yyval).cod 		= "mov #0 " + IntToString(ptr_label) + "\n";
			}
			else
				(yyval).cod = "mov "+ IntToString(s.dir) + " A\n";
		}
	}
#line 2301 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 699 "plp5.y" /* yacc.c:1646  */
    {if(esBase((yyvsp[-1]).tipo)) msgError(ERRFALTAN,nlin,ncol,"");}
#line 2307 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 700 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Ref 2...\n";
		if(!esBase((yyvsp[-1]).tipo)){ msgError(ERR_EXP_ENT,nlin,ncol,"");}
		else {
			(yyval).tipo = tipoBase((yyvsp[-4]).tipo);
			ptr_label = NTemp();
			(yyval).dir = ptr_label;
			(yyval).dBase = (yyvsp[-4]).dBase;
			tipo_t t;
			buscarTipo((yyvsp[-4]).tipo, t);
			(yyval).cod = (yyvsp[-4]).cod + (yyvsp[-1]).cod
					 + "mov " + IntToString((yyvsp[-4]).dir) + " A\n" 
					 + "muli #" + IntToString(t.size) + "\n"
					 + "addi " + IntToString((yyvsp[-1]).dir) + "\n";
					 + "mov A" + IntToString(ptr_label) + "\n";
		}
	}
#line 2329 "plp5.tab.c" /* yacc.c:1646  */
    break;


#line 2333 "plp5.tab.c" /* yacc.c:1646  */
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
#line 719 "plp5.y" /* yacc.c:1906  */

bool esBase(int tipo)
{
  if(tipo <= 4)
    return true;
  else return false;
}

/* 
	Recibe una cadena de caracteres que representa un operador relacional
	y el tipo de la operación (ENTERO, REAL o BOOLEANO) y devuelve otra
	cadena con la instrucción correspondiente en M2R con un espacio al
	final, a falta del operador FUENTE
*/
std::string relopToM2R(const char *relop, int tipo) {
	char t;
	switch(tipo) {
		case BOOLEANO:
		case ENTERO:	t = 'i';	break;
		case REAL:		t = 'r';	break;
	}

	if(!strcmp(relop, "=="))		return std::string("eql") + t + " "; 
	else if(!strcmp(relop, "!="))	return std::string("neq") + t + " "; 
	else if(!strcmp(relop, "<"))	return std::string("lss") + t + " "; 
	else if(!strcmp(relop, "<="))	return std::string("leq") + t + " "; 
	else if(!strcmp(relop, ">"))	return std::string("gtr") + t + " "; 
	else if(!strcmp(relop, ">="))	return std::string("geq") + t + " ";

	return "";
}


std::string addopToM2R(const char *addop, int tipo) {
	char t;
	switch(tipo) {
		case BOOLEANO:
		case ENTERO:	t = 'i';	break;
		case REAL:		t = 'r';	break;
	}

	if(!strcmp(addop, "+"))			return std::string("add") + t + " ";
	else if(!strcmp(addop, "-"))	return std::string("sub") + t + " ";

	return "";
}


std::string mulopToM2R(const char *mulop, int tipo) {
	char t;
	switch(tipo) {
		case BOOLEANO:
		case ENTERO:	t = 'i';	break;
		case REAL:		t = 'r';	break;
	}

	if(!strcmp(mulop, "*"))			return std::string("mul") + t + " "; 
	else if(!strcmp(mulop, "/"))	return std::string("div") + t + " ";

	return "";
}

//Funcion del profesor
void msgError(int nerror,int nlin,int ncol,const char *s)
{

     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s);
            break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s);
            break;
         case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n");
            break;
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n");
            break;
         default:
            fprintf(stderr,"Error semantico (%d,%d): ", nlin,ncol);
            switch(nerror) {
             case ERRYADECL: fprintf(stderr,"simbolo '%s' ya declarado\n",s);
               break;
             case ERRNODECL: fprintf(stderr,"identificador '%s' no declarado\n",s);
               break;
             case ERR_NOSC: fprintf(stderr,"identificador '%s' no es un Scanner\n",s);
               break;
             case ERR_SCVAR: fprintf(stderr,"identificador '%s' es de tipo Scanner\n",s);
               break;
             case ERR_TIPOSDECLARRAY: fprintf(stderr,"los tipos deben ser iguales en la declaracion del array '%s'\n",s);
               break;
             case ERR_DIMSDECLARRAY: fprintf(stderr,"las dimensiones deben ser iguales en la declaracion del array '%s'\n",s);
               break;
             case ERRDIM: fprintf(stderr,"la dimension debe ser mayor que cero\n");
               break;
             case ERR_TIPOSASIG: fprintf(stderr,"tipos incompatibles en asignacion\n");
               break;
             case ERR_TIPOS: fprintf(stderr,"tipos incompatibles en '%s'\n",s);
               break;
             case ERR_TIPOSIFW: fprintf(stderr,"la expresion de if/while debe ser booleana\n");
               break;
             case ERR_OPNOBOOL: fprintf(stderr,"los operandos deben ser booleanos\n");
               break;
             case ERR_NUM: fprintf(stderr,"los operandos deben ser numericos\n");
               break;
             case ERRFALTAN: fprintf(stderr,"faltan indices\n");
               break;
             case ERRSOBRAN: fprintf(stderr,"sobran indices\n");
               break;
             case ERR_EXP_ENT: fprintf(stderr,"la expresion entre corchetes debe ser de tipo entero\n");
               break;

             case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s);
               break;
             case ERR_MAXVAR:fprintf(stderr,"en la variable '%s', hay demasiadas variables declaradas\n",s);
               break;
             case ERR_MAXTIPOS:fprintf(stderr,"hay demasiados tipos definidos\n");
               break;
             case ERR_MAXTMP:fprintf(stderr,"no hay espacio para variables temporales\n");
               break;
            }
        }
     exit(1);
}

int yyerror(char *s)
{
    extern int findefichero;   //  variable definida en plp5.l que indica si
                               // se ha acabado el fichero
    if (findefichero) 
    {
       msgError(ERREOF,-1,-1,"");
    }
    else
    {  
       msgError(ERRSINT,nlin,ncol-strlen(yytext),yytext);
    }
}

void crear_ambito(const char* nombre)
{
	struct tabla_simbolos_t* nuevo_ambito = (tabla_simbolos_t*)calloc(1, sizeof(struct tabla_simbolos_t));
	nuevo_ambito->ts_padre = ambito;
	nuevo_ambito->nombre = nombre;
	ambito = nuevo_ambito; 
}

int tipoBase(int tipo){
	return 1;
}

int buscarDir(const char* lexema){

	simbolo_t s;
	s.lexema = lexema;
	if(buscarSimbolo(s))
		return s.dir;

}

void nuevoSimbolo(char* lexema, bool esArray, int idTipo, int lin, int col) {
	if(DEBUG) std::cout << "*NUEVO SIMBOLO* Simbolo: " << lexema << 
						"\tIdx.Tipo: " << idTipo << 
						"\tDir.: " << ptr_mem <<
						"\tArray? " << esArray << "\n";

	if(!existeSimbolo(lexema)) {  // Si no existe
	simbolo_t s;
	tipo_t obj_tipo;
	buscarTipo(idTipo, obj_tipo);

	s.lexema    = std::string(lexema);
	s.lin       = lin;
	s.col       = col;
	s.dir       = ptr_mem;
	s.idTipo    = idTipo;
	s.esArray   = esArray;

	if(!s.esArray) {
		switch(idTipo) {
			case ENTERO: 	s.idTipo = ENTERO;	break;
			case REAL:		s.idTipo = REAL;	break;
			case BOOLEANO:	s.idTipo = BOOLEANO;break;
			case SCANNER:	s.idTipo = SCANNER;	break;
		}  

		ptr_mem += obj_tipo.size;
	} else if (s.esArray) {
		int var  = obj_tipo.size;
		tipo_t tipo;
		buscarTipo(obj_tipo.tipo_base,tipo);
		var *= tipo.size;

		while(!esBase(tipo.tipo_base)) {
			var *= tipo.size;
			buscarTipo(obj_tipo.tipo_base,tipo);
		}
			ptr_mem += var;
	}

	if(ptr_mem > MAX_MEM)   // Si no cabe en memoria..
		msgError(ERR_NOCABE, lin, col, lexema);    // error, memoria llena  

		simbolos.push_back(s);
	}
	else
		msgError(ERRYADECL, lin, col, lexema);   // Error, simbolo ya declarado
}

bool existeSimbolo(const char* simbolo) {
  		
  if(DEBUG) std::cout << "Existe simbolo\n " ;

  std::vector<simbolo_t>::iterator begin_it = simbolos.begin();
  std::vector<simbolo_t>::iterator end_it   = simbolos.end();
  std::vector<simbolo_t>::iterator it       = std::find_if(begin_it,end_it, find_simbolo(std::string(simbolo))); 

  return it != end_it;

}
bool buscarSimbolo(simbolo_t& simbolo) {    // simbolo debe llegar con el lexema y volvera con todos los atributos
  
  std::vector<simbolo_t>::iterator begin_it = simbolos.begin();
  std::vector<simbolo_t>::iterator end_it   = simbolos.end();
  std::vector<simbolo_t>::iterator it       = std::find_if(begin_it,end_it, find_simbolo(simbolo.lexema)); 

  if(it != end_it)
  {
    simbolo.idTipo  = it->idTipo;
    simbolo.dir   = it->dir;

    #if DEBUG_MODE
      cout << "buscarSimbolo --> Dir: " << simbolo.dir << "\tTipo: "<< simbolo.tipo << "\n";
    #endif

    return true;
  }
  return false;
} 


int NTemp(){
	ptr_mem_temp ++;

	if(ptr_mem_temp >= MAX_POS_MEM)
		msgError(ERR_MAXTMP, nlin, ncol, "") ;

	else return ptr_mem_temp;
}


int buscarTipoSimbolo(const char * lexema) {
  
  simbolo_t simbolo;
  simbolo.lexema = lexema;
  buscarSimbolo(simbolo);
  return simbolo.idTipo;
}

bool buscarTipo(int tipo_buscado, tipo_t& t) {
  std::vector<tipo_t>::iterator it_tipos;
  for(it_tipos = tabla_tipos.begin(); it_tipos != tabla_tipos.end(); ++it_tipos) {
    if(it_tipos->tipo == tipo_buscado) {
      t.tipo      = it_tipos->tipo;
      t.size      = it_tipos->size;
      t.tipo_base = it_tipos->tipo_base;
        if(DEBUG) std::cout << " -FOR ...\n " ;

      return true;
    }
  }
  return false;
}



void inicializarTablaTipos() {
  tipo_t t;
  tabla_tipos.clear();

  t.tipo      = ENTERO;
  t.size      = TAM_BASE;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);

  t.tipo      = REAL;
  t.size      = TAM_BASE;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);

  t.tipo      = BOOLEANO;
  t.size      = TAM_BASE;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);

  t.tipo      = SCANNER;
  t.size      = TAM_BASE;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);
}

void print_tabla_tipos() {
  std::vector<tipo_t>::iterator it_tipos;
  int pos = 0;
  std::cout << "############ TABLA DE TIPOS ############\n";

  for(it_tipos = tabla_tipos.begin(); it_tipos != tabla_tipos.end(); ++it_tipos)
  {
    cout << "Pos: " << pos << 
            "\tTipo: " << it_tipos->tipo << 
            "\tTam: " << it_tipos->size <<
            "\tT.Base: " << it_tipos->tipo_base << "\n";
    ++pos;
  }
  std::cout << "########################################\n";

}

void print_tabla_simbolos() {
  std::cout << "############ TABLA DE SIMBOLOS ############\n";
  std::vector<simbolo_t>::iterator it_simbolos;
  int pos = 0;
  for(it_simbolos = simbolos.begin(); it_simbolos != simbolos.end(); ++it_simbolos)
  {
    cout << "Pos.: " << pos << 
    "\tSimbolo: " << it_simbolos->lexema << 
    "\tIdx.Tipo: " << it_simbolos->idTipo << 
    "\tDir.: " << it_simbolos->dir <<
    "\tArray? " << it_simbolos->esArray << "\n";
    ++pos;
  }
  std::cout << "###########################################\n";
}

int nuevoTipo(int tam,int tipo_base) {
  
	if(DEBUG) std::cout << "*NUEVO TIPO* Pos: " << contIdType << 
            "\tTipo: " << contIdType + 1 << 
            "\tTam: " << tam <<
            "\tT.Base: " << tipo_base << "\n";

  tipo_t t;
 /*switch(tipo_base)
  {
    case ENTERO: 
      t.tipo_base = 0;
      break;
    case REAL:
      t.tipo_base = 1;
      break;
    case BOOLEANO:
      t.tipo_base = 2;
      break;
    case SCANNER:
      t.tipo_base = 3;
      break;
    default:
      t.tipo_base = tipo_base;
      break;
  }*/
  t.tipo_base = tipo_base;
  t.tipo    = ++contIdType;
  t.size    = tam;
  tabla_tipos.push_back(t);

  return t.tipo;
}

void toLower(string& str)
{
  for(int i = 0; i < str.size(); i++)
  {
    str[i] = tolower(str[i]);
  }
}

void destruir_ambito_actual()
{
	struct tabla_simbolos_t* padre;
	padre = ambito->ts_padre;
	free(ambito);
	ambito = padre;
	padre = NULL;
}

void destroy()
{
	struct tabla_simbolos_t* next;
	while(ambito != NULL)
	{
		next = ambito->ts_padre;
		free(ambito);
		ambito = next;
	}
	next = NULL;

}

int main(int argc,char *argv[])
{
    FILE *fent;

    if (argc==2)
    {
        fent = fopen(argv[1],"rt");
        if (fent)
        {
        	crear_ambito("global");
          inicializarTablaTipos();
            yyin = fent;
            yyparse();
            fclose(fent);
        }
        else
            fprintf(stderr,"No puedo abrir el fichero\n");
    }
    else
        fprintf(stderr,"Uso: ejemplo <nombre de fichero>\n");
}
