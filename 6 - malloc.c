#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr;
    int n;

    printf("Array size: ");
    scanf("%d", &n);

    arr = (int)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Not possible to create memory for this array!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    for(int j = 0; j < n; j++){
        printf("%d\n", arr[j]);
    }

    free(arr);

    return 0;
}
