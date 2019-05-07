
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
#line 1 "csmall-parser.y"

#include <bits/stdc++.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<iostream>
#include <vector>
using namespace std;
ofstream codeProblemsFile,AssemblyFile,symbolTableFile;

set<string>unusedVariables;
set<string>uniqueProblems;
stack<int>unconditionalLabels,conditionalLabels;
extern int yylineno;
int curRegID = 0,scopeID = 0,labelID=0;
bool unsuccessfulCompilation=0;
enum dataType {
  UNDEFINED,
  BOOL_TYPE,
  INT_TYPE,
  FLOAT_TYPE,
  CHAR_TYPE
};
struct entry{
	bool isConst;
	dataType type;
	string stringValue;
	bool isInitialized;
	bool isUsed;
	int line;

	entry(bool isConst = 0, dataType type = UNDEFINED, string vall = "", bool isInitialized = 0, bool isUsed = 0, int line = 0) 
		: isConst(isConst), type(type), stringValue(vall), isInitialized(isInitialized), isUsed(isUsed), line(line) {}


  void display(char* variableName){
    string dt;
    switch(type){
      case BOOL_TYPE:
      dt="Boolean";
      break;
      case INT_TYPE:
      dt="Integer";
      break;
      case FLOAT_TYPE:
      dt="Float";
      break;
      case CHAR_TYPE:
      dt="Character";
      default:
      break;
    }
     symbolTableFile<<variableName<<"\t\t\t"<<isConst<<"\t\t"<< dt<<"\t\t\t"<<stringValue<<"\t\t\t"<<isInitialized<<"\t\t\t"<<isUsed<<"\t\t"<<line<<"\n";
  }


};

vector<map<string,entry>>symbolTable(1);
 const string _ADD = "ADD";
 const string _SUB = "SUB";
 const string _MUL = "MUL";
 const string _DIV = "DIV";
 const string _AND = "AND";
 const string _OR  = "OR";
 const string _GTE = "GTE";
 const string _LTE = "LTE";
 const string _GTN = "GTN";
 const string _LTN = "LTN";
 const string _EQU = "EQU";
 const string _NEQ = "NEQ";
 const string _NEG = "NEG";
 const string _NOT = "NOT";
 const string _MOV = "MOV";


 map<string,dataType>variableType;



/* prototypes */
int yylex(void);
void yyerror(char *s);
void declarationHandler(char* variableName,bool isconst,dataType datatype,string value,bool isinitialized,bool isused,string operationtype,int linenumber);
void definedBefore(char* variableName);
int findVariable(char * variableName);
int getChosenType(int t1, int t2);
void variableAssignment(char* variableName,char* assignedValue);
void beforeExit();
void printConstError(char*variableName);
void printNotdefinedError(char*variableName);
void printUninitializedWarning(char* variableName);
void printIncompatibleTypeWarning();
void printfRedeclarationError(char* variableName);
void printTripleOperandOperation(string operationtype,string source,char* destination);
void printQuadOperandOperation(string operationtype,string source1,string source2,char* destination);
template <typename T>
string toString(T x);
void symboTableFileInit();
void printLabel(int labelNumber);
void printJumpTrue(int labelNumber);
void printJumpFalse(int labelNumber);
void printJump(int labelNumber);



/* Line 189 of yacc.c  */
#line 182 "csmall-parser.tab.c"

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
     INTEGER = 258,
     DECIMAL = 259,
     CHARACTER = 260,
     VAR = 261,
     CONST = 262,
     INT = 263,
     FLOAT = 264,
     CHAR = 265,
     BOOL = 266,
     ENDOFFILE = 267,
     GE = 268,
     LE = 269,
     GT = 270,
     LT = 271,
     EQ = 272,
     NE = 273,
     NOT = 274,
     AND = 275,
     OR = 276,
     WHILE = 277,
     FOR = 278,
     DO = 279,
     IF = 280,
     ELSE = 281,
     SWITCH = 282,
     CASE = 283,
     DEFAULT = 284,
     BREAK = 285,
     BOOL_TRUE = 286,
     BOOL_FALSE = 287,
     UMINUS = 288,
     IFX = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 109 "csmall-parser.y"

  char* val; 
      		
	char* name;

  struct info1{
    int type;
    char val[100];
  }info;
		




