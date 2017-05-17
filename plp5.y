%token boolean_
%token int_   
%token double_
%token main_ 
%token system_   
%token out_
%token in_
%token println_
%token print_
%token string_
%token class_
%token import_
%token new_
%token public_
%token static_
%token void_
%token scanner_
%token nextInt_
%token nextDouble_
%token if_
%token else_
%token while_
%token true_
%token false_
%token coma_
%token pyc_   
%token punto_
%token pari_ 
%token pard_   
%token relop_
%token addop_
%token mulop_
%token asig_
%token cori_
%token cord_
%token llavei_
%token llaved_
%token and_
%token or_
%token not_
%token nentero
%token nreal
%token id

%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#include "comun.h"
// variables y funciones del A. Léxico
extern int ncol,nlin,findefichero;
int nTempMin = 16000;
int nTempMax = 16384;

int nTempActual = 16000;
//extern int tmp;
extern int yylex();
extern char *yytext;
extern FILE *yyin;


int yyerror(char *s);


const int ENTERO=1;
const int REAL=2;
const int BOOL_ = 3;
const int FUNCION=4;
const int CLASE=5;
const int VARIABLE=6;

string operador, s1, s2;  // string auxiliares

typedef struct simbolo_t
	{
	   std::string lexema;
	   int tipoSim;
	   int tipo;
	   bool es_var;
	   std::string trad;
	   int lin,col;
	}simbolo;

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

	void add_simbolo(const char* lexema, const int& tipoS,const int&tipo, const bool& es_var, const std::string& trad, int nlin, int ncol);
	simbolo_t* buscar_simbolo(const char* lexema); 
	bool lexema_existe(const char* lexema);
	void print_tabla_simbolos();
	void crear_ambito(const char* nombre);
	void destruir_ambito_actual();
	void destroy();
	int newTemp();
	// Variables globales
	struct tabla_simbolos_t* ambito;

%}

%%
//AQUI LAS REGLAS
S : Import class_ {
							int tk = yylex();
                           if (tk != 0) yyerror("");
                           cout << $2.cod << endl;
};

Import : Import import_ SecImp pyc_ {
	
}
	    | {

	   };

SecImp : SecImp punto_ id {
	
}
	    | SecImp punto_ scanner_ {

	   }
	    | id {

	   };

Class : public_ class_ id llavei_ Main llaved_ {
	
};

Main : public_ static_ void_ main_ pari_ string_ cori_ cord_ id pard_ Bloque  {
	
};

Tipo : int_ {

		int tmp = newTemp();
		$$.dir = tmp;
		$$.tipo = ENTERO;
		$$.nlin = nlin;
		$$.ncol = ncol;
		$$.lexema = "entero";

	}
	  | double_ {
		
		int tmp = newTemp();
		$$.dir = tmp;
		$$.tipo = REAL;
		$$.nlin = nlin;
		$$.ncol = ncol;
		$$.lexema = "real";
	 }
	  | boolean_ {

	  	int tmp = newTemp();
		$$.dir = tmp;
		$$.tipo = BOOL_;
		$$.nlin = nlin;
		$$.ncol = ncol;
		$$.lexema = "bool";

	 };

Bloque : llavei_ BDecl SeqInstr llaved_ {
	
};

BDecl : BDecl DVar {
	
}
	   | {

	  };

DVar : Tipo LIdent pyc_ {
	
}
	  | Tipo DimSN id asig_ new_ Tipo Dimensiones pyc_ {

	 }
	  | scanner_ id asig_ new_ scanner_ pari_ system_ punto_ in_ pard_ pyc_ {

	 };

DimSN : DimSN cori_ cord_ {
	
}
	   | cori_ cord_ {

	  };

Dimensiones : cori_ nentero cord_ Dimensiones {
	
}
			 | cori_ nentero cord_ {

			};

LIdent : LIdent coma_ Variable {
	
}
	   | Variable {

	   };

Variable : id {
	
};

SeqInstr : SeqInstr Instr {
	
}
		  | {

		 };

Instr : pyc_ {
	
}
	  | Bloque {

	  }
	  | Ref asig_ Expr pyc_ {

	  }
	  | system_ punto_ out_ punto_ println_ pari_ Expr pard_ pyc_ {

	  }
	  | system_ punto_ out_ punto_ print_ pari_ Expr pard_ pyc_ {

	  }
	  | if_ pari_ Expr pard_ Instr {

	  }
	  | if_ pari_ Expr pard_ Instr else_ Instr {

	  }
	  | while_ pari_ Expr pard_ Instr {

	  };

