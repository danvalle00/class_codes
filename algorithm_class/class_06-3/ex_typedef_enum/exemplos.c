#include <stdio.h>

int main()
{
    // enumerando os dias das semana; domingo = 0... num_dias_semana = indice 7;
    typedef enum
    {
        DOMINGO,
        SEGUNDA,
        TERCA,
        QUARTA,
        QUINTA,
        SEXTA,
        SABADO,
        NUM_DIAS_SEMANA
    } dias_semana;

    // iniciando e zerando o vetor temperatura;
    float temperatura[NUM_DIAS_SEMANA];
    for (int i = 0; i < NUM_DIAS_SEMANA; i++)
    {
        temperatura[i] = 0;
    }

    // printando os valores de temperatura
    for (int i = 0; i < NUM_DIAS_SEMANA; i++)
    {
        printf("%.1f\n", temperatura[i]);
    }
}