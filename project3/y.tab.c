/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "file2.yacc" /* yacc.c:339  */
								
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <queue>
	#include<iostream>
	int yylex(void);
	extern int yylineno;
	void yyerror(char *);
	using namespace std;
	int deb=0;
	
	struct node
	{
		string content;
		vector<node *> children;
	};

	#define YYSTYPE node*
	node *root = NULL, *temp;

	queue<node*> BFS_queue;

	void print_next_level()
	{
		if(BFS_queue.empty())
			return;

		struct node* temp_node;
		struct node* parent_node;
		queue<node*> temp_queue;

		temp_queue = BFS_queue;

		while(!temp_queue.empty())
		{
			temp_node = temp_queue.front();
			parent_node = BFS_queue.front();
			temp_queue.pop();
			BFS_queue.pop();

			if((temp_node->children).size() > 0)
			{
				cout<<"{"<<parent_node->content<<"} ";
			}

			for(int i=0; i < (temp_node->children).size(); i++)
			{
				cout<<(temp_node->children[i])->content<<" ";
				BFS_queue.push(temp_node->children[i]);			
			}

			//cout<<" ";
		}

		cout<<endl<<endl<<endl;
		print_next_level();

 	}

 	void print_parse_tree(struct node* root)
 	{
 		if(root == NULL)
 			return;

 		cout<<endl<<"Printing Parse Tree..."<<endl<<endl;

 		cout<<root->content<<endl<<endl;

 		for(int i=0; i < (root->children).size(); i++)
		{
			cout<<(root->children[i])->content<<" ";
		}

		cout<<endl;

		for(int i=0; i < (root->children).size(); i++)
		{
			BFS_queue.push(root->children[i]);
		}

		cout<<endl;
		print_next_level();
 	}


#line 153 "y.tab.c" /* yacc.c:339  */

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
    VAR = 258,
    PROTOTYPE = 259,
    DEF = 260,
    INT = 261,
    BOOL = 262,
    BEG = 263,
    END = 264,
    RET = 265,
    ASSIGN = 266,
    CALL = 267,
    SCAN = 268,
    PRINT = 269,
    ENDL = 270,
    SPACE = 271,
    WHILE = 272,
    IF = 273,
    THEN = 274,
    ID = 275,
    NUM = 276
  };
