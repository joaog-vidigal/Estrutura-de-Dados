#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionarios{
    char nome[100];
    float salario;
} funcionarios;

int main(){
    int n;
    funcionarios *func;

    printf("Numero de funcionarios: ");
    scanf("%d", &n);
    getchar();

    func = (funcionarios*)malloc(n*sizeof(funcionarios));

    if(func == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Nome do funcionario %d: ", i+1);
        fgets(func[i].nome, 100, stdin);
        func[i].nome[strcspn(func[i].nome, "\n")] = '\0';

        printf("Salario do funcionario %d: ", i+1);
        scanf("%f", &func[i].salario);
        getchar();
    }

    for(int i = 0; i < n; i++){
        printf("\nNome do funcionario %d: %s\n", i+1, func[i].nome);
        printf("Salario do funcionario %d: %.2f", i+1, func[i].salario);
    }

    free(func);
    func = NULL;

    return 0;
}
