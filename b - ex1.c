#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[100];
    int idade;
} aluno;


int main()
{
    int n;
    aluno *estud;

    printf("Numero de alunos: ");
    scanf("%d", &n);

    getchar();

    estud = (aluno*)malloc(n*sizeof(aluno));

    if(estud == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("\nNome do aluno %d: ", i+1);
        fgets(estud[i].nome, 100, stdin);
        //Remover o "\n" para evitar erros no buffer
        estud[i].nome[strcspn(estud[i].nome, "\n")] = '\0';

        printf("Idade do aluno %d: ", i+1);
        scanf("%d", &estud[i].idade);

        getchar();
    }

    for(int i = 0; i < n; i++){
        printf("\n\nNome do aluno %d: %s\n", i+1, estud[i].nome);
        printf("Idade do aluno %d: %d\n\n", i+1, estud[i].idade);
    }

    free(estud);
    estud = NULL;

    return 0;
}

