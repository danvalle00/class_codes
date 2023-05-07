/* Crie um programa em C que leia do teclado um número que é o código de filial e em seguida leia 12 números que é o valor de vendas mensais no ano corrente, armazenando num vetor bidimensional, com filiais nas linhas e meses(12) nas colunas.
A seguir imprima o mês com mais vendas para cada filial.
A seguir imprima o mês com menos vendas para cada filial.
A seguir imprima a média vendas para cada filial. */

#include <stdio.h>
#define branches 5 // number of branches
#define months 12  // number of months

int main()
{
    float sells[branches][months], total_sell[branches], highest_sell_month[branches], lowest_sell_month[branches];
    int branch[branches];
    int max = 0;
    int min = 0;

    // algorithm to input every branch id and every sells for each month
    for (int i = 0; i < branches; i++)
    {
        printf("Enter the code for the branch %d: ", i + 1);
        scanf("%d\n", &branch[i]);
        printf("Input the sells for the branch: %d\n", i + 1);
        for (int j = 0; j < months; j++)
        {
            printf("Month %d: ", j + 1);
            scanf("%f\n", &sells[i][j]);
            total_sell[i] += sells[i][j]; // will sum every month sell for each branch
            if (sells[i][j] > max)        // condition to seek for the highest and lowest month sell
            {
                highest_sell_month[i] = j + 1;
                max = sells[i][j];
            }
            else
            {
                lowest_sell_month[i] = j + 1;
                min = sells[i][j];
            }
        }
    }
    printf("highest sell month for each branch: \n"); // first question
    for (int i = 0; i < branches; i++)
    {
        printf("Branch ID: %d\n", branch[i]);
        printf("Branch highest sell month: %d\n", highest_sell_month[i]);
    }
    printf("\n");

    printf("lowest sell month for each branch: \n"); // second question
    for (int i = 0; i < branches; i++)
    {
        printf("Branch ID: \n", branch[i]);
        printf("branch lowest sell month: %d\n", lowest_sell_month[i]);
    }
    printf("\n");

    printf("average sells for each branch: \n");
    for (int i = 0; i < branches; i++)
    {
        printf("Branch ID: %d\n", branch[i]);
        printf("branch average sell: %.2f\n", total_sell[i] / (float)months); // espero que num trunque kkkkkkkkkkkkkkk
    }
}