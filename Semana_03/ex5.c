#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
    int altura;
} pessoa_t;

pessoa_t *buffer;
pessoa_t *pBuffer;
char *ptrNome;
int *ptrIdade;
int *ptrAltura;

void SetPonteirosParaPessoaAtual(){
    ptrNome = ( char * )pBuffer;
    ptrIdade = ( int * )( pBuffer + sizeof( char )*30 );
    ptrAltura = ( int * )( pBuffer + sizeof( char )*30 + sizeof( int ) );
}
    
int main() {
    char op = '1';
    int nPessoas = 0;
    char nome[30];

    buffer = ( pessoa_t * )malloc( sizeof( pessoa_t ) );

    do {
        printf( "--------------------\nEscolha uma opcao\n1-Inserir nova pessoa\n0- Sair\nSua escolha: " );

        setbuf( stdin, NULL );
        op = getchar();

        switch ( op ){
        case '1':
            nPessoas++;
            buffer = realloc( buffer, sizeof( pessoa_t ) * nPessoas );
            pBuffer = buffer;

            for(int i = 1; i < nPessoas; i++) {
                pBuffer++;
            }

            SetPonteirosParaPessoaAtual();

            printf( "\n--------------------\nInsira o nome da pessoa: " );
            setbuf( stdin, NULL );
            gets( nome );
            strcpy( ptrNome, nome );

            printf( "\nInsira a idade da pessoa: " );
            setbuf( stdin, NULL );
            scanf( "%d", ptrIdade );

            printf( "\nInsira a altura da pessoa: " );
            setbuf( stdin, NULL );
            scanf( "%d", ptrAltura );
            // system( "cls" );
            break;

        case '0':
            pBuffer = buffer;
            for( int i = 0; i < nPessoas; i++ ){
            
            SetPonteirosParaPessoaAtual();

            printf( "\n---------------------" );
            printf( "\nNome: %s", ptrNome );
            printf( "\nIdade: %d", *ptrIdade );
            printf( "\nAltura: %d", *ptrAltura );
            pBuffer++;
            }
            break;

        default:
            printf( "\nEntrada invalida, insira novamente" );
            break;
        }
    } while ( op != '0' );

    
    free( buffer );

    return 0;
}