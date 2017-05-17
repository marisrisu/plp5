/*----------------------- comun.h -----------------------------*/

/* fichero con definciones comunes para los ficheros .l y .y */

typedef struct {
   char *lexema;
   int nlin,ncol;
   int tipo;
   string cod;
   string prefijo;
   string th;
   string dir;
   string dbase;

} MITIPO;



#define YYSTYPE MITIPO

#define ERRLEXICO    1
#define ERRSINT      2
#define ERREOF       3
#define ERRLEXEOF    4

#define ERRYADECL          10
#define ERRNODECL          11
#define ERRDIM             12
#define ERRFALTAN          13
#define ERRSOBRAN          14
#define ERR_EXP_ENT        15
#define ERR_NOSC           16
#define ERR_TIPOSDECLARRAY 17
#define ERR_DIMSDECLARRAY  18
#define ERR_TIPOSASIG      19
#define ERR_SCVAR          20
#define ERR_TIPOSIFW       21
#define ERR_OPNOBOOL       22
#define ERR_NUM            23
#define ERR_TIPOS          24

#define ERR_NOCABE     100
#define ERR_MAXVAR     101
#define ERR_MAXTIPOS   102
#define ERR_MAXTMP     103


void msgError(int nerror,int nlin,int ncol,const char *s);
