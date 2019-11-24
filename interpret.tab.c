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
#line 1 "interpret.y" /* yacc.c:339  */

//#define YYDEBUG 1
//#define YYERROR_VERBOSE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"	
#include "decl_list.h"
#include "arg_list.h"			//argument list
#include "scope.h"			//scope
#include "type.h"  			//symbol table 이용
#include "symtab.h"			//symbol table
#include "semantics.h"			//semantic

int num_add_to_sytb = 1;
void add_decl_to_symtab(symtab_type class, type_struct *type, location_e location);

/* Declaration list head node (linked list) */
decl_elem *head = NULL, *data;

/* A single symbol table */
symtable *st;

/* Symbol table entry */
st_node_t *st_node;

/* Function/Procedure argument list head node (linked list) */
arg_elem *arg_head = NULL;

char *calling_func_name;

/* Symbol table stack */
scope_elem *symtable_stack;

int num_of_args;
int stack_offset;

int yylex();				//error handling
void yyerror(const char *msg);		//error handling

#line 108 "interpret.tab.c" /* yacc.c:339  */

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
   by #include "interpret.tab.h".  */
#ifndef YY_YY_INTERPRET_TAB_H_INCLUDED
# define YY_YY_INTERPRET_TAB_H_INCLUDED
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
    RNUM = 259,
    INUM = 260,
    ARRAY = 261,
    BBEGIN = 262,
    ELSE = 263,
    END = 264,
    FOR = 265,
    FUNCTION = 266,
    IF = 267,
    INT = 268,
    SEMI = 269,
    COMA = 270,
    COLON = 271,
    LPARENT = 272,
    RPARENT = 273,
    LSBRACK = 274,
    RSBRACK = 275,
    NOT = 276,
    DOT = 277,
    POSITIVE = 278,
    NEGATIVE = 279,
    ELIF = 280,
    OF = 281,
    PROCEDURE = 282,
    MAINPROG = 283,
    FLOAT = 284,
    THEN = 285,
    VAR = 286,
    WHILE = 287,
    PRINT = 288,
    RETURN = 289,
    SIGN = 290,
    IN = 291,
    NOP = 292,
    ADDOP = 293,
    MULOP = 294,
    RELOP = 295,
    ASSIGNOP = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "interpret.y" /* yacc.c:355  */

  char *sval;
  int ival;
  float rval;
  char *opval;
  tree_t *tval;
  type_struct *type_s;

