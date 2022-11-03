#include <stdio.h>

int main()
{
    char str[20];
    puts("Word: "); 
    fgets(str, 20, stdin); // read from input
    printf("Your word is: %s", str);
    return 0;
}
    