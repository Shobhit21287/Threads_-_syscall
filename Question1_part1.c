#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

void *countA(void *runtime){
    int i = 1;
    for(long int j == 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    return;
}

void *countB(void *runtime){
    int i = 1;
    for(long int j == 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    return;
}

void *countC(void *runtime){
    int i = 1;
    for(long int j == 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    return;
}

int main(){
    pthread_t Thr-A;
    pthread_t Thr-B;
    pthread_t Thr-C;
    int rt1,rt2,rt3; //cumulative time of running

    int test_cases = 0; //number of times the program has run

    sched_param forA; //parameters for the 3 threads
    sched_param forB;
    sched_param forC;

    pthread_attr_t attr1, attr2, attr3;

    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    pthread_attr_setinheritedsched(&attr1, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritedsched(&attr2, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritedsched(&attr3, PTHREAD_EXPLICIT_SCHED);

    //base case : case number1 

    pthread_attr_setschedpolicy(&attr1,SCHED_OTHER);
    pthread_attr_setschedpolicy(&attr2,SCHED_RR);
    pthread_attr_setschedpolicy(&attr3,SCHED_FIFO);

    time_t start1 = time(NULL);
    pthread_create(&Thr-A,&attr1,countA,(void*) rt1);
    time_t start2 = time(NULL);
    pthread_create(&Thr-B,&attr2,countB,(void*) rt2);
    time_t start3 = time(NULL);
    pthread_create(&Thr-C,&attr3,countC,(void*) rt3);

    pthread_join(Thr-A,NULL);
    time_t end1 = time(NULL) - start1;
    pthread_join(Thr-B,NULL);
    time_t end2 = time(NULL) - start2;
    pthread_join(Thr-C,NULL);
    time_t end3 = time(NULL) - start3;

}