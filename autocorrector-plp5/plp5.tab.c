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
int ptr_tmp = 0;
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

bool buscar(simbolo_t &s, tabla_simbolos_t* t);

bool lexema_existe(const char* lexema);
void print_tabla_simbolos();
void crear_ambito(const char* nombre);
void destruir_ambito_actual();
void destroy();
int getDimensionesVector(const char* lexema);
int getTBaseVector(int id);
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

#line 190 "plp5.tab.c" /* yacc.c:339  */

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

#line 287 "plp5.tab.c" /* yacc.c:358  */

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
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

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
       0,   171,   171,   180,   185,   190,   194,   199,   204,   210,
     216,   222,   227,   234,   234,   234,   239,   242,   246,   246,
     251,   251,   259,   266,   270,   275,   275,   281,   288,   294,
     294,   300,   307,   312,   317,   321,   327,   340,   355,   368,
     377,   387,   397,   397,   408,   417,   417,   428,   437,   437,
     483,   492,   492,   534,   543,   543,   585,   594,   602,   614,
     626,   633,   640,   647,   654,   660,   671,   671,   724,   750,
     750
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
  "Main", "Tipo", "Bloque", "$@1", "$@2", "BDecl", "DVar", "@3", "@4",
  "DimSN", "Dimensiones", "@5", "LIdent", "@6", "Variable", "SeqInstr",
  "Instr", "Expr", "$@7", "EConj", "$@8", "ERel", "$@9", "Esimple", "$@10",
  "Term", "$@11", "Factor", "$@12", "Ref", "$@13", YY_NULLPTR
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

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -92,    44,    25,   -92,    10,    51,   -92,   -92,    40,    12,
     -92,    -8,    47,   -92,   -92,    68,    69,    48,    71,   -92,
      82,    60,    80,    57,    59,    50,    63,    61,   -92,   -92,
     -92,    14,   -92,   -92,   -92,    52,    64,   -92,    -2,    66,
      65,   -92,     6,    74,    75,    76,   -92,   -92,   -92,    72,
     -92,    39,    83,   -92,    49,    67,    73,    78,    96,    28,
      28,   -92,    28,   -92,    88,    67,   -92,   -92,   -92,   -92,
      93,    85,   -92,   -92,     4,    28,   -92,   -92,    86,   -18,
      77,   -92,    46,    84,   -92,    87,   -17,   -13,    28,    79,
     -92,    58,    70,   -92,   -10,   -92,    62,    -2,   -92,   -92,
     -92,   -92,   -92,    -2,   -92,    23,   109,   -92,    89,    90,
      91,   -92,    94,    95,    98,    28,    28,    28,    28,    28,
     -92,   -92,    97,    92,    28,    28,    28,    99,   100,    -2,
      77,   -92,   101,    84,   -92,   118,   102,   104,    -6,     9,
     -92,   -92,   -92,   -92,   105,   103,   -92,   107,   110,   111,
     113,   -92,   -92,   -92,    92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     2,     7,     0,     0,
       3,     0,     0,     6,     5,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     9,
      17,    33,    12,    10,    11,     0,    18,    16,    14,     0,
       0,    29,     0,     0,     0,     0,    34,    68,    35,     0,
      32,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,    15,     0,    69,     0,     0,    19,    31,    30,    23,
       0,     0,    62,    63,     0,     0,    60,    61,    68,     0,
      44,    47,    50,    53,    56,    57,     0,     0,     0,     0,
      28,     0,     0,    66,     0,    65,     0,     0,    42,    45,
      48,    51,    54,     0,    36,     0,     0,    20,     0,     0,
       0,    64,     0,     0,    39,     0,     0,     0,     0,     0,
      41,    70,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    46,    49,    52,    55,     0,     0,     0,     0,     0,
      67,    58,    59,    40,     0,     0,    21,     0,     0,     0,
      25,    37,    38,    22,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,   -92,   -64,   106,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -25,   -92,   -92,   -92,    81,
     -92,   -91,   -58,   -92,    22,   -92,    26,   -92,   -85,   -92,
      29,   -92,   -74,   -92,   -38,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     6,    17,    36,    48,    30,    49,
      31,    37,    41,   123,    42,   137,   154,    54,    55,    68,
      38,    50,    79,   115,    80,   116,    81,   117,    82,   118,
      83,   119,    84,   110,    85,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    95,    86,   105,    87,    43,   114,    32,    33,    34,
      93,    13,   120,    97,   103,   104,    94,    32,    33,    34,
      44,   111,    45,    98,    98,   147,    46,   107,    98,    72,
      73,    98,   132,    35,    74,    98,    28,    14,   143,     4,
     148,     5,    56,    47,     3,   134,    75,    76,    77,    78,
      98,    57,   140,    72,    73,     7,   101,    12,    74,    51,
     121,    32,    33,    34,     9,    51,   138,   139,    10,    11,
      75,    76,    77,    78,    62,    63,    65,    66,   100,   101,
     108,   109,   112,   113,    16,    15,    18,    19,    21,    20,
      22,    51,    23,    24,    27,    26,    25,    39,    64,    28,
      40,    52,    53,    58,    71,    59,    60,    89,    91,   106,
      69,    61,    67,    70,    92,    96,   122,    99,   102,   124,
     125,   129,   126,    63,   127,   128,   135,   144,   136,   155,
     141,   142,   146,    29,   101,   151,   149,   130,   152,   153,
     150,   -27,   131,     0,     0,   145,    90,   133
};

