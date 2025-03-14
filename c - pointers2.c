#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);
void update(int *ptr);

int main(){
    int var = 15;

    int *ptr;
    ptr = &var;

    display(var, ptr);


    update(&var);


    display(var, ptr);

    return 0;
}


void display(int var, int *ptr){

    printf("\nConteudo de var = %d\n", var);
    printf("Endereco de var = %p\n", &var);

    printf("Conteudo apontado por ptr = %d\n", *ptr);  //Conte�do da var
    printf("Endereco apontado por ptr = %p\n", ptr);  //Endere�o de var
    printf("Endereco de ptr = %p", &ptr);  //Endere�o do pr�prio ptr

    printf("\n\n\n");

}

void update(int *p){
    *p = *p +1;
}
