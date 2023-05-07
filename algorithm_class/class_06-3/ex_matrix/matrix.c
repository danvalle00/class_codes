#include <stdio.h>
#define NUM_ALUNOS 5
#define NUM_NOTAS 3

int main()
{
    int avaliacao[NUM_ALUNOS][NUM_NOTAS];
    for (int i = 0; i < NUM_ALUNOS; i++)
    {
        printf("Inputando os dados para o Aluno %d\n", i + 1);
        for (int j = 0; j < NUM_NOTAS; j++)
        {
            printf("Entrando com a nota %d do Aluno %d ", j + 1, i + 1);
            scanf("%i", &avaliacao[i][j]);
        }
        printf("A media do Aluno %d e igual a: %d\n\n", i + 1, (avaliacao[i][0] + avaliacao[i][1] + avaliacao[i][2]) / 3);
    }

    printf("Todas as notas foram inputadas.");
}