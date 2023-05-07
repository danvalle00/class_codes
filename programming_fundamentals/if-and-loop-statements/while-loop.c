#include <stdio.h>

int main()
{
    int x,y = -1; // quick fix lelw
    while (x != 0 || y != 0){
        puts("Enter two integers: ");
        scanf("%i", &x);
        scanf("%i", &y);
        printf("Addiction of two numbers = %i\n", (x + y));
        printf("Substraction of 2nd number from 1st = %i\n", (x - y));
        printf("Multiplication of two number = %i\n", (x * y));
        if (y == 0){
            puts("Can't divide by 0");
        }
        else {
            printf("Division of 1st number from 2nd = %.2f\n", ((float) x / y));    
        }
    }
    puts("End");
    return 0;
}
