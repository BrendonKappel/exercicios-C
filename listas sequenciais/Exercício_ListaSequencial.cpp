/***********************************************/
/* Lista Sequencial                            */
/* objetivo: controle de registros             */
/* programador: Daniela Bagatini               */
/* recriado em: 19/09/2022                     */
/* data da �ltima altera��o: 19/09/2022        */
/***********************************************/


#include <stdio.h>         // entrada e sa�da padr�o: printf, scanf
#include <stdlib.h>   // exit, malloc, system
#include <string.h>     // strcmp
#include <locale.h>        // setlocale
//#include <ctype.h>       // toupper
//#include <conio.h>       // getch
//#include <time.h>        // rand  


// bibliotecas inclu�das, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELOSEQ.h"     // modelo de dados
#include "GERA_DADOSSEQ.h" // gera dados para povoar lista de forma autom�tica
#include "ENTRADA_DADOS.h" // l� dados de entrada


/***********************************************/
/* Defini��o das Fun��es                       */
/***********************************************/
void imprime_lista   ( NODO lista );          // visualiza lista em tela
void cria_lista      ( int *fim );            // inicializa lista com tamanho 0
void inclui_fim      ( NODO *lista );         // inclui novo registro no final da lista
void inclui_inicio   ( NODO *lista );         // inclui novo registro no in�cio da lista
void inclui_antes    ( NODO *lista );         // inclui novo registro antes de um c�digo de refer�ncia
void inclui_depois   ( NODO *lista );         // inclui novo registro depois de um c�digo de refer�ncia
void exclui_nodo     ( NODO *lista );         // exclui regitro por c�digo
void ordena_lista    ( NODO *lista );         // ordena por c�digo - ordem crescente
void altera_nodo     ( NODO *lista );         // altera regitro a partir de um c�digo de refer�ncia
void consulta_nome   ( NODO lista );          // consulta registro por nome e apresenta demais dados do registro
int  procura_nodo    ( int cod, NODO lista ); // procura por c�digo na lista
void inclui_ordenado ( NODO *lista );         // inclui em ordem crescente de c�digo
void compara_repetidos( NODO *lista );        // verifica c�digos repetidos
void elimina_repetidos( NODO *lista );        // verifica c�digos repetidos e exclui, se lista ordenada
// crie sua pr�pria fun��o aqui!
//void entrada_dados   ( INFORMACAO *aux );     // l� dos dados de entrada
void exclui_final( NODO *lista);
void exclui_inicio( NODO *lista );

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
         printf( "\n [4 ] Inclui registro antes de um c�digo de refer�ncia     " );
         printf( "\n [5 ] Inclui registro depois de um c�digo de refer�ncia    " );
         printf( "\n [6 ] Exclui registro                                      " );
         printf( "\n [7 ] Ordena lista                                         " );
         printf( "\n [8 ] Altera registro                                      " );  
		 printf( "\n [9 ] Consulta por nome                                    " );        
         printf( "\n [10] Inclui ordenado por c�digo                           " );                  
         printf( "\n [11] Crie sua pr�pria fun��o aqui!                        " );
         printf( "\n [12] Compara repetidos                                    " );
         printf( "\n [13] Elimina repetidos                                    " );                  
         printf( "\n [14] Gera dados                                           " );
		 printf( "\n [15] Imprime lista                                        " );
		 printf( "\n [16] exclui inicio										   " );
		 printf( "\n [17] exclui fim									   	   " );
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

            case 4:  // rotina inclui registro antes de um c�digo de refer�ncia informado
                     inclui_antes( &lista );
                     break;

            case 5:  // rotina inclui registro depois de um c�digo de refer�ncia informado
                    inclui_depois( &lista );
                    break;

            case 6:  // rotina exclui registro conforme c�digo de refer�ncia
                    exclui_nodo( &lista );
                    break;

            case 7: // rotina ordena lista por c�digo, ordem crescente
                    ordena_lista( &lista );
                    break;
                   
            case 8: // rotina altera registro com base no c�digo de refer�ncia informado
                    altera_nodo( &lista );
                    break;
                   
            case 9: // rotina consulta por nome e apresentada demais dados do registro
                    consulta_nome( lista );
                    break;

            case 10: // rotina inclui registro por ordem crescente de c�digo            
                    ordena_lista( &lista );  // ordena lista para garantir que ir� incluir o novo registro em ordem
                    inclui_ordenado( &lista );
                    break;

            case 11:  
                    // crie sua pr�pria fun��o aqui!  
                    break;            
                   
            case 12: // rotina compara registros com c�digos repetidos
                    compara_repetidos( &lista );
                    break;                    
                   
            case 13: // rotina exclui registros com c�digos repetidos
                    ordena_lista( &lista );  // ordena lista para garantir que ir� eliminar repetidos                    
                    elimina_repetidos( &lista );
                    break;      

            case 14: // rotina gera dados de forma autom�tica para povoar a lista
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



