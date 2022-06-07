#ifndef DLL_DEQUE_H_
#define DLL_DEQUE_H_

#include <stdbool.h>


/**
 * @brief node.
 *	Uses dynamic memory.
 *	Each node has a next and prev node.
 */
typedef struct node{
    struct node* next;
    struct node* prev;
    double data;
    
}node;

/**
 * @brief Double ended quehue.
 *	Stores the data in a circular double linked list.
 */
typedef struct dll_deque{
    struct node* centi;
}dll_deque;


/**
 * @brief Create a dll deque object
 * 
 * @return dll_deque 
 */
dll_deque create_dll_deque();

/**
 * @brief Insert the element x at the end of the dll deque
 * 
 * @param Q reference to the dll deque
 * @param x element to add
 * @return int 0 o success, 1 if an error occurred
 */
int dll_enquehue_back(dll_deque* Q, double x);

/**
 * @brief Insert the element x at the beginning of the dll deque
 * 
 * @param Q reference to the dll deque
 * @param x element to add
 * @return int 0 o success, 1 if an error occurred
 */
int dll_enquehue_front(dll_deque* Q, double x);

/**
 * @brief Pulls out the last element of the dll deque
 * 
 * @param Q reference to the dll deque
 * @return double The element that's been pulled out
 */
double dll_dequehue_back(dll_deque* Q);

/**
 * @brief Pulls out the first element of the dll deque
 * 
 * @param Q reference to the dll deque
 * @return double The element that's been pulled out
 */
double dll_dequehue_front(dll_deque* Q);

void test_dlldequehue();

#endif
