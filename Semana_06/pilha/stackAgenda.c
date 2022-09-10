#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
} Person;

typedef struct
{
    Person *people;
    int top;
    int base;
    int limit;
} Stack;

void Reset(Stack **stack)
{
    free(stack);
    *stack = (Stack *)malloc(sizeof(int) * 3 + sizeof(Person));
    (**stack).top = 0;
    (**stack).base = 0;
    (**stack).limit = 2;
    (**stack).people = NULL;
}

int Empty(Stack *stack)
{
    return stack->top == 0;
}

int Full(Stack *stack)
{
    return stack->top == stack->limit;
}

void Push(Stack *stack, Person *p)
{
    if (stack->top == 0)
    {
        stack->people = (Person *)malloc(sizeof(Person) * stack->limit);
        if (!stack->people)
        {
            printf("\nError: lack of memory");
            exit(1);
        }
    }
    if (Full(stack))
    {
        stack->limit *= 2;
        stack->people = (Person *)realloc(stack->people, sizeof(Person) * stack->limit);
    }
    stack->people[stack->top] = *p;
    stack->top++;
}

Person Pop(Stack *stack)
{
    if (!Empty(stack))
    {
        Person p;
        stack->top--;
        p = stack->people[stack->top];
        return p;
    }
    else
    {
        printf("\nError, empty stack.");
    }
}

void Clear(Stack *stack)
{
    printf("\nStack cleared.");
    stack->top = stack->base;
}

void List(Stack *stack)
{
    Stack *temp;
    Reset(&temp);
    Person p;

    while (!Empty(stack))
    {
        p = Pop(stack);
        printf("\n---------------");
        printf("\n%s - %d", p.name, p.age);
        Push(temp, &p);
    }
    while (!Empty(temp))
    {
        p = Pop(temp);
        Push(stack, &p);
    }
    free(temp);
    temp = NULL;
}

void DeleteByName(Stack *stack, char *name)
{
    Stack *temp;
    Reset(&temp);
    Person p;

    while (!Empty(stack))
    {
        p = Pop(stack);
        Push(temp, &p);
    }
    while (!Empty(temp))
    {
        p = Pop(temp);

        if (strcmp(p.name, name) != 0)
        {
            Push(stack, &p);
        }
    }
    free(temp);
    temp = NULL;
}

int main(int argc, char const *argv[])
{
    Stack *s;
    Person p;
    char op;
    char name[30];

    Reset(&s);

    do
    {
        printf("\n\n0- Insert person");
        printf("\n1- Delete person from top");
        printf("\n2- Delete person by name");
        printf("\n3- Clear stack");
        printf("\n4- List persons");
        printf("\n5- Exit program");

        printf("\nYour choice: ");
        setbuf(stdin, NULL);
        scanf("%c", &op);

        switch (op)
        {
        case '0':
            printf("\nInsert the person's name: ");
            setbuf(stdin, NULL);
            scanf("%s", name);
            strcpy(p.name, name);
            printf("\nInsert %s's age: ", name);
            scanf("%d", &p.age);
            Push(s, &p);
            break;

        case '1':
            Pop(s);
            break;
        case '2':
            printf("\nInsert the person's name: ");
            setbuf(stdin, NULL);
            scanf("%s", name);
            DeleteByName(s, name);
            break;

        case '3':
            Clear(s);
            break;

        case '4':
            List(s);
            break;

        case '5':
            break;

        default:
            printf("\nInvalid input, insert again");
            break;
        }

    } while (op != '5');
    free(s);
    return 0;
}
