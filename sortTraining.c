#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


typedef struct Array {
    int *data;
    int size;
} Array;

Array *init(int s) {
    Array *arr = malloc(sizeof(Array));
    arr->size = s;
    arr->data = malloc(sizeof(int) * arr->size);
    return arr;
}
        // array[i] = rand() % 10;

Array *createCopy(Array *arr) {
    Array *newArray = malloc(sizeof(Array));
    newArray->data = malloc(sizeof(int) * arr->size);

    for (int i = 0; i < arr->size; i++)
        newArray->data[i] = arr->data[i];
    
    newArray->size = arr->size;
    return newArray;
}

void randomizeArray(Array **arr) {
    srand(time(NULL));

    for(int i = 0; i < (*arr)->size; i++) {
        (*arr)->data[i] = rand() % 100;
        // (*arr)->data[i] = i;
    }

}

void printArray(Array *arr) {
    printf("\n");

    for(int i = 0; i < arr->size; i++)
        printf("%d ", arr->data[i]);
}

void SelectionSort(Array *arr) {
    for(int i = 0; i<arr->size; i++){
        int smallestIndex = i;
        for(int j = i+1; j<arr->size; j++){
            if(arr->data[j] < arr->data[smallestIndex])
                smallestIndex = j;
        }
        int aux = arr->data[i];
        arr->data[i] = arr->data[smallestIndex];
        arr->data[smallestIndex] = aux;
    }
}

void InsertionSort(Array *arr) {
    for(int i = 1; i < arr->size; i++) 
        for (int j = 0; j < i; j++)
            if(arr->data[j] > arr->data[i]){
                int aux = arr->data[i];
                arr->data[i] = arr->data[j];
                arr->data[j] = aux;
            }
}


Array *Merge(Array *left, Array *right) {


    // Array *result = init(left->size + right->size);

    printf("\n%d\n", left->size);

    // int i = 0, j = 0;
    // while(i < left->size || j < right->size) {
    //     if(left->data[i] <= right->data[j]){
    //         result->data[i+j] = left->data[i];
    //         i++;
    //     } else if (right->data[j] < left->data[i]) {
    //         result->data[i+j] = right->data[j];
    //         j++;
    //     }
    // }

    // return result;

}

Array *MergeSort(Array *arr) {
    if(arr->size <= 1)
        return arr;
    
    int half = arr->size / 2;

    Array *left = init(arr->size-half);
    Array *right = init(half);
    Array *result;

    memmove(left->data, arr->data, sizeof(int) * (arr->size - half));
    memmove(right->data, (arr->data)+(arr->size - half), sizeof(int) * (half));
    
 

    // printf("\nLeft:");
    // printArray(left);

    // printf("\nRight:");
    // printArray(right);  

    left = MergeSort(left);
    right = MergeSort(right);
    result = Merge(left, right);

    // return result;
    
}


int main(int argc, char const *argv[])
{
    Array *arr1 = init(5);

    randomizeArray(&arr1);

    Array *insertion = createCopy(arr1);
    Array *selection = createCopy(arr1);
    // Array *quick = createCopy(arr1);
    Array *merge = createCopy(arr1);

    printf("\nOriginal array:");
    printArray(arr1);

    printf("\nInsertion array:");
    InsertionSort(insertion);
    printArray(insertion);

    printf("\nSelection array:");
    SelectionSort(selection);
    printArray(selection);

    printf("\nMerge array:");
    MergeSort(merge);
    printArray(merge);

    return 0;
}
