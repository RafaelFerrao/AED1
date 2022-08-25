#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[10];
    int idade;
    int telefone;
} pessoa_t;

pessoa_t pessoas[10];

int main()
{
    void *pBuffer = malloc( sizeof( int ) * 2 + sizeof( char ) );
    int *pInt1 = pBuffer; // É usada como contador;
    int *pInt2 = pBuffer + sizeof( int );
    char *pChar = pBuffer + sizeof( int ) * 2; // Entrada do usuario

    *pInt2 = 0; // Numero de pessoas;

    while ( *pInt2 < 10 )
    {
        printf( "\nVoce deseja inserir uma nova pessoa? S ou N: " );
        setbuf( stdin, NULL );
        scanf( "%c", pChar );
        if ( *pChar == 'S' ) {
            printf( "\nInsira o nome da pessoa: " );
            setbuf( stdin, NULL );
            scanf( "%s", pessoas[*pInt2].nome );
            printf( "\nInsira a idade da pessoa: " );
            scanf( "%d", &pessoas[*pInt2].idade );
            printf( "\nInsira o telefone da pessoa: " );
            scanf( "%d", &pessoas[*pInt2].telefone );

            ( *pInt2 )++;

            continue;
        }
        else if ( *pChar == 'N' ) {
            break;
        } else {
            printf( "\nEntrada invalida, insira novamente" );
        }
    }

    for( *pInt1 = 0; *pInt1 < *pInt2; ( *pInt1 )++ ) {
        printf( "\n##########################" );
        printf( "\nNome: %s", pessoas[*pInt1].nome );
        printf( "\nIdade: %d", pessoas[*pInt1].idade );
        printf( "\ntelefone: %d", pessoas[*pInt1].telefone );
    }

    free ( pBuffer );

    return 0;
}
