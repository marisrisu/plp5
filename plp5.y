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
%}

%%
//AQUI LAS REGLAS
S : Import Class {
	if(DEBUG) std::cout << " - Leído S...\n";
	$$.cod =$2.cod + "halt";

			int tk = yylex();
            if (tk != 0) yyerror("");
            cout << $$.cod << endl;
};

Import : Import import_ SecImp pyc_ {
	if(DEBUG) std::cout << " - Leído Import 1...\n";
	$$.cod = $1.cod + $3.cod;
	//No hace nada?
}
	    | {
	//No hace nada?
	    	if(DEBUG) std::cout << " - Leído Import 2...\n";
	   };

SecImp : SecImp punto_ id {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído SecImp 1...\n";
	}
	    | SecImp punto_ scanner_ {
		if(DEBUG) std::cout << " - Leído SecImp 2...\n";
	    	//$$.cod = $1.cod;
	//No hace nada?
	   }
	    | id {
		if(DEBUG) std::cout << " - Leído SecImp 3...\n";
	//No hace nada?
	   };

Class : public_ class_ id llavei_ Main llaved_ {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído Class...\n";
		$$.cod = $5.cod;
};

Main : public_ static_ void_ main_ pari_ string_ cori_ cord_ id pard_ Bloque  {
		//No hace nada?
		if(DEBUG) std::cout << " - Leído Main...\n";
		$$.cod = $11.cod;
};

Tipo : int_ {
		if(DEBUG) std::cout << " - Leído Tipo 1...\n";
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.nlin = nlin;
		$$.ncol = ncol;
		$$.tipo = ENTERO;

	}
	  | double_ {
		if(DEBUG) std::cout << " - Leído Tipo 2...\n";
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.tipo = REAL;
		$$.nlin = nlin;
		$$.ncol = ncol;
	 }
	  | boolean_ {
		if(DEBUG) std::cout << " - Leído Tipo 3...\n";
	  	ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.tipo = BOOLEANO;
		$$.nlin = nlin;
		$$.ncol = ncol;

	 };

Bloque : llavei_ { crear_ambito(" "); }  BDecl SeqInstr { destruir_ambito_actual(); } llaved_ {
		if(DEBUG) std::cout << " - Leído Bloque...\n";
		$$.cod = $4.cod;
};

BDecl : BDecl DVar {
		if(DEBUG) std::cout << " - Leído BDecl 1...\n";

}
	   | {
		if(DEBUG) std::cout << " - Leído BDecl 2...\n";
	  };

DVar : Tipo {$$.tipo = $1.tipo;} LIdent pyc_ {
		if(DEBUG) std::cout << " - Leído DVar 1...\n";
	    ptr_tmp = NTemp();
	    $$.dir = ptr_tmp;
	    $$.tipo = $1.tipo;

    }
    | Tipo DimSN id asig_ new_ Tipo {if($1.tipo != $6.tipo) msgError(ERR_TIPOSDECLARRAY, nlin,ncol,$1.lexema); $$.tipo = $1.tipo;} Dimensiones pyc_ {
		if(DEBUG) std::cout << " - Leído DVar 2...\n";
		if($2.dir != $8.dBase) msgError(ERR_DIMSDECLARRAY,nlin,ncol, $3.lexema);
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.tipo = $1.tipo;
		nuevoSimbolo($3.lexema, true, $8.tipo, $3.nlin, $3.ncol);


   }
    | scanner_ id asig_ new_ scanner_ pari_ system_ punto_ in_ pard_ pyc_ {
		if(DEBUG) std::cout << " - Leído DVar 3...\n";
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.tipo = SCANNER;
		nuevoSimbolo($2.lexema, false, SCANNER, nlin, ncol);

   };

DimSN : DimSN cori_ cord_ {
		if(DEBUG) std::cout << " - Leído DimSN 1...\n";
		$$.dir +=1;
}
     | cori_ cord_ {
		if(DEBUG) std::cout << " - Leído DimSN 2...\n";
		$$.dir = 1;
    };

Dimensiones : cori_ nentero cord_ {$$.dBase =1; $$.tipo = $0.tipo; } Dimensiones {
		if(DEBUG) std::cout << " - Leído Dimensiones 1...\n";
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.tipo = nuevoTipo(std::atoi($2.lexema), $5.tipo);
		$$.dBase =$5.dBase + 1;

	}
       | cori_ nentero cord_ {
		if(DEBUG) std::cout << " - Leído Dimensiones 2...\n";
        ptr_tmp = NTemp();
        $$.dir = ptr_tmp;
        $$.tipo = nuevoTipo(std::atoi($2.lexema), $0.tipo);
        $$.dBase = 1;

      };


