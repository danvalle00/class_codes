#include <iostream>
#include <ctime>
#include <cstdlib>

#define SIZE_MATRIX 3

void insert_matrix_data(int matrix[][SIZE_MATRIX]);
void matrix_addition(int matrix1[][SIZE_MATRIX], int matrix2[][SIZE_MATRIX], int result[][SIZE_MATRIX]);
void matrix_subtraction(int matrix1[][SIZE_MATRIX], int matrix2[][SIZE_MATRIX], int result[][SIZE_MATRIX]);
void print_matrix(int matrix[][SIZE_MATRIX]);

int main()
{
    int my_matrix1[SIZE_MATRIX][SIZE_MATRIX], my_matrix2[SIZE_MATRIX][SIZE_MATRIX], result[SIZE_MATRIX][SIZE_MATRIX];

    insert_matrix_data(my_matrix1);
    insert_matrix_data(my_matrix2);
    print_matrix(my_matrix1);
    print_matrix(my_matrix2);
    matrix_addition(my_matrix1, my_matrix2, result);
    // matrix_subtraction(my_matrix1, my_matrix2, result);
    print_matrix(result);
}

void insert_matrix_data(int matrix[][SIZE_MATRIX])
{
    srand(time(0));
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            matrix[i][j] = (rand() % 10) + 1;
        }
    }
}

void matrix_addition(int matrix1[][SIZE_MATRIX], int matrix2[][SIZE_MATRIX], int result[][SIZE_MATRIX])
{
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_subtraction(int matrix1[][SIZE_MATRIX], int matrix2[][SIZE_MATRIX], int result[][SIZE_MATRIX])
{
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void print_matrix(int matrix[][SIZE_MATRIX])
{
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}