Expr : Expr or_ EConj {
	
}
	 | EConj {

	 };

EConj : EConj and_ ERel {
	
}
	  | ERel {

	  };

ERel : Esimple relop_ Esimple {
	
}
	 | Esimple {

	 };

Esimple : Esimple addop_ Term {
	
}
		| Term {

		};

Term : Term mulop_ Factor {
	
}
	 | Factor {

	 };

Factor : Ref {
	
}
	   | id punto_ nextInt_ pari_ pard_ {

	   }
	   | id punto_ nextDouble_ pari_ pard_ {

	   }
	   | nentero {

	   }
	   | nreal {

	   }
	   | true_ {

	   }
	   | false_ {

	   }
	   | pari_ Expr pard_ {

	   }
	   | not_ Factor {

	   }
	   | pari_ Tipo pard_ Expr {

	   };

Ref : id {
	
}
	 | Ref cori_ Esimple cord_ {

	};
	
%%

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

void add_simbolo(const char* lexema, const int& tipoS,const int& tipo, const bool& es_var, const std::string& trad, int nlin, int ncol)
{	
	simbolo_t s;
	s.lexema = string(lexema);
	s.tipoSim = tipoS;
	s.tipo = tipo;
	s.es_var = es_var;
	s.trad = trad;
	s.lin = nlin;
	s.col = ncol;
	vector<simbolo_t>::iterator begin_it = ambito->simbolos.begin();
	vector<simbolo_t>::iterator end_it = ambito->simbolos.end();
	vector<simbolo_t>::iterator it = std::find_if(begin_it,end_it, find_simbolo(lexema)); 
	if(it == end_it)
	{
		ambito->simbolos.push_back(s);
	}else{
		//msgError(ERRSEM_LEXEMAEXISTE, nlin, ncol, lexema);
	}
	
}

int newTemp(){

	nTempActual ++; 
	if(nTempActual >= nTempMax)
		msgError(ERR_MAXTMP, nlin, ncol, "") ;
	else return nTempActual;
}

simbolo_t* buscar_simbolo(const char* lexema)
{
	simbolo_t *s = (simbolo_t*)malloc(sizeof(struct simbolo_t));
	bool encontrado = false;
	tabla_simbolos_t* actual = ambito;
	vector<simbolo_t>::iterator begin_it, end_it, it;	
	begin_it = actual->simbolos.begin();
	end_it = actual->simbolos.end();
	while(!encontrado)
	{
		it = std::find_if(begin_it, end_it, find_simbolo(std::string(lexema))); 
		if(it != end_it)
		{
			encontrado = true;
			s = &(*it);
		}else if(actual->ts_padre != NULL)
		{
			actual = actual->ts_padre;
			begin_it = actual->simbolos.begin();
			end_it = actual->simbolos.end();
		}else{
			s = NULL;
			break;
		}
	}
	return s;
} 

bool lexema_existe(const char* lexema)
{
	bool existe = false;
	tabla_simbolos_t* actual = ambito;
	vector<simbolo_t>::iterator begin_it, end_it, it;
	begin_it = actual->simbolos.begin();
	end_it = actual->simbolos.end();
	while(!existe)
	{
		it = std::find_if(begin_it, end_it, find_simbolo(std::string(lexema))); 
		if(it != end_it)
		{
			existe = true;
		}else if(actual->ts_padre != NULL)
		{
			actual = actual->ts_padre;
			begin_it = actual->simbolos.begin();
			end_it = actual->simbolos.end();
		}else{
			break;
		}
	}
	return existe;
}

void print_tabla_simbolos()
{
	struct tabla_simbolos_t *actual = ambito;
	std::cout << "############ TABLA DE SIMBOLOS ############\n";
	while(actual != NULL)
	{		
		std::cout << actual->nombre << ": ";
		for(unsigned int i=0;i<actual->simbolos.size();i++)
		{
			if(actual->simbolos[i].tipo == ENTERO){
				std::cout << "Integer ";
			}else if(actual->simbolos[i].tipo == REAL){
				std::cout << "Double ";
			}
			std::cout << actual->simbolos[i].lexema << "(" << actual->simbolos[i].trad << ")";
			std::cout << ", ";
		}
		std::cout << "\n";
		if(actual->ts_padre != NULL)
		{
			actual = actual->ts_padre;
		}else{
			break;
		}
	}
	std::cout << "###########################################\n";
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