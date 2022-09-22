#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list
{
    int *number;
    int numberOfElements;
} LIST;

void Reset(LIST **list)
{
    free(list);
    *list = (LIST *)malloc(sizeof(int) * 2);
    if (!(*list))
    {
        printf("Error: lack of memory");
        exit(1);
    }
    (**list).number = NULL;
    (**list).numberOfElements = 0;
}

void Push(LIST *list, int number, int i)
{
    if (!(i < 0 || i > list->numberOfElements))
    {
        if (i == list->numberOfElements)
        {
            list->number = (int *)realloc(list->number, sizeof(int) * list->numberOfElements);
            list->numberOfElements++;
        }
        list->number[i] = number;
    }
}

void Pop(LIST *list, int i)
{
    if(i >= 0 && i <= list->numberOfElements){
        
    }
}

void List(LIST *list)
{
    int i = 0;
    while (i < list->numberOfElements)
    {
        printf(" %d ", list->number[i]);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    LIST *l;
    Reset(&l);
    Push(l, 10, 0);
    Push(l, 12, 1);
    Push(l, 10, 2);
    Push(l, 15, 3);

    printf("\nL1:");
    List(l);
    return 0;
}
