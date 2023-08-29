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
void cria_lista( int *fim ){

    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada! " );
}



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
    int op;                                   // opção do menu
    NODO lista;                               // variável do tipo lista sequencial = vetor de registros
    setlocale( LC_ALL, "Portuguese" );        // alterar idioma para português

    while( 1 ){
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Programa registro - Menu                                  " );
         printf( "\n [1 ] Cria lista                                           " );
         printf( "\n [2 ] Inclui registro no final da lista                    " );
         printf( "\n [3 ] Inclui registro no início da lista                   " );
		 printf( "\n [4 ] Imprime lista                                        " );
		 printf( "\n [5 ] exclui inicio										   " );
		 printf( "\n [6 ] exclui fim									   	   " );
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

            case 4: // rotina imprime todos os registros da lista
                    imprime_lista( lista );
                    break;

            case 5: // exclui elemento inicial
            exclui_inicio( &lista );
            break;

            case 6: // exclui elemento no final da lista
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