static const yytype_int16 yycheck[] =
{
      38,    75,    60,    88,    62,     7,    97,     3,     4,     5,
      74,    19,   103,    31,    31,    28,    74,     3,     4,     5,
      22,    31,    24,    41,    41,    31,    28,    91,    41,    25,
      26,    41,   117,    19,    30,    41,    38,    45,   129,    14,
      31,    16,    36,    45,     0,   119,    42,    43,    44,    45,
      41,    45,   126,    25,    26,    45,    33,    45,    30,    97,
      37,     3,     4,     5,    13,   103,   124,   125,    28,    29,
      42,    43,    44,    45,    35,    36,    27,    28,    32,    33,
      10,    11,    20,    21,    16,    38,    17,    39,     6,    18,
      30,   129,    12,    36,    31,    45,    37,    45,    15,    38,
      36,    35,    37,    29,     8,    30,    30,    19,    15,    30,
      37,    39,    45,    35,    29,    29,     7,    40,    34,    30,
      30,    23,    31,    36,    30,    30,    29,     9,    36,   154,
      31,    31,    28,    27,    33,    28,    31,   115,    28,    28,
      37,    28,   116,    -1,    -1,    43,    65,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,    14,    16,    50,    45,    49,    13,
      28,    29,    45,    19,    45,    38,    16,    51,    17,    39,
      18,     6,    30,    12,    36,    37,    45,    31,    38,    53,
      54,    56,     3,     4,     5,    19,    52,    57,    66,    45,
      36,    58,    60,     7,    22,    24,    28,    45,    53,    55,
      67,    80,    35,    37,    63,    64,    36,    45,    29,    30,
      30,    39,    35,    36,    15,    27,    28,    45,    65,    37,
      35,     8,    25,    26,    30,    42,    43,    44,    45,    68,
      70,    72,    74,    76,    78,    80,    68,    68,    81,    19,
      65,    15,    29,    52,    68,    78,    29,    31,    41,    40,
      32,    33,    34,    31,    28,    74,    30,    52,    10,    11,
      79,    31,    20,    21,    67,    69,    71,    73,    75,    77,
      67,    37,     7,    59,    30,    30,    31,    30,    30,    23,
      70,    72,    74,    76,    78,    29,    36,    61,    68,    68,
      78,    31,    31,    67,     9,    43,    28,    31,    31,    31,
      37,    28,    28,    28,    62,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    51,
      52,    52,    52,    54,    55,    53,    56,    56,    58,    57,
      59,    57,    57,    60,    60,    62,    61,    61,    63,    64,
      63,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    69,    68,    68,    71,    70,    70,    73,    72,
      72,    75,    74,    74,    77,    76,    76,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    78,    80,    81,
      80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     0,     3,     3,     1,     6,    11,
       1,     1,     1,     0,     0,     6,     2,     0,     0,     4,
       0,     9,    11,     3,     2,     0,     5,     3,     3,     0,
       2,     1,     2,     0,     1,     1,     4,     9,     9,     5,
       7,     5,     0,     4,     1,     0,     4,     1,     0,     4,
       1,     0,     4,     1,     0,     4,     1,     1,     5,     5,
       1,     1,     1,     1,     3,     2,     0,     5,     1,     0,
       5
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
#line 171 "plp5.y" /* yacc.c:1646  */
    {
	if(DEBUG) std::cout << " - Leído S...\n";
	(yyval).cod =(yyvsp[0]).cod + "halt";

			int tk = yylex();
            if (tk != 0) yyerror("");
            cout << (yyval).cod << endl;
}
#line 1477 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 180 "plp5.y" /* yacc.c:1646  */
    {
	if(DEBUG) std::cout << " - Leído Import 1...\n";
	(yyval).cod = (yyvsp[-3]).cod + (yyvsp[-1]).cod;
	//No hace nada?
}
#line 1487 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 185 "plp5.y" /* yacc.c:1646  */
    {
	//No hace nada?
	    	if(DEBUG) std::cout << " - Leído Import 2...\n";
	   }
#line 1496 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 190 "plp5.y" /* yacc.c:1646  */
    {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído SecImp 1...\n";
	}
#line 1505 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 194 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SecImp 2...\n";
	    	//$$.cod = $1.cod;
	//No hace nada?
	   }
