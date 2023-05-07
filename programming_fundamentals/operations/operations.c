#include <stdio.h>

int main()
{
    // values from user
    int x,y,sum,sub,multi;
    float div;
    printf("Value for X: ");
    scanf("%d", &x);
    printf("Value for Y: ");
    scanf("%d", &y);
    printf("The values for X and Y is %d and %d\n", x, y);

    // basic operations
    sum = (x + y);
    sub = (x - y);
    multi = (x * y);
    div = ((float) x / y);
    printf("Sum: %d\n", sum);
    printf("Substraction: %d\n", sub);
    printf("Multiplication: %d\n", multi);
    printf("Division: %.2f", div);
    return 0;
}
    