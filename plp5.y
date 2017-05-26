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


int yyerror(char *s);


int ptr_mem = 0;
int ptr_mem_temp = MAX_MEM+1;
int ptr_label = 0;

string operador, s1, s2;  // string auxiliares

typedef struct simbolo_t {
	string 	lexema;
	int 	dir;
	bool 	esArray;
	int 	idTipo;
	int 	lin,col;
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
void nuevoSimbolo(char* lexema,int dir,bool esArray, int idTipo,int nlin,int ncol);
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
void nuevoTipo(int tam,int tipo);

bool esBase(int tipo);

int buscarDir(const char* lexema);

%}

%%
//AQUI LAS REGLAS
S : Import Class {
	$$.cod = $2.cod;

			int tk = yylex();
            if (tk != 0) yyerror("");
            cout << $2.cod << endl;
};

Import : Import import_ SecImp pyc_ {
	$$.cod = $1.cod + $3.cod;
	//No hace nada?
}
	    | {
	//No hace nada?
	   };

SecImp : SecImp punto_ id {
		//No hace nada?
}
	    | SecImp punto_ scanner_ {
	    	//$$.cod = $1.cod;
	//No hace nada?
	   }
	    | id {
	//No hace nada?
	   };

Class : public_ class_ id llavei_ Main llaved_ {
		//No hace nada?
	$$.cod = $5.cod;
};

Main : public_ static_ void_ main_ pari_ string_ cori_ cord_ id pard_ Bloque  {
		//No hace nada?
	$$.cod = $11.cod;
};

Tipo : int_ {
		int tmp = NTemp();
		$$.dir = tmp;
		$$.nlin = nlin;
		$$.ncol = ncol;
		$$.tipo = ENTERO;

	}
	  | double_ {
		
		int tmp = NTemp();
		$$.dir = tmp;
		$$.tipo = REAL;
		$$.nlin = nlin;
		$$.ncol = ncol;
	 }
	  | boolean_ {

	  	int tmp = NTemp();
		$$.dir = tmp;
		$$.tipo = BOOLEANO;
		$$.nlin = nlin;
		$$.ncol = ncol;

	 };

Bloque : llavei_ BDecl SeqInstr llaved_ {
	
	$$.cod = $1.cod;
};

BDecl : BDecl DVar {
	$$.cod = $2.cod;
}
	   | {
	  
	  };

DVar : Tipo {$$.tipo = $1.tipo; } LIdent pyc_ {

    int tmp = NTemp();
    $$.dir = tmp;
    $$.tipo = $1.tipo;
    
    }
    | Tipo DimSN id asig_ new_ Tipo {$$.tipo = $1.tipo;} Dimensiones pyc_ {

      if(esBase($8.tipo))
      {
        int tmp = NTemp();
        $$.dir = tmp;
        $$.tipo = $1.tipo;
        //nuevoSimbolo($3.lexema,$1.tipo, tmp, true, $8.tipo, nlin, ncol-strlen(yytext));

    }else
    {
      msgError(ERRDIM, nlin, ncol, "");
      }

   }
    | scanner_ id asig_ new_ scanner_ pari_ system_ punto_ in_ pard_ pyc_ {

   };

DimSN : DimSN cori_ cord_ {
  
}
     | cori_ cord_ {

    };

Dimensiones : cori_ nentero cord_ Dimensiones {
    
    int tmp = NTemp();
    $$.dir = tmp;
    $$.tipo = $0.tipo;
    //No hace falta cod porque es una declaración, las operacioens de cod se harán cuando se acceda a lectura de los arrays. NOP?
    //nuevoTipo($2.lexema, $0.tipo);
}
       | cori_ nentero cord_ {
        int tmp = NTemp();
        $$.dir = tmp;
        $$.tipo = $0.tipo;
  //      nuevoTipo($2.lexema, $0.tipo);
      };
LIdent : {$$.tipo = $0.tipo;} LIdent coma_  {$$.tipo = $0.tipo;} Variable {

	int tmp = NTemp();
	$$.dir = tmp;
	$$.tipo = $0.tipo ;
	$$.cod = $2.cod + $5.cod;
	}
	   | Variable {
	   	$$ = $1;

	   };

Variable : {$$.tipo = $0.tipo;} id {

	int tmp = NTemp();
	$$.dir = tmp;
	$$.cod = "mov #";
	$$.cod += tmp;
	$$.cod += "A";
	$$.tipo = $0.tipo;
	nuevoSimbolo($2.lexema, tmp, false, $0.tipo,nlin,ncol);
};