#line 1515 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 199 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SecImp 3...\n";
	//No hace nada?
	   }
#line 1524 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 204 "plp5.y" /* yacc.c:1646  */
    {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído Class...\n";
		(yyval).cod = (yyvsp[-1]).cod;
}
#line 1534 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 210 "plp5.y" /* yacc.c:1646  */
    {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído Main...\n";
		(yyval).cod = (yyvsp[0]).cod;
}
#line 1544 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 216 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Tipo 1...\n";
		(yyval).tipo = ENTERO;
		(yyval).lexema = (yyvsp[0]).lexema;

	}
#line 1555 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 222 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Tipo 2...\n";
		(yyval).tipo = REAL;
		(yyval).lexema = (yyvsp[0]).lexema;
	 }
#line 1565 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 227 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Tipo 3...\n";
		(yyval).tipo = BOOLEANO;
		(yyval).lexema = (yyvsp[0]).lexema;

	 }
#line 1576 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 234 "plp5.y" /* yacc.c:1646  */
    { crear_ambito(" "); }
#line 1582 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 234 "plp5.y" /* yacc.c:1646  */
    { destruir_ambito_actual(); }
#line 1588 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 234 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Bloque...\n";
		(yyval).cod = (yyvsp[-2]).cod;
}
#line 1597 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído BDecl 1...\n";
}
#line 1605 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 242 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído BDecl 2...\n";
	  }
#line 1613 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "plp5.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo;}
#line 1619 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 246 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DVar 1...\n";
	    (yyval).tipo = (yyvsp[-3]).tipo;

    }
#line 1629 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 251 "plp5.y" /* yacc.c:1646  */
    {if((yyvsp[-5]).tipo != (yyvsp[0]).tipo) msgError(ERR_TIPOSDECLARRAY, (yyvsp[-5]).nlin,(yyvsp[-5]).ncol,(yyvsp[-5]).lexema); (yyval).tipo = (yyvsp[-5]).tipo;}
#line 1635 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DVar 2...\n";
		if((yyvsp[-7]).dir != (yyvsp[-1]).dBase) msgError(ERR_DIMSDECLARRAY,(yyvsp[-6]).nlin,(yyvsp[-6]).ncol, (yyvsp[-6]).lexema);
		(yyval).tipo = (yyvsp[-8]).tipo;
		nuevoSimbolo((yyvsp[-6]).lexema, true, (yyvsp[-1]).tipo, (yyvsp[-6]).nlin, (yyvsp[-6]).ncol);


   }
#line 1648 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DVar 3...\n";
		(yyval).tipo = SCANNER;
		nuevoSimbolo((yyvsp[-9]).lexema, false, SCANNER, nlin, ncol);

   }
#line 1659 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 266 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DimSN 1...\n";
		(yyval).dir +=1;
}
#line 1668 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 270 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído DimSN 2...\n";
		(yyval).dir = 1;
    }
#line 1677 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 275 "plp5.y" /* yacc.c:1646  */
    {(yyval).dBase =1; (yyval).tipo = (yyvsp[-3]).tipo; }
#line 1683 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 275 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Dimensiones 1...\n";
		(yyval).tipo = nuevoTipo(std::atoi((yyvsp[-3]).lexema), (yyvsp[0]).tipo);
		(yyval).dBase =(yyvsp[0]).dBase + 1;

	}
#line 1694 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 281 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Dimensiones 2...\n";
        (yyval).tipo = nuevoTipo(std::atoi((yyvsp[-1]).lexema), (yyvsp[-3]).tipo);
        (yyval).dBase = 1;
      }
#line 1704 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 288 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído LIdent 1...\n";
		(yyval).lexema = (yyvsp[0]).lexema;
		nuevoSimbolo((yyvsp[0]).lexema,false, (yyvsp[-3]).tipo,(yyvsp[0]).nlin,(yyvsp[0]).ncol );

	}
