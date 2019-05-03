
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

map<char*,bool>unusedVariables;
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
     symbolTableFile<<variableName<<"\t\t"<<isConst<<"\t\t"<< dt<<"\t\t"<<stringValue<<"\t\t"<<isInitialized<<"\t\t"<<isUsed<<"\t\t"<<line<<"\n";
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
 const string _NOT = "NOT";
 const string _MOV = "MOV";



/* prototypes */
int yylex(void);
void yyerror(char *s);
void declarationHandler(char* variableName,bool isconst,dataType datatype,string value,bool isinitialized,bool isused,string operationtype,int linenumber);
void definedBefore(char* variableName);
int findVariable(char * variableName);
void variableAssignment(char* variableName,char* assignedValue);
void printConstError(char*variableName);
void printNotdefinedError(char*variableName);
void printUninitializedWarning(char* variableName);
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
#line 174 "csmall-parser.tab.c"

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
     BOOL_TRUE = 282,
     BOOL_FALSE = 283,
     IFX = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 101 "csmall-parser.y"

  char* val; 
      		
	char* name;

  struct info1{
    int type;
    char val[100];
  }info;
		




/* Line 214 of yacc.c  */
#line 254 "csmall-parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 266 "csmall-parser.tab.c"

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
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    31,    29,     2,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    11,    14,    16,    18,
      21,    24,    27,    29,    31,    35,    38,    40,    42,    48,
      54,    60,    66,    71,    76,    81,    86,    89,    92,    95,
      98,   102,   104,   106,   108,   110,   112,   114,   118,   122,
     126,   130,   134,   138,   142,   146,   150,   154,   157,   161,
     165,   169,   175,   178,   184,   186,   189,   192,   195,   199,
     201,   206,   208,   211,   213,   218,   220
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    44,    -1,    12,    -1,
      -1,    43,    44,    -1,    44,    -1,    34,    -1,    47,    34,
      -1,    48,    34,    -1,    49,    34,    -1,    50,    -1,    58,
      -1,    45,    43,    46,    -1,    45,    46,    -1,    35,    -1,
      36,    -1,     7,     8,     6,    37,    49,    -1,     7,     9,
       6,    37,    49,    -1,     7,    10,     6,    37,    49,    -1,
       7,    11,     6,    37,    49,    -1,     8,     6,    37,    49,
      -1,     9,     6,    37,    49,    -1,    10,     6,    37,    49,
      -1,    11,     6,    37,    49,    -1,     8,     6,    -1,     9,
       6,    -1,    10,     6,    -1,    11,     6,    -1,     6,    37,
      49,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
      27,    -1,    28,    -1,    49,    29,    49,    -1,    49,    30,
      49,    -1,    49,    31,    49,    -1,    49,    32,    49,    -1,
      49,    16,    49,    -1,    49,    15,    49,    -1,    49,    13,
      49,    -1,    49,    14,    49,    -1,    49,    18,    49,    -1,
      49,    17,    49,    -1,    19,    49,    -1,    49,    20,    49,
      -1,    49,    21,    49,    -1,    38,    49,    39,    -1,    51,
      52,    53,    54,    44,    -1,    56,    44,    -1,    57,    44,
      22,    49,    34,    -1,    23,    -1,    38,    48,    -1,    38,
      47,    -1,    34,    49,    -1,    34,    48,    39,    -1,    22,
      -1,    55,    38,    49,    39,    -1,    24,    -1,    59,    44,
      -1,    61,    -1,    60,    38,    49,    39,    -1,    25,    -1,
      59,    44,    26,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   145,   146,   147,   151,   152,   156,   157,
     158,   159,   160,   161,   162,   163,   167,   171,   175,   176,
     177,   178,   181,   182,   183,   184,   187,   188,   189,   190,
     194,   199,   200,   201,   202,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   227,   238,   239,   244,   248,   249,   253,   257,   261,
     264,   268,   272,   273,   277,   280,   283
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
  "BOOL_TRUE", "BOOL_FALSE", "'+'", "'-'", "'*'", "'/'", "IFX", "';'",
  "'{'", "'}'", "'='", "'('", "')'", "$accept", "program", "function",
  "collection_stmt", "stmt", "open_brace", "closed_brace", "declaration",
  "assignment", "expr", "loop", "forKeyword", "for_leftPart",
  "for_condition", "for_rightPart", "whileKeyword", "while", "doKeyword",
  "condition", "if_statement", "ifKeyword", "ifelse_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    43,
      45,    42,    47,   284,    59,   123,   125,    61,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    43,    43,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    51,    52,    52,    53,    54,    55,
      56,    57,    58,    58,    59,    60,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     2,     1,     1,     2,
       2,     2,     1,     1,     3,     2,     1,     1,     5,     5,
       5,     5,     4,     4,     4,     4,     2,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     5,     2,     5,     1,     2,     2,     2,     3,     1,
       4,     1,     2,     1,     4,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     4,     0,     2,     1,    31,    32,    33,    34,     0,
       0,     0,     0,     0,     0,    59,    54,    61,    65,    35,
      36,     8,    16,     0,     3,     0,     0,     0,     0,    12,
       0,     0,     0,     0,    13,     0,     0,    63,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    34,    47,     0,
      17,     0,     7,    15,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,    52,     0,    62,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     6,    14,    43,    44,
      42,    41,    46,    45,    48,    49,    37,    38,    39,    40,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    57,     0,     0,
      60,     0,    66,    64,    18,    19,    20,    21,     0,    51,
      53,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    51,    24,    25,    53,    26,    27,    28,
      29,    30,    70,   104,   119,    31,    32,    33,    34,    35,
      36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -64
