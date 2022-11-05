#include <stdio.h>

int main()
{
    int x, y;
    puts("Enter a integer for the multiplication table: ");
    scanf("%i", &y);
    for (x = 1; x <= 10; x++){
        printf("%i * %i = %i\n", x, y, (x * y));
    }
    puts("End");
    return 0;
}