LIdent : LIdent coma_ Variable {

		if(DEBUG) std::cout << " - Leído LIdent 1...\n";
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.lexema = $3.lexema;
		nuevoSimbolo($3.lexema,false, $0.tipo,$3.nlin,$3.ncol );

	}
	| {$$.tipo = $0.tipo;} Variable {
		if(DEBUG) std::cout << " - Leído LIdent 2...\n";
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.lexema = $2.lexema;
		nuevoSimbolo($$.lexema, false, $0.tipo, $2.nlin,$2.ncol);
	};

Variable : id {
	if(DEBUG) std::cout << " - Leído Variable...\n";

	ptr_tmp = NTemp();
	$$.dir = ptr_tmp;
	$$.lexema = $1.lexema;
};

SeqInstr : SeqInstr Instr {
		if(DEBUG) std::cout << " - Leído SeqInstr 1...\n";
		$$.cod = $1.cod + $2.cod;
		
	}
	| {
		if(DEBUG) std::cout << " - Leído SeqInstr 2...\n";
	};

Instr : pyc_ {
		if(DEBUG) std::cout << " - Leído Instr 1...\n";	

	}
	| Bloque {
		if(DEBUG) std::cout << " - Leído Instr 2...\n";	
		$$.dir = $1.dir;
		$$.cod = $1.cod;
		$$.tipo = $1.tipo;
	}
	| Ref asig_ Expr pyc_ {
		if(DEBUG) std::cout << " - Leído Instr 3...\n";	
		if($1.dBase == ENTERO && $3.tipo == REAL)	msgError(ERR_TIPOSASIG,nlin,ncol,"");
		if($1.dBase == SCANNER)						msgError(ERR_SCVAR, nlin,ncol,$1.lexema);
		else{
			$$.cod = $3.cod;
			if($1.tipo == REAL && $3.tipo == ENTERO)
				$$.cod += "itor\n";
			$$.cod += "mov " + IntToString($3.dir) + " " + IntToString($1.dir) + "\n";
			//$$.cod += $1.cod;
			$$.dir = $3.dir;
		}
	}
	| system_ punto_ out_ punto_ println_ pari_ Expr pard_ pyc_ {
		if(DEBUG) std::cout << " - Leído Instr 4...\n";	
		$$.tipo = $7.tipo;
		$$.dir = $7.dir;
		if($7.tipo == ENTERO)
			$$.cod = $7.cod
					+ "mov " + IntToString($7.dir) + " A\n"
					+ "wri A \n";
		else
			$$.cod = $7.cod
					+ "mov " + IntToString($7.dir) + " A\n"
					+ "wrr A \n";

		$$.cod += "wrl\n";
	}
	| system_ punto_ out_ punto_ print_ pari_ Expr pard_ pyc_ {
		if(DEBUG) std::cout << " - Leído Instr 5...\n";	
		$$.tipo = $7.tipo;
		$$.dir = $7.dir;
		if($7.tipo == ENTERO)
			$$.cod = $7.cod
					+ "mov " + IntToString($7.dir) + " A\n"
					+ "wri A \n";
		else
			$$.cod = $7.cod
					+ "mov " + IntToString($7.dir) + " A\n"
					+"wrr A \n";
	}
	| if_ pari_ Expr pard_ Instr {
		if(DEBUG) std::cout << " - Leído Instr 6...\n";	
		$$.cod = $3.cod;
		$$.cod += "mov " + IntToString($3.dir) + " A\n";
		$$.cod += "jz L" + IntToString(++ptr_label) + "\n";
		$$.cod += $5.cod;
		$$.cod += "L" + IntToString(ptr_label) + "\n";
		
	}
	| if_ pari_ Expr pard_ Instr else_ Instr {
		if(DEBUG) std::cout << " - Leído Instr 7...\n";	
		$$.cod = $3.cod;
		$$.cod += "mov " + IntToString($3.dir) + " A\n";
		$$.cod += "jz L" + IntToString(++ptr_label) + "\n";
		$$.cod += $5.cod;
		$$.cod += "jmp L" + IntToString(++ptr_label) +"\n";
		$$.cod += "L" + IntToString(ptr_label - 1) + " " + $7.cod;
		$$.cod += "L" + IntToString(ptr_label) + "\n";
	}
	| while_ pari_ Expr pard_ Instr {
		if(DEBUG) std::cout << " - Leído Instr 8...\n";	
		$$.cod = "L"+ IntToString(++ptr_label) + " " + $3.cod;
		$$.cod += "mov " + IntToString($3.dir) + " A\n";
		$$.cod += "jz L" + IntToString(++ptr_label) + "\n";
		$$.cod += $5.cod;
		$$.cod += "jmp L" + IntToString(ptr_label - 1) +"\n";
		$$.cod += "L" + IntToString(ptr_label) + "\n";
};

