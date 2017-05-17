D    [0-9]
L    [a-zA-Z]
LD   [0-9a-zA-Z]

%{
#include <string.h> 
#include <string>
#include <iostream>

using namespace std;

#include "comun.h"
#include "plp5.tab.h"

int ncol = 1,
    nlin = 1;

int findefichero = 0;

int ret(int token);  
// función que actualiza 'nlin' y 'ncol' y devuelve el token

void msgError(int nerror, int nlin,int ncol,const char *s);
// función para producir mensajes de error

%}

%x COMENTARIO

%%
%{
/* codigo local */
%}

" "                {ncol++;}
[\t]               {ncol++;}
[\n]               {nlin++;ncol=1;}
"//"(.)*           {; /* comentarios de una linea, no hacer nada */} 

"boolean"         {return ret(boolean_);}
"int"             {return ret(int_);}
"double"          {return ret(double_);}
"main"            {return ret(main_);}
"System"          {return ret(system_);}
"out"             {return ret(out_);}
"in"              {return ret(in_);}
"println"         {return ret(println_);}
"print"           {return ret(print_);}
"String"          {return ret(string_);}
"class"           {return ret(class_);}
"import"          {return ret(import_);}
"new"             {return ret(new_);}
"public"          {return ret(public_);}
"static"          {return ret(static_);}
"void"            {return ret(void_);}
"Scanner"         {return ret(scanner_);}
"nextInt"         {return ret(nextInt_);}
"nextDouble"      {return ret(nextDouble_);}
"if"              {return ret(if_);}
"else"            {return ret(else_);}
"while"           {return ret(while_);}
"true"            {return ret(true_);}
"false"           {return ret(false_);}

        /* Las palabras reservadas deben aparecer antes de la regla que
          reconoce los identificadores, para evitar que sean reconocidas
          como identificadores en lugar de como palabras reservadas */            

","                {return ret(coma_);}
";"                {return ret(pyc_);}
"."                {return ret(punto_);}
"("                {return ret(pari_);}
")"                {return ret(pard_);}
"=="               {return ret(relop_);}
"!="               {return ret(relop_);}
"<"                {return ret(relop_);}
"<="               {return ret(relop_);}
">"                {return ret(relop_);}
">="               {return ret(relop_);}
"+"                {return ret(addop_);}
"-"                {return ret(addop_);}
"*"                {return ret(mulop_);}
"/"                {return ret(mulop_);}
"="                {return ret(asig_);}
"["                {return ret(cori_);}
"]"                {return ret(cord_);}
"{"                {return ret(llavei_);}
"}"                {return ret(llaved_);}
"&&"               {return ret(and_);}
"||"               {return ret(or_);}
"!"                {return ret(not_);}

{L}({LD})*         {return ret(id);}
{D}+               {return ret(nentero);}
{D}+(\.){D}+       {return ret(nreal);}
.                  {msgError(ERRLEXICO,nlin,ncol,yytext);}

%%

int yywrap(void) {findefichero=1; return 1;} /* para no tener que linkar con la
                                libreria del lex */


int ret(int token)
{
   yylval.lexema=strdup(yytext);
   yylval.nlin=nlin;
   yylval.ncol=ncol;
   ncol+=(strlen(yytext));
   return(token);
}