#line 199 "interpret.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INTERPRET_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "interpret.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    78,    83,    74,    93,    97,   102,   106,
     114,   120,   133,   137,   144,   145,   149,   174,   173,   211,
     210,   246,   247,   251,   255,   262,   270,   274,   281,   291,
     293,   295,   297,   300,   302,   304,   306,   313,   315,   320,
     329,   341,   346,   348,   345,   355,   354,   361,   360,   365,
     367,   372,   373,   377,   382,   386,   391,   394,   399,   408,
     410,   412,   414,   415,   417,   419,   426
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "RNUM", "INUM", "ARRAY", "BBEGIN",
  "ELSE", "END", "FOR", "FUNCTION", "IF", "INT", "SEMI", "COMA", "COLON",
  "LPARENT", "RPARENT", "LSBRACK", "RSBRACK", "NOT", "DOT", "POSITIVE",
  "NEGATIVE", "ELIF", "OF", "PROCEDURE", "MAINPROG", "FLOAT", "THEN",
  "VAR", "WHILE", "PRINT", "RETURN", "SIGN", "IN", "NOP", "ADDOP", "MULOP",
  "RELOP", "ASSIGNOP", "$accept", "program", "$@1", "$@2", "$@3",
  "declarations", "identifier_list", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "$@4", "$@5", "arguments", "parameter_list", "compound_statement",
  "statement_list", "statement", "print_statement", "variable",
  "procedure_statement", "if_statement", "$@6", "$@7", "while_statement",
  "$@8", "for_statement", "$@9", "actual_parameter_expression",
  "expression_list", "expression", "simple_expression", "term", "factor", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -20,    22,    33,    21,   -92,   -92,   -92,    -2,   -92,   -92,
       4,    34,    23,    45,    47,   -92,     4,   -92,   -92,    14,
      50,   -92,   -92,    52,   -92,    -3,   -92,    49,    40,    46,
      46,    44,   -92,   -92,   -92,   -92,    34,    51,    54,    -1,
       9,     9,     9,    53,     9,   -92,    57,    55,   -92,    30,
     -92,   -92,   -92,   -92,    25,    56,    -2,   -92,     9,     9,
     -92,   -92,   -92,     9,   -92,     9,   -92,   -92,    36,    35,
      41,    42,    66,    69,     9,   -92,   -92,    44,     9,    -2,
     -92,    59,    68,   -92,    72,    70,   -92,   -92,     9,     9,
       9,     9,    44,    44,    71,   -92,   -92,    74,   -92,   -92,
       9,   -92,    75,   -92,   -92,   -92,   -92,   -92,   -92,    34,
     -92,    44,    76,    79,   -92,   -92,    77,    92,    82,     9,
      87,    96,    90,    44,    91,    44,    89,    44,    93,   -92,
      94,   -92,   -92,    97,   102,    99,    44,    98,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     7,     3,    12,    13,
      15,     0,    10,     0,     0,     4,    15,     7,     8,     0,
       0,    17,    19,     0,    14,     0,     6,     0,     0,    22,
      22,    36,     5,    16,     9,    11,     0,     0,     0,    39,
       0,     0,     0,    37,     0,    31,     0,    26,    29,     0,
      30,    33,    34,    35,     0,     0,     0,    20,    49,     0,
      66,    65,    59,     0,    60,     0,    61,    62,     0,    53,
      55,    57,     0,     0,     0,    32,    25,    36,     0,     0,
      21,     0,     0,    50,    51,     0,    63,    64,     0,     0,
       0,     0,    36,    36,     0,    27,    28,    23,    18,    41,
       0,    40,     0,    54,    56,    58,    42,    45,    38,     0,
      52,    36,     0,     0,    24,    47,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    36,     0,    36,     0,    46,
       0,    43,    48,     0,     0,     0,    36,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,    95,   106,    43,    63,   104,
     -92,   -92,   -92,   -92,    83,    12,    -6,    48,   -91,   -92,
     -31,   -28,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
      24,   -35,   -32,    32,   -42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    10,    23,     7,    54,    11,    12,    15,
      16,    17,    29,    30,    37,    55,    45,    46,    47,    48,
      66,    67,    51,   112,   133,    52,   113,    53,   118,    82,
      83,    84,    69,    70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,   106,   107,    50,    31,    68,    72,    73,     1,    75,
       8,     8,    39,    60,    61,    13,    58,    32,    59,    33,
     115,    86,    62,    87,    85,     3,     9,     9,    26,    27,
      63,    14,   126,     4,   128,     5,   130,    18,    64,    94,
      27,    79,    20,    96,    65,   137,    49,    39,    21,    50,
      22,    31,    34,   102,    40,    28,    41,   103,   104,    31,
      35,    49,    49,    36,    50,    50,    76,    56,    57,    77,
      74,    78,    88,    98,    80,    89,    42,    43,    44,    90,
      49,    91,    92,    50,   122,    93,    99,   100,   109,   108,
     101,   111,    49,   116,    49,    50,    49,    50,   117,    50,
     120,   121,   119,   123,   124,    49,   125,   127,    50,   129,
     135,   131,    25,    38,   132,   136,   134,    19,   138,    81,
      24,   114,    97,   105,   110,    95
};

