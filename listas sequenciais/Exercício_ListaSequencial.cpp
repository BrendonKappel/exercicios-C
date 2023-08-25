/***********************************************/
/* Lista Sequencial                            */
/* objetivo: controle de registros             */
/* programador: Daniela Bagatini               */
/* recriado em: 19/09/2022                     */
/* data da última alteração: 19/09/2022        */
/***********************************************/


#include <stdio.h>         // entrada e saída padrão: printf, scanf
#include <stdlib.h>   // exit, malloc, system
#include <string.h>     // strcmp
#include <locale.h>        // setlocale
//#include <ctype.h>       // toupper
//#include <conio.h>       // getch
//#include <time.h>        // rand  


// bibliotecas incluídas, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELOSEQ.h"     // modelo de dados
#include "GERA_DADOSSEQ.h" // gera dados para povoar lista de forma automática
#include "ENTRADA_DADOS.h" // lê dados de entrada


/***********************************************/
/* Definição das Funções                       */
/***********************************************/
void imprime_lista   ( NODO lista );          // visualiza lista em tela
void cria_lista      ( int *fim );            // inicializa lista com tamanho 0
void inclui_fim      ( NODO *lista );         // inclui novo registro no final da lista
void inclui_inicio   ( NODO *lista );         // inclui novo registro no início da lista
void inclui_antes    ( NODO *lista );         // inclui novo registro antes de um código de referência
void inclui_depois   ( NODO *lista );         // inclui novo registro depois de um código de referência
void exclui_nodo     ( NODO *lista );         // exclui regitro por código
void ordena_lista    ( NODO *lista );         // ordena por código - ordem crescente
void altera_nodo     ( NODO *lista );         // altera regitro a partir de um código de referência
void consulta_nome   ( NODO lista );          // consulta registro por nome e apresenta demais dados do registro
int  procura_nodo    ( int cod, NODO lista ); // procura por código na lista
void inclui_ordenado ( NODO *lista );         // inclui em ordem crescente de código
void compara_repetidos( NODO *lista );        // verifica códigos repetidos
void elimina_repetidos( NODO *lista );        // verifica códigos repetidos e exclui, se lista ordenada
// crie sua própria função aqui!
//void entrada_dados   ( INFORMACAO *aux );     // lê dos dados de entrada
void exclui_final( NODO *lista);
void exclui_inicio( NODO *lista );