/* Line 214 of yacc.c  */
#line 267 "csmall-parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 279 "csmall-parser.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    37,    35,     2,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    39,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    11,    14,    16,    18,
      21,    24,    27,    29,    31,    35,    38,    40,    42,    44,
      50,    56,    62,    68,    73,    78,    83,    88,    91,    94,
      97,   100,   104,   106,   108,   110,   112,   114,   116,   119,
     123,   127,   131,   135,   139,   143,   147,   151,   155,   159,
     162,   166,   170,   174,   180,   183,   189,   191,   194,   197,
     200,   204,   206,   211,   213,   216,   218,   223,   225,   229,
     232,   234,   243,   251,   253,   256,   258,   259,   272,   274,
     280
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    48,    50,    -1,    12,    -1,
      -1,    49,    50,    -1,    50,    -1,    39,    -1,    53,    39,
      -1,    54,    39,    -1,    55,    39,    -1,    56,    -1,    64,
      -1,    51,    49,    52,    -1,    51,    52,    -1,    70,    -1,
      40,    -1,    41,    -1,     7,     8,     6,    42,    55,    -1,
       7,     9,     6,    42,    55,    -1,     7,    10,     6,    42,
      55,    -1,     7,    11,     6,    42,    55,    -1,     8,     6,
      42,    55,    -1,     9,     6,    42,    55,    -1,    10,     6,
      42,    55,    -1,    11,     6,    42,    55,    -1,     8,     6,
      -1,     9,     6,    -1,    10,     6,    -1,    11,     6,    -1,
       6,    42,    55,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,    31,    -1,    32,    -1,    36,    55,    -1,    55,
      35,    55,    -1,    55,    36,    55,    -1,    55,    37,    55,
      -1,    55,    38,    55,    -1,    55,    16,    55,    -1,    55,
      15,    55,    -1,    55,    13,    55,    -1,    55,    14,    55,
      -1,    55,    18,    55,    -1,    55,    17,    55,    -1,    19,
      55,    -1,    55,    20,    55,    -1,    55,    21,    55,    -1,
      43,    55,    44,    -1,    57,    58,    59,    60,    50,    -1,
      62,    50,    -1,    63,    50,    22,    55,    39,    -1,    23,
      -1,    43,    54,    -1,    43,    53,    -1,    39,    55,    -1,
      39,    54,    44,    -1,    22,    -1,    61,    43,    55,    44,
      -1,    24,    -1,    65,    50,    -1,    67,    -1,    66,    43,
      55,    44,    -1,    25,    -1,    65,    50,    68,    -1,    69,
      50,    -1,    26,    -1,    71,    43,    55,    44,    51,    72,
      76,    52,    -1,    71,    43,    55,    44,    51,    72,    52,
      -1,    27,    -1,    72,    73,    -1,    73,    -1,    -1,    75,
       3,    45,    49,    30,    39,    74,    75,     3,    45,    30,
      39,    -1,    28,    -1,    29,    45,    49,    30,    39,    -1,
      29,    45,    30,    39,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   154,   155,   156,   160,   161,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   177,   181,   185,
     186,   187,   188,   191,   192,   193,   194,   197,   198,   199,
     200,   204,   209,   210,   211,   212,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   239,   246,   247,   252,   255,   256,   260,
     264,   268,   271,   275,   279,   280,   283,   286,   289,   294,
     300,   311,   312,   316,   320,   321,   325,   325,   330,   334,
     335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DECIMAL", "CHARACTER", "VAR",
  "CONST", "INT", "FLOAT", "CHAR", "BOOL", "ENDOFFILE", "GE", "LE", "GT",
  "LT", "EQ", "NE", "NOT", "AND", "OR", "WHILE", "FOR", "DO", "IF", "ELSE",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "BOOL_TRUE", "BOOL_FALSE",
  "UMINUS", "IFX", "'+'", "'-'", "'*'", "'/'", "';'", "'{'", "'}'", "'='",
  "'('", "')'", "':'", "$accept", "program", "function", "collection_stmt",
  "stmt", "open_brace", "closed_brace", "declaration", "assignment",
  "expr", "loop", "forKeyword", "for_leftPart", "for_condition",
  "for_rightPart", "whileKeyword", "while", "doKeyword", "condition",
  "if_statement", "ifKeyword", "ifelse_statement", "else_block",
  "elseKeyword", "switch_statement", "switchKeyword", "case_list",
  "case_stmt", "$@1", "caseKeyword", "default_stmt", 0
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
     285,   286,   287,   288,   289,    43,    45,    42,    47,    59,
     123,   125,    61,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    57,    58,    58,    59,
      60,    61,    62,    63,    64,    64,    65,    66,    67,    68,
      69,    70,    70,    71,    72,    72,    74,    73,    75,    76,
      76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     2,     1,     1,     2,
       2,     2,     1,     1,     3,     2,     1,     1,     1,     5,
       5,     5,     5,     4,     4,     4,     4,     2,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     5,     2,     5,     1,     2,     2,     2,
       3,     1,     4,     1,     2,     1,     4,     1,     3,     2,
       1,     8,     7,     1,     2,     1,     0,    12,     1,     5,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     4,     0,     2,     1,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    61,    56,    63,    67,    73,
      36,    37,     0,     8,    17,     0,     3,     0,     0,     0,
       0,    12,     0,     0,     0,     0,    13,     0,     0,    65,
      16,     0,     0,     0,     0,     0,     0,    27,    28,    29,
      30,    35,    49,    38,     0,    18,     0,     7,    15,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,    54,     0,    64,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     6,    14,    45,    46,    44,    43,    48,    47,
      50,    51,    39,    40,    41,    42,     0,    58,    57,     0,
       0,     0,     0,    70,    68,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    59,     0,     0,    62,
       0,    69,    66,     0,    19,    20,    21,    22,     0,    53,
      55,     0,    60,    78,     0,    75,     0,     0,    72,    74,
       0,     0,     0,    71,     0,     0,     0,     0,    80,     0,
       0,    79,    76,     0,     0,     0,     0,     0,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    56,    57,    27,    58,    28,    29,    30,
      31,    32,    75,   110,   128,    33,    34,    35,    36,    37,
      38,    39,   114,   115,    40,    41,   144,   145,   163,   146,
     150
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -128
static const yytype_int16 yypact[] =
{
       6,  -128,    19,   288,  -128,  -128,  -128,  -128,   -14,    13,
      23,    24,    27,    29,     7,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,     7,  -128,  -128,     7,  -128,   124,     1,     2,
      85,  -128,    -7,    -1,   288,   288,  -128,   288,     8,  -128,
    -128,     9,     7,    48,    62,    63,    64,    30,    31,    32,
      35,  -128,  -128,   412,   319,  -128,   124,  -128,  -128,  -128,
    -128,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,  -128,    38,    39,     7,  -128,    57,    54,
       7,     7,   412,    44,    45,    46,    49,     7,     7,     7,
       7,  -128,  -128,  -128,   -30,   -30,   -30,   -30,   -30,   -30,
     438,   438,   -23,   -23,  -128,  -128,   -14,  -128,  -128,     7,
      42,   329,     7,  -128,  -128,   288,   361,   371,     7,     7,
       7,     7,   412,   412,   412,   412,   412,    84,   288,  -128,
     403,  -128,  -128,    52,   412,   412,   412,   412,    50,  -128,
    -128,    65,  -128,  -128,   -25,  -128,    93,    66,  -128,  -128,
      56,    72,   165,  -128,   288,    69,   206,   247,  -128,    70,
      71,  -128,  -128,    65,   115,    74,    96,    97,  -128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -128,  -128,  -128,  -127,    -3,     4,   -55,    67,   -72,    -5,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,    -6,  -128,   -24,
    -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      26,    93,   108,   143,   147,    69,    70,    71,    72,    52,
       5,     6,     7,    51,    71,    72,    55,    53,     1,     4,
      54,    43,    44,    45,    46,   156,    14,   157,    42,    47,
      48,    77,    78,    49,    79,    50,    74,    82,    20,    21,
      59,    60,    76,    22,   106,     9,    10,    11,    12,    13,
      25,    80,    81,    92,    83,   138,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    84,    85,
      86,   111,    87,    88,    89,   116,   117,    90,   109,   112,
     113,   127,   122,   123,   124,   125,   118,   119,   120,   148,
     106,   121,    24,   143,   142,   153,   151,    55,    61,    62,
      63,    64,    65,    66,   126,    67,    68,   130,   158,   161,
     162,   152,   131,   134,   135,   136,   137,   154,   165,   166,
      69,    70,    71,    72,    73,   139,   167,     5,     6,     7,
       8,     9,    10,    11,    12,    13,   168,   141,   149,   164,
       0,   107,     0,    14,     0,     0,    15,    16,    17,    18,
       0,    19,     0,    92,    92,    20,    21,     0,     0,     0,
      22,     0,     0,    23,    24,    55,     0,    25,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,    17,
      18,     0,    19,     0,     0,   155,    20,    21,     0,     0,
       0,    22,     0,     0,    23,    24,     0,     0,    25,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
      17,    18,     0,    19,     0,     0,   159,    20,    21,     0,
       0,     0,    22,     0,     0,    23,    24,     0,     0,    25,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,    17,    18,     0,    19,     0,     0,   160,    20,    21,
       0,     0,     0,    22,     0,     0,    23,    24,     0,     0,
      25,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      15,    16,    17,    18,     0,    19,     0,     0,     0,    20,
      21,     0,     0,     0,    22,     0,     0,    23,    24,     0,
       0,    25,    61,    62,    63,    64,    65,    66,     0,    67,
      68,     0,    61,    62,    63,    64,    65,    66,     0,    67,
      68,     0,     0,     0,    69,    70,    71,    72,     0,     0,
       0,     0,     0,    91,    69,    70,    71,    72,     0,     0,
       0,     0,     0,   129,    61,    62,    63,    64,    65,    66,
       0,    67,    68,     0,    61,    62,    63,    64,    65,    66,
       0,    67,    68,     0,     0,     0,    69,    70,    71,    72,
       0,     0,     0,     0,     0,   132,    69,    70,    71,    72,
       0,     0,     0,     0,     0,   133,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    61,    62,    63,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,    69,    70,
      71,    72,   140,     0,     0,     0,     0,    69,    70,    71,
      72,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72
};