static const yytype_uint8 yycheck[] =
{
      31,    92,    93,    31,     7,    40,    41,    42,    28,    44,
      13,    13,     3,     4,     5,    11,    17,    23,    19,    25,
     111,    63,    13,    65,    59,     3,    29,    29,    14,    15,
      21,    27,   123,     0,   125,    14,   127,     3,    29,    74,
      15,    16,    19,    78,    35,   136,    77,     3,     3,    77,
       3,     7,     3,    88,    10,     5,    12,    89,    90,     7,
      20,    92,    93,    17,    92,    93,     9,    16,    14,    14,
      17,    41,    36,    14,    18,    40,    32,    33,    34,    38,
     111,    39,    16,   111,   119,    16,    18,    15,    14,    18,
      20,    16,   123,    17,   125,   123,   127,   125,    19,   127,
       8,    19,    25,    16,     8,   136,    16,    16,   136,    20,
       8,    18,    17,    30,    20,    16,    19,    11,    20,    56,
      16,   109,    79,    91,   100,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    43,     3,     0,    14,    44,    47,    13,    29,
      45,    49,    50,    11,    27,    51,    52,    53,     3,    48,
      19,     3,     3,    46,    51,    47,    14,    15,     5,    54,
      55,     7,    58,    58,     3,    20,    17,    56,    56,     3,
      10,    12,    32,    33,    34,    58,    59,    60,    61,    62,
      63,    64,    67,    69,    48,    57,    16,    14,    17,    19,
       4,     5,    13,    21,    29,    35,    62,    63,    73,    74,
      75,    76,    73,    73,    17,    73,     9,    14,    41,    16,
      18,    50,    71,    72,    73,    73,    76,    76,    36,    40,
      38,    39,    16,    16,    73,    59,    73,    49,    14,    18,
      15,    20,    73,    74,    74,    75,    60,    60,    18,    14,
      72,    16,    65,    68,    57,    60,    17,    19,    70,    25,
       8,    19,    73,    16,     8,    16,    60,    16,    60,    20,
      60,    18,    20,    66,    19,     8,    16,    60,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    45,    46,    43,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    54,    53,    55,
      53,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    65,    66,    64,    68,    67,    70,    69,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     4,     0,     1,     3,
       1,     4,     1,     1,     2,     0,     3,     0,     7,     0,
       5,     3,     0,     3,     5,     3,     1,     3,     3,     1,
       1,     1,     2,     1,     1,     1,     0,     1,     4,     1,
       4,     4,     0,     0,    17,     0,    10,     0,    12,     0,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     2,     1,     1
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
#line 75 "interpret.y" /* yacc.c:1646  */
    {	
		}
#line 1388 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "interpret.y" /* yacc.c:1646  */
    {
                scope_push(symtable_stack, st); // 전역변수 선언
		print_symtab(st);	//declaration 결과 symbol table 출력
		}
#line 1397 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "interpret.y" /* yacc.c:1646  */
    {
		}
#line 1404 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "interpret.y" /* yacc.c:1646  */
    {	
                stack_offset = calculate_stack_offset(st); // 선언문의 내용 전역변수로 저장
		}
#line 1412 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "interpret.y" /* yacc.c:1646  */
    {
				add_decl_to_symtab(VAR_CLASS, (yyvsp[-2].type_s), ST_LOCAL); // variable class , type, location저장
			}
#line 1420 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "interpret.y" /* yacc.c:1646  */
    {
				head = decl_append(head, (yyvsp[0].sval)); // 첫번째 토큰 ID를 decl_elem list에 확장
			}
#line 1428 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "interpret.y" /* yacc.c:1646  */
    {
//				printf("ID_LIST\n");
				head = decl_append(head, (yyvsp[0].sval)); // . 토큰 ID를 decl_elem list에 확장
			}
#line 1437 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "interpret.y" /* yacc.c:1646  */
    {
				(yyval.type_s) = (type_struct *) calloc(1, sizeof(type_struct)); //type을 추가하고
				(yyval.type_s)->name = (yyvsp[0].ival);					//이름을 추가
			}
#line 1446 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "interpret.y" /* yacc.c:1646  */
    {
               (yyval.type_s) = (type_struct *) calloc(1, sizeof(type_struct));
               if ((yyvsp[-3].ival) == INTEGER_TYPE)
               	(yyval.type_s)->name = ARRAY_TYPE_INT;
               else if ((yyvsp[-3].ival) == FLOAT_TYPE)
               	(yyval.type_s)->name = ARRAY_TYPE_REAL;
               (yyval.type_s)->lb = 1;	//low bound = 1
               (yyval.type_s)->ub = (yyvsp[-1].ival);	//upper bound = inum
		}
#line 1460 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.ival) = INTEGER_TYPE;	//int = integer_type 으로 치환
		}
#line 1468 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.ival) = FLOAT_TYPE;
		}
#line 1476 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "interpret.y" /* yacc.c:1646  */
    {
               /* Calculate a function's stack offset */
               stack_offset = calculate_stack_offset(st);
//               prologue(st->name, stack_offset);

               /* Make sure the function var was assigned if class is function_type
                  The procedure case might not fire because there should be a
                  type mismatch when trying to assign a value to the proc's id */
               if (calling_func_name != NULL) {
                 st_node = search_scope_stack(symtable_stack, calling_func_name);
                 if (st_node->class == FUNCTION_CLASS && st->has_return != 1 && st->name != NULL)
                   sem_error(NO_RETURN_STMT);
                 else if (st_node->class == PROCEDURE_CLASS && st->has_return == 1)
                   sem_error(NON_LOCAL_MODIFICATION);
		/* Pop current scope */
               st = scope_pop(symtable_stack);
		/* Pop parent scope so it's available again */
               st = scope_pop(symtable_stack);
               }
		}
