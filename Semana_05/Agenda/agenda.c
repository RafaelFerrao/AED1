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
int *pIdade;
void *pTelefone;
void *pBusca;

int GetNPessoas()
{
    ppBuffer = pBuffer;
    ppBuffer += sizeof(int) + sizeof(int);
    return *((int *)(ppBuffer));
}

int GetI()
{
    ppBuffer = pBuffer;
    ppBuffer += sizeof(int);
    return *((int *)(ppBuffer));
}

int SizeCabecalho()
{
    return (sizeof(int) * 3 + sizeof(char) * 10);
} // | INT OP | INT qualquer| INT N pessoas  | CHAR [10] Nome Busca

int SizePessoa()
{
    return (sizeof(char) * 10 + sizeof(int) + sizeof(char) * 18);
} // | Nome | Idade | Telefone


void NextPessoa()
{
    pessoaAtual += SizePessoa();
}


int GetIdade()
{
    pIdade = (int *)(pessoaAtual + sizeof(char) * 10);
    return *(pIdade);
}

char *GetTelefone()
{
    pTelefone = (char *)(pessoaAtual + sizeof(char) * 10 + sizeof(int));
    return pTelefone;
}

void GoToPrimeiraPessoa()
{
    pessoaAtual = pBuffer + SizeCabecalho();
}

char *GetBusca()
{
    pBusca = pBuffer + sizeof(int) * 3;
    return pBusca;
}

int main(int argc, char const *argv[])
{
    pBuffer = malloc(SizeCabecalho());
    ppBuffer = pBuffer;
    GetNPessoas();
    *(int *)(ppBuffer) = 0;

    do
    {
        printf("\nO que deseja fazer?\n1 - Incluir\n2 - Apagar\n3 - Buscar\n4 - Listar\n0 - Sair\nSua escolha: ");
        setbuf(stdin, NULL);
        scanf("%d", pBuffer);

        switch (*(int *)(pBuffer))
        {
        case 1:
            GetNPessoas(); // Seta o ppBuffer no endereço onde está o "NPessoas". Então é útil para o incremento do mesmo.
            (*(int *)(ppBuffer))++;

            printf("\n|%d|\n", GetNPessoas());
            pBuffer = realloc(pBuffer, SizeCabecalho() + SizePessoa() * GetNPessoas());

            GoToPrimeiraPessoa();
            GetI();

            for (*(int *)(ppBuffer) = 1; GetNPessoas() > GetI(); (*(int *)(ppBuffer))++)
            {
                NextPessoa();
            }

            printf("\nInsira o nome: ");
            setbuf(stdin, NULL);
            scanf("%s", pessoaAtual);

            printf("\nInsira a idade: ");
            setbuf(stdin, NULL);
            GetIdade();
            scanf("%d", pIdade);

            printf("\nInsira o telefone: ");
            setbuf(stdin, NULL);
            GetTelefone();
            scanf("%s", pTelefone);
            break;

        case 2:
            printf("\nInsira o nome que deseja remover: ");
            setbuf(stdin, NULL);
            GetBusca();
            scanf("%s", pBusca);
            GoToPrimeiraPessoa();
            GetI();
            for (*(int *)(ppBuffer) = 0; (GetNPessoas() > GetI()); (*(int *)(ppBuffer))++)
            {
                if (strcmp(pessoaAtual, pBusca) == 0)
                {
                    printf("A: %d", GetNPessoas());
                    printf("B: %d", GetI());
                    GetNPessoas();
                    (*(int *)(ppBuffer))--;
                    if(GetI() != GetNPessoas()){
                        memcpy(pessoaAtual, (pessoaAtual + SizePessoa()), SizePessoa() * ( GetNPessoas() - GetI() ));
                    }
                    
                    pBuffer = realloc( pBuffer, SizeCabecalho() + SizePessoa() * (GetNPessoas() - GetI() + 2));
                    break;
                }
                NextPessoa();
            }
            break;

        case 3:
            printf("\nInsira o nome que deseja buscar: ");
            setbuf(stdin, NULL);
            GetBusca();
            scanf("%s", pBusca);
            GoToPrimeiraPessoa();
            GetI();

            for (*(int *)(ppBuffer) = 0; (GetNPessoas() > GetI()); (*(int *)(ppBuffer))++)
            {
                if (strcmp(pessoaAtual, pBusca) == 0)
                {
                    printf("\n%s | %d anos | %s ", pessoaAtual, GetIdade(), GetTelefone());
                    break;
                }
                NextPessoa();
            }
            if (strcmp(pessoaAtual, pBusca) != 0)
                printf("\nNome nao encontrado.");
            break;

        case 4:
            GoToPrimeiraPessoa();
            GetI();

            for (*(int *)(ppBuffer) = 0; GetNPessoas() > GetI(); (*(int *)(ppBuffer))++)
            {
                printf("\n%s | %d anos | %s ", pessoaAtual, GetIdade(), GetTelefone());
                NextPessoa();
            }

        case 0:
            break;

        default:
            break;
        }
    } while (*(int *)(pBuffer) != 0);

    free(pBuffer);

    return 0;
}