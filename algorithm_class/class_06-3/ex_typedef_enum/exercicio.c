#include <stdio.h>
// crie uma estrutura 'pessoa' que possua os campos nome,idade e sexo
int main()
{
    typedef enum
    {
        MASCULINO,
        FEMININO
    } sexo;

    struct pessoa
    {
        char nome[20];
        int idade;
        sexo sexo;
    }; 
    
}

