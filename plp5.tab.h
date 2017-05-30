/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
