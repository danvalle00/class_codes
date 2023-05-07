#include <stdio.h>
#define QNTD 5
int main()
{
    int alturas[QNTD];
    int soma_alturas = 0;
    for (int i = 0; i < QNTD; i++)
    {
        printf("Digite a altura %i: ", i + 1);
        scanf("%i", &alturas[i]);
        soma_alturas += alturas[i];
    }
    float media = soma_alturas / QNTD;
    printf("A media das alturas e igual a: %.2f ", media);
}