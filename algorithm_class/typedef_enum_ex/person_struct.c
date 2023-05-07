/* Crie uma estrutura pessoa que possua os campos nome(string), idade(inteiro) e sexo(enumeração).A enumeração sexo deve ser definida usando typedef enum.
seguida,crie uma função que receba como parâmetro um array de estruturas pessoa e retorne a
quantidade de pessoas do sexo masculino presentes no array. */
#include <stdio.h>

typedef enum
{
    Male,
    Female
} Sex;

typedef struct Person
{
    char Name[20];
    int Age;
    Sex sex;
} person;

int male_count(person x[])
{
    int counter;
    for (int i = 0; i < (sizeof(x) / sizeof(x[0])); i++) // array size
    {
        if (x->sex == 0) // everytime when sex is equal to male will add +1 in the counter
        {
            counter++;
        }
    }
    return counter;
}
int main()
{
    person persons_array[10];

    male_count(persons_array);
}
