// Implemente uma func¸ao que calcule as ra ˜ ´ızes de uma equac¸ao do segundo grau do tipo ˜
// Ax2 + Bx + C = 0. BLA BLA BLA
//Essa func¸ao deve obedecer ao seguinte prot ˜ otipo: ´
// int raizes(float A,float B,float C,float * X1,float * X2);

#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float *X1,float *X2){
    float delta = -4 * A * C + (B*B);
    printf("%f", delta);

    if(delta < 0)
        return 0;
    else if(delta == 0){
        *X1 = (-B + sqrt(delta))/(2 * A);
        *X2 = *X1;
        return 1;}
    else{
        *X1 = (-B + sqrt(delta))/(2 * A);
        *X2 = (-B - sqrt(delta))/(2 * A);

        return 2;
        }
}

int main(int argc, char const *argv[])
{

    float A = 1;
    float B = -4;
    float C = 4;
    float X1;
    float X2;

    int quantRaizes = raizes(A, B, C, &X1, &X2);

    printf("\n Quantidade de raizes: %d", quantRaizes);

    printf("\n X': %f", X1);
    printf("\n X'': %f", X2);




    
    return 0;
}
