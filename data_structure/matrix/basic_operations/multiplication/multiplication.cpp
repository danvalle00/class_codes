#include <iostream>
#include <ctime>
#include <cstdlib>

#define ROWS1 2
#define COLS1 2
#define ROWS2 2
#define COLS2 2

void check_matrix(int matrix1[][COLS1], int matrix2[][COLS2]);
void insert_matrixes_data(int matrix1[][COLS1], int matrix2[][COLS2]);
void matrix_multiplication(int matrix1[][COLS1], int matrix2[][COLS2], int result[][COLS2]);
void print_result(int result[][COLS2]);

int main()
{
    int my_matrix1[ROWS1][COLS1], my_matrix2[ROWS2][COLS2], my_result[ROWS1][COLS2];
    check_matrix(my_matrix1, my_matrix2);
    insert_matrixes_data(my_matrix1, my_matrix2);
    matrix_multiplication(my_matrix1, my_matrix2, my_result);
    print_result(my_result);
}

void check_matrix(int matrix1[][COLS1], int matrix2[][COLS2])
{
    if (COLS1 != ROWS2)
    {
        std::cout << "Can't multiply theses matrixes, number of COLS1 isnt equal to ROWS2";
        exit(1);
    }
}

void insert_matrixes_data(int matrix1[][COLS1], int matrix2[][COLS2])
{
    srand(time(0));
    for (int i = 0; i < ROWS1; i++)
    {
        for (int j = 0; j < COLS1; j++)
        {
            matrix1[i][j] = 7; //(rand() % 100) + 1;
        }
    }
    for (int i = 0; i < ROWS2; i++)
    {
        for (int j = 0; j < COLS2; j++)
        {
            matrix2[i][j] = 3; // (rand() % 100) + 1;
        }
    }
}

void matrix_multiplication(int matrix1[][COLS1], int matrix2[][COLS2], int result[][COLS2])
{
    for (int r1 = 0; r1 < ROWS1; r1++)
    {
        for (int c1 = 0; c1 < COLS2; c1++)
        {
            result[r1][c1] = matrix1[r1][c1] * matrix2[r1][c1] + matrix1[r1][c1 + 1] * matrix2[r1 + 1][c1];
            // ! a primeira linha e primeira coluna funciona legal mas depois ta dando uns bugs, como, pegando lixo de lugar random da memoria ou multiplicando o valor errado tipo 7x7 do nada
            // ? Procurar melhorar a logica, começou legal mas depois não funciona direito
            // TODO: Consertar essa porra.
        }
    }
}

void print_result(int result[][COLS2])
{
    for (int i = 0; i < ROWS1; i++)
    {
        for (int j = 0; j < COLS2; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}