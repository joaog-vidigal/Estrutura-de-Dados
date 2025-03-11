#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


typedef struct no{
    int ra;
    char nome[20];
    struct no* next;
} no;

no *corrente, *auxiliar, *inicio, *antes;

void insert();
void enterdata();
void exibir();
void remover();


int main()
{
    setlocale(LC_ALL, "Portuguese");

    corrente = NULL;
    auxiliar = NULL;
    inicio = NULL;
    antes = NULL;

    int op;

    do{
        system("cls");

        printf(" ================ M E N U ===============\n");

        printf("\n [ 1 ] Inserindo elemento na lista");
        printf("\n [ 2 ] Exibindo elementos da lista");
        printf("\n [ 3 ] Removendo elemento da lista");
        printf("\n [ 4 ] Consulta de elemento na lista");
        printf("\n [ 5 ] Fechar programa");
        printf("\n\n ========================================");
        printf("\n Informe a opção desejada: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                insert();
                break;

            case 2 :
                exibir();
                break;

            case 3 :
                remover();
                break;

            case 4 :
                printf("\n Função a ser concluída!");
                break;

            case 5 :
                exit(0);

            default :
                printf("\n Opção inválida.... Tente novamente");
                system("pause");
        }
    }while(op != 5);


    return 0;
}

void insert(){

    if(inicio == NULL){
        corrente = (no*) malloc(sizeof(no));

        auxiliar = corrente;
        inicio = corrente;
        corrente->next = NULL;
        enterdata();
    } else{
        corrente = (no*) malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->next = NULL;
        auxiliar = corrente;
        enterdata();
    }


}

void enterdata(){
    printf("\n Informe o RA: ");
    scanf("%d", &corrente->ra);
    getchar();

    printf(" Informe o nome: ");
    fgets(corrente->nome, 20, stdin);
    corrente->nome[strcspn(corrente->nome, "\n")] = '\0';
}

void exibir(){
    auxiliar = inicio;

    printf("\nEXIBINDO LISTA:\n");

    while(auxiliar != NULL){
        printf("\nNome: %s\n", auxiliar->nome);
        printf("RA: %d\n", auxiliar->ra);
        auxiliar = auxiliar->next;
    }

    system("pause");
}

void remover(){
    int raBusca;

    antes = NULL;

        printf("RA a ser apagado da lista: ");
        scanf("%d", &raBusca);

        auxiliar = inicio;


        while(auxiliar->ra != raBusca){
            antes = auxiliar;
            auxiliar = auxiliar->next;
        }

        if(auxiliar->ra == raBusca){
            antes->next = auxiliar->next;
        }

        //Caso o ra que remova seja o primeiro da lista
        if(auxiliar == inicio){
            inicio = inicio->next;
        }


        free(auxiliar);

        auxiliar = NULL;

        printf("RA removido com sucesso!\n\n");

    system("pause");

}

