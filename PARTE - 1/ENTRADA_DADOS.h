#include <stdio.h>         // entrada e saída padrão: printf, scanf

/**
 
entrada_dados                                *
objetivo: rotina para ler dados              *
entrada : registro aux (auxiliar)            *
saída   : aux atualizado com dados           *
**/
void entrada_dados( INFORMACAO *aux ){

    printf( "\n Digite uma letra: " );
    fflush( stdin );
    gets( aux->nome );
}
