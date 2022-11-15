#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

void *countA(){
    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    return NULL;
}

void *countB(){
    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    return NULL;
}

void *countC(){
    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    return NULL;
}

void *function(){
    countA();
    countB();
    countC();
}

int main(){
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;
    int rt1,rt2,rt3; //cumulative time of running

    int test_cases = 0; //number of times the program has run

    struct sched_param forA; //parameters for the 3 threads
    struct sched_param forB;
    struct sched_param forC;

    pthread_attr_t attr1, attr2, attr3;

    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritsched(&attr3, PTHREAD_EXPLICIT_SCHED);

    //base case : case number1 

    pthread_attr_setschedpolicy(&attr1,SCHED_OTHER);
    pthread_attr_setschedpolicy(&attr2,SCHED_RR);
    pthread_attr_setschedpolicy(&attr3,SCHED_FIFO);

    clock_t s,t;
        
    s = clock();
    pthread_create(&ThrA,&attr1,function,NULL);
    pthread_join(ThrA,NULL);
    t = clock();
    printf("Thread A :");
    double total_t = (double)(t-s) / CLOCKS_PER_SEC;
    printf("%f \n",total_t);

    s = clock();
    pthread_create(&ThrB,&attr2,function,NULL);
    pthread_join(ThrB,NULL);
    t = clock();
    total_t = (double)(t-s) / CLOCKS_PER_SEC;
    printf("Thread B :");
    printf("%f \n",total_t);

    s = clock();
    pthread_create(&ThrC,&attr3,function,NULL);
    pthread_join(ThrC,NULL);
    t = clock();
    total_t = (double)(t-s) / CLOCKS_PER_SEC;
    printf("Thread C :");
    printf("%f \n",total_t);

}