/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "glcpp/glcpp-parse.y"

/*
 * Copyright © 2010 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

#include "glcpp.h"
#include "main/mtypes.h"

#define glcpp_print(stream, str) stream = talloc_strdup_append(stream, str)
#define glcpp_printf(stream, fmt, args...) \
	stream = talloc_asprintf_append(stream, fmt, args)

static void
yyerror (YYLTYPE *locp, glcpp_parser_t *parser, const char *error);

static void
_define_object_macro (glcpp_parser_t *parser,
		      YYLTYPE *loc,
		      const char *macro,
		      token_list_t *replacements);

static void
_define_function_macro (glcpp_parser_t *parser,
			YYLTYPE *loc,
			const char *macro,
			string_list_t *parameters,
			token_list_t *replacements);

static string_list_t *
_string_list_create (void *ctx);

static void
_string_list_append_item (string_list_t *list, const char *str);

static int
_string_list_contains (string_list_t *list, const char *member, int *index);

static int
_string_list_length (string_list_t *list);

static argument_list_t *
_argument_list_create (void *ctx);

static void
_argument_list_append (argument_list_t *list, token_list_t *argument);

static int
_argument_list_length (argument_list_t *list);

static token_list_t *
_argument_list_member_at (argument_list_t *list, int index);

/* Note: This function talloc_steal()s the str pointer. */
static token_t *
_token_create_str (void *ctx, int type, char *str);

static token_t *
_token_create_ival (void *ctx, int type, int ival);

static token_list_t *
_token_list_create (void *ctx);

/* Note: This function adds a talloc_reference() to token.
 *
 * You may want to talloc_unlink any current reference if you no
 * longer need it. */
static void
_token_list_append (token_list_t *list, token_t *token);

static void
_token_list_append_list (token_list_t *list, token_list_t *tail);

static active_list_t *
_active_list_push (active_list_t *list,
		   const char *identifier,
		   token_node_t *marker);

static active_list_t *
_active_list_pop (active_list_t *list);

int
_active_list_contains (active_list_t *list, const char *identifier);

static void
_glcpp_parser_expand_if (glcpp_parser_t *parser, int type, token_list_t *list);

static void
_glcpp_parser_expand_token_list (glcpp_parser_t *parser,
				 token_list_t *list);

static void
_glcpp_parser_print_expanded_token_list (glcpp_parser_t *parser,
					 token_list_t *list);

static void
_glcpp_parser_skip_stack_push_if (glcpp_parser_t *parser, YYLTYPE *loc,
				  int condition);

static void
_glcpp_parser_skip_stack_change_if (glcpp_parser_t *parser, YYLTYPE *loc,
				    const char *type, int condition);

static void
_glcpp_parser_skip_stack_pop (glcpp_parser_t *parser, YYLTYPE *loc);

#define yylex glcpp_parser_lex

static int
glcpp_parser_lex (YYSTYPE *yylval, YYLTYPE *yylloc, glcpp_parser_t *parser);

static void
glcpp_parser_lex_from (glcpp_parser_t *parser, token_list_t *list);

static void
add_builtin_define(glcpp_parser_t *parser, const char *name, int value);



