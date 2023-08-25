#include <stdio.h>         // entrada e saída padrão: printf, scanf

/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * saída   : aux atualizado com dados           *
 ************************************************/
void entrada_dados( INFORMACAO *aux ){
	 
    printf( "\n\n Digite o código: " );
    fflush( stdin );                        // limpa buffer do teclado, funciona junto com entrada de dados
    scanf( "%d", &aux->codigo );

    printf( "\n Digite o nome: " );
    fflush( stdin );     
    gets( aux->nome );
}
