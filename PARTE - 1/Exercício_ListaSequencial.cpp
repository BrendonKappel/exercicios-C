#include <stdio.h>         
#include <stdlib.h>   
#include <string.h>     
#include <locale.h>        



// bibliotecas 
#include "MODELOSEQ.h"     // modelo de dados
#include "ENTRADA_DADOS.h" // l� dados de entrada


/***********************************************/
/* Fun��es                     					*/
/***********************************************/
void cria_lista( int *fim ){

    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada! " );
}



void inclui_fim( NODO *lista ){
	INFORMACAO aux;

	if(lista->f > N_MAX) {
		printf("lista est� cheia");
	} else {
		entrada_dados(&aux);
		lista->info[lista->f] = aux;
		lista->f++;
	}

}



void inclui_inicio(NODO *lista) {
    if (lista->f > N_MAX) {  // Verifica se a lista n�o est� cheia
    printf("A lista est� cheia. N�o � poss�vel adicionar mais registros.\n");

    } else {
        int i;
        INFORMACAO aux;

        // entrada de dados
        entrada_dados(&aux);

        // move da esquerda p/ direita 1 casa.
        for (i = lista->f; i > 0; i--) {
            lista->info[i] = lista->info[i - 1]; // o f vale a pr�xima casa a ser preenchida (sempre estamos uma casa a frente com o f)
        }

        // Inserindo o novo valar no inicio da lista
        lista->info[0] = aux;

        lista->f++;  // aumenta o tamanho de espa�os ocupados na lista em um valor
        printf("Registro adicionado no in�cio da lista com sucesso!\n");
    }
}

void imprime_lista( NODO lista ){

    int i;                                // �ndice do la�o

    if( lista.f == 0 )                    // verifica se lista vazia
        printf( "\n Lista vazia! " );
    else{
        printf("\n Relat�rio Geral ----------------------------------------- ");
   for( i = 0 ; i < lista.f ; i++ ) { // percorre a lista e imprime dados
        printf( "\n Registro[%d]", i );
        printf( "\t Nome.: %s", lista.info[ i ].nome );
   }
    }    
    getchar();                             // parada da tela
}


void exclui_inicio( NODO *lista ) {  //fun��o para fila
	int i;

	if(lista->f < 0) {
		printf("\nlista est� vazia!");
	} else {

		for(i=0; i < lista->f ; i++) {
		lista->info[i] = lista->info[i + 1];
		}

		lista->f = lista->f-1;
		printf("Primeiro elemento da listra foi excluido.");
		getchar();
	}


}

void exclui_final( NODO *lista ) {	// o f perde 1, n�o exclui o elemento, mas n�o mostra mais ele
	if(lista->f < 0) {
		printf("\nlista est� vazia!");
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
    int op;                                   // op��o do menu
    NODO lista;                               // vari�vel do tipo lista sequencial = vetor de registros
    setlocale( LC_ALL, "Portuguese" );        // alterar idioma para portugu�s

    while( 1 ){
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Programa registro - Menu                                  " );
         printf( "\n [1 ] Cria lista                                           " );
         printf( "\n [2 ] Inclui registro no final da lista                    " );
         printf( "\n [3 ] Inclui registro no in�cio da lista                   " );
		 printf( "\n [4 ] Imprime lista                                        " );
		 printf( "\n [5 ] exclui inicio										   " );
		 printf( "\n [6 ] exclui fim									   	   " );
         printf( "\n [0 ] Para sair do programa                                " );		
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Op��o: " );
         fflush( stdin );    // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op ); // tecla de op��o do menu

         switch( op ) {
            case 1:  // rotina cria lista, inicializa a lista em zero
                    cria_lista( &lista.f );
                    break;

            case 2:  // rotina inclui registro no final da lista, conforme indicado pelo gerenciados da lista (posi��o lista.f)
                    inclui_fim( &lista );
                    break;

            case 3:  // rotina inclui registro no in�cio da lista, posi��o 0
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

            case 0: // t�rmino do programa
                    exit( 1 );
                    break;

            default :
                    printf( "\n Digite uma op��o!" );
                    break;
        } // fim switch( op )

        printf("\n");
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
 return 0;
} // fim do programa principal




