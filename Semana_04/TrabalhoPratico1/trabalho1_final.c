#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *buffer;
void *pBuffer;
char *tipos;
int sizeBuffer = 0;

void ImprimeSequencia(int totalNums)
{
    pBuffer = buffer;
    for (int i = 0; i < totalNums; i++)
    {
        printf("\n| %c |", tipos[i]);

        if (tipos[i] == 'i')
        {
            printf(" %d ", *((int *)(pBuffer)));
            pBuffer += sizeof(int);
        }
        else if (tipos[i] == 'f')
        {
            printf(" %f ", *((float *)(pBuffer)));
            pBuffer += sizeof(float);
        }
        else if (tipos[i] == 'd')
        {
            printf(" %lf ", *((double *)(pBuffer)));
            pBuffer += sizeof(double);
        }
    }
}

void ImprimeTipo(char tipoId, int totalNums)
{
    pBuffer = buffer;

    for (int i = 0; i < totalNums; i++)
    {
        switch (tipoId)
        {
        case 'i':
            if (tipos[i] == 'i')
                printf("| %d ", *((int *)(pBuffer)));
            break;
        case 'f':
            if (tipos[i] == 'f')
                printf("| %f ", *((float *)(pBuffer)));
            break;
        case 'd':
            if (tipos[i] == 'd')
                printf("| %lf ", *((double *)(pBuffer)));
            break;
        }

        if (tipos[i] == 'i')
        {
            pBuffer += sizeof(int);
        }
        else if (tipos[i] == 'f')
        {
            pBuffer += sizeof(float);
        }
        else if (tipos[i] == 'd')
        {
            pBuffer += sizeof(double);
        }
    }
    printf("|");
}

int main(int argc, char const *argv[])
{
    int totalNums = 0;
    char op;
    char opTipo;
    buffer = malloc(sizeof(char));
    tipos = malloc(sizeof(char));

    do
    {
        printf("\nVoce deseja inserir um numero? S - Sim;  N - Nao: ");
        setbuf(stdin, NULL);
        scanf("%c", &op);
        switch (op)
        {
        case 'S':
            printf("\nQual o tipo do numero inserido? ");
            printf("\nI- Inteiro");
            printf("\nF- Float");
            printf("\nD- Double");
            printf("\nSua escolha:");

            setbuf(stdin, NULL);
            scanf("%c", &opTipo);
            printf("\nInsira o numero: ");

            if (opTipo == 'I' || opTipo == 'i')
            {
                tipos = realloc(tipos, sizeof(char) * totalNums + 1);
                tipos[totalNums] = 'i';
                sizeBuffer += sizeof(int);
                buffer = realloc(buffer, sizeBuffer);
                pBuffer = buffer;
                pBuffer += sizeBuffer - sizeof(int);
                setbuf(stdin, NULL);
                scanf("%d", (int *)pBuffer);
                totalNums++;
            }

            else if (opTipo == 'F' || opTipo == 'f')
            {
                tipos = realloc(tipos, sizeof(char) * totalNums + 1);
                tipos[totalNums] = 'f';
                sizeBuffer += sizeof(float);
                buffer = realloc(buffer, sizeBuffer);
                pBuffer = buffer;
                pBuffer += sizeBuffer - sizeof(float);
                setbuf(stdin, NULL);
                scanf("%f", (float *)pBuffer);
                totalNums++;
            }
            else if (opTipo == 'D' || opTipo == 'd')
            {
                tipos = realloc(tipos, sizeof(char) * totalNums + 1);
                tipos[totalNums] = 'd';
                sizeBuffer += sizeof(double);
                buffer = realloc(buffer, sizeBuffer);
                pBuffer = buffer;
                pBuffer += sizeBuffer - sizeof(double);
                setbuf(stdin, NULL);
                scanf("%lf", (double *)pBuffer);
                totalNums++;
            }
            break;

        case 'N':
            break;

        default:
            printf("\nEntrada invalida, insira novamente");
            break;
        }
    } while (op != 'N');

    printf("\nValores sequenciais: ");

    ImprimeSequencia(totalNums);

    printf("\nValores inteiros: ");

    ImprimeTipo('i', totalNums);

    printf("\nValores floats: ");

    ImprimeTipo('f', totalNums);

    printf("\nValores double: ");

    ImprimeTipo('d', totalNums);

    free(buffer);
    free(tipos);
}