/***********************************************/ 
/* Definição do Registro e da Estrutura        */
/* Profa Daniela Bagatini                      */
/***********************************************/ 
#define N_MAX   100 // definicao de uma constante

typedef struct{                 
       char nome[2]; // string com 2 caracteres
}INFORMACAO;
       
typedef struct{
       INFORMACAO info[N_MAX];  // dados do registro
       int f;                   // número de registro(s) ocupado(s) na estrutura
}NODO;                          // estrutura do tipo NODO