Expr : Expr or_ { if($1.tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, $2.lexema); } EConj {
		if(DEBUG) std::cout << " - Leído Expr 1...\n";	
		if($4.tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, $2.lexema);
		$$.tipo = BOOLEANO;
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.cod = $4.cod
					+ "mov " + IntToString($4.dir) + " A\n"
					+ "ori " + IntToString($1.dir) + "\n"
					+ "mov A " + IntToString(ptr_tmp) + "\n";
	}
	| EConj {
		if(DEBUG) std::cout << " - Leído Expr 2...\n";
		$$.tipo 	= $1.tipo;
		$$.dir 		= $1.dir;
		$$.cod 		= $1.cod;
		$$.dBase 	= $1.dBase;
		$$.esArray = $1.esArray;
	};

EConj : EConj and_ { if($1.tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, $2.lexema); } ERel {
		if(DEBUG) std::cout << " - Leído EConj 1...\n";
		if($4.tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, $2.lexema);
		$$.tipo = BOOLEANO;
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.cod = $4.cod
					+ "mov " + IntToString($4.dir) + " A\n"
					+ "andi " + IntToString($1.dir) + "\n"
					+ "mov A " + IntToString(ptr_tmp) + "\n";
	}
	| ERel {
		if(DEBUG) std::cout << " - Leído EConj 2...\n";
		$$.tipo 	= $1.tipo;
		$$.dir 		= $1.dir;
		$$.cod 		= $1.cod;
		$$.dBase 	= $1.dBase;
		$$.esArray = $1.esArray;
	};

