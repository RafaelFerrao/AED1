#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

#define MAX 4

typedef struct
{
    int age;
    char name[50];
} Person;

typedef struct
{
    Person people[MAX];
    int top;
    int base;
    int limit;
} Stack;

void Reset(Stack *stack)
{
    stack->top = 0;
    stack->base = 0;
    stack->limit = MAX;
};

bool Empty(Stack *stack)
{
    return stack->top == 0;
};

bool Full(Stack *stack)
{
    return stack->top == stack->limit;
};

bool Push(Stack *stack, Person *item)
{
    if (!Full(stack))
    {
        stack->people[stack->top] = *item;
        stack->top++;
        return true;
    }
    else
    {
        return false;
    }
};

void Pop(Stack *stack, Person *person)
{
    if (!Empty(stack))
    {
        stack->top--;
        *person = stack->people[stack->top];
    }
    else
    {
        return;
    }
};

void List(Stack *stack)
{
    Stack aux;
    Person p;
    Reset(&aux);
    if (!Empty(stack))
    {
        for (int i = stack->top; i > 0; i--) {
            Pop(stack, &p);
            printf("\n%s - %d", p.name, p.age);
            Push(&aux, &p);
        }
        for (int i = aux.top; i > 0; i--) {
            Pop(&aux, &p);
            Push(stack, &p);
        }
    }
}

void DeleteByName(Stack *stack, char *name)
{
    Stack aux;
    Person p;
    Reset(&aux);
    for (int i = stack->top; i > 0; i--)
    {
        Pop(stack, &p);
        if(strcmp(p.name, name) != 0)
            Push(&aux, &p);
    }
    for (int i = aux.top; i > 0; i--)
    {
        Pop(&aux, &p);
        Push(stack, &p);
    }
    
}

int main(int argc, char const *argv[])
{
    char op;
    char name[50];

    Stack stack1;
    Person p;

    Reset(&stack1);

    do
    {
        printf("\n---- MENU ----");
        printf("\n0- Insert person\n1- Remove person from top\n2- Delete person by name\n3- Clear stack\n4- List\n5- Exit\nYour choice: ");
        setbuf(stdin, NULL);
        scanf("%c", &op);

        switch (op)
        {
        case '0':
            printf("\nInsert person's name: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", p.name);
            printf("\nInsert person's age: ");
            scanf("%d", &p.age);
            Push(&stack1, &p);
            break;
        case '1':
            Pop(&stack1, &p);
            break;
        case '2':
            printf("\nInsert the name of the person to be deleted: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", name);
            DeleteByName(&stack1, name);
            break;
        case '3':
            Reset(&stack1);
        case '4':
            List(&stack1);
        default:
            break;
        }

    } while (op != '5');

    return 0;
}
