#include <stdio.h>

int main()
{
    float a = 0, b = 0;
    puts("Input a value for A: ");
    scanf("%f", &a);
    puts("Input another value for B: ");
    scanf("%f", &b);
    float aux = a;
    a = b;
    b = aux;
    printf("The swapped values for A: %.2f and B: %.2f", a, b);
    return 0;
}
