#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char *buffer = (char *) malloc(sizeof(char) * 8);
    buffer[0] = 'j';
    buffer[1] = 'B';
    buffer[2] = '\0';
    buffer[3] = 'D';
    buffer[4] = 'e';
    buffer[5] = 'F';
    buffer[6] = 'G';
    buffer[7] = '\0';

    char *buffer2 = (char *) malloc(sizeof(char));

    char c = '\0';
    int i = 0;
    do
    {
        (i)++;
        c = getchar();
        if (c != '\n')
        {
            buffer2 = (char *)realloc(buffer2, sizeof(char) * (i));
            buffer2[(i) - 1] = c;
        }
        else
        {
            buffer2[(i) - 1] = '\0';
        }
    } while (c != '\n');

    printf("%s", buffer2);
    printf("\n%d", i);

    char *ptr = strstr(buffer, buffer2);

    printf("\n%s", ptr);

    
    // printf("%s\n", buffer);
    // printf("%s\n", ptr);

    // printf("%d\n", ptr);
    // printf("%d\n", buffer);
    // printf("%d\n", ptr - buffer);
    // printf("%d", *buffer);

    
    return 0;
}
