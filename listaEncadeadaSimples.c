#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct no {
    int ra;
    char nome[20];
    struct no* next;
} no;

struct no *corrente, *auxiliar, *inicio, *auxiliar2;

void insert();
void enterdata();
void exibir();
void remover();
void insert_data();
void consulta();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    corrente = NULL;
    auxiliar = NULL;
    inicio = NULL;

    int op;

    do {
        system("cls");

        printf("\n ================ M E N U ===============\n");

        printf("\n [ 1 ] Inserir elemento na lista");
        printf("\n [ 2 ] Exibir elementos da lista");
        printf("\n [ 3 ] Remover elemento da lista");
        printf("\n [ 4 ] Consultar elemento na lista");
        printf("\n [ 5 ] Fechar programa");
        printf("\n\n ========================================");
        printf("\n Informe a opção desejada: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insert_data();
                break;

            case 2:
                exibir();
                break;

            case 3:
                remover();
                break;

            case 4:
                consulta();
                break;

            case 5:
                exit(0);

            default:
                printf("\n Opção inválida.... Tente novamente\n\n");
                system("pause");
        }
    } while (op != 5);

    return 0;
}

void enterdata(){
    printf("\n Informe o RA: ");
    scanf("%d", &corrente->ra);
    getchar();

    printf(" Informe o nome: ");
    fgets(corrente->nome, 20, stdin);
    corrente->nome[strcspn(corrente->nome, "\n")] = '\0';
}

void exibir() {
    auxiliar = inicio;

    printf("\nEXIBINDO LISTA:\n");

    while (auxiliar != NULL) {
        printf("\n Nome: %s\n", auxiliar->nome);
        printf("RA: %d\n", auxiliar->ra);
        auxiliar = auxiliar->next;
    }

    system("pause");
}

void remover() {
    if (inicio == NULL) {
        printf("\n Lista vazia!");
        system("pause");
    } else {
        auxiliar = inicio;

        int raBusca;
        int achou = 0;
        printf("\n RA a ser removido: ");
        scanf("%d", &raBusca);

        if (auxiliar->ra == raBusca) {
            inicio = inicio->next;
            free(auxiliar);
            printf("\n Removido o primeiro elemento");
            printf("\n\n");
            system("pause");
            achou = 1;
        } else {
            corrente = auxiliar->next;

            while (corrente != NULL) {
                if (corrente->ra == raBusca) {
                    auxiliar->next = corrente->next;
                    free(corrente);
                    printf("\n Removido elemento no meio da lista\n\n");
                    system("pause");
                    achou = 1;
                    break;
                } else {
                    auxiliar = auxiliar->next;
                    corrente = corrente->next;
                }
            }

            if (achou == 0) {
                printf("\n Elemento não consta na lista\n\n");
                printf("\n\n");
                system("pause");
            }
        }
    }
}


//CONSULTA
void consulta(){
    int achou = 0, k = 0, opt = 0;
    char nome[20];
    int ra;

    if(inicio == NULL){
        printf("\n Lista vazia!\n\n");
        system("pause");
        return;
    }


    do{
        printf(" Deseja consultar pelo nome [1] ou RA [2]: ");
        scanf("%d", &opt);
        getchar();

        if(opt == 1){

            printf(" \n Nome do aluno: ");
            scanf("%s", &nome);
            corrente = inicio;

            while(corrente != NULL){
                k++;
                if(strcmp(corrente->nome, nome) == 0){
                    printf("\n O registro foi encontrado na posição %d da lista\n\n", k);
                    auxiliar = NULL;
                    achou = 1;
                    system("pause");
                    break;

                }else{
                    corrente = corrente->next;
                }
            }


        } else if(opt == 2){

            printf(" \n RA do aluno: ");
            scanf("%d", &ra);
            corrente = inicio;

            while(corrente != NULL){
                k++;
                if(corrente->ra == ra){
                    printf("\n O registro foi encontrado na posição %d da lista\n\n", k);
                    auxiliar = NULL;
                    achou = 1;
                    system("pause");
                    break;
                }else{
                    corrente = corrente->next;
                }
            }


        }else{
            printf("\n Por favor, escolha uma opção válida! [1 ou 2]\n\n");
        }


    }while(opt == 0);


    if(achou == 0){
        printf("\n Registro não consta na lista\n\n");
        system("pause");
    }
}

//INSERÇÃO DE DADOS DE MANEIRA ORDENADA
void insert_data() {
    corrente = (no*) malloc(sizeof(no));
    enterdata();

    if (inicio == NULL) {
        auxiliar = corrente;
        inicio = corrente;
        corrente->next = NULL;

        printf("\n Implementando o primeiro nó na lista\n\n");
        system("pause");
    } else {
        auxiliar = inicio;
        if (strcmp(corrente->nome, auxiliar->nome) < 0) {
            corrente->next = auxiliar;
            inicio = corrente;

            printf("\n Elemento foi inserido no início da lista\n\n");
            system("pause");
        } else {
            auxiliar2 = auxiliar->next;

            while (auxiliar2 != NULL) {
                if (strcmp(corrente->nome, auxiliar->nome) > 0 && strcmp(corrente->nome, auxiliar2->nome) < 0) {
                    auxiliar->next = corrente;
                    corrente->next = auxiliar2;
                    achou = 1;

                    printf("\n Elemento foi inserido na lista ordenada!\n\n");
                    system("pause");
                    break;
                } else {
                    auxiliar = auxiliar->next;
                    auxiliar = auxiliar2->next;
                }
            }
            if(achou == 0 && strcmp(corrente->nome, auxiliar->nome)){
                auxiliar->next = corrente;
                corrente->next = NULL;
                printf("\n Elemento inserido no final da lista! \n");
                system("pause");
            }
        }
    }
}