#line 1715 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 294 "plp5.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo;}
#line 1721 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 294 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído LIdent 2...\n";
		(yyval).lexema = (yyvsp[0]).lexema;
		nuevoSimbolo((yyval).lexema, false, (yyvsp[-2]).tipo, (yyvsp[0]).nlin,(yyvsp[0]).ncol);
	}
#line 1731 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 300 "plp5.y" /* yacc.c:1646  */
    {
	if(DEBUG) std::cout << " - Leído Variable...\n";
	ptr_tmp = NTemp();
	(yyval).dir = ptr_tmp;
	(yyval).lexema = (yyvsp[0]).lexema;
}
#line 1742 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 307 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SeqInstr 1...\n";
		(yyval).cod = (yyvsp[-1]).cod + (yyvsp[0]).cod;
		
	}
#line 1752 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 312 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído SeqInstr 2...\n";
		(yyval).cod = "";
	}
#line 1761 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 317 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 1...\n";	

	}
#line 1770 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 321 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 2...\n";	
		(yyval).dir = (yyvsp[0]).dir;
		(yyval).cod = (yyvsp[0]).cod;
		(yyval).tipo = (yyvsp[0]).tipo;
	}
#line 1781 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 327 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 3...\n";	
		if((yyvsp[-3]).dBase == ENTERO && (yyvsp[-1]).tipo == REAL)	msgError(ERR_TIPOSASIG,nlin,ncol,"");
		if((yyvsp[-3]).dBase == SCANNER)						msgError(ERR_SCVAR, nlin,ncol,(yyvsp[-3]).lexema);
		else{
			(yyval).cod = (yyvsp[-1]).cod;
			if((yyvsp[-3]).tipo == REAL && (yyvsp[-1]).tipo == ENTERO)
				(yyval).cod += "itor\n";
			(yyval).cod += "mov " + IntToString((yyvsp[-1]).dir) + " " + IntToString((yyvsp[-3]).dir) + "\n";
			//$$.cod += $1.cod;
			(yyval).dir = (yyvsp[-1]).dir;
		}
	}
#line 1799 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 340 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 4...\n";	
		(yyval).tipo = (yyvsp[-2]).tipo;
		(yyval).dir = (yyvsp[-2]).dir;
		if((yyvsp[-2]).tipo == ENTERO)
			(yyval).cod = (yyvsp[-2]).cod
					+ "mov " + IntToString((yyvsp[-2]).dir) + " A\n"
					+ "wri A \n";
		else
			(yyval).cod = (yyvsp[-2]).cod
					+ "mov " + IntToString((yyvsp[-2]).dir) + " A\n"
					+ "wrr A \n";

		(yyval).cod += "wrl\n";
	}
#line 1819 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 355 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 5...\n";	
		(yyval).tipo = (yyvsp[-2]).tipo;
		(yyval).dir = (yyvsp[-2]).dir;
		if((yyvsp[-2]).tipo == ENTERO)
			(yyval).cod = (yyvsp[-2]).cod
					+ "mov " + IntToString((yyvsp[-2]).dir) + " A\n"
					+ "wri A \n";
		else
			(yyval).cod = (yyvsp[-2]).cod
					+ "mov " + IntToString((yyvsp[-2]).dir) + " A\n"
					+"wrr A \n";
	}
#line 1837 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 368 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 6...\n";	
		(yyval).cod = (yyvsp[-2]).cod;
		(yyval).cod += "mov " + IntToString((yyvsp[-2]).dir) + " A\n";
		(yyval).cod += "jz L" + IntToString(++ptr_label) + "\n";
		(yyval).cod += (yyvsp[0]).cod;
		(yyval).cod += "L" + IntToString(ptr_label) + "\n";
		
	}
#line 1851 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 377 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 7...\n";	
		(yyval).cod = (yyvsp[-4]).cod;
		(yyval).cod += "mov " + IntToString((yyvsp[-4]).dir) + " A\n";
		(yyval).cod += "jz L" + IntToString(++ptr_label) + "\n";
		(yyval).cod += (yyvsp[-2]).cod;
		(yyval).cod += "jmp L" + IntToString(++ptr_label) +"\n";
		(yyval).cod += "L" + IntToString(ptr_label - 1) + " " + (yyvsp[0]).cod;
		(yyval).cod += "L" + IntToString(ptr_label) + "\n";
	}
