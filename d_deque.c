
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "d_deque.h"

deque create_deque(int size){ 

    printf("\nCreating deque of size %d...\n", size);
    
    deque Q;
    Q.size = size;
    Q.first = 1;
    Q.last = 1;
    Q.deq = (double*)calloc(size + 1, sizeof(double*));
    return Q;
}

void add_size(deque* Q){
    int n = 1;
    double* D = (double*) calloc(Q->size * 2 + 1, sizeof(double*));

    for(int i = Q->first; i != Q->last; i = i % Q->size + 1){
        D[n] = Q->deq[i];
        n++;
    }

    free(Q->deq);
    Q->deq = NULL;
    Q->deq = D;  
    Q->size = Q->size * 2;
    Q->first = 1;
    Q->last = n; 
}

void cut_size(deque* Q){
    int n = 1;
    double* D = (double*) calloc(Q->size / 2 + 1, sizeof(double*));

    for(int i = Q->first; i != Q->last; i = i % Q->size + 1){
        D[n] = Q->deq[i];
        n++;
    }

    free(Q->deq);
    Q->deq = NULL;
    Q->deq = D;  
    Q->size = Q->size / 2;
    Q->first = 1;
    Q->last = n; 
}

bool full(deque* Q){
    return ((Q->last % Q->size)+ 1 == Q->first);
}

bool empty(deque* Q){
    return (Q->last == Q->first);
}

int enquehue_back(deque* Q, double x){
    if (full(Q)) add_size(Q);
    if (Q == NULL) {
        printf("Not enough memory");
        return 1;
    }

    Q->deq[Q->last] = x;

    if (Q->last == Q->size) Q->last = 1;
    else Q->last++;

    return 0;
}

int enquehue_front(deque* Q, double x){
    if (full(Q)) add_size(Q);
    if (Q == NULL) {
        printf("Not enough memory");
        return 1;
    }
    
    if (Q->first == 1) Q->first = Q->size;
    else Q->first--;

    Q->deq[Q->first] = x;
    return 0;
}

double dequehue_back(deque* Q){
    if (empty(Q)){
        printf("Empty deqhue");
        return 1;
    }

    if (Q->last > Q->first) 
        if((Q->last - Q->first) < Q->size / 2) 
            cut_size(Q);
    if (Q->last < Q->first ) 
        if ((Q->first - Q->last) > Q->size / 2) 
            cut_size(Q);

    if (Q->last == 1) Q->last = Q->size;
    else Q->last--;
    
    double data = Q->deq[Q->last];
    Q->deq[Q->last] = 0;
    return data;
}

double dequehue_front(deque* Q){
        if (empty(Q)){
        printf("Empty deqhue");
        return 1;
    }
    
    double data = Q->deq[Q->first];
    Q->deq[Q->last] = 0;

    if (Q->last > Q->first) 
        if((Q->last - Q->first) < Q->size / 2) 
            cut_size(Q);
    if (Q->last < Q->first ) 
        if ((Q->first - Q->last) > Q->size / 2) 
            cut_size(Q);
        
    if (Q->first == Q->size) Q->first = 1;
    else Q->first++;

    return data;
}

void print_ddeque(deque* Q){
    printf("\n[");
    for(int i = 1; i <= Q->size; i++){
       printf("%f, ", Q->deq[i]);
    }
    printf("\b\b]\n");
}

void test_dynamic_deque(){
    deque Q = create_deque(4);

    double success = 0;
    printf("\nEncolando al final: ");
    for(int i = 1; i <= 4; i++) {
        success = enquehue_back(&Q, i);
        if (success == 1){
            printf("An error occurred in enquehue_back\n");
            return;
        } 
    }
    print_ddeque(&Q);
    printf("head: %d tail: %d \n\n", Q.first, Q.last);

    printf("\nEncolando al inicio: ");
    for(int i = 1; i <= 5; i++) {
        success = enquehue_front(&Q, i);
        if (success == 1){
            printf("An error occurred in enquehue_front\n");
            return;
        } 
    }
    print_ddeque(&Q);
    printf("head: %d tail: %d \n\n", Q.first, Q.last);


    double dequehued;
    printf("\nDesencolado al final (elementos): ");
    for(int i = 1; i <= 3; i++){
        dequehued = dequehue_back(&Q);
        printf("- %f ", dequehued); 
    }
    print_ddeque(&Q);
    printf("head: %d tail: %d \n\n", Q.first, Q.last);


    printf("\nDesencolado al inicio: ");
    for(int i = 1; i <= 4; i++){
        dequehued = dequehue_front(&Q);
        printf("- %f ", dequehued); 
    }
    print_ddeque(&Q);
    printf("head: %d tail: %d \n\n", Q.first, Q.last);
 

    free(Q.deq);
}