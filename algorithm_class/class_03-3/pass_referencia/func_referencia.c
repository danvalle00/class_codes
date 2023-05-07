#include <stdio.h>
// n sei ponteiro.
int dezvezes(int *a)
{ 
    //*a é o ponteiro que está recebendo o endereço de &num
    printf("entrou na função: %x.\n", *a);
    *a = *a * 10;
    printf("dentro da funcao, apos a executacao: %x.\n", *a);
    return *a;
}

int main(){
    int num = 42;
    printf("numero original: %d.\n", num);
    printf("Passagem por referencia.\n");
    dezvezes(&num);
    // &num está enviando o endereço de onde eu quero alterar
    printf("numero original: %d", num);
}