#line 1866 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Instr 8...\n";	
		(yyval).cod = "L"+ IntToString(++ptr_label) + " " + (yyvsp[-2]).cod;
		(yyval).cod += "mov " + IntToString((yyvsp[-2]).dir) + " A\n";
		(yyval).cod += "jz L" + IntToString(++ptr_label) + "\n";
		(yyval).cod += (yyvsp[0]).cod;
		(yyval).cod += "jmp L" + IntToString(ptr_label - 1) +"\n";
		(yyval).cod += "L" + IntToString(ptr_label) + "\n";
}
#line 1880 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 397 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema); }
#line 1886 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 397 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Expr 1...\n";	
		if((yyvsp[0]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema);
		(yyval).tipo = BOOLEANO;
		ptr_tmp = NTemp();
		(yyval).dir = ptr_tmp;
		(yyval).cod = (yyvsp[0]).cod
					+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
					+ "ori " + IntToString((yyvsp[-3]).dir) + "\n"
					+ "mov A " + IntToString(ptr_tmp) + "\n";
	}
#line 1902 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 408 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Expr 2...\n";
		(yyval).tipo 	= (yyvsp[0]).tipo;
		(yyval).dir 		= (yyvsp[0]).dir;
		(yyval).cod 		= (yyvsp[0]).cod;
		(yyval).dBase 	= (yyvsp[0]).dBase;
		(yyval).esArray = (yyvsp[0]).esArray;
	}
#line 1915 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 417 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema); }
#line 1921 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído EConj 1...\n";
		if((yyvsp[0]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema);
		(yyval).tipo = BOOLEANO;
		ptr_tmp = NTemp();
		(yyval).dir = ptr_tmp;
		(yyval).cod = (yyvsp[0]).cod
					+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
					+ "andi " + IntToString((yyvsp[-3]).dir) + "\n"
					+ "mov A " + IntToString(ptr_tmp) + "\n";
	}
#line 1937 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 428 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído EConj 2...\n";
		(yyval).tipo 	= (yyvsp[0]).tipo;
		(yyval).dir 		= (yyvsp[0]).dir;
		(yyval).cod 		= (yyvsp[0]).cod;
		(yyval).dBase 	= (yyvsp[0]).dBase;
		(yyval).esArray = (yyvsp[0]).esArray;
	}
#line 1950 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 437 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != ENTERO && (yyvsp[-1]).tipo != REAL && (yyvsp[-1]).tipo != BOOLEANO) msgError(ERR_NUM, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema); }
#line 1956 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 437 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído ERel 1...\n";
		if((yyvsp[0]).tipo != ENTERO && (yyvsp[0]).tipo != REAL && (yyvsp[-3]).tipo != BOOLEANO) msgError(ERR_NUM, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema);
		(yyval).tipo = BOOLEANO;
		ptr_tmp = NTemp();
		(yyval).dir = ptr_tmp;

		if((yyvsp[-3]).tipo == (yyvsp[0]).tipo) {
			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ relopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else if((yyvsp[-3]).tipo == REAL) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ relopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ relopToM2R((yyvsp[-2]).lexema, BOOLEANO) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else if((yyvsp[-3]).tipo != BOOLEANO && (yyvsp[0]).tipo != BOOLEANO) {
			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ "itor\n"
						+ relopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
						+ "itor\n"
						+ relopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[-3]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else
			msgError(ERR_TIPOS, nlin, ncol, (yyvsp[-2]).lexema);
	}
#line 2007 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 483 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído ERel 2...\n";
		(yyval).tipo 	= (yyvsp[0]).tipo;
		(yyval).dir 		= (yyvsp[0]).dir;
		(yyval).cod 		= (yyvsp[0]).cod;
		(yyval).dBase 	= (yyvsp[0]).dBase;
		(yyval).esArray = (yyvsp[0]).esArray;
	}
#line 2020 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 492 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != ENTERO && (yyvsp[-1]).tipo != REAL) msgError(ERR_NUM, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema); }
#line 2026 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 492 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Esimple 1...\n";
		if((yyvsp[0]).tipo != ENTERO && (yyvsp[0]).tipo != REAL) msgError(ERR_NUM, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema);
		ptr_tmp = NTemp();
		(yyval).dir = ptr_tmp;

		if((yyvsp[-3]).tipo == (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ addopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ addopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else {
			(yyval).tipo = REAL;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ "itor\n"
						+ addopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
						+ "itor\n"
						+ addopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[-3]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		}
	}
#line 2073 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 534 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Esimple 2...\n";
		(yyval).tipo 	= (yyvsp[0]).tipo;
		(yyval).dir 		= (yyvsp[0]).dir;
		(yyval).cod 		= (yyvsp[0]).cod;
		(yyval).dBase 	= (yyvsp[0]).dBase;
		(yyval).esArray = (yyvsp[0]).esArray;
	}