static const yytype_int16 yycheck[] =
{
       3,    56,    74,    28,    29,    35,    36,    37,    38,    14,
       3,     4,     5,     6,    37,    38,    41,    22,    12,     0,
      25,     8,     9,    10,    11,   152,    19,   154,    42,     6,
       6,    34,    35,     6,    37,     6,    43,    42,    31,    32,
      39,    39,    43,    36,     6,     7,     8,     9,    10,    11,
      43,    43,    43,    56,     6,   127,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     6,     6,
       6,    76,    42,    42,    42,    80,    81,    42,    39,    22,
      26,    39,    87,    88,    89,    90,    42,    42,    42,   144,
       6,    42,    40,    28,    44,   150,     3,    41,    13,    14,
      15,    16,    17,    18,   109,    20,    21,   112,    39,    39,
      39,    45,   115,   118,   119,   120,   121,    45,     3,    45,
      35,    36,    37,    38,    39,   128,    30,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    39,   133,   144,   163,
      -1,    74,    -1,    19,    -1,    -1,    22,    23,    24,    25,
      -1,    27,    -1,   156,   157,    31,    32,    -1,    -1,    -1,
      36,    -1,    -1,    39,    40,    41,    -1,    43,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    36,    -1,    -1,    39,    40,    -1,    -1,    43,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    39,    40,    -1,    -1,    43,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    39,    40,    -1,    -1,
      43,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,    -1,
      -1,    43,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    -1,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    47,    48,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    19,    22,    23,    24,    25,    27,
      31,    32,    36,    39,    40,    43,    50,    51,    53,    54,
      55,    56,    57,    61,    62,    63,    64,    65,    66,    67,
      70,    71,    42,     8,     9,    10,    11,     6,     6,     6,
       6,     6,    55,    55,    55,    41,    49,    50,    52,    39,
      39,    13,    14,    15,    16,    17,    18,    20,    21,    35,
      36,    37,    38,    39,    43,    58,    43,    50,    50,    50,
      43,    43,    55,     6,     6,     6,     6,    42,    42,    42,
      42,    44,    50,    52,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     6,    53,    54,    39,
      59,    55,    22,    26,    68,    69,    55,    55,    42,    42,
      42,    42,    55,    55,    55,    55,    55,    39,    60,    44,
      55,    50,    44,    44,    55,    55,    55,    55,    54,    50,
      39,    51,    44,    28,    72,    73,    75,    29,    52,    73,
      76,     3,    45,    52,    45,    30,    49,    49,    39,    30,
      30,    39,    39,    74,    75,     3,    45,    30,    39
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
        case 2:

/* Line 1455 of yacc.c  */
#line 151 "csmall-parser.y"
    {beforeExit(); exit(0);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 154 "csmall-parser.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 155 "csmall-parser.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 160 "csmall-parser.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 161 "csmall-parser.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 165 "csmall-parser.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 166 "csmall-parser.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 167 "csmall-parser.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 168 "csmall-parser.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 169 "csmall-parser.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 170 "csmall-parser.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 171 "csmall-parser.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 173 "csmall-parser.y"
    {cout << "stmt : switch_statement" << endl;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 177 "csmall-parser.y"
    {++scopeID; map<string,entry>initMap; symbolTable.push_back(initMap);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 181 "csmall-parser.y"
    {symbolTable.pop_back(); --scopeID;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 185 "csmall-parser.y"
    {getChosenType(INT_TYPE,(yyvsp[(5) - (5)].info).type); variableType[(yyvsp[(3) - (5)].name)] = INT_TYPE; declarationHandler((yyvsp[(3) - (5)].name),1,INT_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 186 "csmall-parser.y"
    {getChosenType(FLOAT_TYPE,(yyvsp[(5) - (5)].info).type); variableType[(yyvsp[(3) - (5)].name)] = FLOAT_TYPE; declarationHandler((yyvsp[(3) - (5)].name),1,FLOAT_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 187 "csmall-parser.y"
    {getChosenType(CHAR_TYPE,(yyvsp[(5) - (5)].info).type); variableType[(yyvsp[(3) - (5)].name)] = CHAR_TYPE; declarationHandler((yyvsp[(3) - (5)].name),1,CHAR_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 188 "csmall-parser.y"
    {getChosenType(BOOL_TYPE,(yyvsp[(5) - (5)].info).type); variableType[(yyvsp[(3) - (5)].name)] = BOOL_TYPE; declarationHandler((yyvsp[(3) - (5)].name),1,BOOL_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 191 "csmall-parser.y"
    {getChosenType(INT_TYPE,(yyvsp[(4) - (4)].info).type); variableType[(yyvsp[(2) - (4)].name)] = INT_TYPE; declarationHandler((yyvsp[(2) - (4)].name),0,INT_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 192 "csmall-parser.y"
    {getChosenType(FLOAT_TYPE,(yyvsp[(4) - (4)].info).type); variableType[(yyvsp[(2) - (4)].name)] = FLOAT_TYPE; declarationHandler((yyvsp[(2) - (4)].name),0,FLOAT_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 193 "csmall-parser.y"
    {getChosenType(CHAR_TYPE,(yyvsp[(4) - (4)].info).type); variableType[(yyvsp[(2) - (4)].name)] = CHAR_TYPE; declarationHandler((yyvsp[(2) - (4)].name),0,CHAR_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 194 "csmall-parser.y"
    {getChosenType(BOOL_TYPE,(yyvsp[(4) - (4)].info).type); variableType[(yyvsp[(2) - (4)].name)] = BOOL_TYPE; declarationHandler((yyvsp[(2) - (4)].name),0,BOOL_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 197 "csmall-parser.y"
    {variableType[(yyvsp[(2) - (2)].name)] = INT_TYPE; declarationHandler((yyvsp[(2) - (2)].name),0,INT_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 198 "csmall-parser.y"
    {variableType[(yyvsp[(2) - (2)].name)] = FLOAT_TYPE; declarationHandler((yyvsp[(2) - (2)].name),0,FLOAT_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 199 "csmall-parser.y"
    {variableType[(yyvsp[(2) - (2)].name)] = CHAR_TYPE; declarationHandler((yyvsp[(2) - (2)].name),0,CHAR_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 200 "csmall-parser.y"
    {variableType[(yyvsp[(2) - (2)].name)] = BOOL_TYPE; declarationHandler((yyvsp[(2) - (2)].name),0,BOOL_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 204 "csmall-parser.y"
    {getChosenType(variableType[(yyvsp[(1) - (3)].name)],(yyvsp[(3) - (3)].info).type); variableAssignment((yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].info).val);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 209 "csmall-parser.y"
    { (yyval.info).type = INT_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());  printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].val),(yyval.info).val);/* mov int register*/;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 210 "csmall-parser.y"
    { (yyval.info).type = FLOAT_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].val),(yyval.info).val);/* mov dec register*/;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 211 "csmall-parser.y"
    { (yyval.info).type = CHAR_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].val),(yyval.info).val);/*mov char register*/;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 212 "csmall-parser.y"
    {(yyval.info).type = variableType[(yyvsp[(1) - (1)].name)]; string registerNumber = "R" + toString<int>(curRegID++);
                    cout << "reduce VAR -> expr" << endl;
                    strcpy((yyval.info).val,registerNumber.c_str()); 
                    /*check if defined before*/
                     definedBefore((yyvsp[(1) - (1)].name));
                     printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].name),(yyval.info).val);/*mov var register*/
                  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 219 "csmall-parser.y"
    {(yyval.info).type = BOOL_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,"1",(yyval.info).val);/* mov 1 register*/;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 220 "csmall-parser.y"
    {(yyval.info).type = BOOL_TYPE; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,"0",(yyval.info).val);/* mov 0 register*/;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 221 "csmall-parser.y"
    {(yyval.info).type = (yyvsp[(2) - (2)].info).type; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_NEG,(yyvsp[(2) - (2)].info).val,(yyval.info).val);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 222 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type);  string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_ADD,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*add source1 source2 destination*/;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 223 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_SUB,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*sub source1 source2 destination*/;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 224 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_MUL,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*mul source1 source2 destination*/;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 225 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_DIV,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*div source1 source2 destination*/;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 226 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_LTN,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*lt source1 source2 destination*/;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 227 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_GTN,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*gt source1 source2 destination*/;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 228 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_GTE,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*ge source1 source2 destination*/;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 229 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_LTE,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*le source1 source2 destination*/;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 230 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_NEQ,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*ne source1 source2 destination*/;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 231 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_EQU,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*eq source1 source2 destination*/;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 232 "csmall-parser.y"
    { (yyval.info).type = (yyvsp[(2) - (2)].info).type; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_NOT,(yyvsp[(2) - (2)].info).val,(yyval.info).val); /*not source destination*/;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 233 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_AND,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*and source1 source2 destination*/;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 234 "csmall-parser.y"
    { (yyval.info).type = getChosenType((yyvsp[(1) - (3)].info).type,(yyvsp[(3) - (3)].info).type); string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_OR,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*or source1 source2 destination*/;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 235 "csmall-parser.y"
    { (yyval.info).type = (yyvsp[(2) - (3)].info).type; string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,(yyvsp[(2) - (3)].info).val,(yyval.info).val);/* mov register register*/;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 239 "csmall-parser.y"
    {
                                                            printJump(unconditionalLabels.top()); 
                                                            unconditionalLabels.pop();                                                                                           
                                                            printLabel(conditionalLabels.top());
                                                            conditionalLabels.pop();
                                                            symbolTable[scopeID--].clear();                                      
                                                            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 246 "csmall-parser.y"
    {printJump(unconditionalLabels.top()); unconditionalLabels.pop(); printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 247 "csmall-parser.y"
    {printJumpTrue(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 252 "csmall-parser.y"
    {  map<string,entry>temp; symbolTable.push_back(temp); ++scopeID;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 255 "csmall-parser.y"
    {printLabel(++labelID); unconditionalLabels.push(labelID);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 256 "csmall-parser.y"
    {printLabel(++labelID); unconditionalLabels.push(labelID);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 260 "csmall-parser.y"
    {printJumpFalse(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 264 "csmall-parser.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 268 "csmall-parser.y"
    {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; printLabel(++labelID); unconditionalLabels.push(labelID);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 271 "csmall-parser.y"
    {printJumpFalse(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 275 "csmall-parser.y"
    {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; printLabel(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 279 "csmall-parser.y"
    {cout << "condition : if_statement" << endl; printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 280 "csmall-parser.y"
    {cout << "condition : ifelse_statement" << endl; printLabel(unconditionalLabels.top()); unconditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 283 "csmall-parser.y"
    {cout << "if_statement" << endl; printJumpFalse(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 286 "csmall-parser.y"
    {cout << "ifkeyword" << endl;map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 289 "csmall-parser.y"
    {
                                                    cout << "ifelse_statement" << endl;
                                                    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 294 "csmall-parser.y"
    {
                                                    cout << "else_block" << endl;                                                    
                                                    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 300 "csmall-parser.y"
    {
                                                    cout << "else_keyword" << endl;
                                                    printJump(++labelID);
                                                    unconditionalLabels.push(labelID);
                                                    printLabel(conditionalLabels.top()); conditionalLabels.pop();
                                                    map<string,entry>temp; symbolTable.push_back(temp); ++scopeID;

                                                    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 311 "csmall-parser.y"
    {cout << "switch_statement" << endl;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 312 "csmall-parser.y"
    {cout << "switch_statement" << endl;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 316 "csmall-parser.y"
    {cout << "switchKeyword" << endl;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 320 "csmall-parser.y"
    {cout << "case_list" << endl;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 321 "csmall-parser.y"
    {cout << "case_list" << endl;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 325 "csmall-parser.y"
    {cout << "case_stmt" << endl;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 326 "csmall-parser.y"
    {cout << "case_stmt" << endl;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 330 "csmall-parser.y"
    {cout << "caseKeyword" << endl;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 334 "csmall-parser.y"
    {cout << "default_stmt" << endl;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 335 "csmall-parser.y"
    {cout << "default_stmt" << endl;;}
    break;



/* Line 1455 of yacc.c  */
#line 2243 "csmall-parser.tab.c"
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
#line 341 "csmall-parser.y"


void yyerror(char *s) {
  printf("%s at line: %d\n", s,yylineno);
}

void declarationHandler(char* variableName,bool isconst,dataType datatype,string value,bool isinitialized,bool isused,string operationtype,int linenumber){
      
        //check if re-declaration
        if(findVariable(variableName) != -1) {
             printfRedeclarationError(variableName);
            unsuccessfulCompilation=1;          
        }
        else{
          printTripleOperandOperation(operationtype,value,variableName);
           symbolTable[scopeID][variableName]= entry(isconst,datatype,value,isinitialized,isused,linenumber);
           unusedVariables.insert(variableName); 
           entry& e =symbolTable[scopeID][variableName];
           e.display(variableName);  
        }
        return;
}

void definedBefore(char* variableName){
      cout << "definedBefore is called " << yylineno << endl;
      //check if defined before or not
     int idx=findVariable(variableName);
     
     if(idx==-1){
           printNotdefinedError(variableName);
           unsuccessfulCompilation=1;
           cout << "Not found" << endl;
     }
     else {
           entry& e = symbolTable[idx][variableName];
            if(e.isInitialized==0){
              printUninitializedWarning(variableName);
            }
            e.isUsed=1;
            cout << "Varable Name = " << variableName << endl;
            for(auto i : unusedVariables) {
              cout << i << endl;
            }
        
            unusedVariables.erase(variableName);
            e.display(variableName);
            cout << "-------------------------------" << endl;
            for(auto i : unusedVariables) {
              cout << i << endl;
            }
     }

    return;


}
int findVariable(char * variableName){

 
    int currentScopeID = scopeID;
    
     for(int i=currentScopeID;i>=0;--i){
       
       if(symbolTable[i].find(variableName)!=symbolTable[i].end()){
         //l2eto
         
        return i;
       }
     }
     return -1;
}

int getChosenType(int t1, int t2) {

    if(t1 != t2){
        printIncompatibleTypeWarning();
    }
    if(t1 == FLOAT_TYPE || t2 == FLOAT_TYPE) {
      return FLOAT_TYPE;
    }else if(t1 == INT_TYPE || t2 == INT_TYPE) {
      return INT_TYPE;
    }else if(t1 == CHAR_TYPE || t2 == CHAR_TYPE){
      return CHAR_TYPE;
    }else {
      return t1;
    }

}



void variableAssignment(char* variableName,char* assignedValue){
     

 int idx=findVariable(variableName);
   if(idx==-1){
    printNotdefinedError(variableName);
    unsuccessfulCompilation=1;
   }
   else {
     entry& e= symbolTable[idx][variableName];
     if(e.isConst){

        printConstError(variableName);
        unsuccessfulCompilation=1;
     }
     else {
       e.isInitialized=1; 
        printTripleOperandOperation(_MOV,assignedValue,variableName);
      
        e.display(variableName);
     }
   }
  return;
}




















void printJump(int labelNumber){
  AssemblyFile<<"JMP \tLabel"<<labelNumber<<"\n";
}

void printJumpFalse(int labelNumber){
  AssemblyFile<<"JMF \tLabel"<<labelNumber<<"\n";
}
void printJumpTrue(int labelNumber){
  AssemblyFile<<"JMT \tLabel"<<labelNumber<<"\n";
}

void printLabel(int labelNumber){
  AssemblyFile<<"Label"<<labelNumber<<":\n";
}

void beforeExit() {

    for (auto i : unusedVariables) {

        codeProblemsFile << "Warning: Variable " << i << " is not used.\n";
  

    }

    for (auto i : uniqueProblems) {
        codeProblemsFile << i;
    }

    if(!unsuccessfulCompilation){
      codeProblemsFile << "Compiled Successfully." << endl;
    }else {
      codeProblemsFile << "Compilation Error." << endl;
    }

}

void printConstError(char*variableName){
   string s="";
   s+=variableName;
   s+=" is constant and cannot be changed at line ";
   s+=toString<int>(yylineno);
   codeProblemsFile << s << endl;
  return;
}
void printNotdefinedError(char*variableName){
         string s="";
          s+= variableName; 
          s+= "  is not defined ";
          s+="at line ";
          s+=toString<int>(yylineno)+"\n";
          codeProblemsFile<<s;
           return;
          
}
void printUninitializedWarning(char* variableName){
        string s = "WARNING: variable ";
        s += variableName;
        s += " is not initialized ";
        s += "at line ";
        s += toString<int>(yylineno);
        s += "\n";
        codeProblemsFile << s;
        return;
}

void printIncompatibleTypeWarning() {

  string s = "Warning: Incompatible types at line: ";
  s += toString<int>(yylineno);
  s += "\n";
  uniqueProblems.insert(s);
  return;

}

void printfRedeclarationError(char* variableName){
    string redeclarationError="";
    redeclarationError+="multible definintions of variable: ";
    redeclarationError+=variableName;
    redeclarationError+=" at line: ";
    redeclarationError+=toString<int>(yylineno);
    redeclarationError+="\n";
    codeProblemsFile<<redeclarationError;
    return;
}


 void printTripleOperandOperation(string operationtype,string source,char* destination){


AssemblyFile<<operationtype<<" \t"<<source<<" \t"<<destination<<"\n";
return;
}
void printQuadOperandOperation(string operationtype,string source1,string source2,char* destination){

 AssemblyFile<<operationtype<<" \t"<<source1<<" \t"<<source2<<" \t"<<destination<<"\n";
 return;
}
template <typename T>
string toString(T x){
  stringstream ss;
  ss<<x;
  string ret;
  ss>>ret;
  return ret;
}
void symboTableFileInit(){
  symbolTableFile<<"Variable Name\t\tIsConst\t\tDatatype\t\tVariable Value\t\tIsInitialized\t\tIsUsed\t\tLine Number\n";
}

int main(void) {
  AssemblyFile.open("ASM.txt");
  codeProblemsFile.open("CodeProblems.txt");
  symbolTableFile.open("SymbolTable.txt");
  symboTableFileInit();
  yyparse();
  return 0;
}
