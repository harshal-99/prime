#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

typedef unsigned long long int lint;
void *result;
void printpn() {
    lint pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97};
    for(int i = 0;i < 24; i++ ) {
        printf("%llu\n",pr[i]);
    }
}



void *pprime1() {
    lint pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97};
    for (lint i = 101; i < 25000000; i++) {
    bool prime = true;
    for ( int n = 0; n < 24; n++) {
        if(i%pr[n] == 0) {
            prime = false;
            break;
        }
        }
        if(prime) {
            printf("%llu\n",i);
        }
    }
    return NULL;
}
void *pprime2() {
    lint pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97};
    for (lint i = 25000001; i < 50000000; i++) {
    bool prime = true;
    for ( int n = 0; n < 24; n++) {
        if(i%pr[n] == 0) {
            prime = false;
            break;
        }
        }
        if(prime) {
            printf("%llu\n",i);
        }
    }
    return NULL;
}

void *pprime3() {
    lint pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97};
    for (lint i = 50000001; i < 75000000; i++) {
    bool prime = true;
    for ( int n = 0; n < 24; n++) {
        if(i%pr[n] == 0) {
            prime = false;
            break;
        }
        }
        if(prime) {
            printf("%llu\n",i);
        }
    }
    return NULL;
}

void *pprime4() {
    lint pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97};
    for (lint i = 75000001; i < 100000000; i++) {
    bool prime = true;
    for ( int n = 0; n < 24; n++) {
        if(i%pr[n] == 0) {
            prime = false;
            break;
        }
        }
        if(prime) {
            printf("%llu\n",i);
        }
    }
    return NULL;
}

void check(pthread_t *t) {
    if(pthread_create(&t[0],NULL,pprime1,NULL) == -1) {
        printf("\n***ERROR***\nCan not create thread 1");
        exit(-1);
    }
    if(pthread_create(&t[1],NULL,pprime2,NULL) == -1) {
        printf("\n***ERROR***\nCan not create thread 2");
        exit(-1);
    }
    if(pthread_create(&t[2],NULL,pprime3,NULL) == -1) {
        printf("\n***ERROR***\nCan not create thread 3");
        exit(-1);
    }
    if(pthread_create(&t[3],NULL,pprime4,NULL) == -1) {
        printf("\n***ERROR***\nCan not create thread 4");
        exit(-1);
    }
}
void join(pthread_t *t) {
    if(pthread_join(t[0],&result) == -1) {
        printf("\n***ERROR***\nCan not join thread 1\n");
        exit(-1);
    }
    if(pthread_join(t[1],&result) == -1) {
        printf("\n***ERROR***\nCan not join thread 2\n");
        exit(-1);
    }
    if(pthread_join(t[2],&result) == -1) {
        printf("\n***ERROR***\nCan not join thread 2\n");
        exit(-1);
    }
    if(pthread_join(t[3],&result) == -1) {
        printf("\n***ERROR***\nCan not join thread 3\n");
        exit(-1);
    }
}



int main() {
    pthread_t t[4];
    check(&t);
    join(&t);
    return 0;
}