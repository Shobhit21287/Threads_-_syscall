#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void main(){
    pid_t new;
    clock_t start,end;
    start = clock();
    
    char* arr[] = {"bruhbash.sh",NULL};

    new = fork();

    if (new == 0){
        execv(path,arr);
        exit(EXIT_SUCCESS);
    }
    else if(new > 0){
        wait(NULL);
    }
    else{
        printf("unable to make child process");
    }
    
    new = fork();

    if (new == 0){
        execv("./bruhbash.sh",arr);
        exit(EXIT_SUCCESS);
    }
    else if(new > 0){
        wait(NULL);
    }
    else{
        printf("unable to make child process");
    }
    
    new = fork();

    if (new == 0){
        execv(path,arr);
        exit(EXIT_SUCCESS);
    }
    else if(new > 0){
        wait(NULL);
    }
    else{
        printf("unable to make child process");
    }
    end = clock();

    double final_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n%f seconds taken to compile the kernel thrice \n",final_time);
}