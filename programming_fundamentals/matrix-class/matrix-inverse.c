#include <stdio.h>
#define RANGE 10

// inverse a matrix exercise
int main()
{
    int m[RANGE] = {10, 10, 2, 3, 45, 6, 5, 6, 8, 10};
    int inv[RANGE];

    // printing the normal matrix and allocating the inverse matrix numbers;
    puts("Normal Matrix: ");
    for (int i = 0; i < RANGE; i++){
        printf("%d ", m[i]);
        inv[i] = m[RANGE - i - 1];
    }

    puts("\nInverse:");
    for (int i = 0; i < RANGE; i++){
        printf("%i ", inv[i]);
    }
    puts("\nDone.");
    return 0;
}
