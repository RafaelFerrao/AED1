// Faça um programa que armazena nomes.
// O programa deve armazenar todos os names na mesma string
// O tamanho da string deve crescer e diminuir conforme nomes
// forem colocados ou removidos.
// Não pode ter desperdício de memória.

#include <stdio.h>
#include <stdlib.h>

void AddName(int *nameListCharAmount, char *nameList);
void ListNames(int *nameListCharAmount, char *nameList);

int main()
{
    char *nameList;

    nameList = (char *)malloc(sizeof(char) * 1);
    if (!nameList)
        printf("Erro! Falta de memoria");
    int nameListCharAmount = 0;
    int namesAmount = 0;

    AddName(&nameListCharAmount, nameList);
    AddName(&nameListCharAmount, nameList);

    ListNames(&nameListCharAmount, nameList);


    // int a = 0;
    // char userChoice;
    // do
    // {

    //     printf("----Insira a opcao desejada----\n1) Adicionar nome\n2) Remover nome\n3) Listar\n4) Sair\n\nSua escolha:");
    //     scanf("%c", &userChoice);
    //     switch (userChoice)
    //     {
    //     case '1':
    //         printf("%c", userChoice);
    //         break;
    //     case '2':
    //         break;
    //     case '3':
    //         ListNames();
    //         break;
    //     case '4':
    //         break;
    //     }
    // } while (userChoice != '4');

    return 0;
}

/*
====================================================================================================
AddName
This function reads a String input from the user and save it in a dynamic char array.
During the input reading, the dynamic array will use realloc to fit itself to the user's input.
====================================================================================================
*/

void AddName(int *nameListCharAmount, char *nameList)
{

    while ((nameList[(*nameListCharAmount)] = fgetc(stdin)) != '\n')
    {
        ++(*nameListCharAmount);
        nameList = realloc(nameList, sizeof(char) * (*nameListCharAmount));
        if (!nameList)
            printf("Erro! Falta de memoria");
    }

    nameList[(*nameListCharAmount)] = '\0';
    (*nameListCharAmount)++;
}

/*
======================================================================================================
ListNames
This function prints the names in the array, one per line.
It funcionality allows it to print char per char of the string until it finds the '\0' between the names, wich I use as separators.
For each name, we have one separator.
======================================================================================================
*/

void ListNames(int *nameListCharAmount, char *nameList)
{
    for (int i = 0; i < (*nameListCharAmount) - 1; i++)
    {
        if (nameList[i] == '\0' || i == 0)
            printf("\nNome: ");
        printf("%c", nameList[i]);
    }
}