/* Line 189 of yacc.c  */
#line 215 "glcpp/glcpp-parse.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     COMMA_FINAL = 258,
     DEFINED = 259,
     ELIF_EXPANDED = 260,
     HASH = 261,
     HASH_DEFINE_FUNC = 262,
     HASH_DEFINE_OBJ = 263,
     HASH_ELIF = 264,
     HASH_ELSE = 265,
     HASH_ENDIF = 266,
     HASH_IF = 267,
     HASH_IFDEF = 268,
     HASH_IFNDEF = 269,
     HASH_UNDEF = 270,
     HASH_VERSION = 271,
     IDENTIFIER = 272,
     IF_EXPANDED = 273,
     INTEGER = 274,
     INTEGER_STRING = 275,
     NEWLINE = 276,
     OTHER = 277,
     PLACEHOLDER = 278,
     SPACE = 279,
     PASTE = 280,
     OR = 281,
     AND = 282,
     NOT_EQUAL = 283,
     EQUAL = 284,
     GREATER_OR_EQUAL = 285,
     LESS_OR_EQUAL = 286,
     RIGHT_SHIFT = 287,
     LEFT_SHIFT = 288,
     UNARY = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 303 "glcpp/glcpp-parse.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   604

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNRULES -- Number of states.  */
#define YYNSTATES  161

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
       2,     2,     2,    47,     2,     2,     2,    43,    30,     2,
      45,    46,    41,    39,    49,    40,    54,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
      33,    56,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    28,    53,    48,     2,     2,     2,
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
      25,    26,    27,    31,    32,    35,    36,    37,    38,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    16,    20,
      24,    29,    36,    44,    48,    52,    57,    62,    66,    69,
      72,    75,    79,    82,    84,    86,    88,    92,    96,   100,
     104,   108,   112,   116,   120,   124,   128,   132,   136,   140,
     144,   148,   152,   156,   160,   163,   166,   169,   172,   176,
     178,   182,   184,   187,   190,   191,   193,   194,   196,   199,
     204,   206,   208,   211,   213,   216,   218,   220,   222,   224,
     226,   228,   230,   232,   234,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   262,   264,
     266,   268,   270,   272,   274,   276,   278,   280,   282,   284,
     286
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,    58,    59,    -1,    61,    -1,    65,
      -1,    60,    -1,     6,    66,    -1,    18,    63,    21,    -1,
       5,    63,    21,    -1,     8,    17,    67,    21,    -1,     7,
      17,    45,    46,    67,    21,    -1,     7,    17,    45,    64,
      46,    67,    21,    -1,    15,    17,    21,    -1,    12,    70,
      21,    -1,    13,    17,    68,    21,    -1,    14,    17,    68,
      21,    -1,     9,    70,    21,    -1,     9,    21,    -1,    10,
      21,    -1,    11,    21,    -1,    16,    62,    21,    -1,     6,
      21,    -1,    20,    -1,    19,    -1,    62,    -1,    63,    26,
      63,    -1,    63,    27,    63,    -1,    63,    28,    63,    -1,
      63,    29,    63,    -1,    63,    30,    63,    -1,    63,    31,
      63,    -1,    63,    32,    63,    -1,    63,    35,    63,    -1,
      63,    36,    63,    -1,    63,    34,    63,    -1,    63,    33,
      63,    -1,    63,    37,    63,    -1,    63,    38,    63,    -1,
      63,    40,    63,    -1,    63,    39,    63,    -1,    63,    43,
      63,    -1,    63,    42,    63,    -1,    63,    41,    63,    -1,
      47,    63,    -1,    48,    63,    -1,    40,    63,    -1,    39,
      63,    -1,    45,    63,    46,    -1,    17,    -1,    64,    49,
      17,    -1,    21,    -1,    71,    21,    -1,    71,    21,    -1,
      -1,    71,    -1,    -1,    71,    -1,     4,    17,    -1,     4,
      45,    17,    46,    -1,    72,    -1,    69,    -1,    70,    69,
      -1,    72,    -1,    71,    72,    -1,    17,    -1,    20,    -1,
      73,    -1,    22,    -1,    24,    -1,    50,    -1,    51,    -1,
      45,    -1,    46,    -1,    52,    -1,    53,    -1,    54,    -1,
      30,    -1,    41,    -1,    39,    -1,    40,    -1,    48,    -1,
      47,    -1,    42,    -1,    43,    -1,    38,    -1,    37,    -1,
      33,    -1,    34,    -1,    36,    -1,    35,    -1,    32,    -1,
      31,    -1,    29,    -1,    28,    -1,    27,    -1,    26,    -1,
      55,    -1,    49,    -1,    56,    -1,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   174,   178,   181,   186,   187,   191,   194,
     200,   203,   206,   209,   217,   228,   233,   238,   247,   258,
     261,   264,   273,   277,   286,   291,   292,   295,   298,   301,
     304,   307,   310,   313,   316,   319,   322,   325,   328,   331,
     334,   337,   340,   343,   346,   349,   352,   355,   358,   364,
     369,   377,   378,   382,   388,   389,   392,   394,   401,   405,
     409,   414,   420,   428,   434,   442,   446,   450,   454,   458,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA_FINAL", "DEFINED",
  "ELIF_EXPANDED", "HASH", "HASH_DEFINE_FUNC", "HASH_DEFINE_OBJ",
  "HASH_ELIF", "HASH_ELSE", "HASH_ENDIF", "HASH_IF", "HASH_IFDEF",
  "HASH_IFNDEF", "HASH_UNDEF", "HASH_VERSION", "IDENTIFIER", "IF_EXPANDED",
  "INTEGER", "INTEGER_STRING", "NEWLINE", "OTHER", "PLACEHOLDER", "SPACE",
  "PASTE", "OR", "AND", "'|'", "'^'", "'&'", "NOT_EQUAL", "EQUAL", "'<'",
  "'>'", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "RIGHT_SHIFT", "LEFT_SHIFT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY", "'('", "')'", "'!'", "'~'",
  "','", "'['", "']'", "'{'", "'}'", "'.'", "';'", "'='", "$accept",
  "input", "line", "expanded_line", "control_line", "integer_constant",
  "expression", "identifier_list", "text_line", "non_directive",
  "replacement_list", "junk", "conditional_token", "conditional_tokens",
  "pp_tokens", "preprocessing_token", "operator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   124,    94,
      38,   283,   284,    60,    62,   285,   286,   287,   288,    43,
      45,    42,    47,    37,   289,    40,    41,    33,   126,    44,
      91,    93,   123,   125,    46,    59,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     3,     3,
       4,     6,     7,     3,     3,     4,     4,     3,     2,     2,
       2,     3,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     1,
       3,     1,     2,     2,     0,     1,     0,     1,     2,     4,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,    66,    51,    68,
      69,   100,    96,    95,    94,    93,    77,    92,    91,    87,
      88,    90,    89,    86,    85,    79,    80,    78,    83,    84,
      72,    73,    82,    81,    98,    70,    71,    74,    75,    76,
      97,    99,     3,     6,     4,     5,     0,    63,    67,    24,
      23,     0,     0,     0,     0,     0,    25,     0,    22,     7,
       0,     0,    54,     0,    18,    61,     0,    60,    19,    20,
       0,    56,    56,     0,     0,     0,    52,    64,    47,    46,
       0,    44,    45,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,    55,    58,     0,    17,    62,
      14,     0,    57,     0,    13,    21,     8,    48,    26,    27,
      28,    29,    30,    31,    32,    36,    35,    33,    34,    37,
      38,    40,    39,    43,    42,    41,    49,    54,     0,    10,
       0,    15,    16,     0,    54,     0,    59,    11,     0,    50,
      12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    52,    53,    54,    66,    67,   148,    55,    69,
     114,   121,    75,    76,   115,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
    -146,   111,  -146,   429,   -10,    -9,    -4,   151,   -15,    27,
     271,    54,    63,    86,    82,  -146,   429,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,   311,  -146,  -146,  -146,
    -146,   429,   429,   429,   429,   429,  -146,   452,  -146,  -146,
     351,    59,   391,    17,  -146,  -146,   191,  -146,  -146,  -146,
     231,   391,   391,    84,    85,   475,  -146,  -146,  -146,  -146,
     424,  -146,  -146,  -146,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,  -146,    30,    88,   391,  -146,    90,  -146,  -146,
    -146,    89,   391,    91,  -146,  -146,  -146,  -146,   492,   508,
     523,   537,   550,   561,   561,    18,    18,    18,    18,    25,
      25,    36,    36,  -146,  -146,  -146,  -146,   391,    26,  -146,
      67,  -146,  -146,    93,   391,   113,  -146,  -146,   148,  -146,
    -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,   120,   -11,  -146,  -146,  -146,
    -145,    92,    -6,   160,     0,    -7,  -146
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      77,    56,   153,    77,    70,    85,    78,    15,    71,   158,
      17,    68,    19,    72,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   116,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,   146,    79,    87,
      88,    89,    90,    91,    92,   105,   106,   107,   108,   109,
     110,   111,   117,    87,   107,   108,   109,   110,   111,    77,
     119,    81,   154,    77,   119,   155,   147,   109,   110,   111,
      82,   122,   122,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    59,    60,    83,   113,   124,   125,   150,    87,   149,
     151,     2,   152,   156,   157,    87,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     159,    17,    18,    19,    84,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    73,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,   160,
      80,    17,    74,    19,   123,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    73,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,     0,
       0,    17,   118,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    73,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,     0,
       0,    17,   120,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    73,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,     0,
       0,    17,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,     0,
       0,    17,    86,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,     0,
       0,    17,   112,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    15,     0,
       0,    17,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    59,    60,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    61,    62,
     127,     0,     0,    93,    63,     0,    64,    65,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   126,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
       7,     1,   147,    10,     4,    16,    21,    17,    17,   154,
      20,    21,    22,    17,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    17,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    17,    21,    56,
      61,    62,    63,    64,    65,    37,    38,    39,    40,    41,
      42,    43,    45,    70,    39,    40,    41,    42,    43,    76,
      76,    17,    46,    80,    80,    49,    46,    41,    42,    43,
      17,    81,    82,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    19,    20,    17,    45,    21,    21,    17,   115,    21,
      21,     0,    21,    46,    21,   122,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      17,    20,    21,    22,    14,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     4,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    21,
      10,    20,    21,    22,    82,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     4,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     4,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     4,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    -1,
      -1,    20,    -1,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    17,    -1,
      -1,    20,    -1,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    19,    20,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    39,    40,
      46,    -1,    -1,    21,    45,    -1,    47,    48,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    20,    21,    22,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    59,    60,    61,    65,    71,    72,    73,    19,
      20,    39,    40,    45,    47,    48,    62,    63,    21,    66,
      71,    17,    17,     4,    21,    69,    70,    72,    21,    21,
      70,    17,    17,    17,    62,    63,    21,    72,    63,    63,
      63,    63,    63,    21,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    21,    45,    67,    71,    17,    45,    21,    69,
      21,    68,    71,    68,    21,    21,    21,    46,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    17,    46,    64,    21,
      17,    21,    21,    67,    46,    49,    46,    21,    67,    17,
      21
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (&yylloc, parser, YY_("syntax error: cannot back up")); \
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, parser)
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
		  Type, Value, Location, parser); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, glcpp_parser_t *parser)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    glcpp_parser_t *parser;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (parser);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, glcpp_parser_t *parser)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    glcpp_parser_t *parser;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parser);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, glcpp_parser_t *parser)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, parser)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    glcpp_parser_t *parser;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, parser); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, glcpp_parser_t *parser)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, parser)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    glcpp_parser_t *parser;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parser);

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
int yyparse (glcpp_parser_t *parser);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





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
yyparse (glcpp_parser_t *parser)
#else
int
yyparse (parser)
    glcpp_parser_t *parser;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1464 of yacc.c  */