/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * sa�da   : aux atualizado com dados           *
 ***********************************************
void entrada_dados( INFORMACAO *aux ){

    printf( "\n\n Digite o c�digo: " );
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
 * sa�da   : nenhuma, apenas em tela             *
 *************************************************/
void imprime_lista( NODO lista ){
     
    int i;                                // �ndice do la�o

    if( lista.f == 0 )                    // verifica se lista vazia
        printf( "\n Lista vazia! " );
    else{
        printf("\n Relat�rio Geral ----------------------------------------- ");
   for( i = 0 ; i < lista.f ; i++ ) { // percorre a lista e imprime dados
        printf( "\n Registro[%d]", i );
        printf( "\t C�digo.: %d", lista.info[ i ].codigo );
        printf( "\t Nome.: %s", lista.info[ i ].nome );
   }
    }    
    getchar();                             // parada da tela
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * sa�da   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_lista( int *fim ){
     
    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada! " );
}



/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ***********************************************/
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



/************************************************
 * inclui_in�cio                                *
 * objetivo: inserir no in�cio da lista         *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
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



/************************************************
 * procura_nodo                                 *
 * objetivo: achar posi��o a partir de um campo *
 * entrada : c�digo de refer�ncia e lista       *
 * sa�da   : posi��o f�sica da refer�ncia ou -1 *
 ************************************************/
int procura_nodo( int cod, NODO lista ){
int i; // declara��o do contador

        for(i=0; i < lista.f; i++) { // percorrendo lista da frente para tr�s
        if(lista.info[i].codigo == cod) {  // compara c�digo de cada posi��o com o codigo informado pelo usu�rio
        return i;  // retorna a posi��o do c�digo na lista
}
       
}

return -1; // retorna -1, informando que n�o existe esse c�digo
}



/************************************************
 * inclui_antes                                 *
 * objetivo: inserir antes de um c�digo         *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_antes( NODO *lista ){
     
}



/************************************************
 * inclui_depois                                *
 * objetivo: inserir depois de um c�digo        *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_depois( NODO *lista ){
 
}



/************************************************
 * exclui_nodo                                  *
 * objetivo: rotina para excluir registro       *
 * entrada : lista                              *
 * sa�da   : lista com um elemento removido     *
 ************************************************/
void exclui_nodo( NODO *lista ){
     
}



/************************************************
* ordena_lista                                  *
* objetivo: rotina para ordenar lista por c�digo*
* entrada : lista                               *
* sa�da   : lista ordenada                      *
*************************************************/
void ordena_lista( NODO *lista ){              // Algoritmo M�todo Bolha - Bubble Sort
     
}



/************************************************
 * altera_nodo                                  *
 * objetivo: rotina para alterar registro       *
 * entrada : lista                              *
 * sa�da   : lista com um elemento alterado     *
 ************************************************/
void altera_nodo( NODO *lista ) {
int codigo, posicao;  // declarar vari�vel posicao aqui
INFORMACAO aux;

printf("Digite o c�digo: ");
scanf("%i", &codigo);

posicao = procura_nodo( codigo, *lista ); // Criamos a fun��o "procura_nodo"
if( posicao == -1 ) {
printf("\n N�o achou!");
getchar(); // adicionamos para congelar a tela
} else {

printf( "\n Registro[%d]", posicao );
printf( "\t C�digo.: %d", lista->info[ posicao ].codigo );
printf( "\t Nome.: %s\n ", lista->info[ posicao ].nome );
printf("\n Insira os novos dados");
entrada_dados( &aux );
lista->info[posicao] = aux;
printf("\nlista atualizada"); // adicionamos essa parte
//getchar();   --> tiramos o getchar pois estava prejudicando a finaliza��o do c�digo
}
}            


/************************************************
 * consulta_nome                                *
 * objetivo: rotina para consultar nome         *
 * entrada : lista                              *
 * sa�da   : nenhuma, dados em tela             *
 ************************************************/
void consulta_nome( NODO lista ){
       
}



/************************************************
 * inclui_ordenado                              *
 * objetivo: rotina que inclui registro ordenado*
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/        
void inclui_ordenado ( NODO *lista ){
     
}


/************************************************
 * busca_bin�ria                                *
 * objetivo: rotina busca bin�ria por c�digo    *
 * entrada : lista                              *
 * sa�da   : nenhuma                            *
 ***********************************************/    
void busca_binaria( NODO lista ){
       
}



/************************************************
 * compara_repetidos                            *
 * objetivo: rotina compara registros           *
 * entrada : lista                              *
 * sa�da   : nenhuma                            *
 ************************************************/
void compara_repetidos ( NODO *lista ){  
     
}



/************************************************
 * elimina_repetidos                            *
 * objetivo: rotina exclui registros repetidos  *
 * entrada : lista                              *
 * sa�da   : lista atualizada                   *
 ***********************************************/
void elimina_repetidos( NODO *lista ){
       
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
	
