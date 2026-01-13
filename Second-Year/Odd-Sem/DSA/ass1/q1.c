#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr = (int *) malloc(10 * sizeof(int ));
    // printf("%d",sizeof(int));
    printf("Enter the 10 values : ");
    for(int i = 0; i< 10; i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(int i = 5; i< 9 ; i++){
        arr[i] = arr[i + 1];
    }
    for(int i = 2; i< 9 ; i++){
        arr[i] = arr[i + 1];
    }
    printf("%d",arr[4]);
    free(arr);
    return 0;
}