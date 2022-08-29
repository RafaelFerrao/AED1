#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    void *buffer;
    void *pBuffer;
    char *tipos;
    char *pTipos;
    int sizeBuffer = 0;
    int totalNums = 0;
    int op;
    int opTipo;
    buffer = malloc(sizeof(char));
    tipos = malloc(sizeof(char));

    do
    {
        printf("\nVoce deseja inserir um numero? 1 - Sim;  2 - Nao: ");
        setbuf(stdin, NULL);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nQual o tipo do numero inserido? ");
            printf("\n1- Inteiro");
            printf("\n2- Double");
            printf("\n3- Float");
            printf("\nSua escolha:");

            setbuf(stdin, NULL);
            scanf("%d", &opTipo);
            printf("\nInsira o numero: ");

            if (opTipo == 1)
            {
                tipos = realloc( tipos, sizeof(char) * totalNums + 1);
                pTipos = tipos;
                pTipos[totalNums] = 'i';
                sizeBuffer += sizeof(int);
                buffer = realloc(buffer, sizeBuffer);
                pBuffer = buffer;
                if(totalNums == 0)
                    scanf("%d", pBuffer);
                else
                    scanf("%d", pBuffer + sizeof(sizeBuffer) - sizeof(int));
                totalNums++;
            }
            else if (opTipo == 2)
            {
                sizeBuffer += sizeof(double);
                buffer = realloc(buffer, sizeBuffer);
                pBuffer = buffer;
                if (totalNums == 0)
                    scanf("%lf", pBuffer);
                else
                    scanf("%lf", pBuffer + sizeof(sizeBuffer) - sizeof(double));

                pTipos = 'd';
                pTipos++;
                totalNums++;
            }
            else if (opTipo == 3)
            {
                sizeBuffer += sizeof(float);
                buffer = realloc(buffer, sizeBuffer);
                pBuffer = buffer;
                if (totalNums == 0)
                    scanf("%f", pBuffer);
                else
                    scanf("%f", pBuffer + sizeof(sizeBuffer) - sizeof(float));

                pTipos = 'f';
                pTipos++;
                totalNums++;
            }
            break;

        case 2:
            break;

        default:
            printf("\nEntrada invalida, insira novamente");
            break;
        }
    } while (op != 2);

    pBuffer = buffer;
    pTipos = tipos;

    printf("%d", *((int *)(buffer)));
    printf("| %d", *((int *)(pBuffer)));

    // for (int i = 0; i < totalNums; i++) {
    //     printf("\n| %c |", pTipos[i]);
    //     if (pTipos[i] == 'i') {
    //         printf(" %d ", *((int *)(pBuffer)));
    //         pBuffer += sizeof(int);
    //     }
        // else if (*pTipos == 'f') {
        //     printf(" %f ", *((float *)(pBuffer)));
        //     pBuffer += sizeof(float);
        // }
        // else if (*pTipos == 'd') {
        //     printf(" %lf ", *((double *)(pBuffer)));
        //     pBuffer += sizeof(double);
        // }
        // pTipos++;
    // }
}