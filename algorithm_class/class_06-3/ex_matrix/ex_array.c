#include <stdio.h>
#define FILIAL 4
#define MESES 12
int main()
{
    int venda[FILIAL][MESES];
    for (int i = 0; i < FILIAL; i++)
    {
        printf("cod filial: ");
        scanf("%i", &venda[i][MESES]);
        for (int j = 0; i < MESES; j++)
        {
            printf("venda no mes %d: ", j);
            scanf("%i", &venda[i][j]);
        }
    }
    /* for (int i = 0; i < FILIAL; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            printf("%d, %d\n", venda[i], venda[j]);
        }
    } */
}