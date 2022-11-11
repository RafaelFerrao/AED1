#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int numberOfElements;

typedef struct _list
{
    int *array;
    int sizeOfArray;
} List;

void SelectionSort(int *array)
{
    int aux, min, minIndex;
    for (int i = 0; i < numberOfElements; i++)
    {
        min = array[i];
        minIndex = i;

        for (int j = i + 1; j < numberOfElements; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                minIndex = j;
            }
        }
        aux = array[i];
        array[i] = min;
        array[minIndex] = aux;
    }
}

void InsertionSort(int *array)
{
    int aux;
    int i;
    for (int j = 0; j < numberOfElements; j++)
    {
        i = j - 1;
        aux = array[j];
        while (i >= 0 && aux < array[i])
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = aux;
    }
}

void PrintArray(int *array)
{
    for (int i = 0; i < numberOfElements; i++)
        if (i != numberOfElements - 1)
            printf(" %d |", array[i]);
        else
            printf(" %d ", array[i]);
}

// int Pop(List *list, int index) {
//     int aux = list->array[index];
//     for(int i = index; i+1 < list->sizeOfArray; i++){
//         list->array[i] = list->array[i+1];
//     }
//     list->sizeOfArray--;
//     list->array = realloc(list->array, sizeof(int) * list->sizeOfArray);
//     return aux;
// }

void Push(List *list, int value) {
    // list->array = realloc(list->array, sizeof(int) * (list->sizeOfArray+1));
    list->array[list->sizeOfArray] = value;
    list->sizeOfArray++;
}

List *Reset() {
    List *list;
    list = (List *)malloc(sizeof(List));
    list->array = (int *)malloc(sizeof(int));
    list->sizeOfArray = 0;
    return list;
}

List *Merge(List *left, List *right){
    List *result;
    result = malloc(sizeof(List));
    result->sizeOfArray = 0;
    result->array = malloc( sizeof(int) * (left->sizeOfArray + right->sizeOfArray) );

    int i = 0;
    int j = 0;

    while(left->sizeOfArray > 0 || right->sizeOfArray > 0) {
        if(left->sizeOfArray > 0 && right->sizeOfArray > 0) {
            if(left->array[i] <= right->array[j]){
                Push(result, left->array[i]);
                i++;
                left->sizeOfArray--;
            }
            else {
                Push(result, right->array[j]);
                right->sizeOfArray--;
                j++;
            }
        } else if (left->sizeOfArray > 0) {
                Push(result, left->array[i]);
                left->sizeOfArray--;
                i++;
        }
        else if (right->sizeOfArray > 0){
                Push(result, right->array[j]);
                right->sizeOfArray--;
                j++;
        }
    }
    return result;
}

List *MergeSort(List *list){
    if(list->sizeOfArray <= 1)
        return list;
    List *left, *right, *result;

    left = Reset();
    right = Reset();

    int size = list->sizeOfArray;
    int pivot = list->sizeOfArray/2;
    left->array = malloc(sizeof(int) * pivot+1);
    right->array = malloc(sizeof(int) * (size - pivot+1));


    int j = 0;
    for(int i = 0; i < pivot; i++){
        Push(left, list->array[j]);
        j++;
        list->sizeOfArray--;
    }

    for(int i = pivot; i < size; i++){
        Push(right, list->array[i]);
        list->sizeOfArray--;
    }
    
    left = MergeSort(left);
    right = MergeSort(right);
    result = Merge(left, right);
    return result;
}

void QuickSort(int *array, int left, int right) {
    int mid, tmp, i, j;
    i = left;
    j = right;
    mid = array[(left + right)/2];
    do {
        while(array[i] < mid) 
            i++;
        while(mid < array[j])
            j--;
        if (i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if(left < j)
        QuickSort(array, left, j);
    if(i < right)
        QuickSort(array, i, right);
    
}



int *CreateArrayCopy(int *array)
{
    int *arrayCopy = (int *)malloc(sizeof(int) * numberOfElements);
    // for (int i = 0; i < numberOfElements; i++)
    //     arrayCopy[i] = array[i];

    memcpy(arrayCopy, array, sizeof(int) * numberOfElements);
    return arrayCopy;
}

int RandomizeArrayElements(int *array)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        array[i] = rand() % 10;
    }
}

int main(int argc, char const *argv[])
{
    int *array;

    srand(time(NULL));

    printf("\nInsert the array length: ");
    scanf("%d", &numberOfElements);

    array = (int *)malloc(sizeof(int) * numberOfElements);

    RandomizeArrayElements(array);

    // printf("\n Original array:");
    // PrintArray(array);

    //Execution time measure 
    struct timespec begin, end; 
    long seconds;
    long nanoseconds;
    double elapsed;

    // SelectionSort
    int *selectionSortBuffer;
    selectionSortBuffer = CreateArrayCopy(array);
    clock_gettime(CLOCK_REALTIME, &begin);
    SelectionSort(selectionSortBuffer);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    printf("\n SelectionSort:");
    printf("\nTime measured: %.7f seconds.\n", elapsed);
    // PrintArray(selectionSortBuffer);



    // InsertionSort
    int *insertionSortBuffer;
    insertionSortBuffer = CreateArrayCopy(array);
    clock_gettime(CLOCK_REALTIME, &begin);
    InsertionSort(insertionSortBuffer);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    printf("\n InsertionSort:");
    printf("\nTime measured: %.7f seconds.\n", elapsed);

    // PrintArray(insertionSortBuffer);



    //QuickSort
    int *quickSortBuffer;
    quickSortBuffer = CreateArrayCopy(array);

    clock_gettime(CLOCK_REALTIME, &begin);
    QuickSort(quickSortBuffer, 0, numberOfElements - 1);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    printf("\n QuickSort:");
    // PrintArray(quickSortBuffer);
    printf("\nTime measured: %.7f seconds.\n", elapsed);

    //MergeSort
    List *mergeSortList;
    mergeSortList = Reset();
    mergeSortList->array = CreateArrayCopy(array);
    mergeSortList->sizeOfArray = numberOfElements;
    clock_gettime(CLOCK_REALTIME, &begin);
    mergeSortList = MergeSort(mergeSortList);
    // PrintArray(mergeSortList->array);
    clock_gettime(CLOCK_REALTIME, &end);
    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed = seconds + nanoseconds*1e-9;
    printf("\nMergeSort:");
    printf("\nTime measured: %.7f seconds.\n", elapsed);










    free(array);

    return 0;
}
