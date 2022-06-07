#ifndef FLAVIO_JOSEFO_H_
#define FLAVIO_JOSEFO_H_


//Student functions and definition

typedef struct student{
    int pos;
    int original_pos;
    char* name;
}student;


typedef struct student_node{
    struct student_node* next;
    struct student_node* prev;
    student data;
}student_node;

typedef struct dll_student{
    student_node* centi;
    int first, last;
}dll_student;


/**
 * @brief Read the names and position of each student in the file 
 *      "filename" and allocates dynamic memory for each name and
 *       each student added to the list
 * 
 * @param list list that saves the students read
 * @param filename name of the file to read
 * @return int 0 on success, 1 if an error occurred
 */
int create_studentlist(dll_student* list, const char* filename);

/**
 * @brief free allocated memory for the list and the names of the students
 * 
 * @param list dll_student list of students
 * @return int 0 on success, 1 if an error occurred
 */
int free_studentlist(dll_student* list);




//////////////////////////////////////////////////////////////////////////////////////
// Flavio Josefo methods

/**
 * @brief Executes the flavio josefo problem for a group of students given in the 
 *        filename
 * 
 * @param filename name of the file with the students an position
 * @param k steps to kill a student. (if k = 4, survives 0, 1, 2, dies 3)
 * @return int 0 on success, 1 if an error occurred
 */
int flavio_josefo(const char* filename, int k);

/**
 * @brief kills everyone except the last two people. Modifies the list
 *      in such a way that only the 2 survivors remain
 * 
 * @param list list of participants in the circle
 * @param k steps to kill a student. (if k = 4, survives 0, 1, 2, dies 3)
 * @return int original position of the last survivor
 */
int massive_suicide(dll_student* list, int k);



#endif