ERel : Esimple relop_ { if($1.tipo != ENTERO && $1.tipo != REAL && $1.tipo != BOOLEANO) msgError(ERR_NUM, nlin, ncol, $2.lexema); } Esimple {
		if(DEBUG) std::cout << " - Leído ERel 1...\n";
		if($4.tipo != ENTERO && $4.tipo != REAL && $1.tipo != BOOLEANO) msgError(ERR_NUM, nlin, ncol, $2.lexema);
		$$.tipo = BOOLEANO;
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;

		if($1.tipo == $4.tipo) {
			if($1.tipo == ENTERO) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ relopToM2R($2.lexema, ENTERO) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else if($1.tipo == REAL) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ relopToM2R($2.lexema, REAL) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ relopToM2R($2.lexema, BOOLEANO) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else if($1.tipo != BOOLEANO && $4.tipo != BOOLEANO) {
			if($1.tipo == ENTERO) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ "itor\n"
						+ relopToM2R($2.lexema, REAL) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($4.dir) + " A\n"
						+ "itor\n"
						+ relopToM2R($2.lexema, REAL) + IntToString($1.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else
			msgError(ERR_TIPOS, nlin, ncol, $2.lexema);
	}
	| Esimple {
		if(DEBUG) std::cout << " - Leído ERel 2...\n";
		$$.tipo 	= $1.tipo;
		$$.dir 		= $1.dir;
		$$.cod 		= $1.cod;
		$$.dBase 	= $1.dBase;
		$$.esArray = $1.esArray;
	};

Esimple : Esimple addop_ { if($1.tipo != ENTERO && $1.tipo != REAL) msgError(ERR_NUM, nlin, ncol, $2.lexema); } Term {
		if(DEBUG) std::cout << " - Leído Esimple 1...\n";
		if($4.tipo != ENTERO && $4.tipo != REAL) msgError(ERR_NUM, nlin, ncol, $2.lexema);
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;

		if($1.tipo == $4.tipo) {
			$$.tipo = $4.tipo;

			if($1.tipo == ENTERO) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ addopToM2R($2.lexema, ENTERO) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ addopToM2R($2.lexema, ENTERO) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else {
			$$.tipo = REAL;

			if($1.tipo == ENTERO) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ "itor\n"
						+ addopToM2R($2.lexema, REAL) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($4.dir) + " A\n"
						+ "itor\n"
						+ addopToM2R($2.lexema, REAL) + IntToString($1.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		}
	}
	| Term {
		if(DEBUG) std::cout << " - Leído Esimple 2...\n";
		$$.tipo 	= $1.tipo;
		$$.dir 		= $1.dir;
		$$.cod 		= $1.cod;
		$$.dBase 	= $1.dBase;
		$$.esArray = $1.esArray;
	};

Term : Term mulop_ { if($1.tipo != ENTERO && $1.tipo != REAL) msgError(ERR_NUM, nlin, ncol, $2.lexema); } Factor {
		if(DEBUG) std::cout << " - Leído Term 1...\n";
		if($4.tipo != ENTERO && $4.tipo != REAL) msgError(ERR_NUM, nlin, ncol, $2.lexema);
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;

		if($1.tipo == $4.tipo) {
			$$.tipo = $4.tipo;

			if($1.tipo == ENTERO) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ mulopToM2R($2.lexema, ENTERO) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ mulopToM2R($2.lexema, REAL) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		} else {
			$$.tipo = REAL;

			if($1.tipo == ENTERO) {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($1.dir) + " A\n"
						+ "itor\n"
						+ mulopToM2R($2.lexema, REAL) + IntToString($4.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			} else {
				$$.cod = $4.cod
						+ $1.cod
						+ "mov " + IntToString($4.dir) + " A\n"
						+ "itor\n"
						+ mulopToM2R($2.lexema, REAL) + IntToString($1.dir) + "\n"
						+ "mov A " + IntToString(ptr_tmp) + "\n";
			}
		}
	}
	| Factor {
		if(DEBUG) std::cout << " - Leído Term 2...\n";
		$$.tipo = $1.tipo;
		$$.dir 	= $1.dir;
		$$.cod 	= $1.cod;
		$$.dBase = $1.dBase;
		$$.esArray = $1.esArray;
	};

Factor : Ref {
		if(DEBUG) std::cout << " - Leído Factor 1...\n";
		$$.tipo 	= $1.tipo;
		$$.dir 		= $1.dir;
		$$.cod 		= $1.cod;
		$$.dBase 	= $1.dBase;
		$$.esArray = $1.esArray;
	}
	| id punto_ nextInt_ pari_ pard_ {
		if(DEBUG) std::cout << " - Leído Factor 2...\n";
		simbolo_t simbolo;
		simbolo.lexema = $1.lexema;
		buscar(simbolo,ambito);
		if(simbolo.idTipo != SCANNER) msgError(ERR_NOSC,nlin,ncol,$1.lexema);

		ptr_tmp = NTemp();
		$$.tipo = ENTERO;
		$$.dir 	= ptr_tmp;
		$$.cod 	= "rdi " + IntToString(ptr_tmp) + "\n";
	}
	| id punto_ nextDouble_ pari_ pard_ {
		if(DEBUG) std::cout << " - Leído Factor 3...\n";
		simbolo_t simbolo;
		simbolo.lexema = $1.lexema;
		buscar(simbolo,ambito);
		if(simbolo.idTipo != SCANNER) msgError(ERR_NOSC,nlin,ncol,$1.lexema);

		ptr_tmp = NTemp();
		$$.tipo = REAL;
		$$.dir 	= ptr_tmp;
		$$.cod 	= "rdr " + IntToString(ptr_tmp) + "\n";
	}
	| nentero {
		if(DEBUG) std::cout << " - Leído Factor 4...\n";
		ptr_tmp = NTemp();
		$$.tipo = ENTERO;
		$$.dir 	= ptr_tmp;
		$$.cod 	= std::string("mov #") + $1.lexema + " " + IntToString(ptr_tmp) + "\n";
	}
	| nreal {
		if(DEBUG) std::cout << " - Leído Factor 5...\n";
		ptr_tmp = NTemp();
		$$.tipo = REAL;
		$$.dir 	= ptr_tmp;
		$$.cod 	= std::string("mov $") + $1.lexema + " " + IntToString(ptr_tmp) + "\n";
	}
	| true_ {
		if(DEBUG) std::cout << " - Leído Factor 6...\n";
		ptr_tmp = NTemp();
		$$.tipo = BOOLEANO;
		$$.dir 	= ptr_tmp;
		$$.cod 	= "mov #1 " + IntToString(ptr_tmp) + "\n";
	}
	| false_ {
		if(DEBUG) std::cout << " - Leído Factor 7...\n";
		ptr_tmp = NTemp();
		$$.tipo = BOOLEANO;
		$$.dir 	= ptr_tmp;
		$$.cod 	= "mov #0 " + IntToString(ptr_tmp) + "\n";
	}
	| pari_ Expr pard_ {
		if(DEBUG) std::cout << " - Leído Factor 8...\n";
		$$.tipo = $2.tipo;
		$$.dir 	= $2.dir;
		$$.cod 	= $2.cod;
	}
	| not_ Factor {
		if(DEBUG) std::cout << " - Leído Factor 9...\n";
		if($2.tipo != BOOLEANO) msgError(ERR_OPNOBOOL, nlin, ncol, $1.lexema);
		ptr_tmp = NTemp();
		$$.dir = ptr_tmp;
		$$.tipo = $2.tipo;
		$$.cod 	= $2.cod
				+ "mov " + IntToString($2.dir) + " A\n"
				+ "noti\n"
				+ "mov A " + IntToString(ptr_tmp) + "\n";
	}
	| pari_ Tipo { if(!esBase($2.tipo)) msgError(ERR_TIPOS,nlin,ncol,$2.lexema); } pard_ Factor {
		if(DEBUG) std::cout << " - Leído Factor 10...\n";

		if(!esBase($5.tipo)) msgError(ERR_TIPOS,nlin,ncol,$5.lexema);

		if($2.tipo == $5.tipo) {
			$$.tipo = $5.tipo;
			$$.dir 	= $5.dir;
			$$.cod 	= $5.cod;
		} else {
			ptr_tmp = NTemp();
			$$.tipo = $2.tipo;
			$$.dir 	= ptr_tmp;

			if($5.tipo == BOOLEANO) {
				if($2.tipo == ENTERO) {
					$$.cod 	= $5.cod
								+ "mov " + IntToString($5.dir) + " A\n"
								+ "ori #0\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				} else {
					$$.cod 	= $5.cod
								+ "mov " + IntToString($5.dir) + " A\n"
								+ "orr #0\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				}
			} else if($5.tipo == ENTERO) {
				if($2.tipo == BOOLEANO) {
					$$.cod 	= $5.cod
								+ "mov " + IntToString($5.dir) + " A\n"
								+ "andi #1\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				} else {
					$$.cod 	= $5.cod
								+ "mov " + IntToString($5.dir) + " A\n"
								+ "itor\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				}
			} else {
				if($2.tipo == BOOLEANO) {
					$$.cod 	= $5.cod
								+ "mov " + IntToString($5.dir) + " A\n"
								+ "andr #1\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				} else {
					$$.cod 	= $5.cod
								+ "mov " + IntToString($5.dir) + " A\n"
								+ "rtoi\n"
								+ "mov A " + IntToString(ptr_tmp) + "\n";
				}
			}
		}
	};
Ref : id {
		if(DEBUG) std::cout << " - Leído Ref 1...\n";
		simbolo_t s;
		s.lexema = $1.lexema;
		if(!buscar(s,ambito))
			msgError(ERRNODECL,$1.nlin,$1.ncol, $1.lexema);
		else{
			$$.tipo = s.idTipo;

			if(s.esArray) {
				ptr_tmp 	= NTemp();
				$$.dir = ptr_tmp;
				$$.dBase	= getTBaseVector(s.idTipo);
				//$$.dBase = $1.dir;
				$$.esArray = true;
				$$.cod 		= "mov #0 " + IntToString(ptr_tmp) + "\n";
			}
			else {
				$$.dir = s.dir;
				$$.tipo = s.idTipo;
				if(DEBUG) std::cout << "Ref -> id, símbolo [lex]" << s.lexema << "\t[dir]"<< s.dir << "\t[tipo]" << s.idTipo << "\n";
				//$$.cod = "mov "+ IntToString(s.dir) + " A\n";
				$$.esArray = false;
			}
		}
	}
	| Ref cori_ { /*if(!$1.esArray) msgError(ERRFALTAN,nlin,ncol,"");*/ }
	  Esimple  cord_ {
		if(DEBUG) std::cout << " - Leído Ref 2...\n";
		if(!esBase($4.tipo)) msgError(ERR_EXP_ENT,nlin,ncol,"");
		else {
			tipo_t t;
			buscarTipo($1.tipo, t);
			

			$$.tipo = tipoBase($1.tipo);
			ptr_tmp = NTemp();
			$$.dir = ptr_tmp;
			$$.dBase = $1.dBase;
			$$.esArray = $1.esArray;
			$$.cod = $1.cod + $4.cod
					 + "mov " + IntToString($1.dir) + " A\n" 
					 + "muli #" + IntToString(t.size) + "\n"
					 + "addi " + IntToString($4.dir) + "\n";
					 + "mov A" + IntToString(ptr_tmp) + "\n";
		}
	};
  
	
%%

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