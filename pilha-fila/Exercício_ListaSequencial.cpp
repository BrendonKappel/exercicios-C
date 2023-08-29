#include <stdio.h>            
#include <locale.h>        



// bibliotecas 
#include "MODELOSEQ.h"     // modelo de dados
#include "ENTRADA_DADOS.h" // lê dados de entrada


/***********************************************/
/* Funções                     					*/
/***********************************************/
void inclui_fim( NODO *lista ){
	INFORMACAO aux;

	if(lista->f > N_MAX) { // se tamanho da lista for maior do que a constante que delimita o tamanho maximo da lista ele da erro. 
		printf("lista está cheia");
	} else { // senao 
		entrada_dados(&aux); // chama a funcao entrada de dados, para o ususario poder informar o dado que ele quer
		lista->info[lista->f] = aux; // ira adicionar o valor da entrada de dados na ultima posicao da lista
		lista->f++; // tamanho da lista cresce em + 1
	}

}



void imprime_lista( NODO lista ){
     
    int i;                                // índice do laço

    if( lista.f == 0 )                    // verifica se lista vazia
        printf( "\n Lista vazia! " );
    else{
        printf("\n Relatório Geral ----------------------------------------- ");
   for( i = 0 ; i < lista.f ; i++ ) { // percorre a lista e imprime dados
        printf( "\n Registro[%d]", i );
        printf( "\t Nome.: %s", lista.info[ i ].nome );
   }
    }    
    getchar();                             // parada da tela
}



void troca_pilha( NODO lista, NODO *pilha ) { // pega o ultimo elemento da primeira estrutura de dados e coloca no final da segunda
	int i;
	
	for(i=lista.f-1; i >= 0; i--) {
		pilha->info[pilha->f] = lista.info[i];  // vai adicionando sempre no ultimo elemento da pilha e navegando nos ultimos elementos da lista a cada interação. 
		pilha->f++; // adiciona + 1 elemento no tamanho da lista (f)
	}
	
}





/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void ){
	int num, i;     // quantidades de letra da palavra
    NODO fila1, pilha1, pilha2;                               // filas e pilhas utilizadas
   
    setlocale( LC_ALL, "Portuguese" );        // alterar idioma para português
	
	fila1.f = 0, pilha1.f = 0, pilha2.f = 0;  // substitui a função "cria_lista" --> inicializa com o tamanho 0
	
	printf("quantas letras tem a palavra que deseja digitar? ");
	scanf("%i", &num);
	
	for(i=0; num > i; i++) {	// incluindo no fim  -->  FILA
	
		inclui_fim(&fila1);
	}	
	
	imprime_lista(fila1); // imprime a lista
	
	troca_pilha(fila1, &pilha1);  // realiza a operação 
	
	imprime_lista(pilha1);
	
	troca_pilha(pilha1, &pilha2);
	
	imprime_lista(pilha2);
                    
} // fim do programa principal





























           









	


	
