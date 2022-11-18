#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void *countA(){
    clock_t s,t;
    s = clock();
    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    t = clock();
    double final = (double)(t - s)/ CLOCKS_PER_SEC;
    printf("Thread A : %f\n",final);
}

void *countB(){
    clock_t s,t;
    s = clock();
    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    t = clock();
    double final = (double)(t - s)/ CLOCKS_PER_SEC;
    printf("Thread B : %f\n",final);
}

void *countC(){
    clock_t s,t;
    s = clock();
    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){ 
        i++;
    }
    t = clock();
    double final = (double)(t - s)/ CLOCKS_PER_SEC;
    printf("Thread C : %f\n",final);
}

void func1(){       //test
    pthread_t ThrA;
    struct sched_param forA;
    pthread_attr_t attr1;
    pthread_attr_init(&attr1);
    pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr1,SCHED_OTHER);
    pthread_create(&ThrA,&attr1,countA,NULL);
    pthread_join(ThrA,NULL);
}

int main(){
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;

    struct sched_param forA; //parameters for the 3 threads
    struct sched_param forB;
    struct sched_param forC;

    forB.sched_priority = 25;
    forC.sched_priority = 15;

    pthread_attr_t attr1, attr2, attr3;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setinheritsched(&attr3, PTHREAD_EXPLICIT_SCHED);

    pthread_attr_setschedpolicy(&attr1,SCHED_OTHER);
    pthread_attr_setschedpolicy(&attr2,SCHED_FIFO);
    pthread_attr_setschedpolicy(&attr3,SCHED_RR);

    int var1,var2,var3;

    var2 = pthread_create(&ThrA,&attr1,countA,NULL);
    var3 = pthread_create(&ThrB,&attr2,countB,NULL);
    var1 = pthread_create(&ThrC,&attr3,countC,NULL);
    
    pthread_join(ThrA,NULL);
    pthread_join(ThrB,NULL);
    pthread_join(ThrC,NULL);

    //func1();
}