/* Final 4
Crie dois vetores A e B com 100 números aleatórios e escreva os números do vetor
A que estão no vetor B. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 100

// função de comparação
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int mA[TAMANHO], mB[TAMANHO], n1Random, n2Random;
    srand(time(0));
    for (int i = 0; i < TAMANHO; i++)
    {
        n1Random = rand() % TAMANHO;
        n2Random = rand() % TAMANHO;
        // preenchendo as matrizes com valores random.
        mA[i] = n1Random;
        mB[i] = n2Random;
    }

    // colocando em ordem crescente os valores das matrizes
    qsort(mA, TAMANHO, sizeof(int), cmpfunc);
    qsort(mB, TAMANHO, sizeof(int), cmpfunc);
    puts("Os valores que estão em A e em B são: ");

    // Colocando na tela os valores de A que estão em B
    for (int i = 0; i < TAMANHO; i++)
    {
        if (mA[i] == mB[i])
        {
            mA[i] = mB[i];
            printf("(%i) ", mA[i]);
        }
    }

    return 0;

}