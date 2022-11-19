#include <stdio.h>
#define RANGE 3

int main()
{
    int m[RANGE][RANGE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int inv[RANGE][RANGE];

    // will print normal matrix and assign every inversed element to the inverse matrix;
    puts("Normal Matrix: ");
    for (int i = 0; i < RANGE; i++){ 
        for (int j = 0; j < RANGE; j++){
            printf("%d ", m[i][j]);
            inv[i][j] = m[RANGE - i - 1][RANGE - j - 1];
        } // columns
        printf("\n");
    } // rows

    puts("\nInverse: ");
    for (int i = 0; i < RANGE; i++){
        for (int j = 0; j < RANGE; j++){
            printf("%d ", inv[i][j]);
        } // columns
    printf("\n");
    } // rows
    return 0;
}
