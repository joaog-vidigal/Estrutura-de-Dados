#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No{
    char nome[100];
    int ra;
    struct No* next;
} No;


int main(){
    No *a, *b, *c;

    a = NULL;
    b = NULL;
    c = NULL;

    for(int i = 0; i < 3; i++){
        if(c == NULL){
            a = (No*) malloc(sizeof(No));

            if(a == NULL){
                printf("Erro ao alocar memoria!");
                exit(1);
            }

            printf("\nRA: ");
            scanf("%d", &a->ra);
            getchar();

            printf("Nome: ");
            fgets(a->nome, 100, stdin);
            a->nome[strcspn(a->nome, "\n")] = '\0';

            b = a;
            c = a;
            a->next = NULL;
        }
        else{
            a = (No*) malloc(sizeof(No));

             if(a == NULL){
                printf("Erro ao alocar memoria!");
                exit(1);
            }

            printf("\nRA: ");
            scanf("%d", &a->ra);
            getchar();

            printf("Nome: ");
            fgets(a->nome, 100, stdin);
            a->nome[strcspn(a->nome, "\n")] = '\0';

            b->next = a;
            a->next = NULL;
            b = a;
        }
    }

    system("pause");
    system("cls");

    printf("\n");

    b = c;

    while(b != NULL){
        printf("Nome: %s\n", b->nome);
        printf("RA: %d\n\n", b->ra);
        b = b->next;
    }

    return 0;
}
