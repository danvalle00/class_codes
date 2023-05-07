#include <stdio.h>

int main(){
    int rows, columns;
    puts("Rows: ");
    scanf("%i", &rows);
    puts("Columns: ");
    scanf("%i", &columns);
    int matrix[rows][columns];
    
    // Will loop every single element in matrix and assign a value to it
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("Enter a integer to the element (%i, %i)", i, j);
            scanf("%i", &matrix[i][j]);
        }
    }
    // Prompt of the matrix 
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf(" %i ", matrix[i][j]);
        }
    printf("\n");
    }
    
    puts("Done.");
}