static const yytype_int16 yypact[] =
{
      -1,   -64,    10,   133,   -64,   -64,   -64,   -64,   -23,    19,
      31,    32,    33,    34,    -2,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,    -2,   -64,    97,   -18,     7,   219,   -64,
      16,    18,   133,   133,   -64,   133,    20,   -64,    -2,    53,
      54,    56,    57,    27,    28,    29,    35,   -64,   -64,   159,
     -64,    97,   -64,   -64,   -64,   -64,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,   -64,    12,
      37,    -2,   -64,    51,    48,    -2,   263,    38,    39,    40,
      41,    -2,    -2,    -2,    -2,   -64,   -64,   -64,     3,     3,
       3,     3,     3,     3,   272,   272,   -24,   -24,   -64,   -64,
     -23,   -64,   -64,    -2,    45,   179,    -2,   133,   199,    -2,
      -2,    -2,    -2,   263,   263,   263,   263,   263,    74,   133,
     -64,   241,   -64,   -64,   263,   263,   263,   263,    42,   -64,
     -64,   -64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   -64,   -20,   -64,    43,    13,   -63,   -14,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,     5,     6,     7,    47,    52,   102,    66,    67,    49,
       4,     1,    72,    73,    38,    74,    54,    14,   100,     9,
      10,    11,    12,    13,    76,    19,    20,    39,    40,    41,
      42,    86,    64,    65,    66,    67,    23,    43,    44,    45,
      46,    55,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    69,   128,    71,   105,    75,    77,
      78,   108,    79,    80,    81,    82,    83,   113,   114,   115,
     116,   103,    84,   106,   107,   109,   110,   111,   112,   118,
     100,   131,   101,     0,     0,     0,     0,   122,     0,   117,
       0,     0,   121,     0,    87,   124,   125,   126,   127,   129,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,    17,    18,     0,    19,    20,     0,     0,     0,     0,
       0,    21,    22,    50,     0,    23,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,    17,    18,     0,
      19,    20,     0,     0,     0,     0,     0,    21,    22,     0,
       0,    23,    56,    57,    58,    59,    60,    61,     0,    62,
      63,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    56,    57,    58,    59,    60,    61,    85,    62,
      63,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    56,    57,    58,    59,    60,    61,   120,    62,
      63,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    56,    57,    58,    59,    60,    61,   123,    62,
      63,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,     0,    68,    56,    57,    58,    59,    60,    61,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    66,    67,     0,   130,    56,    57,    58,    59,
      60,    61,     0,    62,    63,    56,    57,    58,    59,    60,
      61,     0,    64,    65,    66,    67,     0,     0,     0,     0,
       0,    64,    65,    66,    67
};