#endif
/* Tokens.  */
#define VAR 258
#define PROTOTYPE 259
#define DEF 260
#define INT 261
#define BOOL 262
#define BEG 263
#define END 264
#define RET 265
#define ASSIGN 266
#define CALL 267
#define SCAN 268
#define PRINT 269
#define ENDL 270
#define SPACE 271
#define WHILE 272
#define IF 273
#define THEN 274
#define ID 275
#define NUM 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,    29,     2,
      23,    24,    35,    33,    25,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
      32,    26,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,    27,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   118,   126,   135,   147,   160,   173,   185,
     198,   211,   223,   236,   237,   249,   264,   273,   283,   294,
     305,   318,   332,   347,   357,   369,   379,   389,   426,   463,
     500,   539,   548,   557,   574,   591,   609,   623,   637,   650,
     663,   679,   696,   703,   720,   736,   754,   762,   770,   782,
     793,   801,   809,   816,   823,   833,   844,   854,   868,   877,
     890,   898,   909,   918,   926,   937,   946,   954,   965,   974,
     982,   994,  1003,  1011,  1022,  1031,  1039,  1049,  1060,  1069,
    1077,  1087,  1098,  1107,  1113,  1119,  1133,  1148
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "PROTOTYPE", "DEF", "INT", "BOOL",
  "BEG", "END", "RET", "ASSIGN", "CALL", "SCAN", "PRINT", "ENDL", "SPACE",
  "WHILE", "IF", "THEN", "ID", "NUM", "';'", "'('", "')'", "','", "'='",
  "'~'", "'|'", "'&'", "'%'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "$accept", "Start", "S", "S1", "DV", "PF", "FF", "PARAM", "PP", "DF",
  "stmt_list", "stmt", "E_or_C", "PARAM1", "PP1", "V", "V1", "num", "id",
  "expr", "E1", "O", "O1", "A", "A1", "M", "M1", "G", "G1", "L", "L1",
  "AS", "AS1", "MD", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    40,    41,    44,    61,   126,   124,    38,
      37,    62,    60,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -156

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-156)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     139,   129,   140,   142,   144,     9,  -156,   139,    67,    67,
      49,    51,    67,    67,    26,    67,    67,    52,    67,    67,
    -156,  -156,  -156,    59,  -156,  -156,    23,  -156,  -156,    28,
    -156,  -156,  -156,  -156,  -156,  -156,    15,  -156,  -156,  -156,
      68,  -156,  -156,   146,   146,   146,   146,    67,    67,    69,
      12,    18,    77,    50,    50,  -156,  -156,    46,  -156,    96,
     146,  -156,  -156,    85,    85,  -156,    67,    67,    67,   106,
      14,    14,    97,    71,   113,    83,   105,    54,  -156,  -156,
    -156,   134,    55,  -156,  -156,    14,    14,  -156,  -156,   133,
      41,   145,   115,   127,   131,   123,   124,   165,    43,  -156,
      43,     5,     5,  -156,  -156,  -156,  -156,  -156,   151,    19,
      99,    14,  -156,    14,  -156,    14,  -156,    14,  -156,    14,
    -156,    14,    14,  -156,    14,    14,  -156,    99,   154,  -156,
    -156,    56,    67,   155,  -156,    61,  -156,  -156,  -156,   169,
      41,   145,   115,   127,   131,   123,   123,   124,   124,   170,
     171,   172,    13,    29,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,    43,    43,   158,   159,    20,  -156,    43,  -156,
    -156,  -156,  -156
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     3,    58,     0,    18,    12,     0,    19,    15,     0,
       7,    10,    16,    17,     6,     5,     0,     9,     8,    11,
       0,    14,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    26,    22,    21,     0,    20,     0,
       0,    23,    24,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    54,
      56,     0,     0,    53,    52,     0,     0,    83,    84,     0,
      62,    65,    68,    71,    74,    78,    82,     0,     0,    31,
       0,     0,     0,    37,    36,    57,    39,    38,     0,     0,
       0,     0,    60,     0,    63,     0,    66,     0,    69,     0,
      72,     0,     0,    75,     0,     0,    79,     0,     0,    50,
      51,     0,     0,     0,    42,     0,    87,    86,    85,     0,
      62,    65,    68,    71,    74,    78,    78,    82,    82,     0,
       0,     0,     0,     0,    34,    35,    33,    40,    61,    64,
      67,    70,    73,    76,    77,    80,    81,    41,    29,    28,
      30,    27,    47,    47,     0,    49,     0,    44,    47,    46,
      45,    43,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,   176,  -156,   183,   184,   116,    74,   132,   119,
     -61,  -156,    86,  -155,  -156,   -33,  -156,   -67,    -8,    44,
      53,    78,    57,    79,    48,    76,    58,    80,    60,    75,
      16,    45,    21,    47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    10,    11,    24,    49,    61,    25,
      72,    73,   133,   174,   179,   175,    82,    87,    88,   134,
     112,    90,   114,    91,   116,    92,   118,    93,   120,    94,
     123,    95,   126,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    29,    83,    74,    32,    33,    85,    36,    36,    20,
      40,    40,    99,    56,   170,    85,    43,   132,   176,    56,
     137,   180,   171,   182,    43,    22,    80,    34,    86,    43,
     172,   129,    81,   129,    22,    80,    57,    86,    45,    53,
      54,    81,    58,   138,   181,   -16,    44,    63,    35,   139,
     -17,    44,   173,    37,    64,   103,   106,   151,    75,    76,
      77,    84,   155,    22,    80,   128,   149,   131,   -20,   111,
      81,    30,    66,    31,    38,    60,   104,   107,   152,    42,
     -32,   -32,    67,   156,    68,    69,    66,    22,    70,    71,
     130,    46,   130,    55,    23,   -32,    67,    63,    68,    69,
      66,    59,    70,    71,    64,   129,   129,    98,   -32,   101,
      67,   129,    68,    69,    89,    97,    70,    71,    50,    51,
      52,    78,    79,   100,   153,    27,    22,    80,    28,   108,
     109,   102,    27,    81,    65,     8,     9,    39,    41,    -4,
       1,   110,     2,     3,     4,   115,    12,    13,    15,    16,
      18,    19,    47,    48,    42,   105,   121,   122,   117,   124,
     125,   163,   164,   119,   130,   130,   145,   146,   165,   166,
     130,   147,   148,   127,   113,   136,   150,   154,   157,   167,
     168,   169,   177,    21,   178,    14,    62,    17,   135,   140,
     160,   142,   141,   158,   144,     0,     0,   143,   159,     0,
       0,   161,     0,     0,   162
};

