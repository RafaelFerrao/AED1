#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    void *buffer;
    void *pBuffer;
    int *intBuffer = malloc(sizeof(int));
    int *pInt;
    int nInt = 0;
    float *floatBuffer = malloc(sizeof(float));
    float *pFloat;
    int nFloat = 0;
    double *doubleBuffer = malloc(sizeof(double));
    double *pDouble;
    int nDouble = 0;
    int sizeBuffer = 0;
    int totalNums = 0;
    int op;
    int opTipo;
    buffer = malloc(sizeof(char));

    do {
        printf( "\nVoce deseja inserir um numero? 1 - Sim;  2 - Nao: " );
        setbuf( stdin, NULL );
        scanf( "%d", &op );
        switch (op)
        {
        case 1:
            printf( "\nQual o tipo do numero inserido? ");
            printf( "\n1- Inteiro");
            printf( "\n2- Double");
            printf( "\n3- Float");
            printf( "\nSua escolha:");

            setbuf( stdin, NULL );
            scanf( "%d", &opTipo );
            printf( "\nInsira o numero: " );

            if( opTipo == 1 ){
                sizeBuffer += sizeof(int);
                buffer = realloc( buffer, sizeBuffer );
                pBuffer = buffer;
                nInt++;
                intBuffer = realloc( intBuffer, sizeof(int) * nInt);
                pInt = intBuffer;
                if(totalNums == 0){
                    scanf( "%d", pBuffer );
                    *intBuffer = *((int *)pBuffer);
                } else {
                    scanf( "%d", pBuffer + sizeof(sizeBuffer) - sizeof(int));
                    for(int i = 1; i < nInt; i++){
                        pInt++;
                    }
                    *pInt = *((int *)(pBuffer + sizeof(sizeBuffer) - sizeof(int)));
                }

                totalNums++;
            } else if( opTipo == 2 ) {
                sizeBuffer += sizeof(double);
                buffer = realloc( buffer, sizeBuffer );
                pBuffer = buffer;
                nDouble++;
                doubleBuffer = realloc( doubleBuffer, sizeof(double) * nDouble);
                pDouble = doubleBuffer;
                if(totalNums == 0){
                    scanf( "%d", pBuffer );
                    *doubleBuffer = *((double *)pBuffer);
                } else {
                    scanf( "%d", pBuffer + sizeof(sizeBuffer) - sizeof(double));
                    for(int i = 1; i < nDouble; i++){
                        pDouble++;
                    }
                    *pDouble = *((double *)(pBuffer + sizeof(sizeBuffer) - sizeof(double)));
                }

                totalNums++;
            } else if ( opTipo == 3 ){
                sizeBuffer += sizeof(float);
                buffer = realloc( buffer, sizeBuffer );
                pBuffer = buffer;
                nFloat++;
                floatBuffer = realloc( floatBuffer, sizeof(float) * nFloat);
                pFloat = floatBuffer;
                if(totalNums == 0){
                    scanf( "%f", pBuffer );
                    *floatBuffer = *((float *)pBuffer);
                } else {
                    scanf( "%f", pBuffer + sizeof(sizeBuffer) - sizeof(float));
                    for(int i = 1; i < nFloat; i++){
                        pFloat++;
                    }
                    *pFloat = *((float *)(pBuffer + sizeof(sizeBuffer) - sizeof(float)));
                }

                totalNums++;
            }
            break;
        case 2:
            break;
        
        default:
            printf( "\nEntrada invalida, insira novamente" );
            break;
        }



    } while ( op != 2 );

    // printf("\n Todos os numeros: ");
    // for( int i = 0; i < totalNums; i++ ){
    //     printf( "%f", *pBuffer );
    // }

    // printf( "%d", nInt );

    pInt = intBuffer;
    pFloat = floatBuffer;
    pDouble = doubleBuffer;

    printf("\nInteiros: ");
    for( int i = 0; i < nInt; i++ ){
        printf( "| %d |", *pInt );
        pInt++;
    }

    printf("\n");

    printf("\nFloat: ");


    for( int i = 0; i < nFloat; i++ ){
        printf( "| %f |", *pFloat );
        pFloat++;
    }

    printf("\n");

    printf("\nDouble: ");


    for( int i = 0; i < nDouble; i++ ){
        printf( "%d", *pDouble );
        pDouble++;
    }

    return 0;
}
