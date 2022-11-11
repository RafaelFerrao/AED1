#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeDuplicates(char * s){
    char *stack = malloc( sizeof(char) * ( strlen(s)+1 ) );
    int top = 0, i = 0;

    while (s[i] != '\0')
    {
        if(top == 0){
            stack[top] = s[i];
            top++;
        } else
        if(s[i] != stack[top-1]) {
            stack[top] = s[i];
            top++;
        } else {
            top--;
        }

        i++;
    }

    stack[top] = '\0';
    
    
    free(s);
    
    return stack;
}

int main(int argc, char const *argv[])
{
    char *str = malloc(sizeof(char) * 105);
    strcpy(str, "abbacdda");

    printf("\n%s", removeDuplicates(str));


    return 0;
}
