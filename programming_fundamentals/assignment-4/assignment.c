/* Final 4 Faça um programa que solicite os lados de um retângulo informe de que tipo o retângulo é : Quadrado, Paralelogramo, trapézio ou outros. */
#include <stdio.h>

int main()
{
    int lados[4];
    puts("Seguindo o sentido horario.");
    for (int i = 0; i < 4; i++)
    {
        printf("Informe o lado %i do quadrilatero: ", i + 1);
        scanf("%i", &lados[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("lado: %i\n", lados[i]);
    }
    printf("\n");
    if (lados[0] == lados[2] && lados[1] == lados[3])
    {
        if (lados[0] == lados[1])
        {
            puts("O retangulo informado e um quadrado");
            return 0;
        }
        else
        {
            puts("O retangulo informado e um paralelogramo.");
            return 0;
        }
    }
    else if (lados[0] < lados[2] )
    {
        puts("O retangulo informado e um trapezio.");
        return 0;
    }
    puts("O retangulo informado e de outro tipo");
    return 0;
}
