#include <stdio.h>
#include <stdlib.h>

void main(){
    int arr = {{1,2,3},{4,5,6},{7,8,9}};
    
    int **arr2;

    twodcopy(arr,arr2,3,3);

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ;j++){
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    
}