/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void ){
    int op;                                   // opção do menu
    NODO lista;                               // variável do tipo lista sequencial = vetor de registros
    setlocale( LC_ALL, "Portuguese" );        // alterar idioma para português

    while( 1 ){
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Programa registro - Menu                                  " );
         printf( "\n [1 ] Cria lista                                           " );
         printf( "\n [2 ] Inclui registro no final da lista                    " );
         printf( "\n [3 ] Inclui registro no início da lista                   " );
         printf( "\n [4 ] Inclui registro antes de um código de referência     " );
         printf( "\n [5 ] Inclui registro depois de um código de referência    " );
         printf( "\n [6 ] Exclui registro                                      " );
         printf( "\n [7 ] Ordena lista                                         " );
         printf( "\n [8 ] Altera registro                                      " );  
		 printf( "\n [9 ] Consulta por nome                                    " );        
         printf( "\n [10] Inclui ordenado por código                           " );                  
         printf( "\n [11] Crie sua própria função aqui!                        " );
         printf( "\n [12] Compara repetidos                                    " );
         printf( "\n [13] Elimina repetidos                                    " );                  
         printf( "\n [14] Gera dados                                           " );
		 printf( "\n [15] Imprime lista                                        " );
		 printf( "\n [16] exclui inicio										   " );
		 printf( "\n [17] exclui fim									   	   " );
         printf( "\n [0 ] Para sair do programa                                " );		
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Opção: " );
         fflush( stdin );    // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op ); // tecla de opção do menu
         
         switch( op ) {
            case 1:  // rotina cria lista, inicializa a lista em zero
                    cria_lista( &lista.f );
                    break;

            case 2:  // rotina inclui registro no final da lista, conforme indicado pelo gerenciados da lista (posição lista.f)
                    inclui_fim( &lista );
                    break;

            case 3:  // rotina inclui registro no início da lista, posição 0
                    inclui_inicio( &lista );
                    break;

            case 4:  // rotina inclui registro antes de um código de referência informado
                     inclui_antes( &lista );
                     break;

            case 5:  // rotina inclui registro depois de um código de referência informado
                    inclui_depois( &lista );
                    break;

            case 6:  // rotina exclui registro conforme código de referência
                    exclui_nodo( &lista );
                    break;

            case 7: // rotina ordena lista por código, ordem crescente
                    ordena_lista( &lista );
                    break;
                   
            case 8: // rotina altera registro com base no código de referência informado
                    altera_nodo( &lista );
                    break;
                   
            case 9: // rotina consulta por nome e apresentada demais dados do registro
                    consulta_nome( lista );
                    break;

            case 10: // rotina inclui registro por ordem crescente de código            
                    ordena_lista( &lista );  // ordena lista para garantir que irá incluir o novo registro em ordem
                    inclui_ordenado( &lista );
                    break;

            case 11:  
                    // crie sua própria função aqui!  
                    break;            
                   
            case 12: // rotina compara registros com códigos repetidos
                    compara_repetidos( &lista );
                    break;                    
                   
            case 13: // rotina exclui registros com códigos repetidos
                    ordena_lista( &lista );  // ordena lista para garantir que irá eliminar repetidos                    
                    elimina_repetidos( &lista );
                    break;      

            case 14: // rotina gera dados de forma automática para povoar a lista
                    gera_dados( &lista );
                    break;      
                                                               
            case 15: // rotina imprime todos os registros da lista
                    imprime_lista( lista );
                    break;
                   
            case 16: // exclui elemento inicial
            exclui_inicio( &lista );
            break;
           
            case 17: // exclui elemento no final da lista
            exclui_final( &lista );
            break;
                   
            case 0: // término do programa
                    exit( 1 );
                    break;

            default :
                    printf( "\n Digite uma opção!" );
                    break;
        } // fim switch( op )
       
        printf("\n");
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
 return 0;
} // fim do programa principal



/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * saída   : aux atualizado com dados           *
 ***********************************************
void entrada_dados( INFORMACAO *aux ){

    printf( "\n\n Digite o código: " );
    fflush( stdin );                        // limpa buffer do teclado, funciona junto com entrada de dados
    scanf( "%d", &aux->codigo );

    printf( "\n Digite o nome: " );
    fflush( stdin );    
    gets( aux->nome );
}
*/


/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saída   : nenhuma, apenas em tela             *
 *************************************************/
void imprime_lista( NODO lista ){
     
    int i;                                // índice do laço

    if( lista.f == 0 )                    // verifica se lista vazia
        printf( "\n Lista vazia! " );
    else{
        printf("\n Relatório Geral ----------------------------------------- ");
   for( i = 0 ; i < lista.f ; i++ ) { // percorre a lista e imprime dados
        printf( "\n Registro[%d]", i );
        printf( "\t Código.: %d", lista.info[ i ].codigo );
        printf( "\t Nome.: %s", lista.info[ i ].nome );
   }
    }    
    getchar();                             // parada da tela
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * saída   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_lista( int *fim ){
     
    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada! " );
}



/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ***********************************************/
void inclui_fim( NODO *lista ){
INFORMACAO aux;

if(lista->f > N_MAX) {
printf("lista está cheia");
} else {
entrada_dados(&aux);
lista->info[lista->f] = aux;
lista->f++;
}

}



/************************************************
 * inclui_início                                *
 * objetivo: inserir no início da lista         *
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_inicio(NODO *lista) {
    if (lista->f > N_MAX) {  // Verifica se a lista não está cheia
    printf("A lista está cheia. Não é possível adicionar mais registros.\n");
   
    } else {
        int i;
        INFORMACAO aux;
       
        // entrada de dados
        entrada_dados(&aux);
       
        // move da esquerda p/ direita 1 casa.
        for (i = lista->f; i > 0; i--) {
            lista->info[i] = lista->info[i - 1]; // o f vale a próxima casa a ser preenchida (sempre estamos uma casa a frente com o f)
        }
       
        // Inserindo o novo valar no inicio da lista
        lista->info[0] = aux;
       
        lista->f++;  // aumenta o tamanho de espaços ocupados na lista em um valor
        printf("Registro adicionado no início da lista com sucesso!\n");
    }
}



/************************************************
 * procura_nodo                                 *
 * objetivo: achar posição a partir de um campo *
 * entrada : código de referência e lista       *
 * saída   : posição física da referência ou -1 *
 ************************************************/
int procura_nodo( int cod, NODO lista ){
int i; // declaração do contador

        for(i=0; i < lista.f; i++) { // percorrendo lista da frente para trás
        if(lista.info[i].codigo == cod) {  // compara código de cada posição com o codigo informado pelo usuário
        return i;  // retorna a posição do código na lista
}
       
}

return -1; // retorna -1, informando que não existe esse código
}



/************************************************
 * inclui_antes                                 *
 * objetivo: inserir antes de um código         *
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_antes( NODO *lista ){
     
}



/************************************************
 * inclui_depois                                *
 * objetivo: inserir depois de um código        *
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_depois( NODO *lista ){
 
}



/************************************************
 * exclui_nodo                                  *
 * objetivo: rotina para excluir registro       *
 * entrada : lista                              *
 * saída   : lista com um elemento removido     *
 ************************************************/
void exclui_nodo( NODO *lista ){
     
}



/************************************************
* ordena_lista                                  *
* objetivo: rotina para ordenar lista por código*
* entrada : lista                               *
* saída   : lista ordenada                      *
*************************************************/
void ordena_lista( NODO *lista ){              // Algoritmo Método Bolha - Bubble Sort
     
}



/************************************************
 * altera_nodo                                  *
 * objetivo: rotina para alterar registro       *
 * entrada : lista                              *
 * saída   : lista com um elemento alterado     *
 ************************************************/
void altera_nodo( NODO *lista ) {
int codigo, posicao;  // declarar variável posicao aqui
INFORMACAO aux;

printf("Digite o código: ");
scanf("%i", &codigo);

posicao = procura_nodo( codigo, *lista ); // Criamos a função "procura_nodo"
if( posicao == -1 ) {
printf("\n Não achou!");
getchar(); // adicionamos para congelar a tela
} else {

printf( "\n Registro[%d]", posicao );
printf( "\t Código.: %d", lista->info[ posicao ].codigo );
printf( "\t Nome.: %s\n ", lista->info[ posicao ].nome );
printf("\n Insira os novos dados");
entrada_dados( &aux );
lista->info[posicao] = aux;
printf("\nlista atualizada"); // adicionamos essa parte
//getchar();   --> tiramos o getchar pois estava prejudicando a finalização do código
}
}            


/************************************************
 * consulta_nome                                *
 * objetivo: rotina para consultar nome         *
 * entrada : lista                              *
 * saída   : nenhuma, dados em tela             *
 ************************************************/
void consulta_nome( NODO lista ){
       
}



/************************************************
 * inclui_ordenado                              *
 * objetivo: rotina que inclui registro ordenado*
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/        
void inclui_ordenado ( NODO *lista ){
     
}


/************************************************
 * busca_binária                                *
 * objetivo: rotina busca binária por código    *
 * entrada : lista                              *
 * saída   : nenhuma                            *
 ***********************************************/    
void busca_binaria( NODO lista ){
       
}



/************************************************
 * compara_repetidos                            *
 * objetivo: rotina compara registros           *
 * entrada : lista                              *
 * saída   : nenhuma                            *
 ************************************************/
void compara_repetidos ( NODO *lista ){  
     
}



/************************************************
 * elimina_repetidos                            *
 * objetivo: rotina exclui registros repetidos  *
 * entrada : lista                              *
 * saída   : lista atualizada                   *
 ***********************************************/
void elimina_repetidos( NODO *lista ){
       
}

	

void exclui_inicio( NODO *lista ) {  //função para fila
	int i;
	
	if(lista->f < 0) {
		printf("\nlista está vazia!");
	} else {
		
		for(i=0; i < lista->f ; i++) {
		lista->info[i] = lista->info[i + 1];
		}
		
		lista->f = lista->f-1;
		printf("Primeiro elemento da listra foi excluido.");
		getchar();
	}
	

}

void exclui_final( NODO *lista ) {	// o f perde 1, não exclui o elemento, mas não mostra mais ele
	if(lista->f < 0) {
		printf("\nlista está vazia!");
	} else {
		lista->f = lista->f-1;
		printf("Ultimo elemento da listra foi excluido.");
		getchar();
	}
}
	