static const yytype_int8 yycheck[] =
{
      14,     3,     4,     5,     6,    25,    69,    31,    32,    23,
       0,    12,    32,    33,    37,    35,    34,    19,     6,     7,
       8,     9,    10,    11,    38,    27,    28,     8,     9,    10,
      11,    51,    29,    30,    31,    32,    38,     6,     6,     6,
       6,    34,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    38,   118,    38,    71,    38,     6,
       6,    75,     6,     6,    37,    37,    37,    81,    82,    83,
      84,    34,    37,    22,    26,    37,    37,    37,    37,    34,
       6,    39,    69,    -1,    -1,    -1,    -1,   107,    -1,   103,
      -1,    -1,   106,    -1,    51,   109,   110,   111,   112,   119,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    -1,    38,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    13,    14,    15,    16,    17,    18,    39,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    13,    14,    15,    16,    17,    18,    39,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    13,    14,    15,    16,    17,    18,    39,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    13,    14,    15,    16,    17,
      18,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    41,    42,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    19,    22,    23,    24,    25,    27,
      28,    34,    35,    38,    44,    45,    47,    48,    49,    50,
      51,    55,    56,    57,    58,    59,    60,    61,    37,     8,
       9,    10,    11,     6,     6,     6,     6,     6,    49,    49,
      36,    43,    44,    46,    34,    34,    13,    14,    15,    16,
      17,    18,    20,    21,    29,    30,    31,    32,    34,    38,
      52,    38,    44,    44,    44,    38,    49,     6,     6,     6,
       6,    37,    37,    37,    37,    39,    44,    46,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
       6,    47,    48,    34,    53,    49,    22,    26,    49,    37,
      37,    37,    37,    49,    49,    49,    49,    49,    34,    54,
      39,    49,    44,    39,    49,    49,    49,    49,    48,    44,
      34,    39
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
#line 142 "csmall-parser.y"
    {exit(0);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 145 "csmall-parser.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 146 "csmall-parser.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 151 "csmall-parser.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 152 "csmall-parser.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 156 "csmall-parser.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 157 "csmall-parser.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "csmall-parser.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 159 "csmall-parser.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "csmall-parser.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 161 "csmall-parser.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 162 "csmall-parser.y"
    {/* check */;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 167 "csmall-parser.y"
    {++scopeID; map<string,entry>initMap; symbolTable.push_back(initMap);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 171 "csmall-parser.y"
    {symbolTable.pop_back(); --scopeID;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 175 "csmall-parser.y"
    {declarationHandler((yyvsp[(3) - (5)].name),1,INT_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 176 "csmall-parser.y"
    {declarationHandler((yyvsp[(3) - (5)].name),1,FLOAT_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 177 "csmall-parser.y"
    {declarationHandler((yyvsp[(3) - (5)].name),1,CHAR_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 178 "csmall-parser.y"
    {declarationHandler((yyvsp[(3) - (5)].name),1,BOOL_TYPE,(yyvsp[(5) - (5)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 181 "csmall-parser.y"
    { declarationHandler((yyvsp[(2) - (4)].name),0,INT_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 182 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (4)].name),0,FLOAT_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 183 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (4)].name),0,CHAR_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 184 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (4)].name),0,BOOL_TYPE,(yyvsp[(4) - (4)].info).val,1,0,_MOV,yylineno);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (2)].name),0,INT_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 188 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (2)].name),0,FLOAT_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 189 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (2)].name),0,CHAR_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 190 "csmall-parser.y"
    {declarationHandler((yyvsp[(2) - (2)].name),0,BOOL_TYPE,"0",0,0,_MOV,yylineno);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 194 "csmall-parser.y"
    {variableAssignment((yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].info).val);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 199 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());  printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].val),(yyval.info).val);/* mov int register*/;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 200 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].val),(yyval.info).val);/* mov dec register*/;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 201 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].val),(yyval.info).val);/*mov char register*/;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 202 "csmall-parser.y"
    { string registerNumber = "R" + toString<int>(curRegID++);
                    strcpy((yyval.info).val,registerNumber.c_str()); 
                    /*check if defined before*/
                     definedBefore((yyvsp[(1) - (1)].name));
                     printTripleOperandOperation(_MOV,(yyvsp[(1) - (1)].name),(yyval.info).val);/*mov var register*/
                  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 208 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,"1",(yyval.info).val);/* mov 1 register*/;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 209 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,"0",(yyval.info).val);/* mov 0 register*/;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 210 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_ADD,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*add source1 source2 destination*/;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 211 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_SUB,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*sub source1 source2 destination*/;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 212 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_MUL,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*mul source1 source2 destination*/;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 213 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_DIV,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*div source1 source2 destination*/;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 214 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_LTN,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*lt source1 source2 destination*/;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 215 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_GTN,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*gt source1 source2 destination*/;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 216 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_GTE,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*ge source1 source2 destination*/;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 217 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_LTE,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*le source1 source2 destination*/;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 218 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_NEQ,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*ne source1 source2 destination*/;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 219 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_EQU,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*eq source1 source2 destination*/;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 220 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_NOT,(yyvsp[(2) - (2)].info).val,(yyval.info).val); /*not source destination*/;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 221 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_AND,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*and source1 source2 destination*/;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 222 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printQuadOperandOperation(_OR,(yyvsp[(1) - (3)].info).val,(yyvsp[(3) - (3)].info).val,(yyval.info).val);/*or source1 source2 destination*/;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 223 "csmall-parser.y"
    {string registerNumber = "R" + toString<int>(curRegID++);strcpy((yyval.info).val,registerNumber.c_str());printTripleOperandOperation(_MOV,(yyvsp[(2) - (3)].info).val,(yyval.info).val);/* mov register register*/;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 227 "csmall-parser.y"
    {
                                                     


                                                     printJump(unconditionalLabels.top()); 
                                                     unconditionalLabels.pop();                                                                                           
                                                     printLabel(conditionalLabels.top());
                                                     conditionalLabels.pop();
                                                     symbolTable[scopeID--].clear();                                      
                                                                                           
                                                                                                ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 238 "csmall-parser.y"
    {printJump(unconditionalLabels.top()); unconditionalLabels.pop(); printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 239 "csmall-parser.y"
    {printJumpTrue(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 244 "csmall-parser.y"
    {  map<string,entry>temp; symbolTable.push_back(temp); ++scopeID;
                                                     ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 248 "csmall-parser.y"
    {printLabel(++labelID); unconditionalLabels.push(labelID);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 249 "csmall-parser.y"
    {printLabel(++labelID); unconditionalLabels.push(labelID);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 253 "csmall-parser.y"
    {printJumpFalse(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 257 "csmall-parser.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 261 "csmall-parser.y"
    { map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; printLabel(++labelID); unconditionalLabels.push(labelID);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 264 "csmall-parser.y"
    {printJumpFalse(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 268 "csmall-parser.y"
    {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; printLabel(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 272 "csmall-parser.y"
    { printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 273 "csmall-parser.y"
    { printLabel(conditionalLabels.top()); conditionalLabels.pop(); symbolTable[scopeID--].clear();;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 277 "csmall-parser.y"
    {printJumpFalse(++labelID); conditionalLabels.push(labelID);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 280 "csmall-parser.y"
    {map<string,entry>temp; symbolTable.push_back(temp); ++scopeID; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 283 "csmall-parser.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 2062 "csmall-parser.tab.c"
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
#line 287 "csmall-parser.y"


void yyerror(char *s) {
  //printf("%s at line: %d\n", s,yylineno);
}

void declarationHandler(char* variableName,bool isconst,dataType datatype,string value,bool isinitialized,bool isused,string operationtype,int linenumber){
      
        //check if re-declaration
        if(symbolTable[scopeID].count(variableName)>0){
             printfRedeclarationError(variableName);
            unsuccessfulCompilation=1;          
        }
        else{
          printTripleOperandOperation(operationtype,value,variableName);
           symbolTable[scopeID][variableName]= entry(isconst,datatype,value,isinitialized,isused,linenumber);
           unusedVariables[variableName]=1; 
           entry& e =symbolTable[scopeID][variableName];
           e.display(variableName);  
        }
        return;
}

void definedBefore(char* variableName){
      //check if defined before or not
     int idx=findVariable(variableName);
     
     if(idx==-1){
           printNotdefinedError(variableName);
           unsuccessfulCompilation=1;
     }
     else {
           entry& e = symbolTable[idx][variableName];
            if(e.isInitialized==0){
              printUninitializedWarning(variableName);
            }
            e.isUsed=1;
            unusedVariables.erase(variableName);
            e.display(variableName);
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
  AssemblyFile<<"JMP ";
  printLabel(labelNumber);
}

void printJumpFalse(int labelNumber){
  AssemblyFile<<"JMF ";
  printLabel(labelNumber);
}
void printJumpTrue(int labelNumber){
  AssemblyFile<<"JMT ";
  printLabel(labelNumber);
}

void printLabel(int labelNumber){
  AssemblyFile<<"Label"<<labelNumber<<":\n";
}

void printConstError(char*variableName){
  string s="";
   s+=variableName;
   s+=" is constant and cannot be changed\nat line";
   s+=toString<int>(yylineno);
  return;
}
void printNotdefinedError(char*variableName){
         string s="";
          s+= variableName; 
          s+= "  is not defined\n";
          s+="at line ";
          s+=toString<int>(yylineno)+"\n";
          codeProblemsFile<<s;
           return;
          
}
void printUninitializedWarning(char* variableName){
        codeProblemsFile<<"WARNING: variable ";
        codeProblemsFile<<variableName;
        codeProblemsFile<<" is not initialized\n";
        codeProblemsFile<<"at line ";
        codeProblemsFile<<toString<int>(yylineno);
        codeProblemsFile<<"\n";
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


AssemblyFile<<operationtype<<" "<<source<<" "<<destination<<"\n";
return;
}
void printQuadOperandOperation(string operationtype,string source1,string source2,char* destination){

 AssemblyFile<<operationtype<<" "<<source1<<" "<<source2<<" "<<destination<<"\n";
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