#line 2086 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 543 "plp5.y" /* yacc.c:1646  */
    { if((yyvsp[-1]).tipo != ENTERO && (yyvsp[-1]).tipo != REAL) msgError(ERR_NUM, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema); }
#line 2092 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 543 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Term 1...\n";
		if((yyvsp[0]).tipo != ENTERO && (yyvsp[0]).tipo != REAL) msgError(ERR_NUM, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema);
		ptr_tmp = NTemp();
		(yyval).dir = ptr_tmp;

		if((yyvsp[-3]).tipo == (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ mulopToM2R((yyvsp[-2]).lexema, ENTERO) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ mulopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else {
			(yyval).tipo = REAL;

			if((yyvsp[-3]).tipo == ENTERO) {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[-3]).dir) + " A\n"
						+ "itor\n"
						+ mulopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[0]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				(yyval).cod = (yyvsp[0]).cod
						+ (yyvsp[-3]).cod
						+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
						+ "itor\n"
						+ mulopToM2R((yyvsp[-2]).lexema, REAL) + IntToString((yyvsp[-3]).dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		}
	}
#line 2139 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 585 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Term 2...\n";
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).dir 	= (yyvsp[0]).dir;
		(yyval).cod 	= (yyvsp[0]).cod;
		(yyval).dBase = (yyvsp[0]).dBase;
		(yyval).esArray = (yyvsp[0]).esArray;
	}
#line 2152 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 594 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 1...\n";
		(yyval).tipo 	= (yyvsp[0]).tipo;
		(yyval).dir 		= (yyvsp[0]).dir;
		(yyval).cod 		= (yyvsp[0]).cod;
		(yyval).dBase 	= (yyvsp[0]).dBase;
		(yyval).esArray = (yyvsp[0]).esArray;
	}
#line 2165 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 602 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 2...\n";
		simbolo_t simbolo;
		simbolo.lexema = (yyvsp[-4]).lexema;
		buscar(simbolo,ambito);
		if(simbolo.idTipo != SCANNER) msgError(ERR_NOSC, (yyvsp[-4]).nlin, (yyvsp[-4]).ncol,(yyvsp[-4]).lexema);

		ptr_tmp = NTemp();
		(yyval).tipo = ENTERO;
		(yyval).dir 	= ptr_tmp;
		(yyval).cod 	= "rdi " + IntToString(ptr_tmp) + "\n";
	}
#line 2182 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 614 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 3...\n";
		simbolo_t simbolo;
		simbolo.lexema = (yyvsp[-4]).lexema;
		buscar(simbolo,ambito);
		if(simbolo.idTipo != SCANNER) msgError(ERR_NOSC,(yyvsp[-4]).nlin,(yyvsp[-4]).ncol,(yyvsp[-4]).lexema);

		ptr_tmp = NTemp();
		(yyval).tipo = REAL;
		(yyval).dir 	= ptr_tmp;
		(yyval).cod 	= "rdr " + IntToString(ptr_tmp) + "\n";
	}
#line 2199 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 626 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 4...\n";
		ptr_tmp = NTemp();
		(yyval).tipo = ENTERO;
		(yyval).dir 	= ptr_tmp;
		(yyval).cod 	= std::string("mov #") + (yyvsp[0]).lexema + " " + IntToString(ptr_tmp) + "\n";
	}
#line 2211 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 633 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 5...\n";
		ptr_tmp = NTemp();
		(yyval).tipo = REAL;
		(yyval).dir 	= ptr_tmp;
		(yyval).cod 	= std::string("mov $") + (yyvsp[0]).lexema + " " + IntToString(ptr_tmp) + "\n";
	}
#line 2223 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 640 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 6...\n";
		ptr_tmp = NTemp();
		(yyval).tipo = BOOLEANO;
		(yyval).dir 	= ptr_tmp;
		(yyval).cod 	= "mov #1 " + IntToString(ptr_tmp) + "\n";
	}
#line 2235 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 647 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 7...\n";
		ptr_tmp = NTemp();
		(yyval).tipo = BOOLEANO;
		(yyval).dir 	= ptr_tmp;
		(yyval).cod 	= "mov #0 " + IntToString(ptr_tmp) + "\n";
	}
#line 2247 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 654 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 8...\n";
		(yyval).tipo = (yyvsp[-1]).tipo;
		(yyval).dir 	= (yyvsp[-1]).dir;
		(yyval).cod 	= (yyvsp[-1]).cod;
	}
