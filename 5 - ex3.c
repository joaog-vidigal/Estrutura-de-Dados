#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produtos{
    char nome[100];
    float preco;
} produtos;

int main(){
    int n;
    produtos *prod;

    printf("Numero de produtos: ");
    scanf("%d", &n);
    getchar();

    prod = (produtos*)malloc(n*sizeof(produtos));

    if(prod == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Nome do produto %d: ", i+1);
        fgets(prod[i].nome, 100, stdin);
        prod[i].nome[strcspn(prod[i].nome, "\n")] = '\0';

        if(strcmp(prod[i].nome, "") == 0){
            printf("Nome nao definido!");
            exit(1);
        }

        printf("Valor do produto %d: ", i+1);
        scanf("%f", &prod[i].preco);
        getchar();
    }

    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("Produto %d: Nome: %s, Preço: %.2f\n", i + 1, prod[i].nome, prod[i].preco);
    }

    free(prod);
    prod = NULL;

    return 0;
}
