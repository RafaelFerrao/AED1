#include <stdio.h>
#include <stdlib.h>

int numberOfElements;



void SelectionSort(int *array) {
    int aux, min, minIndex;
    for(int i = 0; i < numberOfElements; i++) {
        min = array[i];
        minIndex = i;
        
        for(int j = i+1; j < numberOfElements; j++){
            if(array[j] < min) {
                min = array[j];
                minIndex = j;
            }
        }
        aux = array[i];
        array[i] = min;
        array[minIndex] = aux;
    }
}


void InsertionSort(int *array) {
    int aux;
    int i;
    for(int j = 0; j < numberOfElements; j++) {
        i = j - 1;
        aux = array[j];
        while( i >= 0 &&  aux < array[i]){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = aux;
    }
}

void PrintArray(int *array){
    for(int i = 0; i < numberOfElements; i++)
        if(i != numberOfElements - 1)
            printf(" %d |", array[i]);
        else
            printf(" %d ", array[i]);

}

int *CreateArrayCopy(int *array) {
    int *arrayCopy = (int *) malloc (sizeof(int) * numberOfElements);
    for(int i = 0; i < numberOfElements; i++)
        arrayCopy[i] = array[i];
    return arrayCopy;
}


int main(int argc, char const *argv[])
{
    int *pBuffer;

    numberOfElements = 4;

    // printf("\nInsert the array length: ");
    // scanf("%d", &numberOfElements);

    pBuffer = (int *) malloc (sizeof(int) * numberOfElements);
    pBuffer[0] = 3;
    pBuffer[1] = 7;
    pBuffer[2] = 22;
    pBuffer[3] = 2;

    printf("\n Original array:");
    PrintArray(pBuffer);


    //SelectionSort
    int *selectionSortBuffer;
    selectionSortBuffer = CreateArrayCopy(pBuffer);
    SelectionSort(selectionSortBuffer);
    printf("\n SelectionSort:");
    PrintArray(selectionSortBuffer);

    //InsertionSort
    int *insertionSortBuffer;
    insertionSortBuffer = CreateArrayCopy(pBuffer);
    InsertionSort(insertionSortBuffer);
    printf("\n InsertionSort:");
    PrintArray(insertionSortBuffer);

     


    free(pBuffer);

    return 0;
}