#line 2258 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 660 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 9...\n";
		if((yyvsp[0]).tipo != BOOLEANO) msgError(ERR_OPNOBOOL, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol, (yyvsp[-1]).lexema);
		ptr_tmp = NTemp();
		(yyval).dir = ptr_tmp;
		(yyval).tipo = (yyvsp[0]).tipo;
		(yyval).cod 	= (yyvsp[0]).cod
				+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
				+ "noti\n"
				+ "mov A " + IntToString(ptr_tmp) + "\n";
	}
#line 2274 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 671 "plp5.y" /* yacc.c:1646  */
    { if(!esBase((yyvsp[0]).tipo)) msgError(ERR_TIPOS,nlin,ncol,(yyvsp[0]).lexema); }
#line 2280 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 671 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Factor 10...\n";

		if(!esBase((yyvsp[0]).tipo)) msgError(ERR_TIPOS,(yyvsp[-3]).nlin,(yyvsp[-3]).ncol,(yyvsp[-3]).lexema);

		if((yyvsp[-3]).tipo == (yyvsp[0]).tipo) {
			(yyval).tipo = (yyvsp[0]).tipo;
			(yyval).dir 	= (yyvsp[0]).dir;
			(yyval).cod 	= (yyvsp[0]).cod;
		} else {
			ptr_tmp = NTemp();
			(yyval).tipo = (yyvsp[-3]).tipo;
			(yyval).dir 	= ptr_tmp;

			if((yyvsp[0]).tipo == BOOLEANO) {
				if((yyvsp[-3]).tipo == ENTERO) {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
								+ "ori #0\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				} else {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
								+ "orr #0\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				}
			} else if((yyvsp[0]).tipo == ENTERO) {
				if((yyvsp[-3]).tipo == BOOLEANO) {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
								+ "andi #1\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				} else {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
								+ "itor\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				}
			} else {
				if((yyvsp[-3]).tipo == BOOLEANO) {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
								+ "andr #1\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				} else {
					(yyval).cod 	= (yyvsp[0]).cod
								+ "mov " + IntToString((yyvsp[0]).dir) + " A\n"
								+ "rtoi\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				}
			}
		}
	}
#line 2338 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 724 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Ref 1...\n";
		simbolo_t s;
		s.lexema = (yyvsp[0]).lexema;
		if(!buscar(s,ambito))
			msgError(ERRNODECL,(yyvsp[0]).nlin,(yyvsp[0]).ncol, (yyvsp[0]).lexema);
		else{
			(yyval).tipo = s.idTipo;

			if(s.esArray) {
				ptr_tmp 	= NTemp();
				(yyval).dir = ptr_tmp;
				(yyval).dBase	= getTBaseVector(s.idTipo);
				//$$.dBase = $1.dir;
				(yyval).esArray = true;
				(yyval).cod 		= "mov #0 " + IntToString(ptr_tmp) + "\n";
			}
			else {
				(yyval).dir = s.dir;
				(yyval).tipo = s.idTipo;
				if(DEBUG) std::cout << "Ref -> id, símbolo [lex]" << s.lexema << "\t[dir]"<< s.dir << "\t[tipo]" << s.idTipo << "\n";
				//$$.cod = "mov "+ IntToString(s.dir) + " A\n";
				(yyval).esArray = false;
			}
		}
	}
#line 2369 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 750 "plp5.y" /* yacc.c:1646  */
    { /*if(!$1.esArray) msgError(ERRFALTAN,nlin,ncol,"");*/ }
#line 2375 "plp5.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 750 "plp5.y" /* yacc.c:1646  */
    {
		if(DEBUG) std::cout << " - Leído Ref 2...\n";
		if(!esBase((yyvsp[-1]).tipo)) msgError(ERR_EXP_ENT, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol,"");
		else {
			tipo_t t;
			buscarTipo((yyvsp[-4]).tipo, t);
			

			(yyval).tipo = tipoBase((yyvsp[-4]).tipo);
			ptr_tmp = NTemp();
			(yyval).dir = ptr_tmp;
			(yyval).dBase = (yyvsp[-4]).dBase;
			(yyval).esArray = (yyvsp[-4]).esArray;
			(yyval).cod = (yyvsp[-4]).cod + (yyvsp[-1]).cod
					 + "mov " + IntToString((yyvsp[-4]).dir) + " A\n" 
					 + "muli #" + IntToString(t.size) + "\n"
					 + "addi " + IntToString((yyvsp[-1]).dir) + "\n"
					 + "mov A " + IntToString(ptr_tmp) + "\n";
		}
	}
#line 2400 "plp5.tab.c" /* yacc.c:1646  */
    break;


#line 2404 "plp5.tab.c" /* yacc.c:1646  */
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
#line 772 "plp5.y" /* yacc.c:1906  */


int getDimensionesVector(const char* lexema){

	simbolo_t simboloVector;
	simboloVector.lexema = lexema;
	buscar(simboloVector,ambito);
	int cont = 0;
	tipo_t obj_tipo;
	buscarTipo(simboloVector.idTipo,obj_tipo);
	tipo_t tipo;
	cont ++;
	if(buscarTipo(obj_tipo.tipo_base,tipo)){

		cont ++;
		while(!esBase(tipo.tipo_base)) {
			cont ++;
			buscarTipo(obj_tipo.tipo_base,tipo);
			obj_tipo.tipo_base = tipo.tipo_base;
		}
	}
	return cont;
}


int getTBaseVector(int id){

	tipo_t obj_tipo;
	buscarTipo(id,obj_tipo);
	tipo_t tipo;

	if(buscarTipo(obj_tipo.tipo_base,tipo)){

		while(!esBase(tipo.tipo_base)) {
			buscarTipo(obj_tipo.tipo_base,tipo);
			obj_tipo.tipo_base = tipo.tipo_base;
		}
	}
	return tipo.tipo_base;
}


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
	tipo_t t;
	buscarTipo(tipo, t);
	return t.tipo_base;
}

