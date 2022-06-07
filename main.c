#include <stdlib.h>
#include <stdio.h>
#include "d_deque.h"
#include "dll_deque.h"
#include "flavio_josefo.h"

#define FILENAME "grupo.dat"
#define K 3

void print_ddeque(deque* Q);
void print_dlldeque(dll_deque* Q);

int main(){
    
    test_dynamic_deque();

    test_dlldequehue();
    
    int success = flavio_josefo(FILENAME,K);
    if (success == 1){
        printf("An error occurred in flavio josefo function\n");
        return 1;
    }

    return 0;
}






