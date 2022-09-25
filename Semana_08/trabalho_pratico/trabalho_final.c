#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq;
    int top;
    int base;
    int limit;
} Stack;

Stack *Reset() { // Creates the new Stack
    Stack *stack;
    stack = ( Stack * )malloc( sizeof( int ) * 3 + sizeof( char * ) );
    stack->top = 0;
    stack->base = 0;
    stack->limit = 2;
    stack->seq = NULL;

    return stack;
}

int Empty( Stack *stack ) {
    return stack->top == 0;
}

int Full( Stack *stack ) {
    return stack->top == stack->limit;
}

void Push( Stack *stack, char c ) {
    if ( stack->top == 0 ) {
        stack->seq = ( char * )realloc( stack->seq, sizeof( char ) * stack->limit );
        if ( !stack->seq ) {
            printf( "\nError: lack of memory" );
            exit( 1 );
        }
    }
    if ( Full( stack ) ) {
        stack->limit *= 2;
        stack->seq = ( char * )realloc( stack->seq, sizeof( char ) * stack->limit );
    }
    stack->seq[ stack->top ] = c;
    stack->top++;
}

char Pop( Stack *stack ) {
    if ( !Empty( stack ) ) {
        char c;
        stack->top--;
        c = stack->seq[ stack->top ];
        return c;
    }
    else {
        printf( "\nError, empty stack." );
    }
}

void List( Stack *stack ) {
    Stack *temp = Reset();
    char c;

    while ( !Empty( stack ) ) {
        c = Pop( stack );
        Push( temp, c );
    }
    while ( !Empty( temp ) ) {
        c = Pop( temp );
        printf( "%c", c );
        Push( stack, c );
    }
    free( temp->seq );
    free( temp );
    temp = NULL;
}

void VerifyPalindromo( Stack *stack ) {
    int i = 0;
    char c;
    char c2;
    int ehPalindromo = 1;

    if ( stack->top == 0 ) {
        printf( "\nEmpty sequence, not sure if this is a 'palindromo'" );
        return;
    }

    if ( stack->top == 1 ) {
        printf( "\nThe sequence is a single character, not sure if this is a 'palindromo'" );
        return;
    }

    Stack *aux = Reset();

    if( stack->top % 2 == 0 ) { // Even number of characters in the stack
        i = stack->top / 2;
        while( stack->top > i ) {
            c = Pop( stack );
            Push( aux, c );
        }
        while( !Empty( stack ) ) {
            c = Pop( stack );
            c2 = Pop( aux );

            if( c != c2 )
                ehPalindromo = 0;
        }

    } else { // Odd number of characters in the stack
        i = ( stack->top / 2 ) + 1;
        //ABFBA

        while( stack->top >= i ) {
            c = Pop( stack );
            Push( aux, c );
        }

        Pop( aux );
        while( !Empty( stack ) ){

            c = Pop( stack );
            c2 = Pop( aux );

            if( c != c2 )
                ehPalindromo = 0;
        }
    }

    if( ehPalindromo == 0 )
        printf( "\nThe sequence is not a 'palindromo'" );
    else 
        printf( "\nThe sequence is a 'palindromo'" );

    free( aux->seq );
    free( aux );
}

int main( int argc, char const *argv[] ) {
    Stack *s = Reset();
    char c;
    do {
        printf( "\nInsert char + enter to insert or insert x + enter to end execution: " );
        setbuf( stdin, NULL );
        scanf( "%c", &c );
        if( c != 'x' && c != 'X' )
            Push( s, c );
    } while ( c != 'x' && c != 'X' );

    printf( "\nSequence: " );
    List( s );
    VerifyPalindromo( s );

    free( s->seq );
    free( s );
    return 0;
}