#line 1501 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 174 "interpret.y" /* yacc.c:1646  */
    {
               type_struct *t = calloc(1, sizeof(type_struct));

               /* st->entries increases to keep track of the variable's
                  index in the symbol table (st).  Used for gencode identifier lookups */
               (st->entries)++;
               symtab_insert(st, (yyvsp[0].sval), FUNCTION_CLASS, t, ST_LOCAL, st->entries);

               // push parent with function name added to it
               scope_push(symtable_stack, st);
               st = calloc(1, sizeof(symtable));
               /* reset to 0 because a new symbol table has its own set of offsets
                  for local declarations */
               st->entries = 0;

               // set encountered func as calling func name
               calling_func_name = (yyvsp[0].sval);

               // reset arg counter and argument list
               num_of_args = 0;
               arg_head = NULL;
		}
#line 1528 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 197 "interpret.y" /* yacc.c:1646  */
    {
 		// set symtab name as the function name
               st->name = calling_func_name;

               // create arg_type_list for the parent symbol table
               st_node = search_scope_stack(symtable_stack, (yyvsp[-5].sval));
               st_node->arg_type_list = arg_head;
               st_node->type->name = (yyvsp[-1].ival);
               st_node->num_of_args = num_of_args;

               // push symtab so it can be searched in the function
               scope_push(symtable_stack, st);
		}
#line 1546 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "interpret.y" /* yacc.c:1646  */
    {
               type_struct *t = calloc(1, sizeof(type_struct));

               (st->entries)++;
               symtab_insert(st, (yyvsp[0].sval), PROCEDURE_CLASS, t, ST_LOCAL, st->entries);

               // push parent with procedure name added to it
               scope_push(symtable_stack, st);
               st = calloc(1, sizeof(symtable));
               st->entries = 0;

               // set func as calling func name
               calling_func_name = (yyvsp[0].sval);

               // reset arg counter and argument list
               num_of_args = 0;
               //arg_destroy(arg_head);
               arg_head = NULL;
		}
#line 1570 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 231 "interpret.y" /* yacc.c:1646  */
    {
  		// set symtab name as the procedure name
               st->name = calling_func_name;

               // create arg_type_list for the parent symbol table
               st_node = search_scope_stack(symtable_stack, (yyvsp[-3].sval));
               st_node->arg_type_list = arg_head;
               st_node->num_of_args = num_of_args;

               // push symtab so it can be searched in the function
               scope_push(symtable_stack, st);
		}
#line 1587 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "interpret.y" /* yacc.c:1646  */
    {
               add_decl_to_symtab(VAR_CLASS, (yyvsp[0].type_s), ST_PARAMETER);
		}
#line 1595 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 256 "interpret.y" /* yacc.c:1646  */
    {
               //add_decl_to_symtab(VAR_CLASS, $3, ST_PARAMETER);
		}
#line 1603 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 263 "interpret.y" /* yacc.c:1646  */
    {
		(yyval.tval) = mktree(BEGIN_END, 1, (yyvsp[-1].tval));
		}
#line 1611 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 271 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.tval)=(yyvsp[0].tval);
		}
#line 1619 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 275 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.tval) = mktree(STMT_LIST, 2, (yyvsp[0].tval), (yyvsp[-2].tval));
		}
#line 1627 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "interpret.y" /* yacc.c:1646  */
    {
			//type checking
			fprintf(stderr, "type comparison : %d (compare) %d\n",type_check((yyvsp[-2].tval)),type_check((yyvsp[0].tval)));
	               	if (type_check((yyvsp[-2].tval)) != type_check((yyvsp[0].tval))) {
			sem_error(TYPE_MISMATCH_ASSN);
			}            
			(yyval.tval) = mktree(ASSIGN_STMT, 2, (yyvsp[-2].tval), (yyvsp[0].tval));
			printf("assign success\n");
		}
#line 1641 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "interpret.y" /* yacc.c:1646  */
    {}
#line 1647 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 294 "interpret.y" /* yacc.c:1646  */
    {}
#line 1653 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 296 "interpret.y" /* yacc.c:1646  */
    {}
#line 1659 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 298 "interpret.y" /* yacc.c:1646  */
    { st->has_return = 1;}
#line 1665 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 301 "interpret.y" /* yacc.c:1646  */
    {}
#line 1671 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 303 "interpret.y" /* yacc.c:1646  */
    {}
#line 1677 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 305 "interpret.y" /* yacc.c:1646  */
    {}
#line 1683 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 306 "interpret.y" /* yacc.c:1646  */
    {}
#line 1689 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 314 "interpret.y" /* yacc.c:1646  */
    {}
#line 1695 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 316 "interpret.y" /* yacc.c:1646  */
    {}
