#include <stdio.h>         // entrada e sa�da padr�o: printf, scanf

/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * sa�da   : aux atualizado com dados           *
 ************************************************/
void entrada_dados( INFORMACAO *aux ){
	 
    printf( "\n\n Digite o c�digo: " );
    fflush( stdin );                        // limpa buffer do teclado, funciona junto com entrada de dados
    scanf( "%d", &aux->codigo );

    printf( "\n Digite o nome: " );
    fflush( stdin );     
    gets( aux->nome );
}
