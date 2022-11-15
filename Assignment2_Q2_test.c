#include <stdio.h>
#include <stdlib.h>

void main(){
    double arr = {{1.23,2.34,3.45},{4.56,5.67,6.78},{7.9012,8.2345,9.5678}};
    
    double arr2[3][3];

    syscall(twodcopy,arr,arr2,3,3);

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ;j++){
            printf("%f ",arr2[i][j]);
        }
        printf("\n");
    }
    
}