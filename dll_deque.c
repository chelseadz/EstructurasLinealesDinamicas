#include "dll_deque.h"
#include <stdlib.h>
#include <stdio.h>

dll_deque create_dll_deque(){
    dll_deque Q;
    Q.centi = (node*)malloc(sizeof(node));
    
    Q.centi->next = Q.centi;
    Q.centi->prev = Q.centi;

    Q.last = 0;

    printf("deque creada\n");
    return Q;
}

int dll_enquehue_back(dll_deque* Q, double x){

    node *new = (node*)malloc(sizeof(node));
    
    new->data = x;
    new->prev = Q->centi->prev;
    new->next = Q->centi;
    Q->centi->prev->next = new;
    Q->centi->prev = new;

    Q->last++;

    return 0;
}

int dll_enquehue_front(dll_deque* Q, double x){
    
    node *new = (node*)malloc(sizeof(node));
    
    new->data = x;
    new->next = Q->centi->next;
    new->prev = Q->centi;
    Q->centi->next->prev = new;
    Q->centi->next = new;

    Q->last++;

    return 0;
}

double dll_dequehue_back(dll_deque* Q){

    if(Q->last == 0){
        printf("Empty list");
        return 1;
    }
    
    node* temp;
    temp = Q->centi->prev;

    double data = temp->data;
    Q->centi->prev = temp->prev;
    Q->centi->prev->next = Q->centi;

    Q->last--;
    free(temp);
    temp = NULL;
    return data;
}

double dll_dequehue_front(dll_deque* Q){

    if(Q->last == 0){
        printf("Empty list");
        return 1;
    }
    node *temp;
    temp = Q->centi->next;
    
    double data = temp->data;
    Q->centi->next = temp->next;
    Q->centi->prev->next = Q->centi;

    Q->last--;
    free(temp);
    temp = NULL;
    return data;
}

void free_dlldeque(dll_deque* Q){

    if (Q->centi == NULL){
        printf("\nCan't free empty list\n");
        return;
    }

    if (Q->centi->next == Q->centi) {
        free(Q->centi);
        return;
    }

    node* temp = Q->centi;
    while(temp->next != NULL){
        temp = Q->centi;
        Q->centi = temp->next;
        free(temp);
        temp = NULL;
    }
}

void print_dlldeque(dll_deque* Q){
    printf("\nImprimiendo lista... ");
    node *ptr = Q->centi->next;
    if (ptr == Q->centi) {
        printf("No se puede imprimir lista vacía.\n\n");
        return;
    }
    printf("\n[");
    while (ptr != Q->centi)
    {
        printf("%f, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\b\b]\n\n");
}

void test_dlldequehue(){
 
    dll_deque D = create_dll_deque();


    double success = 0;
    printf("\nEncolando al final: ");
    for(int i = 1; i <= 4; i++) {
        success = dll_enquehue_back(&D, i);
        if (success == 1){
            printf("An error occurred in dll_enquehue_back\n");
            return;
        } 
    }
    print_dlldeque(&D);


    printf("\nEncolando al inicio: ");
    for(int i = 5; i <= 9; i++){
        success = dll_enquehue_front(&D, i);
        if (success == 1){
            printf("An error occurred in dll_enquehue_back\n");
            return;
        } 
    }
    print_dlldeque(&D);


    double dequehued;
    printf("\nDesencolado al final: ");
    for(int i = 1; i <= 5; i++){
        dequehued = dll_dequehue_back(&D);
        printf("- %f ", dequehued); 
    }
    print_dlldeque(&D);


    printf("\nDesencolado al inicio: ");
    for(int i = 1; i <= 4; i++){
        dequehued = dll_dequehue_front(&D);
        printf("- %f ", dequehued); 
    }
    print_dlldeque(&D);


    free_dlldeque(&D);
}