static const yytype_int16 yycheck[] =
{
       8,     9,    69,    64,    12,    13,     1,    15,    16,     0,
      18,    19,    73,     1,     1,     1,     1,    12,   173,     1,
       1,     1,     9,   178,     1,    20,    21,     1,    23,     1,
       1,    98,    27,   100,    20,    21,    24,    23,    23,    47,
      48,    27,    24,    24,    24,    22,    23,     1,    22,   110,
      22,    23,    23,     1,     8,     1,     1,     1,    66,    67,
      68,    69,     1,    20,    21,    98,   127,   100,    22,    28,
      27,    22,     1,    22,    22,    25,    22,    22,    22,    20,
       9,    10,    11,    22,    13,    14,     1,    20,    17,    18,
      98,    23,   100,    24,    27,    10,    11,     1,    13,    14,
       1,    24,    17,    18,     8,   172,   173,    10,     9,    26,
      11,   178,    13,    14,    70,    71,    17,    18,    44,    45,
      46,    15,    16,    10,   132,     9,    20,    21,     9,    85,
      86,    26,    16,    27,    60,     6,     7,    18,    19,     0,
       1,     8,     3,     4,     5,    30,     6,     7,     6,     7,
       6,     7,     6,     7,    20,    21,    33,    34,    31,    35,
      36,   145,   146,    32,   172,   173,   121,   122,   147,   148,
     178,   124,   125,     8,    29,    24,    22,    22,     9,     9,
       9,     9,    24,     7,    25,     2,    54,     3,   102,   111,
     142,   115,   113,   140,   119,    -1,    -1,   117,   141,    -1,
      -1,   143,    -1,    -1,   144
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,    38,    39,    40,     6,     7,
      41,    42,     6,     7,    41,     6,     7,    42,     6,     7,
       0,    39,    20,    27,    43,    46,    55,    43,    46,    55,
      22,    22,    55,    55,     1,    22,    55,     1,    22,    46,
      55,    46,    20,     1,    23,    23,    23,     6,     7,    44,
      44,    44,    44,    55,    55,    24,     1,    24,    24,    24,
      25,    45,    45,     1,     8,    44,     1,    11,    13,    14,
      17,    18,    47,    48,    47,    55,    55,    55,    15,    16,
      21,    27,    53,    54,    55,     1,    23,    54,    55,    56,
      58,    60,    62,    64,    66,    68,    70,    56,    10,    47,
      10,    26,    26,     1,    22,    21,     1,    22,    56,    56,
       8,    28,    57,    29,    59,    30,    61,    31,    63,    32,
      65,    33,    34,    67,    35,    36,    69,     8,    52,    54,
      55,    52,    12,    49,    56,    49,    24,     1,    24,    47,
      58,    60,    62,    64,    66,    68,    68,    70,    70,    47,
      22,     1,    22,    55,    22,     1,    22,     9,    57,    59,
      61,    63,    65,    67,    67,    69,    69,     9,     9,     9,
       1,     9,     1,    23,    50,    52,    50,    24,    25,    51,
       1,    24,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    58,    59,    59,    60,    61,    61,    62,
      63,    63,    64,    65,    65,    66,    67,    67,    67,    68,
      69,    69,    69,    70,    70,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     3,     3,     2,     2,     2,     2,
       4,     4,     4,     3,     3,     2,     0,    10,    10,    10,
      10,     2,     0,     5,     5,     5,     3,     3,     3,     3,
       5,     5,     1,     5,     5,     5,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       2,     3,     0,     2,     3,     0,     2,     3,     0,     2,
       3,     0,     2,     3,     0,     2,     3,     3,     0,     2,
       3,     3,     0,     1,     1,     3,     3,     3
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
#line 109 "file2.yacc" /* yacc.c:1646  */
    { 	
	printf("valid\n"); 
	(yyval)=new node; 
	root=(yyval); 
	(yyval)->content="Start"; 
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 119 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="S"; 
	(yyval)->children.push_back((yyvsp[-1])); 
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="S"; 
	temp = new node;
	temp->content = "Epsilon";
	(yyval)->children.push_back(temp);
}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 136 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "VAR";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) =new node;
	(yyvsp[0])->content="Semicolon";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 148 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing semicolon at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "VAR";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) =new node;
	(yyvsp[0])->content="Semicolon";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 161 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing var at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "VAR";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) =new node;
	(yyvsp[0])->content="Semicolon";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 174 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="S1"; 
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "PROTOTYPE";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) =new node;
	(yyvsp[0])->content="Semicolon";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 186 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing semicolon at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="S1"; 
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "PROTOTYPE";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) =new node;
	(yyvsp[0])->content="Semicolon";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 199 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing prototype at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="S1"; 
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "PROTOTYPE";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) =new node;
	(yyvsp[0])->content="Semicolon";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 212 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "DEF";
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="INT";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 224 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing 'def' at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "DEF";
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="INT";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "DEF";
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="BOOL";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 250 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing 'def' at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="S1";
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "DEF";
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="BOOL";
	(yyval)->children.push_back((yyvsp[-2])); 
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 265 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="DV";
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="INT";
	(yyval)->children.push_back((yyvsp[-1])); 
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 274 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="DV"; 
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="BOOL";
	(yyval)->children.push_back((yyvsp[-1])); 
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 284 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="PF"; 
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="INT";
	(yyval)->children.push_back((yyvsp[-1])); 
	(yyval)->children.push_back((yyvsp[0]));

}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 295 "file2.yacc" /* yacc.c:1646  */
    {
(yyval)=new node; 
(yyval)->content="PF"; 
(yyvsp[-1])=new node;
(yyvsp[-1])->content="BOOL";
(yyval)->children.push_back((yyvsp[-1])); 
(yyval)->children.push_back((yyvsp[0]));
}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 306 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="FF"; 
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content="(";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) = new node;
	(yyvsp[0])->content=")";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 319 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing ) at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="FF"; 
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content="(";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) = new node;
	(yyvsp[0])->content=")";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 333 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing ( at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="FF"; 
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content="(";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0]) = new node;
	(yyvsp[0])->content=")";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 348 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content = "INT";
	(yyval)->content = "PARAM";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 358 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content = "BOOL";
	(yyval)->content = "PARAM";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 370 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyvsp[-1])= new node;
	(yyvsp[-1])->content = "Comma";
	(yyval)->content = "PP";
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 379 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	temp= new node;
	temp->content = "Epsilon";
	(yyval)->content = "PP";
	(yyval)->children.push_back(temp);

}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 390 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content = "DF";
	(yyval)->children.push_back((yyvsp[-9]));

	(yyvsp[-8])= new node;
	(yyvsp[-8])->content = "(";
	(yyval)->children.push_back((yyvsp[-8]));

	(yyval)->children.push_back((yyvsp[-7]));

	(yyvsp[-6])= new node;
	(yyvsp[-6])->content = ")";
	(yyval)->children.push_back((yyvsp[-6]));

	(yyvsp[-5])= new node;
	(yyvsp[-5])->content = "BEG";
	(yyval)->children.push_back((yyvsp[-5]));
	
	(yyval)->children.push_back((yyvsp[-4]));

	(yyvsp[-3])= new node;	
	(yyvsp[-3])->content = "RET";
	(yyval)->children.push_back((yyvsp[-3]));

	(yyval)->children.push_back((yyvsp[-2]));

	(yyvsp[-1])= new node;	
	(yyvsp[-1])->content = ";";
	(yyval)->children.push_back((yyvsp[-1]));

	(yyvsp[0])= new node;	
	(yyvsp[0])->content = "END";
	(yyval)->children.push_back((yyvsp[0]));

}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 427 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing semicolon at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content = "DF";
	(yyval)->children.push_back((yyvsp[-9]));

	(yyvsp[-8])= new node;
	(yyvsp[-8])->content = "(";
	(yyval)->children.push_back((yyvsp[-8]));

	(yyval)->children.push_back((yyvsp[-7]));

	(yyvsp[-6])= new node;
	(yyvsp[-6])->content = ")";
	(yyval)->children.push_back((yyvsp[-6]));

	(yyvsp[-5])= new node;
	(yyvsp[-5])->content = "BEG";
	(yyval)->children.push_back((yyvsp[-5]));
	
	(yyval)->children.push_back((yyvsp[-4]));

	(yyvsp[-3])= new node;	
	(yyvsp[-3])->content = "RET";
	(yyval)->children.push_back((yyvsp[-3]));

	(yyval)->children.push_back((yyvsp[-2]));

	(yyvsp[-1])= new node;	
	(yyvsp[-1])->content = ";";
	(yyval)->children.push_back((yyvsp[-1]));

	(yyvsp[0])= new node;	
	(yyvsp[0])->content = "END";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 464 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing begin at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content = "DF";
	(yyval)->children.push_back((yyvsp[-9]));

	(yyvsp[-8])= new node;
	(yyvsp[-8])->content = "(";
	(yyval)->children.push_back((yyvsp[-8]));

	(yyval)->children.push_back((yyvsp[-7]));

	(yyvsp[-6])= new node;
	(yyvsp[-6])->content = ")";
	(yyval)->children.push_back((yyvsp[-6]));

	(yyvsp[-5])= new node;
	(yyvsp[-5])->content = "BEG";
	(yyval)->children.push_back((yyvsp[-5]));
	
	(yyval)->children.push_back((yyvsp[-4]));

	(yyvsp[-3])= new node;	
	(yyvsp[-3])->content = "RET";
	(yyval)->children.push_back((yyvsp[-3]));

	(yyval)->children.push_back((yyvsp[-2]));

	(yyvsp[-1])= new node;	
	(yyvsp[-1])->content = ";";
	(yyval)->children.push_back((yyvsp[-1]));

	(yyvsp[0])= new node;	
	(yyvsp[0])->content = "END";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 501 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing end at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content = "DF";
	(yyval)->children.push_back((yyvsp[-9]));

	(yyvsp[-8])= new node;
	(yyvsp[-8])->content = "(";
	(yyval)->children.push_back((yyvsp[-8]));

	(yyval)->children.push_back((yyvsp[-7]));

	(yyvsp[-6])= new node;
	(yyvsp[-6])->content = ")";
	(yyval)->children.push_back((yyvsp[-6]));

	(yyvsp[-5])= new node;
	(yyvsp[-5])->content = "BEG";
	(yyval)->children.push_back((yyvsp[-5]));
	
	(yyval)->children.push_back((yyvsp[-4]));

	(yyvsp[-3])= new node;	
	(yyvsp[-3])->content = "RET";
	(yyval)->children.push_back((yyvsp[-3]));

	(yyval)->children.push_back((yyvsp[-2]));

	(yyvsp[-1])= new node;	
	(yyvsp[-1])->content = ";";
	(yyval)->children.push_back((yyvsp[-1]));

	(yyvsp[0])= new node;	
	(yyvsp[0])->content = "END";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 540 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="Stmt list";
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));

}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 548 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	temp= new node;
	temp->content = "Epsilon";
	(yyval)->content = "Stmt List";
	(yyval)->children.push_back(temp);
}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 559 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-4])= new node;
	(yyvsp[-4])->content= "ASSIGN";
	(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "Equals";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 575 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing assign at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-4])= new node;
	(yyvsp[-4])->content= "ASSIGN";
	(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "Equals";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 592 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing semicolon at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-4])= new node;
	(yyvsp[-4])->content= "ASSIGN";
	(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "Equals";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 610 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "SCAN";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));


}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 624 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing semicolon at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "SCAN";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 638 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "PRINT";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));

}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 651 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing semicolon at line "<<yylineno<<endl;
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "PRINT";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "Semicolon";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 664 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-4])= new node;
	(yyvsp[-4])->content= "WHILE";
	(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "BEG";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "END";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 680 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
	(yyval)->content="Stmt";
	(yyvsp[-4])= new node;
	(yyvsp[-4])->content= "IF";
	(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
	(yyvsp[-2])->content= "BEG";
	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
	(yyvsp[0])->content= "END";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 697 "file2.yacc" /* yacc.c:1646  */
    {

	(yyval)=new node;
	(yyval)->content="E_or_C";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 704 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node; 
		(yyval)->content="E_or_C";
	(yyvsp[-4])= new node;
		(yyvsp[-4])->content= "CALL";
		(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
		(yyvsp[-2])->content= "(";
		(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
		(yyvsp[0])->content= ")";
		(yyval)->children.push_back((yyvsp[0]));

}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 721 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing ( at line "<<yylineno<<endl;
	(yyval)=new node; 
		(yyval)->content="E_or_C";
	(yyvsp[-4])= new node;
		(yyvsp[-4])->content= "CALL";
		(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
		(yyvsp[-2])->content= "(";
		(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
		(yyvsp[0])->content= ")";
		(yyval)->children.push_back((yyvsp[0]));}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 737 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing ) at line "<<yylineno<<endl;
	(yyval)=new node; 
		(yyval)->content="E_or_C";
	(yyvsp[-4])= new node;
		(yyvsp[-4])->content= "CALL";
		(yyval)->children.push_back((yyvsp[-4]));
	(yyval)->children.push_back((yyvsp[-3]));
	(yyvsp[-2])= new node;
		(yyvsp[-2])->content= "(";
		(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyvsp[0])= new node;
		(yyvsp[0])->content= ")";
		(yyval)->children.push_back((yyvsp[0]));
}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 755 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)= new node;
	(yyval)->content= "PARAM1";
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 762 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="PARAM1"; 
	temp = new node;
	temp->content = "Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 771 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "PP1";

	(yyvsp[-1]) = new node;
	(yyvsp[-1])->content = ",";

	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 782 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "PP1";

	temp = new node;
	temp->content = "Epsilon";

	(yyval)->children.push_back(temp);
}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 794 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V";

	(yyval)->children.push_back((yyvsp[0]));
}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 802 "file2.yacc" /* yacc.c:1646  */
    {
 	(yyval) = new node;
	(yyval)->content = "V";

	(yyval)->children.push_back((yyvsp[0]));
 }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 810 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V1";

	(yyval)->children.push_back((yyvsp[0]));
}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 817 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V1";

	(yyval)->children.push_back((yyvsp[0]));
}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 824 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V1";

	(yyvsp[0]) = new node;
	(yyvsp[0])->content = "SPACE";

	(yyval)->children.push_back((yyvsp[0]));
}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 834 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V1";

	(yyvsp[0]) = new node;
	(yyvsp[0])->content = "ENDL";

	(yyval)->children.push_back((yyvsp[0]));
}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 845 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V1";

	(yyvsp[0]) = new node;
	(yyvsp[0])->content = "NUM";

	(yyval)->children.push_back((yyvsp[0]));
}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 855 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "V";

	(yyvsp[-1]) = new node;
	(yyvsp[-1])->content = "~";
	(yyvsp[0]) = new node;
	(yyvsp[0])->content = "NUM";

	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 869 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="id";
	(yyvsp[0])=new node;
	(yyvsp[0])->content="ID";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 878 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="id";
	(yyvsp[-1])=new node;
	(yyvsp[-1])->content="~";
	(yyvsp[0])=new node;
	(yyvsp[0])->content="ID";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 891 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="expr";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 899 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="E1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="|";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 909 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="E1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 919 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="O";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 927 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="O1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="&";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 937 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="O1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 947 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="A";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 955 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="A1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="%";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 965 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="A1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 975 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="M";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 983 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="M1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content=">";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));

}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 994 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="M1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1004 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="G";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1012 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="G1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="<";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1022 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="G1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1032 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="L";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1040 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="L1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="+";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1050 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="L1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="-";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1060 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="L1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1070 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="AS";
	(yyval)->children.push_back((yyvsp[-1]));	
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1078 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="AS1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="*";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1088 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="AS1";
	(yyvsp[-2])=new node;
	(yyvsp[-2])->content="/";
	(yyval)->children.push_back((yyvsp[-2]));	
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1098 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval)=new node;
	(yyval)->content="AS1";
	temp=new node;
	temp->content="Epsilon";
	(yyval)->children.push_back(temp);
}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1108 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "MD";
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1114 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "MD";
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1120 "file2.yacc" /* yacc.c:1646  */
    {
	(yyval) = new node;
	(yyval)->content = "MD";

	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "(";
	(yyvsp[0]) = new node;
	(yyvsp[0])->content = ")";

	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1134 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing ) at line "<<yylineno<<endl;
	(yyval) = new node;
	(yyval)->content = "MD";

	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "(";
	(yyvsp[0]) = new node;
	(yyvsp[0])->content = ")";

	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));	
}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1149 "file2.yacc" /* yacc.c:1646  */
    {
	cout<<"missing ( at line "<<yylineno<<endl;
	(yyval) = new node;
	(yyval)->content = "MD";

	(yyvsp[-2]) = new node;
	(yyvsp[-2])->content = "(";
	(yyvsp[0]) = new node;
	(yyvsp[0])->content = ")";

	(yyval)->children.push_back((yyvsp[-2]));
	(yyval)->children.push_back((yyvsp[-1]));
	(yyval)->children.push_back((yyvsp[0]));
}
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2780 "y.tab.c" /* yacc.c:1646  */
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
#line 1166 "file2.yacc" /* yacc.c:1906  */

void yyerror(char *s) {

	extern int yylineno;
	fprintf(stderr, "At line %d %s\n", yylineno , s);
 
 fprintf(stderr, "%s\n", s);

}

int main(void) {
 yyparse();
 cout<<"DONE"<<endl; 

 print_parse_tree(root);
 return 0;
}
