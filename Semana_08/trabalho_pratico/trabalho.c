#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq;
    int top;
    int base;
    int limit;
} Stack;

void Reset(Stack **stack){
    free((**stack).seq);
    free(*stack);
    *stack = (Stack *)malloc(sizeof(Stack));
    (**stack).seq = (char *)malloc(sizeof( char ) * (**stack).limit);
    (**stack).base = 0;
    (**stack).limit = 2;
    (**stack).top = 0;
}

int Empty(Stack *stack){
    if (stack->top == 0)
        return 1; // Is empty
    else 
        return 0; // Not empty
}

int Full(Stack *stack){
    if (stack->top == stack->limit)
        return 1; // Is full
    else 
        return 0; // Not full
}

void Push(Stack **stack, char c) {
    if(Full(*stack)){
        (**stack).limit *= 2;
        (**stack).seq = realloc((**stack).seq, sizeof(char) * (**stack).limit);
    }
    (**stack).seq[(**stack).top] = c;
    (**stack).top += 1;
}

char Pop(Stack **stack) {
    char c;

    if(!Empty(*stack)){
        c = (**stack).seq[(**stack).top-1];
        (**stack).top -= 1;

        return c;
    }
}

void VerifyPalindromo(Stack **stack){
    int i = 0;
    char c;
    char c2;
    int ehPalindromo = 1;

    Stack *aux;
    Reset(&aux);
    if( (**stack).top % 2 == 0 ){ // Even number of characters in the stack
        i = (**stack).top / 2;

        while( (**stack).top > i ){
            c = Pop(stack);
            Push(&aux, c);
        }

        while(!Empty(*stack)){

            c = Pop(stack);
            c2 = Pop(&aux);

            if(c != c2)
                ehPalindromo = 0;
        
        }


    } else { // Odd number of characters in the stack

        i = ((**stack).top / 2) + 1;
        //ABFBA

        while( (**stack).top >= i ){
            c = Pop(stack);
            Push(&aux, c);
        }

        Pop(&aux);
        while(!Empty(*stack)){

            c = Pop(stack);
            c2 = Pop(&aux);

            if(c != c2)
                ehPalindromo = 0;
        
        }

    }

    if(ehPalindromo == 0)
        printf("\nThe sequence is not 'palindromo'");
    else 
        printf("\nThe sequence is 'palindromo'");

    free(aux->seq);
    free(aux);
}

//sobrou uns minutos vou adicionar um list

void List(Stack *stack){
    Stack *aux;
    Reset(&aux);
    char c;

    while(!Empty(stack)){
        c = Pop(&stack);
        Push(&aux, c);
    }

    while(!Empty(aux)){
        c = Pop(&aux);
        printf("%c", c);
        Push(&stack, c);
    }

    free(aux->seq);
    free(aux);
}


int main(int argc, char const *argv[])
{
    Stack *s;
    char c;
    char input = 'a';
    Reset(&s);

    while(input != 'x' && input != 'X'){
        printf("\nInsert a character or press x and enter to end the execution: ");
        setbuf(stdin, NULL);
        scanf("%c", &input);

        if(input == 'x' || input == 'X'){
            break;
        } else {
            Push(&s, input);
        }
    }

    printf("\nInput sequence: ");
    List(s);
    VerifyPalindromo(&s);


    free(s->seq);
    free(s);

    return 0;
}
