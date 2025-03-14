#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa{
    char descricao[100];
    int prioridade;
    struct tarefa *next; //Ponteiro para a próxima tarefa
} tarefa;

int main()
{
    /*Cria 3 pointers: 1 pro início (vazio),
    1 pra tarefa a ser criada, e 1 pra percorrer a lista*/
    tarefa *inicio, *nova, *atual;
    char opcao;

    do{
        tarefa *nova = (tarefa*) malloc(sizeof(tarefa));

        if(nova == NULL){
            printf("Erro ao alocar a memoria!");
            exit(1);
        }

        printf("Descricao da tarefa: ");
        fgets(nova->descricao, 100, stdin);
        nova->descricao[strcspn(nova->descricao, "\n")] = '\0'; //Limpeza de buffer

        printf("Prioridade da tarefa: ");
        scanf("%d", &nova->prioridade);
        getchar();

        inicio->next = NULL;

        if(inicio == NULL){ //1a insercao na lista
            inicio = nova;
        }
        else{ // passa toda a lista até achar o ultimo e por o novo depois dele
            atual = inicio;
            while(atual->next != NULL){
                atual = atual->next;
            }
            atual->next = nova;
        }

        printf("Desejar add outra tarefa [S/N]? ");
        scanf("%c", &opcao);

    }while(opcao == 's' || opcao == 'S');

    system("pause");
    system("cls");

    printf("\n--- EXIBINDO AS TAREFAS ---\n\n");

    atual = inicio;

    while(atual != NULL){
        printf("Descricao: %s\n", atual->descricao);
        printf("Prioridade: %i\n", atual->prioridade);
        atual = atual-> next;
    }

    //Liberacao de todos o nos da lista
    while(inicio != NULL){
        atual = inicio;
        inicio = inicio->next;
        free(atual);
    }

    atual = NULL;



    return 0;
}
