// Considere um cadastro de produtos de um estoque, com as seguintes informac¸oes para ˜
// cada produto:
// • Codigo de identificac¸ ´ ao do produto: representado por um valor inteiro ˜
// • Nome do produto: com ate 50 caracteres ´
// • Quantidade dispon´ıvel no estoque: representado por um numero inteiro ´
// • Prec¸o de venda: representado por um valor real
// (a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para
// guardar as informac¸oes de um produto ˜
// (b) Crie um conjunto de N produtos (N e um valor fornecido pelo usu ´ ario) e pec¸a ao ´
// usuario para entrar com as informac¸ ´ oes de cada produto ˜
// (c) Encontre o produto com o maior prec¸o de venda
// (d) Encontre o produto com a maior quantidade dispon´ıvel no estoque

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{
    int id;
    char nome[50];
    int estoque;
    float preco;
};

typedef struct Produto prod;

char *InserirNome(char *nome)
{
    char c = '0';
    int i = 0;
    getchar();
    do
    {
        c = getchar();
        if (c != '\n')
            nome[i] = c;
        else
            nome[i] = '\0';

        i++;

    } while (c != '\n');

    return nome;
}

int main()
{
    prod *buffer = malloc(sizeof(prod));
    prod *prodContador = buffer;
    void *pBuffer = buffer;
    int *pId;
    char *pNome;
    int *pEstoque;
    float *pPreco;

    int n = 0;
    printf("Digite a quantidade de produtos que deseja inserir: ");
    scanf("%d", &n);

    char nome[50];

    for (int i = 1; i <= n; i++)
    {
        buffer = realloc(buffer, sizeof(prod) * i);
        prodContador = buffer;

        for (int j = 1; j < i; j++)
        {
            prodContador++;
        }

        pBuffer = prodContador;

        pId = pBuffer;
        pNome = pBuffer + sizeof(int);
        pEstoque = pBuffer + sizeof(int) + sizeof(char) * 50;
        pPreco = pBuffer + sizeof(int) + sizeof(char) * 50 + sizeof(int);

        printf("\nInsira o cddigo do produto: ");
        scanf("%d", pId);
        printf("\nInsira o nome do produto: ");
        strcpy(pNome, InserirNome(nome));
        printf("\nInsira a quantia em estoque do produto: ");
        scanf("%d", pEstoque);
        printf("\nInsira o preco do produto: ");
        scanf("%f", pPreco);
    }

    // pBuffer = buffer;

    for (int i = 1; i <= n; i++)
    {

        prodContador = buffer;

        for (int j = 1; j < i; j++)
        {
            prodContador++;
        }

        pBuffer = prodContador;

        pId = pBuffer;
        pNome = pBuffer + sizeof(int);
        pEstoque = pBuffer + sizeof(int) + sizeof(char) * 50;
        pPreco = pBuffer + sizeof(int) + sizeof(char) * 50 + sizeof(int);

        printf("\n----------\nCodigo: ");
        printf("%d", *pId);
        printf("\nNome: ");
        printf("%s", pNome);
        printf("\nEstoque: ");
        printf("%d", *pEstoque);
        printf("\nPreco: R$ ");
        printf("%.2f", *pPreco);
    }

    float maiorPreco;
    prodContador = buffer;

    for (int i = 1; i <= n; i++)
    {
        pBuffer = prodContador;
        pPreco = pBuffer + sizeof(int) + sizeof(char) * 50 + sizeof(int);

        if (i == 1)
            maiorPreco = *pPreco;
        else if (maiorPreco < *pPreco)
            maiorPreco = *pPreco;
        prodContador++;
    }

    prodContador = buffer;

    for (int i = 1; i <= n; i++)
    {
        pBuffer = prodContador;
        pPreco = pBuffer + sizeof(int) + sizeof(char) * 50 + sizeof(int);

        if (maiorPreco == *pPreco)
        {
            pId = pBuffer;
            pNome = pBuffer + sizeof(int);
            pEstoque = pBuffer + sizeof(int) + sizeof(char) * 50;
            pPreco = pBuffer + sizeof(int) + sizeof(char) * 50 + sizeof(int);
            printf("%d", pPreco);


            break;
        }
        prodContador++;
    }

    printf("\n------------\nMaior preco\n");
    printf("\nCodigo: ");
    printf("%d", *pId);
    printf("\nNome: ");
    printf("%s", pNome);
    printf("\nEstoque: ");
    printf("%d", *pEstoque);
    printf("\nPreco: R$ ");
    printf("%f", *pPreco);

    int maiorEstoque;
    prodContador = buffer;

    for (int i = 1; i <= n; i++)
    {
        pBuffer = prodContador;
        pEstoque = pBuffer + sizeof(int) + sizeof(char) * 50;

        if (i == 1)
            maiorEstoque = *pEstoque;
        else if (maiorEstoque < *pEstoque)
            maiorEstoque = *pEstoque;
        prodContador++;
    }

    prodContador = buffer;

    for (int i = 1; i <= n; i++)
    {
        pBuffer = prodContador;
        pEstoque = pBuffer + sizeof(int) + sizeof(char) * 50;

        if (maiorEstoque == *pEstoque)
        {
            pId = pBuffer;
            pNome = pBuffer + sizeof(int);
            pPreco = pBuffer + sizeof(int) + sizeof(char) * 50 + sizeof(int);
            break;
        }
        prodContador++;
    }

    printf("\n------------\nMaior estoque\n");
    printf("\nCodigo: ");
    printf("%d", *pId);
    printf("\nNome: ");
    printf("%s", pNome);
    printf("\nEstoque: ");
    printf("%d", *pEstoque);
    printf("\nPreco: R$ ");
    printf("%f", *pPreco);

    free(buffer);

    return 0;
}