SeqInstr : SeqInstr Instr {
	$$.cod = $1.cod + $2.cod;
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

	  	$$.cod = $3.cod + "\nmov " + IntToString($3.dir) + "A\njz " + IntToString($5.dir) + "\n" + $5.cod;
	  }
	  | if_ pari_ Expr pard_ Instr else_ Instr {

	  	$$.cod = $3.cod + "\nmov " + IntToString($3.dir) + "A\njz " + IntToString($5.dir) + "\n" + $5.cod + "\njmp " + IntToString($7.dir) + $7.cod;
	  }
	  | while_ pari_ Expr pard_ Instr {
	  	$$.cod = $3.cod + "mov " + IntToString($3.dir) + " A\njz " + IntToString($5.dir) + "\n" + $5.cod + "\njmp " + IntToString($3.dir);
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
	   		int tmp 	= NTemp();
	   		$$.tipo = ENTERO;
	   		$$.dir 	= tmp;
	   		$$.cod 	= $1.lexema;
	   }
	   | nreal {
	   		int tmp 	= NTemp();
	   		$$.tipo = REAL;
	   		$$.dir 	= tmp;
	   		$$.cod 	= $1.lexema;
	   }
	   | true_ {
	   		int tmp 	= NTemp();
	   		$$.tipo = BOOLEANO;
	   		$$.dir 	= tmp;
	   		$$.cod 	= "0";
	   }
	   | false_ {
	   		int tmp = NTemp();
	   		$$.tipo = BOOLEANO;
	   		$$.dir 	= tmp;
	   		$$.cod 	= "1";
	   }
	   | pari_ Expr pard_ {

	   }
	   | not_ Factor {

	   }
	   | pari_ Tipo pard_ Expr {

	   };

Ref : id {
  
  simbolo_t s;
  $$.tipo = buscarTipoSimbolo($1.lexema);
  int tmp = NTemp();
  $$.dir = tmp;
  $$.dBase = buscarDir($1.lexema);
  $$.cod = "mov #0 " + tmp;

}
   | Ref cori_ {if(esBase($1.tipo)) msgError(1,1,1,"");}
    Esimple cord_ {
      if(!esBase($4.tipo)){ msgError(ERR_EXP_ENT,1,1,"");}
      else{
        $$.tipo = tipoBase($1.tipo);
        int tmp = NTemp();
        $$.dir = tmp;
        $$.dBase = $1.dBase;
        //$$.cod = $1.cod + $4.cod + "mov #" + tamTipo($1.tipo) + "\naddi " + $4.dir + "\nmov A " + tmp;
      }

  };
	
%%
bool esBase(int tipo)
{
  if(tipo <= 3)
    return true;
  else return false;
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

//void nuevoSimbolo(simbolo_t& simbolo, const int& tipo) { 
void nuevoSimbolo(char* lexema, int dir, bool esArray, int idTipo, int lin, int col) {
  if(!existeSimbolo(lexema))  // Si no existe
  {
    simbolo_t s;
    tipo_t obj_tipo;
    buscarTipo(idTipo, obj_tipo);

    s.lexema    = std::string(lexema);
    s.lin       = lin;
    s.col       = col;
    s.dir       = ptr_mem;
    s.idTipo  	= idTipo;
    s.esArray  	= esArray;
    
	    if(!s.esArray) {
	      switch(idTipo) {
	        case ENTERO: 
	          s.idTipo = 0;
	          break;
	        case REAL:
	          s.idTipo = 1;
	          break;
	        case BOOLEANO:
	          s.idTipo = 2;
	          break;
	        case SCANNER:
	          s.idTipo = 3;
	          break;
	      }     
	    }


    ptr_mem += obj_tipo.size;

    if(ptr_mem > MAX_MEM)   // Si no cabe en memoria..
      msgError(ERR_NOCABE, lin, col, lexema);    // error, memoria llena  

    simbolos.push_back(s);
  }
  else
    msgError(ERRYADECL, lin, col, lexema);   // Error, simbolo ya declarado
}

bool existeSimbolo(const char* simbolo) {
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

int getDir() {
	return 1;
}

int NTemp(){
	nTempActual ++; 
	if(nTempActual >= nTempMax)
		msgError(ERR_MAXTMP, nlin, ncol, "") ;
	else return nTempActual;
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

		  return true;
		}
	}
	return false;
}


void inicializarTablaTipos() {
  tipo_t t;
  tabla_tipos.clear();

  t.tipo      = ENTERO;
  t.size      = TAM_ENTERO;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);

  t.tipo      = REAL;
  t.size      = TAM_REAL;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);

  t.tipo      = BOOLEANO;
  t.size      = TAM_BOOLEANO;
  t.tipo_base = -1;
  tabla_tipos.push_back(t);

  t.tipo      = SCANNER;
  t.size      = TAM_SCANNER;
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

/* void print_tabla_simbolos() {
  std::cout << "############ TABLA DE SIMBOLOS ############\n";
  std::vector<simbolo_t>::iterator it_simbolos;
  int pos = 0;
  for(it_simbolos = simbolos.begin(); it_simbolos != simbolos.end(); ++it_simbolos)
  {
    cout << "Pos.: " << pos << 
    "\tSimbolo: " << it_simbolos->lexema << 
    "\tTipo: " << it_simbolos->tipo << 
    "\tIdx.Tipo: " << it_simbolos->idTipo << 
    "\tDir.: " << it_simbolos->dir <<
    "\tArray? " << it_simbolos->esArray << "\n";
    ++pos;
  }
  std::cout << "###########################################\n";
} */

void nuevoTipo(int tam,int tipo_base) {
  tipo_t t;
  switch(tipo_base)
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
  }
  t.tipo    = ARRAY;
  t.size    = tam;
  tabla_tipos.push_back(t);
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