#line 178 "glcpp/glcpp-parse.y"
    {
		glcpp_print(parser->output, "\n");
	;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 181 "glcpp/glcpp-parse.y"
    {
		_glcpp_parser_print_expanded_token_list (parser, (yyvsp[(1) - (1)].token_list));
		glcpp_print(parser->output, "\n");
		talloc_free ((yyvsp[(1) - (1)].token_list));
	;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 191 "glcpp/glcpp-parse.y"
    {
		_glcpp_parser_skip_stack_push_if (parser, & (yylsp[(1) - (3)]), (yyvsp[(2) - (3)].ival));
	;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 194 "glcpp/glcpp-parse.y"
    {
		_glcpp_parser_skip_stack_change_if (parser, & (yylsp[(1) - (3)]), "elif", (yyvsp[(2) - (3)].ival));
	;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 200 "glcpp/glcpp-parse.y"
    {
		_define_object_macro (parser, & (yylsp[(2) - (4)]), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].token_list));
	;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 203 "glcpp/glcpp-parse.y"
    {
		_define_function_macro (parser, & (yylsp[(2) - (6)]), (yyvsp[(2) - (6)].str), NULL, (yyvsp[(5) - (6)].token_list));
	;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 206 "glcpp/glcpp-parse.y"
    {
		_define_function_macro (parser, & (yylsp[(2) - (7)]), (yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].string_list), (yyvsp[(6) - (7)].token_list));
	;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 209 "glcpp/glcpp-parse.y"
    {
		macro_t *macro = hash_table_find (parser->defines, (yyvsp[(2) - (3)].str));
		if (macro) {
			hash_table_remove (parser->defines, (yyvsp[(2) - (3)].str));
			talloc_free (macro);
		}
		talloc_free ((yyvsp[(2) - (3)].str));
	;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 217 "glcpp/glcpp-parse.y"
    {
		/* If we're skipping to the next #elif/#else case or to #endif,
		 * don't bother expanding or parsing the expression.
		 */
		if (parser->skip_stack != NULL && parser->skip_stack->type != SKIP_NO_SKIP) {
			_glcpp_parser_skip_stack_push_if (parser, & (yylsp[(1) - (3)]), 0);
			parser->skip_stack->type = SKIP_TO_ENDIF;
		} else {
			_glcpp_parser_expand_if (parser, IF_EXPANDED, (yyvsp[(2) - (3)].token_list));
		}
	;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 228 "glcpp/glcpp-parse.y"
    {
		macro_t *macro = hash_table_find (parser->defines, (yyvsp[(2) - (4)].str));
		talloc_free ((yyvsp[(2) - (4)].str));
		_glcpp_parser_skip_stack_push_if (parser, & (yylsp[(1) - (4)]), macro != NULL);
	;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 233 "glcpp/glcpp-parse.y"
    {
		macro_t *macro = hash_table_find (parser->defines, (yyvsp[(2) - (4)].str));
		talloc_free ((yyvsp[(2) - (4)].str));
		_glcpp_parser_skip_stack_push_if (parser, & (yylsp[(1) - (4)]), macro == NULL);
	;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 238 "glcpp/glcpp-parse.y"
    {
		/* If we just finished a non-skipped #if/#ifdef/#ifndef block,
		 * don't bother expanding or parsing the expression.
		 */
		if (parser->skip_stack != NULL && parser->skip_stack->type == SKIP_NO_SKIP)
			parser->skip_stack->type = SKIP_TO_ENDIF;
		else
			_glcpp_parser_expand_if (parser, ELIF_EXPANDED, (yyvsp[(2) - (3)].token_list));
	;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 247 "glcpp/glcpp-parse.y"
    {
		/* #elif without an expression results in a warning if the
		 * condition doesn't matter (we just handled #if 1 or such)
		 * but an error otherwise. */
		if (parser->skip_stack != NULL && parser->skip_stack->type == SKIP_NO_SKIP) {
			parser->skip_stack->type = SKIP_TO_ENDIF;
			glcpp_warning(& (yylsp[(1) - (2)]), parser, "ignoring illegal #elif without expression");
		} else {
			glcpp_error(& (yylsp[(1) - (2)]), parser, "#elif needs an expression");
		}
	;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 258 "glcpp/glcpp-parse.y"
    {
		_glcpp_parser_skip_stack_change_if (parser, & (yylsp[(1) - (2)]), "else", 1);
	;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 261 "glcpp/glcpp-parse.y"
    {
		_glcpp_parser_skip_stack_pop (parser, & (yylsp[(1) - (2)]));
	;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 264 "glcpp/glcpp-parse.y"
    {
		macro_t *macro = hash_table_find (parser->defines, "__VERSION__");
		if (macro) {
			hash_table_remove (parser->defines, "__VERSION__");
			talloc_free (macro);
		}
		add_builtin_define (parser, "__VERSION__", (yyvsp[(2) - (3)].ival));
		glcpp_printf(parser->output, "#version %" PRIiMAX "\n", (yyvsp[(2) - (3)].ival));
	;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 277 "glcpp/glcpp-parse.y"
    {
		if (strlen ((yyvsp[(1) - (1)].str)) >= 3 && strncmp ((yyvsp[(1) - (1)].str), "0x", 2) == 0) {
			(yyval.ival) = strtoll ((yyvsp[(1) - (1)].str) + 2, NULL, 16);
		} else if ((yyvsp[(1) - (1)].str)[0] == '0') {
			(yyval.ival) = strtoll ((yyvsp[(1) - (1)].str), NULL, 8);
		} else {
			(yyval.ival) = strtoll ((yyvsp[(1) - (1)].str), NULL, 10);
		}
	;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 286 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (1)].ival);
	;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 292 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) || (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 295 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) && (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 298 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 301 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) ^ (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 304 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) & (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 307 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 310 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) == (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 313 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) >= (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 316 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) <= (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 319 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) > (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 322 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) < (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 325 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) >> (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 328 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) << (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 331 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 334 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 337 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) % (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 340 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 343 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival);
	;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 346 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = ! (yyvsp[(2) - (2)].ival);
	;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 349 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = ~ (yyvsp[(2) - (2)].ival);
	;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 352 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = - (yyvsp[(2) - (2)].ival);
	;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 355 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = + (yyvsp[(2) - (2)].ival);
	;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 358 "glcpp/glcpp-parse.y"
    {
		(yyval.ival) = (yyvsp[(2) - (3)].ival);
	;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 364 "glcpp/glcpp-parse.y"
    {
		(yyval.string_list) = _string_list_create (parser);
		_string_list_append_item ((yyval.string_list), (yyvsp[(1) - (1)].str));
		talloc_steal ((yyval.string_list), (yyvsp[(1) - (1)].str));
	;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 369 "glcpp/glcpp-parse.y"
    {
		(yyval.string_list) = (yyvsp[(1) - (3)].string_list);	
		_string_list_append_item ((yyval.string_list), (yyvsp[(3) - (3)].str));
		talloc_steal ((yyval.string_list), (yyvsp[(3) - (3)].str));
	;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 377 "glcpp/glcpp-parse.y"
    { (yyval.token_list) = NULL; ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 382 "glcpp/glcpp-parse.y"
    {
		yyerror (& (yylsp[(1) - (2)]), parser, "Invalid tokens after #");
	;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 388 "glcpp/glcpp-parse.y"
    { (yyval.token_list) = NULL; ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 394 "glcpp/glcpp-parse.y"
    {
		glcpp_warning(&(yylsp[(1) - (1)]), parser, "extra tokens at end of directive");
	;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 401 "glcpp/glcpp-parse.y"
    {
		int v = hash_table_find (parser->defines, (yyvsp[(2) - (2)].str)) ? 1 : 0;
		(yyval.token) = _token_create_ival (parser, INTEGER, v);
	;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 405 "glcpp/glcpp-parse.y"
    {
		int v = hash_table_find (parser->defines, (yyvsp[(3) - (4)].str)) ? 1 : 0;
		(yyval.token) = _token_create_ival (parser, INTEGER, v);
	;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 414 "glcpp/glcpp-parse.y"
    {
		parser->space_tokens = 1;
		(yyval.token_list) = _token_list_create (parser);
		_token_list_append ((yyval.token_list), (yyvsp[(1) - (1)].token));
		talloc_unlink (parser, (yyvsp[(1) - (1)].token));
	;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 420 "glcpp/glcpp-parse.y"
    {
		(yyval.token_list) = (yyvsp[(1) - (2)].token_list);
		_token_list_append ((yyval.token_list), (yyvsp[(2) - (2)].token));
		talloc_unlink (parser, (yyvsp[(2) - (2)].token));
	;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 428 "glcpp/glcpp-parse.y"
    {
		parser->space_tokens = 1;
		(yyval.token_list) = _token_list_create (parser);
		_token_list_append ((yyval.token_list), (yyvsp[(1) - (1)].token));
		talloc_unlink (parser, (yyvsp[(1) - (1)].token));
	;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 434 "glcpp/glcpp-parse.y"
    {
		(yyval.token_list) = (yyvsp[(1) - (2)].token_list);
		_token_list_append ((yyval.token_list), (yyvsp[(2) - (2)].token));
		talloc_unlink (parser, (yyvsp[(2) - (2)].token));
	;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 442 "glcpp/glcpp-parse.y"
    {
		(yyval.token) = _token_create_str (parser, IDENTIFIER, (yyvsp[(1) - (1)].str));
		(yyval.token)->location = yylloc;
	;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 446 "glcpp/glcpp-parse.y"
    {
		(yyval.token) = _token_create_str (parser, INTEGER_STRING, (yyvsp[(1) - (1)].str));
		(yyval.token)->location = yylloc;
	;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 450 "glcpp/glcpp-parse.y"
    {
		(yyval.token) = _token_create_ival (parser, (yyvsp[(1) - (1)].ival), (yyvsp[(1) - (1)].ival));
		(yyval.token)->location = yylloc;
	;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 454 "glcpp/glcpp-parse.y"
    {
		(yyval.token) = _token_create_str (parser, OTHER, (yyvsp[(1) - (1)].str));
		(yyval.token)->location = yylloc;
	;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 458 "glcpp/glcpp-parse.y"
    {
		(yyval.token) = _token_create_ival (parser, SPACE, SPACE);
		(yyval.token)->location = yylloc;
	;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 465 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '['; ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 466 "glcpp/glcpp-parse.y"
    { (yyval.ival) = ']'; ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 467 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '('; ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 468 "glcpp/glcpp-parse.y"
    { (yyval.ival) = ')'; ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 469 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '{'; ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 470 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '}'; ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 471 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '.'; ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 472 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '&'; ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 473 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '*'; ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 474 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '+'; ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 475 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '-'; ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 476 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '~'; ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 477 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '!'; ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 478 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '/'; ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 479 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '%'; ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 480 "glcpp/glcpp-parse.y"
    { (yyval.ival) = LEFT_SHIFT; ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 481 "glcpp/glcpp-parse.y"
    { (yyval.ival) = RIGHT_SHIFT; ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 482 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '<'; ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 483 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '>'; ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 484 "glcpp/glcpp-parse.y"
    { (yyval.ival) = LESS_OR_EQUAL; ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 485 "glcpp/glcpp-parse.y"
    { (yyval.ival) = GREATER_OR_EQUAL; ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 486 "glcpp/glcpp-parse.y"
    { (yyval.ival) = EQUAL; ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 487 "glcpp/glcpp-parse.y"
    { (yyval.ival) = NOT_EQUAL; ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 488 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '^'; ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 489 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '|'; ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 490 "glcpp/glcpp-parse.y"
    { (yyval.ival) = AND; ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 491 "glcpp/glcpp-parse.y"
    { (yyval.ival) = OR; ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 492 "glcpp/glcpp-parse.y"
    { (yyval.ival) = ';'; ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 493 "glcpp/glcpp-parse.y"
    { (yyval.ival) = ','; ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 494 "glcpp/glcpp-parse.y"
    { (yyval.ival) = '='; ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 495 "glcpp/glcpp-parse.y"
    { (yyval.ival) = PASTE; ;}
    break;



/* Line 1464 of yacc.c  */
#line 2589 "glcpp/glcpp-parse.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
      yyerror (&yylloc, parser, YY_("syntax error"));
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
	    yyerror (&yylloc, parser, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, parser, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc, parser);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, parser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, parser);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, parser);
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



/* Line 1684 of yacc.c  */
#line 498 "glcpp/glcpp-parse.y"


string_list_t *
_string_list_create (void *ctx)
{
	string_list_t *list;

	list = talloc (ctx, string_list_t);
	list->head = NULL;
	list->tail = NULL;

	return list;
}

void
_string_list_append_item (string_list_t *list, const char *str)
{
	string_node_t *node;

	node = talloc (list, string_node_t);
	node->str = talloc_strdup (node, str);

	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}

	list->tail = node;
}

int
_string_list_contains (string_list_t *list, const char *member, int *index)
{
	string_node_t *node;
	int i;

	if (list == NULL)
		return 0;

	for (i = 0, node = list->head; node; i++, node = node->next) {
		if (strcmp (node->str, member) == 0) {
			if (index)
				*index = i;
			return 1;
		}
	}

	return 0;
}

int
_string_list_length (string_list_t *list)
{
	int length = 0;
	string_node_t *node;

	if (list == NULL)
		return 0;

	for (node = list->head; node; node = node->next)
		length++;

	return length;
}

argument_list_t *
_argument_list_create (void *ctx)
{
	argument_list_t *list;

	list = talloc (ctx, argument_list_t);
	list->head = NULL;
	list->tail = NULL;

	return list;
}

void
_argument_list_append (argument_list_t *list, token_list_t *argument)
{
	argument_node_t *node;

	node = talloc (list, argument_node_t);
	node->argument = argument;

	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}

	list->tail = node;
}

int
_argument_list_length (argument_list_t *list)
{
	int length = 0;
	argument_node_t *node;

	if (list == NULL)
		return 0;

	for (node = list->head; node; node = node->next)
		length++;

	return length;
}

token_list_t *
_argument_list_member_at (argument_list_t *list, int index)
{
	argument_node_t *node;
	int i;

	if (list == NULL)
		return NULL;

	node = list->head;
	for (i = 0; i < index; i++) {
		node = node->next;
		if (node == NULL)
			break;
	}

	if (node)
		return node->argument;

	return NULL;
}

/* Note: This function talloc_steal()s the str pointer. */
token_t *
_token_create_str (void *ctx, int type, char *str)
{
	token_t *token;

	token = talloc (ctx, token_t);
	token->type = type;
	token->value.str = talloc_steal (token, str);

	return token;
}

token_t *
_token_create_ival (void *ctx, int type, int ival)
{
	token_t *token;

	token = talloc (ctx, token_t);
	token->type = type;
	token->value.ival = ival;

	return token;
}

token_list_t *
_token_list_create (void *ctx)
{
	token_list_t *list;

	list = talloc (ctx, token_list_t);
	list->head = NULL;
	list->tail = NULL;
	list->non_space_tail = NULL;

	return list;
}

void
_token_list_append (token_list_t *list, token_t *token)
{
	token_node_t *node;

	node = talloc (list, token_node_t);
	node->token = talloc_reference (list, token);

	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}

	list->tail = node;
	if (token->type != SPACE)
		list->non_space_tail = node;
}

void
_token_list_append_list (token_list_t *list, token_list_t *tail)
{
	if (tail == NULL || tail->head == NULL)
		return;

	if (list->head == NULL) {
		list->head = tail->head;
	} else {
		list->tail->next = tail->head;
	}

	list->tail = tail->tail;
	list->non_space_tail = tail->non_space_tail;
}

static token_list_t *
_token_list_copy (void *ctx, token_list_t *other)
{
	token_list_t *copy;
	token_node_t *node;

	if (other == NULL)
		return NULL;

	copy = _token_list_create (ctx);
	for (node = other->head; node; node = node->next)
		_token_list_append (copy, node->token);

	return copy;
}

static void
_token_list_trim_trailing_space (token_list_t *list)
{
	token_node_t *tail, *next;

	if (list->non_space_tail) {
		tail = list->non_space_tail->next;
		list->non_space_tail->next = NULL;
		list->tail = list->non_space_tail;

		while (tail) {
			next = tail->next;
			talloc_free (tail);
			tail = next;
		}
	}
}

static void
_token_print (char **out, token_t *token)
{
	if (token->type < 256) {
		glcpp_printf (*out, "%c", token->type);
		return;
	}

	switch (token->type) {
	case INTEGER:
		glcpp_printf (*out, "%" PRIiMAX, token->value.ival);
		break;
	case IDENTIFIER:
	case INTEGER_STRING:
	case OTHER:
		glcpp_print (*out, token->value.str);
		break;
	case SPACE:
		glcpp_print (*out, " ");
		break;
	case LEFT_SHIFT:
		glcpp_print (*out, "<<");
		break;
	case RIGHT_SHIFT:
		glcpp_print (*out, ">>");
		break;
	case LESS_OR_EQUAL:
		glcpp_print (*out, "<=");
		break;
	case GREATER_OR_EQUAL:
		glcpp_print (*out, ">=");
		break;
	case EQUAL:
		glcpp_print (*out, "==");
		break;
	case NOT_EQUAL:
		glcpp_print (*out, "!=");
		break;
	case AND:
		glcpp_print (*out, "&&");
		break;
	case OR:
		glcpp_print (*out, "||");
		break;
	case PASTE:
		glcpp_print (*out, "##");
		break;
	case COMMA_FINAL:
		glcpp_print (*out, ",");
		break;
	case PLACEHOLDER:
		/* Nothing to print. */
		break;
	default:
		assert(!"Error: Don't know how to print token.");
		break;
	}
}

/* Return a new token (talloc()ed off of 'token') formed by pasting
 * 'token' and 'other'. Note that this function may return 'token' or
 * 'other' directly rather than allocating anything new.
 *
 * Caution: Only very cursory error-checking is performed to see if
 * the final result is a valid single token. */
static token_t *
_token_paste (glcpp_parser_t *parser, token_t *token, token_t *other)
{
	token_t *combined = NULL;

	/* Pasting a placeholder onto anything makes no change. */
	if (other->type == PLACEHOLDER)
		return token;

	/* When 'token' is a placeholder, just return 'other'. */
	if (token->type == PLACEHOLDER)
		return other;

	/* A very few single-character punctuators can be combined
	 * with another to form a multi-character punctuator. */
	switch (token->type) {
	case '<':
		if (other->type == '<')
			combined = _token_create_ival (token, LEFT_SHIFT, LEFT_SHIFT);
		else if (other->type == '=')
			combined = _token_create_ival (token, LESS_OR_EQUAL, LESS_OR_EQUAL);
		break;
	case '>':
		if (other->type == '>')
			combined = _token_create_ival (token, RIGHT_SHIFT, RIGHT_SHIFT);
		else if (other->type == '=')
			combined = _token_create_ival (token, GREATER_OR_EQUAL, GREATER_OR_EQUAL);
		break;
	case '=':
		if (other->type == '=')
			combined = _token_create_ival (token, EQUAL, EQUAL);
		break;
	case '!':
		if (other->type == '=')
			combined = _token_create_ival (token, NOT_EQUAL, NOT_EQUAL);
		break;
	case '&':
		if (other->type == '&')
			combined = _token_create_ival (token, AND, AND);
		break;
	case '|':
		if (other->type == '|')
			combined = _token_create_ival (token, OR, OR);
		break;
	}

	if (combined != NULL) {
		/* Inherit the location from the first token */
		combined->location = token->location;
		return combined;
	}

	/* Two string-valued tokens can usually just be mashed
	 * together.
	 *
	 * XXX: This isn't actually legitimate. Several things here
	 * should result in a diagnostic since the result cannot be a
	 * valid, single pre-processing token. For example, pasting
	 * "123" and "abc" is not legal, but we don't catch that
	 * here. */
	if ((token->type == IDENTIFIER || token->type == OTHER || token->type == INTEGER_STRING) &&
	    (other->type == IDENTIFIER || other->type == OTHER || other->type == INTEGER_STRING))
	{
		char *str;

		str = talloc_asprintf (token, "%s%s", token->value.str,
				       other->value.str);
		combined = _token_create_str (token, token->type, str);
		combined->location = token->location;
		return combined;
	}

	glcpp_error (&token->location, parser, "");
	glcpp_print (parser->info_log, "Pasting \"");
	_token_print (&parser->info_log, token);
	glcpp_print (parser->info_log, "\" and \"");
	_token_print (&parser->info_log, other);
	glcpp_print (parser->info_log, "\" does not give a valid preprocessing token.\n");

	return token;
}

static void
_token_list_print (glcpp_parser_t *parser, token_list_t *list)
{
	token_node_t *node;

	if (list == NULL)
		return;

	for (node = list->head; node; node = node->next)
		_token_print (&parser->output, node->token);
}

void
yyerror (YYLTYPE *locp, glcpp_parser_t *parser, const char *error)
{
	glcpp_error(locp, parser, "%s", error);
}

static void add_builtin_define(glcpp_parser_t *parser,
			       const char *name, int value)
{
   token_t *tok;
   token_list_t *list;

   tok = _token_create_ival (parser, INTEGER, value);

   list = _token_list_create(parser);
   _token_list_append(list, tok);
   _define_object_macro(parser, NULL, name, list);

   talloc_unlink(parser, tok);
}

glcpp_parser_t *
glcpp_parser_create (const struct gl_extensions *extensions)
{
	glcpp_parser_t *parser;
	int language_version;

	parser = talloc (NULL, glcpp_parser_t);

	glcpp_lex_init_extra (parser, &parser->scanner);
	parser->defines = hash_table_ctor (32, hash_table_string_hash,
					   hash_table_string_compare);
	parser->active = NULL;
	parser->lexing_if = 0;
	parser->space_tokens = 1;
	parser->newline_as_space = 0;
	parser->in_control_line = 0;
	parser->paren_count = 0;

	parser->skip_stack = NULL;

	parser->lex_from_list = NULL;
	parser->lex_from_node = NULL;

	parser->output = talloc_strdup(parser, "");
	parser->info_log = talloc_strdup(parser, "");
	parser->error = 0;

	/* Add pre-defined macros. */
	add_builtin_define(parser, "GL_ARB_draw_buffers", 1);
	add_builtin_define(parser, "GL_ARB_texture_rectangle", 1);

	if (extensions != NULL) {
	   if (extensions->EXT_texture_array) {
	      add_builtin_define(parser, "GL_EXT_texture_array", 1);
	   }

	   if (extensions->ARB_fragment_coord_conventions)
	      add_builtin_define(parser, "GL_ARB_fragment_coord_conventions",
				 1);
	}

	language_version = 110;
	add_builtin_define(parser, "__VERSION__", language_version);

	return parser;
}

int
glcpp_parser_parse (glcpp_parser_t *parser)
{
	return yyparse (parser);
}

void
glcpp_parser_destroy (glcpp_parser_t *parser)
{
	if (parser->skip_stack)
		glcpp_error (&parser->skip_stack->loc, parser, "Unterminated #if\n");
	glcpp_lex_destroy (parser->scanner);
	hash_table_dtor (parser->defines);
	talloc_free (parser);
}

typedef enum function_status
{
	FUNCTION_STATUS_SUCCESS,
	FUNCTION_NOT_A_FUNCTION,
	FUNCTION_UNBALANCED_PARENTHESES
} function_status_t;

/* Find a set of function-like macro arguments by looking for a
 * balanced set of parentheses.
 *
 * When called, 'node' should be the opening-parenthesis token, (or
 * perhaps preceeding SPACE tokens). Upon successful return *last will
 * be the last consumed node, (corresponding to the closing right
 * parenthesis).
 *
 * Return values:
 *
 *   FUNCTION_STATUS_SUCCESS:
 *
 *	Successfully parsed a set of function arguments.	
 *
 *   FUNCTION_NOT_A_FUNCTION:
 *
 *	Macro name not followed by a '('. This is not an error, but
 *	simply that the macro name should be treated as a non-macro.
 *
 *   FUNCTION_UNBALANCED_PARENTHESES
 *
 *	Macro name is not followed by a balanced set of parentheses.
 */
static function_status_t
_arguments_parse (argument_list_t *arguments,
		  token_node_t *node,
		  token_node_t **last)
{
	token_list_t *argument;
	int paren_count;

	node = node->next;

	/* Ignore whitespace before first parenthesis. */
	while (node && node->token->type == SPACE)
		node = node->next;

	if (node == NULL || node->token->type != '(')
		return FUNCTION_NOT_A_FUNCTION;

	node = node->next;

	argument = _token_list_create (arguments);
	_argument_list_append (arguments, argument);

	for (paren_count = 1; node; node = node->next) {
		if (node->token->type == '(')
		{
			paren_count++;
		}
		else if (node->token->type == ')')
		{
			paren_count--;
			if (paren_count == 0)
				break;
		}

		if (node->token->type == ',' &&
			 paren_count == 1)
		{
			_token_list_trim_trailing_space (argument);
			argument = _token_list_create (arguments);
			_argument_list_append (arguments, argument);
		}
		else {
			if (argument->head == NULL) {
				/* Don't treat initial whitespace as
				 * part of the arguement. */
				if (node->token->type == SPACE)
					continue;
			}
			_token_list_append (argument, node->token);
		}
	}

	if (paren_count)
		return FUNCTION_UNBALANCED_PARENTHESES;

	*last = node;

	return FUNCTION_STATUS_SUCCESS;
}

static token_list_t *
_token_list_create_with_one_space (void *ctx)
{
	token_list_t *list;
	token_t *space;

	list = _token_list_create (ctx);
	space = _token_create_ival (list, SPACE, SPACE);
	_token_list_append (list, space);

	return list;
}

static void
_glcpp_parser_expand_if (glcpp_parser_t *parser, int type, token_list_t *list)
{
	token_list_t *expanded;
	token_t *token;

	expanded = _token_list_create (parser);
	token = _token_create_ival (parser, type, type);
	_token_list_append (expanded, token);
	_glcpp_parser_expand_token_list (parser, list);
	_token_list_append_list (expanded, list);
	glcpp_parser_lex_from (parser, expanded);
}

/* This is a helper function that's essentially part of the
 * implementation of _glcpp_parser_expand_node. It shouldn't be called
 * except for by that function.
 *
 * Returns NULL if node is a simple token with no expansion, (that is,
 * although 'node' corresponds to an identifier defined as a
 * function-like macro, it is not followed with a parenthesized
 * argument list).
 *
 * Compute the complete expansion of node (which is a function-like
 * macro) and subsequent nodes which are arguments.
 *
 * Returns the token list that results from the expansion and sets
 * *last to the last node in the list that was consumed by the
 * expansion. Specifically, *last will be set as follows: as the
 * token of the closing right parenthesis.
 */
static token_list_t *
_glcpp_parser_expand_function (glcpp_parser_t *parser,
			       token_node_t *node,
			       token_node_t **last)
			       
{
	macro_t *macro;
	const char *identifier;
	argument_list_t *arguments;
	function_status_t status;
	token_list_t *substituted;
	int parameter_index;

	identifier = node->token->value.str;

	macro = hash_table_find (parser->defines, identifier);

	assert (macro->is_function);

	arguments = _argument_list_create (parser);
	status = _arguments_parse (arguments, node, last);

	switch (status) {
	case FUNCTION_STATUS_SUCCESS:
		break;
	case FUNCTION_NOT_A_FUNCTION:
		return NULL;
	case FUNCTION_UNBALANCED_PARENTHESES:
		glcpp_error (&node->token->location, parser, "Macro %s call has unbalanced parentheses\n", identifier);
		return NULL;
	}

	/* Replace a macro defined as empty with a SPACE token. */
	if (macro->replacements == NULL) {
		talloc_free (arguments);
		return _token_list_create_with_one_space (parser);
	}

	if (! ((_argument_list_length (arguments) == 
		_string_list_length (macro->parameters)) ||
	       (_string_list_length (macro->parameters) == 0 &&
		_argument_list_length (arguments) == 1 &&
		arguments->head->argument->head == NULL)))
	{
		glcpp_error (&node->token->location, parser,
			      "Error: macro %s invoked with %d arguments (expected %d)\n",
			      identifier,
			      _argument_list_length (arguments),
			      _string_list_length (macro->parameters));
		return NULL;
	}

	/* Perform argument substitution on the replacement list. */
	substituted = _token_list_create (arguments);

	for (node = macro->replacements->head; node; node = node->next)
	{
		if (node->token->type == IDENTIFIER &&
		    _string_list_contains (macro->parameters,
					   node->token->value.str,
					   &parameter_index))
		{
			token_list_t *argument;
			argument = _argument_list_member_at (arguments,
							     parameter_index);
			/* Before substituting, we expand the argument
			 * tokens, or append a placeholder token for
			 * an empty argument. */
			if (argument->head) {
				token_list_t *expanded_argument;
				expanded_argument = _token_list_copy (parser,
								      argument);
				_glcpp_parser_expand_token_list (parser,
								 expanded_argument);
				_token_list_append_list (substituted,
							 expanded_argument);
			} else {
				token_t *new_token;

				new_token = _token_create_ival (substituted,
								PLACEHOLDER,
								PLACEHOLDER);
				_token_list_append (substituted, new_token);
			}
		} else {
			_token_list_append (substituted, node->token);
		}
	}

	/* After argument substitution, and before further expansion
	 * below, implement token pasting. */

	_token_list_trim_trailing_space (substituted);

	node = substituted->head;
	while (node)
	{
		token_node_t *next_non_space;

		/* Look ahead for a PASTE token, skipping space. */
		next_non_space = node->next;
		while (next_non_space && next_non_space->token->type == SPACE)
			next_non_space = next_non_space->next;

		if (next_non_space == NULL)
			break;

		if (next_non_space->token->type != PASTE) {
			node = next_non_space;
			continue;
		}

		/* Now find the next non-space token after the PASTE. */
		next_non_space = next_non_space->next;
		while (next_non_space && next_non_space->token->type == SPACE)
			next_non_space = next_non_space->next;

		if (next_non_space == NULL) {
			yyerror (&node->token->location, parser, "'##' cannot appear at either end of a macro expansion\n");
			return NULL;
		}

		node->token = _token_paste (parser, node->token, next_non_space->token);
		node->next = next_non_space->next;
		if (next_non_space == substituted->tail)
			substituted->tail = node;

		node = node->next;
	}

	substituted->non_space_tail = substituted->tail;

	return substituted;
}

/* Compute the complete expansion of node, (and subsequent nodes after
 * 'node' in the case that 'node' is a function-like macro and
 * subsequent nodes are arguments).
 *
 * Returns NULL if node is a simple token with no expansion.
 *
 * Otherwise, returns the token list that results from the expansion
 * and sets *last to the last node in the list that was consumed by
 * the expansion. Specifically, *last will be set as follows:
 *
 *	As 'node' in the case of object-like macro expansion.
 *
 *	As the token of the closing right parenthesis in the case of
 *	function-like macro expansion.
 */
static token_list_t *
_glcpp_parser_expand_node (glcpp_parser_t *parser,
			   token_node_t *node,
			   token_node_t **last)
{
	token_t *token = node->token;
	const char *identifier;
	macro_t *macro;

	/* We only expand identifiers */
	if (token->type != IDENTIFIER) {
		/* We change any COMMA into a COMMA_FINAL to prevent
		 * it being mistaken for an argument separator
		 * later. */
		if (token->type == ',') {
			token->type = COMMA_FINAL;
			token->value.ival = COMMA_FINAL;
		}

		return NULL;
	}

	/* Look up this identifier in the hash table. */
	identifier = token->value.str;
	macro = hash_table_find (parser->defines, identifier);

	/* Not a macro, so no expansion needed. */
	if (macro == NULL)
		return NULL;

	/* Finally, don't expand this macro if we're already actively
	 * expanding it, (to avoid infinite recursion). */
	if (_active_list_contains (parser->active, identifier)) {
		/* We change the token type here from IDENTIFIER to
		 * OTHER to prevent any future expansion of this
		 * unexpanded token. */
		char *str;
		token_list_t *expansion;
		token_t *final;

		str = talloc_strdup (parser, token->value.str);
		final = _token_create_str (parser, OTHER, str);
		expansion = _token_list_create (parser);
		_token_list_append (expansion, final);
		*last = node;
		return expansion;
	}

	if (! macro->is_function)
	{
		*last = node;

		/* Replace a macro defined as empty with a SPACE token. */
		if (macro->replacements == NULL)
			return _token_list_create_with_one_space (parser);

		return _token_list_copy (parser, macro->replacements);
	}

	return _glcpp_parser_expand_function (parser, node, last);
}

/* Push a new identifier onto the active list, returning the new list.
 *
 * Here, 'marker' is the token node that appears in the list after the
 * expansion of 'identifier'. That is, when the list iterator begins
 * examinging 'marker', then it is time to pop this node from the
 * active stack.
 */
active_list_t *
_active_list_push (active_list_t *list,
		   const char *identifier,
		   token_node_t *marker)
{
	active_list_t *node;

	node = talloc (list, active_list_t);
	node->identifier = talloc_strdup (node, identifier);
	node->marker = marker;
	node->next = list;

	return node;
}

active_list_t *
_active_list_pop (active_list_t *list)
{
	active_list_t *node = list;

	if (node == NULL)
		return NULL;

	node = list->next;
	talloc_free (list);

	return node;
}

int
_active_list_contains (active_list_t *list, const char *identifier)
{
	active_list_t *node;

	if (list == NULL)
		return 0;

	for (node = list; node; node = node->next)
		if (strcmp (node->identifier, identifier) == 0)
			return 1;

	return 0;
}

/* Walk over the token list replacing nodes with their expansion.
 * Whenever nodes are expanded the walking will walk over the new
 * nodes, continuing to expand as necessary. The results are placed in
 * 'list' itself;
 */
static void
_glcpp_parser_expand_token_list (glcpp_parser_t *parser,
				 token_list_t *list)
{
	token_node_t *node_prev;
	token_node_t *node, *last = NULL;
	token_list_t *expansion;

	if (list == NULL)
		return;

	_token_list_trim_trailing_space (list);

	node_prev = NULL;
	node = list->head;

	while (node) {

		while (parser->active && parser->active->marker == node)
			parser->active = _active_list_pop (parser->active);

		/* Find the expansion for node, which will replace all
		 * nodes from node to last, inclusive. */
		expansion = _glcpp_parser_expand_node (parser, node, &last);
		if (expansion) {
			token_node_t *n;

			for (n = node; n != last->next; n = n->next)
				while (parser->active &&
				       parser->active->marker == n)
				{
					parser->active = _active_list_pop (parser->active);
				}

			parser->active = _active_list_push (parser->active,
							    node->token->value.str,
							    last->next);
			
			/* Splice expansion into list, supporting a
			 * simple deletion if the expansion is
			 * empty. */
			if (expansion->head) {
				if (node_prev)
					node_prev->next = expansion->head;
				else
					list->head = expansion->head;
				expansion->tail->next = last->next;
				if (last == list->tail)
					list->tail = expansion->tail;
			} else {
				if (node_prev)
					node_prev->next = last->next;
				else
					list->head = last->next;
				if (last == list->tail)
					list->tail = NULL;
			}
		} else {
			node_prev = node;
		}
		node = node_prev ? node_prev->next : list->head;
	}

	while (parser->active)
		parser->active = _active_list_pop (parser->active);

	list->non_space_tail = list->tail;
}

void
_glcpp_parser_print_expanded_token_list (glcpp_parser_t *parser,
					 token_list_t *list)
{
	if (list == NULL)
		return;

	_glcpp_parser_expand_token_list (parser, list);

	_token_list_trim_trailing_space (list);

	_token_list_print (parser, list);
}

static void
_check_for_reserved_macro_name (glcpp_parser_t *parser, YYLTYPE *loc,
				const char *identifier)
{
	/* According to the GLSL specification, macro names starting with "__"
	 * or "GL_" are reserved for future use.  So, don't allow them.
	 */
	if (strncmp(identifier, "__", 2) == 0) {
		glcpp_error (loc, parser, "Macro names starting with \"__\" are reserved.\n");
	}
	if (strncmp(identifier, "GL_", 3) == 0) {
		glcpp_error (loc, parser, "Macro names starting with \"GL_\" are reserved.\n");
	}
}

void
_define_object_macro (glcpp_parser_t *parser,
		      YYLTYPE *loc,
		      const char *identifier,
		      token_list_t *replacements)
{
	macro_t *macro;

	if (loc != NULL)
		_check_for_reserved_macro_name(parser, loc, identifier);

	macro = talloc (parser, macro_t);

	macro->is_function = 0;
	macro->parameters = NULL;
	macro->identifier = talloc_strdup (macro, identifier);
	macro->replacements = talloc_steal (macro, replacements);

	hash_table_insert (parser->defines, macro, identifier);
}

void
_define_function_macro (glcpp_parser_t *parser,
			YYLTYPE *loc,
			const char *identifier,
			string_list_t *parameters,
			token_list_t *replacements)
{
	macro_t *macro;

	_check_for_reserved_macro_name(parser, loc, identifier);

	macro = talloc (parser, macro_t);

	macro->is_function = 1;
	macro->parameters = talloc_steal (macro, parameters);
	macro->identifier = talloc_strdup (macro, identifier);
	macro->replacements = talloc_steal (macro, replacements);

	hash_table_insert (parser->defines, macro, identifier);
}

static int
glcpp_parser_lex (YYSTYPE *yylval, YYLTYPE *yylloc, glcpp_parser_t *parser)
{
	token_node_t *node;
	int ret;

	if (parser->lex_from_list == NULL) {
		ret = glcpp_lex (yylval, yylloc, parser->scanner);

		/* XXX: This ugly block of code exists for the sole
		 * purpose of converting a NEWLINE token into a SPACE
		 * token, but only in the case where we have seen a
		 * function-like macro name, but have not yet seen its
		 * closing parenthesis.
		 *
		 * There's perhaps a more compact way to do this with
		 * mid-rule actions in the grammar.
		 *
		 * I'm definitely not pleased with the complexity of
		 * this code here.
		 */
		if (parser->newline_as_space)
		{
			if (ret == '(') {
				parser->paren_count++;
			} else if (ret == ')') {
				parser->paren_count--;
				if (parser->paren_count == 0)
					parser->newline_as_space = 0;
			} else if (ret == NEWLINE) {
				ret = SPACE;
			} else if (ret != SPACE) {
				if (parser->paren_count == 0)
					parser->newline_as_space = 0;
			}
		}
		else if (parser->in_control_line)
		{
			if (ret == NEWLINE)
				parser->in_control_line = 0;
		}
		else if (ret == HASH_DEFINE_OBJ || ret == HASH_DEFINE_FUNC ||
			   ret == HASH_UNDEF || ret == HASH_IF ||
			   ret == HASH_IFDEF || ret == HASH_IFNDEF ||
			   ret == HASH_ELIF || ret == HASH_ELSE ||
			   ret == HASH_ENDIF || ret == HASH)
		{
			parser->in_control_line = 1;
		}
		else if (ret == IDENTIFIER)
		{
			macro_t *macro;
			macro = hash_table_find (parser->defines,
						 yylval->str);
			if (macro && macro->is_function) {
				parser->newline_as_space = 1;
				parser->paren_count = 0;
			}
		}

		return ret;
	}

	node = parser->lex_from_node;

	if (node == NULL) {
		talloc_free (parser->lex_from_list);
		parser->lex_from_list = NULL;
		return NEWLINE;
	}

	*yylval = node->token->value;
	ret = node->token->type;

	parser->lex_from_node = node->next;

	return ret;
}

static void
glcpp_parser_lex_from (glcpp_parser_t *parser, token_list_t *list)
{
	token_node_t *node;

	assert (parser->lex_from_list == NULL);

	/* Copy list, eliminating any space tokens. */
	parser->lex_from_list = _token_list_create (parser);

	for (node = list->head; node; node = node->next) {
		if (node->token->type == SPACE)
			continue;
		_token_list_append (parser->lex_from_list, node->token);
	}

	talloc_free (list);

	parser->lex_from_node = parser->lex_from_list->head;

	/* It's possible the list consisted of nothing but whitespace. */
	if (parser->lex_from_node == NULL) {
		talloc_free (parser->lex_from_list);
		parser->lex_from_list = NULL;
	}
}

static void
_glcpp_parser_skip_stack_push_if (glcpp_parser_t *parser, YYLTYPE *loc,
				  int condition)
{
	skip_type_t current = SKIP_NO_SKIP;
	skip_node_t *node;

	if (parser->skip_stack)
		current = parser->skip_stack->type;

	node = talloc (parser, skip_node_t);
	node->loc = *loc;

	if (current == SKIP_NO_SKIP) {
		if (condition)
			node->type = SKIP_NO_SKIP;
		else
			node->type = SKIP_TO_ELSE;
	} else {
		node->type = SKIP_TO_ENDIF;
	}

	node->next = parser->skip_stack;
	parser->skip_stack = node;
}

static void
_glcpp_parser_skip_stack_change_if (glcpp_parser_t *parser, YYLTYPE *loc,
				    const char *type, int condition)
{
	if (parser->skip_stack == NULL) {
		glcpp_error (loc, parser, "%s without #if\n", type);
		return;
	}

	if (parser->skip_stack->type == SKIP_TO_ELSE) {
		if (condition)
			parser->skip_stack->type = SKIP_NO_SKIP;
	} else {
		parser->skip_stack->type = SKIP_TO_ENDIF;
	}
}

static void
_glcpp_parser_skip_stack_pop (glcpp_parser_t *parser, YYLTYPE *loc)
{
	skip_node_t *node;

	if (parser->skip_stack == NULL) {
		glcpp_error (loc, parser, "#endif without #if\n");
		return;
	}

	node = parser->skip_stack;
	parser->skip_stack = node->next;
	talloc_free (node);
}
