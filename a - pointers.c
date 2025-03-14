#include <stdio.h>
#include <stdlib.h>

int main(){
    int valor = 72;


    int *ptr;

    ptr = &valor;

    printf("\nConteudo da variavel = %d\n", valor);
    printf("Endereco da variavel = %p\n", &valor);
    printf("Conteudo da variavel apontada por ptr = %d\n", *ptr);
    printf("Endereco da variavel apontada por ptr = %p\n", ptr);
    printf("Endereco de ptr = %p", &ptr);

    printf("\n\n");


    return 0;
}
