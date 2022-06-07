#ifndef D_DEQUE_H_
#define D_DEQUE_H

#include <stdbool.h>

/**
 * @brief double ended quehue has a first and last element.
 *      Stores the data in a dynamic array
 */
typedef struct{
    int first, last, size;
    double* deq;
}deque;

/**
 * @brief Create a deque object
 * 
 * @param size A deque can store (size - 1) elements
 * @return * deque 
 */
deque create_deque(int size);

/**
 * @brief Increases the size of the deque Q
 *        in a factor of two.
 * 
 * @param Q reference to the deque
 */
void add_size(deque* Q);

/**
 * @brief Decreases the size of the deque Q
 *        in a factor of two.
 * 
 * @param Q reference to the deque
 */
void cut_size(deque* Q);

/**
 * @brief Check if a deque is full
 * 
 * @param Q reference to the deque
 * @return true if the deque is full
 * @return false if deque is not full
 */
bool full(deque* Q);

/**
 * @brief Check if a deque is empty
 * 
 * @param Q reference to the deque
 * @return true if the deque is empty
 * @return false if deque is not empty
 */
bool empty(deque* Q);

/**
 * @brief Insert the element x at the end of the deque
 * 
 * @param Q reference to the deque
 * @param x elemto to add
 * @return int 0 o success, 1 if an error occurred
 */
int enquehue_back(deque* Q, double x);

/**
 * @brief Insert the element x at the beggining of the deque
 * 
 * @param Q reference to the deque
 * @param x element to add
 * @return int 0 o success, 1 if an error occurred
 */
int enquehue_front(deque* Q, double x);

/**
 * @brief Pulls out the last element of the deque
 * 
 * @param Q reference to the deque
 * @return double The element that's been pulled out
 */
double dequehue_back(deque* Q);

/**
 * @brief Pulls out the first element of the deque
 * 
 * @param Q reference to the deque
 * @return double The element that's been pulled out
 */
double dequehue_front(deque* Q);

void test_dynamic_deque();

#endif //DEQUE_H_
