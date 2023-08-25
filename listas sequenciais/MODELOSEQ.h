/***********************************************/ 
/* Definição do Registro e da Estrutura        */
/* Profa Daniela Bagatini                      */
/***********************************************/ 
#define N_MAX   100

typedef struct{                 // registro pessoa
       char nome[30];
       int  codigo;
}INFORMACAO;
       
typedef struct{
       INFORMACAO info[N_MAX];  // dados do registro
       int f;                   // número de registro(s) ocupado(s) na estrutura
}NODO;                          // estrutura do tipo NODO