#line 1701 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 321 "interpret.y" /* yacc.c:1646  */
    {
               st_node = search_scope_stack(symtable_stack, (yyvsp[0].sval));	//Search Stack
               if (st_node == NULL) { sem_error(VAR_UNDECLARED); }	//None - Error
             

               (yyval.tval) = mktree(IDENT, 0);
               (yyval.tval)->attr.sval = st_node;
}
#line 1714 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 330 "interpret.y" /* yacc.c:1646  */
    {
				st_node = search_scope_stack(symtable_stack, (yyvsp[-3].sval));
				if (st_node == NULL) { sem_error(VAR_UNDECLARED); }
				array_semantics(st_node, (yyvsp[-1].tval));

				(yyval.tval) = mktree(ID_ARRAY, 1, (yyvsp[-1].tval));
				(yyval.tval)->attr.sval = st_node;
			}
#line 1727 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 342 "interpret.y" /* yacc.c:1646  */
    {}
#line 1733 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 346 "interpret.y" /* yacc.c:1646  */
    {}
#line 1739 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 348 "interpret.y" /* yacc.c:1646  */
    {}
#line 1745 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 350 "interpret.y" /* yacc.c:1646  */
    {}
#line 1751 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 355 "interpret.y" /* yacc.c:1646  */
    {}
#line 1757 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 357 "interpret.y" /* yacc.c:1646  */
    {}
#line 1763 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 361 "interpret.y" /* yacc.c:1646  */
    {}
#line 1769 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 378 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.tval)= (yyvsp[0].tval);
printf("simple -> expression\n");	
		}
#line 1778 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 387 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.tval)=(yyvsp[0].tval);
			printf("term -> simple\n");
		}
#line 1787 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 395 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.tval)=(yyvsp[0].tval);
			printf("factor -> term\n");
		}
#line 1796 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 400 "interpret.y" /* yacc.c:1646  */
    {
			(yyval.tval) = mktree(MULOP_EXPR, 2, (yyvsp[0].tval), (yyvsp[-2].tval));
			(yyval.tval)->attr.opval = (yyvsp[-1].opval);
		}
#line 1805 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 409 "interpret.y" /* yacc.c:1646  */
    {}
#line 1811 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 411 "interpret.y" /* yacc.c:1646  */
    {}
#line 1817 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 413 "interpret.y" /* yacc.c:1646  */
    {(yyval.tval) = (yyvsp[0].tval);}
#line 1823 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 416 "interpret.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(NOT_FACTOR, 1, (yyvsp[0].tval)); }
#line 1829 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 418 "interpret.y" /* yacc.c:1646  */
    { (yyval.tval) = mktree(SIGN_TERM, 1,(yyvsp[0].tval)); }
#line 1835 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 420 "interpret.y" /* yacc.c:1646  */
    {
		printf("int number : %d\n",(yyvsp[0].ival));	
		(yyval.tval) = mktree(INUMBER,0);
		(yyval.tval)->attr.ival = (yyvsp[0].ival);
		printf("int number accept success - %d\n",(yyvsp[0].ival));			
		}
#line 1846 "interpret.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 427 "interpret.y" /* yacc.c:1646  */
    {
		printf("real number : %f\n",(yyvsp[0].rval));
		(yyval.tval) = mktree(RNUMBER,0);
		(yyval.tval)->attr.rval = (yyvsp[0].rval);
		printf("real number accept success - %f\n",(yyvsp[0].rval));			
		}
#line 1857 "interpret.tab.c" /* yacc.c:1646  */
    break;


#line 1861 "interpret.tab.c" /* yacc.c:1646  */
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
#line 435 "interpret.y" /* yacc.c:1906  */


void add_decl_to_symtab(symtab_type class, type_struct *type, location_e location) {
  data = head;
//	printf("num_add_to_sytb : %d\n",num_add_to_sytb++);
  if (data != NULL) {
    do {
      if (location == ST_PARAMETER) {
        num_of_args++;
        arg_head = arg_append(arg_head, type->name);
      }

	fprintf(stderr,"calling func name: %s\n",calling_func_name);
      (st->entries)++;
      symtab_insert(st, data->name, class, type, location, st->entries);
	fprintf(stderr,"PARAM_LIST,NAME: %s, type: %d\n\n",data->name, type->name);

      data = data->next;
    }
    while (data != head);

    decl_destroy(head);
    decl_destroy(data);
    head = NULL;
  }
  else
    fprintf(stderr, "data is null\n");

}

int main() {
  symtable_stack = scope_init(10);
  st = calloc(1, sizeof(symtable));
  st->entries = 0;
 

  yyparse();
  printf("\n");
}

