#include <stdio.h>         
#include <stdlib.h>   
#include <string.h>     
#include <locale.h>        



// bibliotecas 
#include "MODELOSEQ.h"     // modelo de dados
#include "ENTRADA_DADOS.h" // lê dados de entrada


/***********************************************/
/* Funções                     					*/
/***********************************************/




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
	
	imprime_lista(fila1);
                    
} // fim do programa principal





























           









	


	
