// Write a program that prints an empty square, starting from the size entered by the user.

#include <stdio.h>


int main()
{
    int n;
    puts("Input the size of the square: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 || j == 0 || i == (n - 1) || j == (n - 1)){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
    printf("\n");
    }
    return 0;
}
