// Faça um programa que armazena nomes.
// O programa deve armazenar todos os names na mesma string
// O tamanho da string deve crescer e diminuir conforme nomes
// forem colocados ou removidos.
// Não pode ter desperdício de memória.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *AddName(char *agenda, int *size) {
    char c = '\0';
    do {
        (*size)++;
        c = getchar();
        if (c != '\n') {
            agenda = (char *)realloc(agenda, sizeof(char) * (*size));
            agenda[(*size) - 1] = c;
        } else {
            agenda[(*size) - 1] = '\0';
        }
    } while (c != '\n');
    
    return agenda;
}

void ListAgenda(char *agenda, int *size){
        for (int i = 0; i < (*size) - 1; i++) {
            if(agenda[i] == '\0' || i == 0)
                printf("\nNome: ");
        printf("%c", agenda[i]);
    }
    printf("\n");
}

int main() {

    char *agenda = (char *)malloc(sizeof(char));
    int agendaSize = 0;
    int a = 0;

    int userChoice = 0;
    
    do
    {
        printf("\n-----Faca sua escolha-----\n1) Adicionar nome\n2) Remover nome\n3) Listar nome\n4) Parar\nSua escolha: ");

        scanf("%d", &userChoice);
        fgetc(stdin);

        switch (userChoice)
        {
        case 1:
            printf("\nInsira o nome: ");
            agenda = AddName(agenda, &agendaSize);
            break;

        case 3:
            ListAgenda(agenda, &agendaSize);
            break;

        case 4:
            break;
        
        default:
            printf("\nEntrada invalida! Insira novamente.");
            break;
        }

    } while (userChoice != 4);
    

        
    free(agenda);

    return 0;
}