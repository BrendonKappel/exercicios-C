#include <stdio.h>         // entrada e sa�da padr�o: printf, scanf

/**
 
entrada_dados                                *
objetivo: rotina para ler dados              *
entrada : registro aux (auxiliar)            *
sa�da   : aux atualizado com dados           *
**/
void entrada_dados( INFORMACAO *aux ){

    printf( "\n Digite uma letra: " );
    fflush( stdin );
    gets( aux->nome );
}