int buscarDir(const char* lexema){

	simbolo_t s;
	s.lexema = lexema;
	if(buscar(s,ambito))
		return s.dir;

}

void nuevoSimbolo(char* lexema, bool esArray, int idTipo, int lin, int col) {
	if(DEBUG) std::cout << "*NUEVO SIMBOLO* Simbolo: " << lexema << 
						"\tIdx.Tipo: " << idTipo << 
						"\tDir.: " << ptr_mem <<
						"\tArray? " << esArray << "\n";
	simbolo_t s;
	s.lexema = lexema;
	if(!buscar(s,ambito)) {  // Si no existe
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
				obj_tipo.tipo_base = tipo.tipo_base;
			}
				ptr_mem += var;
		}

		if(ptr_mem > MAX_MEM)   // Si no cabe en memoria..
			msgError(ERR_NOCABE, lin, col, lexema);    // error, memoria llena  

			ambito->simbolos.push_back(s);
		}
	else{
		msgError(ERRYADECL, lin, col, lexema);   // Error, simbolo ya declarado
	}
}


bool existeSimbolo(const char* simbolo) {
  		
  if(DEBUG) std::cout << "Existe simbolo\n " ;

  std::vector<simbolo_t>::iterator begin_it = ambito->simbolos.begin();
  std::vector<simbolo_t>::iterator end_it   = ambito->simbolos.end();
  std::vector<simbolo_t>::iterator it       = std::find_if(begin_it,end_it, find_simbolo(std::string(simbolo))); 

  return it != end_it;

}

bool buscarSimbolo(simbolo_t& simbolo) {    // simbolo debe llegar con el lexema y volvera con todos los atributos
  
  std::vector<simbolo_t>::iterator begin_it = ambito->simbolos.begin();
  std::vector<simbolo_t>::iterator end_it   = ambito->simbolos.end();
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
  buscar(simbolo,ambito);
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

bool buscar(simbolo_t &s, tabla_simbolos* actual) {
	if(DEBUG) std::cout << "Vamos a buscar el simbolo..." << s.lexema << "\n";
	for (int i = 0; i < actual->simbolos.size(); i++) {
		if (s.lexema.compare(actual->simbolos[i].lexema) == 0) {
			s.idTipo = actual->simbolos[i].idTipo;
			s.dir = actual->simbolos[i].dir;
			s.esArray = actual->simbolos[i].esArray;
			s.lin = actual->simbolos[i].lin;
			s.col = actual->simbolos[i].col;
			if(DEBUG) std::cout << "Encontrado símbolo [lex]" << s.lexema << "\t[dir]"<< s.dir << "\t[tipo]" << s.idTipo << "\n";
			return true;
		}
	}


  if (actual->ts_padre != NULL) return buscar(s, actual->ts_padre);
  else        return false;
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


  std::cout << "############ TABLA DE SIMBOLOS ############ " << ambito->nombre<<endl;
  std::vector<simbolo_t>::iterator it_simbolos;
  int pos = 0;
  for(it_simbolos = ambito->simbolos.begin(); it_simbolos != ambito->simbolos.end(); ++it_simbolos)
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
