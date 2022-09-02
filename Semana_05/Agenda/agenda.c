#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pessoa
// char nome[10]
// int idade;
// char telefone[18]

void *pBuffer;
void *ppBuffer;
void *pessoaAtual;

int GetNPessoas()
{
    ppBuffer = pBuffer;
    ppBuffer += sizeof(char) + sizeof(int);
    return *((int *)(ppBuffer));
}

int GetI()
{
    ppBuffer = pBuffer;
    ppBuffer += sizeof(char);
    return *((int *)(ppBuffer));
}



int main(int argc, char const *argv[])
{
    pBuffer = malloc(sizeof(char) * 1 + sizeof(int) * 2);
    ppBuffer = pBuffer;
    GetNPessoas();
    *(int *)(ppBuffer) = 0;
    // | OP | INT qualquer| N pessoas (int)

    do
    {

        printf("\nDeseja inserir uma nova pessoa?\nS - Sim\nN - Nao\nSua escolha: ");
        setbuf( stdin, NULL );
        scanf("%c", pBuffer);

        switch (*(char *)(pBuffer))
        {
        case 'S':
            GetNPessoas();
            (*(int *)(ppBuffer))++;

            printf("\n|%d|\n", GetNPessoas());
            pBuffer = realloc(pBuffer, sizeof(char) * 1 + sizeof(int) * 2 + sizeof(char) * 10 * GetNPessoas() + sizeof(int) * GetNPessoas() + sizeof(char) * 18 * GetNPessoas());


            pessoaAtual = pBuffer + sizeof(char) + sizeof(int) * 2;
            GetI();

            for(*(int *)(ppBuffer) = 1; GetNPessoas() > GetI(); (*(int *)(ppBuffer))++) {
                pessoaAtual += sizeof(char) * 10 + sizeof(int) + sizeof(char) * 18;
            }

            setbuf( stdin, NULL );
            scanf("%s", pessoaAtual);

            printf("%s", pessoaAtual);

            // printf("\nInsira o nome: ");

            // printf("\nInsira a idade: ");

            // printf("\nInsira o telefone: ");
            break;

        case 'N':

            break;

        default:
            break;
        }
    } while (*(char *)(pBuffer) != 'N');

    pessoaAtual = pBuffer + sizeof(char) + sizeof(int) * 2;
    printf("\n\n%s", pessoaAtual);
    pessoaAtual += sizeof(char) * 10 + sizeof(int) + sizeof(char) * 18;
    printf("\n\n%s", pessoaAtual);


    

    return 0;
}