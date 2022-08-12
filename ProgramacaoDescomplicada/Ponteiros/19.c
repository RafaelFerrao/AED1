// Escreva uma func¸ao que aceita como par ˜ ametro um array de inteiros com N valores, e ˆ
// determina o maior elemento do array e o numero de vezes que este elemento ocorreu ´
// no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
// 8, 6, 15, a func¸ao deve retorna para o programa que a chamou o valor 15 e o n ˜ umero 3 ´
// (indicando que o numero 15 ocorreu 3 vezes). A func¸ ´ ao deve ser do tipo ˜ void.

#include <stdio.h>

int GetMaior(int *ptr, int size){
    int maior;
    for(int i = 0; i < size; i++){
        if(i == 0)
            maior = ptr[0];
        else
            if(maior < ptr[i])
                maior = ptr[i];
    }

    return maior;
}

void GetMaiorRepeticoes(int *ptr, int size, int *biggestNumRep, int *biggest){
    *biggest = GetMaior(ptr, size);

    for(int i = 0; i < size; i++){
        if((*biggest) == ptr[i])
            (*biggestNumRep)++;
    }
}


int main(int argc, char const *argv[])
{
    int v[9];
    int vSize = 9;

    int returnBiggest = 0;
    int returnBiggestRep = 0;

    v[0] = 5;
    v[1] = 2;
    v[2] = 15;
    v[3] = 3;
    v[4] = 7;
    v[5] = 15;
    v[6] = 8;
    v[7] = 6;
    v[8] = 15;

    GetMaiorRepeticoes(v, vSize, &returnBiggestRep, &returnBiggest);

    printf("\n%d", returnBiggest);
    printf("\n%d", returnBiggestRep);

    return 0;
}
