#include <stdio.h>

int main(){
    int *ptr; // cria um ponteiro para o tipo inteiro
    int valor = 999;
    
    ptr = &valor; // ponteiro recebe o endereço da variável valor.

    printf("Endereco de valor (&valor): %x\n", &valor);
    printf("Valor de ptr: %x\n", ptr);
    printf("Valor armazenado no endereco apontado por ptr (*ptr): %d\n", *ptr);
}