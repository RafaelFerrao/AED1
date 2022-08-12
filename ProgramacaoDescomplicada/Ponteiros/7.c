// Crie um programa que contenha uma func¸ao que permita passar por par ˜ ametro dois ˆ
// numeros inteiros A e B. A func¸ ´ ao dever ˜ a calcular a soma entre estes dois n ´ umeros e ´
// armazenar o resultado na variavel A. Esta func¸ ´ ao n ˜ ao dever ˜ a possuir retorno, mas dever ´ a´
// modificar o valor do primeiro parametro. Imprima os valores de A e B na func¸ ˜ ao principal.

#include <stdio.h>

void Soma(int *a, int *b){
    *a = *a + *b;
}

int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 5;

    Soma(&a, &b);

    printf("A: %d\n", a);
    printf("B: %d", b);

    return 0;
}
