#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "flavio_josefo.h"

//Student functions///////////////////////////////////////////////////////////////////

/**
 * @brief Create a student object
 * 
 * @param name name of the student
 * @param pos position of the student in the circle (first = 0)
 * @return student 
 */
student create_student(char* name, int pos){
    student A;
    A.name = name;
    A.pos = pos;
    A.original_pos = pos;
    return A;
}

void edit_student(student A, char* name, int pos, int original_pos){
    A.name = name;
    A.pos = pos;
    A.original_pos = original_pos;
}


/**
 * @brief Create a dll student object
 * 
 * @return dll_student or NULL if can't allocate memory
 */
dll_student create_dll_student(){
    dll_student Q;
    Q.centi = (student_node*)malloc(sizeof(student_node));

    if(Q.centi == NULL){
        printf("can't allocate memory for dll_student");
    }
    
    Q.centi->next = Q.centi;
    Q.centi->prev = Q.centi;

    Q.last = 0;

    return Q;
}

/**
 * @brief Insert the element x at the END of the dll list of students
 * 
 * @param Q reference to the dll_student
 * @param x student to add
 * @return int 0 o success, 1 if an error occurred
 */
int student_enquehue_back(dll_student* Q, student x){

    student_node *new = (student_node*)malloc(sizeof(student_node));

    if(new == NULL){
        printf("can't allocate memory for new student");
        return 1;
    }
    
    new->data = x;
    new->prev = Q->centi->prev;
    new->next = Q->centi;
    Q->centi->prev->next = new;
    Q->centi->prev = new;

    Q->last++;

    return 0;
}

/**
 * @brief Insert the element x at the BEGINNING of the dll list of students
 * 
 * @param Q reference to the dll_student
 * @param x student to add
 * @return int 0 o success, 1 if an error occurred
 */
int student_enquehue_front(dll_student* Q, student x){
    
    student_node *new = (student_node*)malloc(sizeof(student_node));
    
    if(new == NULL){
        printf("can't allocate memory for new student");
        return 1;
    }

    new->data = x;
    new->next = Q->centi->next;
    new->prev = Q->centi;
    Q->centi->next->prev = new;
    Q->centi->next = new;

    Q->last++;

    return 0;
}

student student_kill(dll_student* Q, int pos){

    student killed;
    if(pos >= Q->last) {
        printf("Error: tried to kill an unexistent student\n");
        return killed;
    }

    student_node* temp = NULL;
    student_node* kill = NULL;

    if(Q->last == 0){
        printf("Empty list. Can't kill anyone\n");
        return temp->data;
    }
    int cont = 0;

    temp = Q->centi;

    while(cont < pos){
        temp = temp->next;
        cont ++;
    }
    
    kill = temp->next;
    killed = kill->data;
    temp->next = kill->next;
    kill->next->prev = temp;
    
    Q->last--;
    free(kill);
    kill = NULL;

    //Reenumerar la posicion del resto de estudiantes de la lista
    for(pos; pos < Q->last; pos++){
        temp->next->data.pos = pos;
        temp = temp->next;
    }

    return killed;
}

void print_dllstudent(dll_student* Q){
    student_node *ptr = Q->centi->next;
    if (ptr == Q->centi) printf("No se puede imprimir lista vacía.\n");
    while (ptr != Q->centi)
    {
        printf("Position: %d  Name: %s \n", ptr->data.pos, ptr->data.name);
        ptr = ptr->next;
    }
}


/**
 * @brief Exchanges the data and position of the nodes A & B in the list
 * 
 * @param list dll_student (list of students)
 * @param A student_node*
 * @param B student_node*
 */
void exchange_student(dll_student* list, student_node* A, student_node* B){
    
    if(A == B) return;

    int pos = A->data.pos;
    A->data.pos = B->data.pos;
    B->data.pos = pos;

    student data = A->data;
    A->data = B->data;
    B->data = data;
}

/**
 * @brief sorts a dll_list by name and set the original position to each student
 * 
 * @param list dll_student (list of students)
 */
void sort_dllstudent(dll_student* list){

    //Sort by name
    for (student_node* i = list->centi->next ; i != list->centi->prev; i = i->next)
    {
        student_node* minimo = i;
        for (student_node* j = i->next ; j != list->centi ; j = j->next)
        {
            if (strcmp(j->data.name, minimo->data.name) < 0) minimo = j;
        }
        exchange_student(list, i, minimo);
    }

    //Set original position
    student_node* temp = list->centi->next;
    int position = 0;

    while(temp->next != list->centi){
        edit_student(temp->data, temp->data.name, temp->data.pos, position);
        position = position + 1;
        temp = temp->next;
    }
}


int create_studentlist(dll_student* list, const char* filename){

    FILE* input_file = fopen(filename, "r");
    if (!input_file) exit(EXIT_FAILURE);

    
    char line[50];
    int success, pos;

    while (!feof(input_file)){
        char* name1 = (char*)calloc(60, sizeof(char));
        char* name2 = (char*)calloc(15, sizeof(char));
        char* name3 = (char*)calloc(15, sizeof(char));
        char* name4 = (char*)calloc(15, sizeof(char));
        char* name5 = (char*)calloc(15, sizeof(char));

        if(name1 == NULL | name2 == NULL | name3 == NULL | name4 == NULL | name5 == NULL){
            printf("can't allocate memory for student name\n");
            return 1;
        }

        fgets(line, 50, input_file);
        sscanf(line, "%d %s %s %s %s %s", &pos, name1, name2, name3, name4, name5);
        strcat(name1, " ");
        strcat(name2, " ");
        strcat(name3, " ");
        strcat(name4, " ");
        strcat(name1, name2);
        strcat(name1, name3);
        strcat(name1, name4);
        strcat(name1, name5);

        student A = create_student(name1, pos);
        success = student_enquehue_back(list, A);

        if (success == 1) return 1;

        free(name2);
        free(name3);
        free(name4);
        free(name5);
    }

    fclose(input_file);

    return 0;
}

int free_studentlist(dll_student* list){
    
    printf("\n");
    student_node *temp;
    while (list->centi->next != list->centi)
    {
        temp = list->centi->next;
        list->centi->next = temp->next;
        printf("FREE: %d  Name: %s \n", temp->data.pos, temp->data.name);
        free(temp->data.name);
        temp->data.name = NULL;
        free(temp);
        temp = NULL;
    }
    free(list->centi);
    
    return 0;
}



////////////////////////////////////////////////////////////////////////////////////
//flavio josefo methods

int flavio_josefo(const char* filename, int k){
    dll_student students = create_dll_student();

    int success = create_studentlist(&students, filename);
    if (success == 1){
        printf("An error occurred creating student list\n");
        return 1;
    }

    printf("\nOriginal list of students:\n");
    print_dllstudent(&students);

    sort_dllstudent(&students);
    printf("\nSorted students by name:\n");
    print_dllstudent(&students);

    int survive_pos = massive_suicide(&students, k);

    printf("Survivors:\n");
    print_dllstudent(&students);

    printf("\nPosition to survive: %d \n", survive_pos);

    success = free_studentlist(&students);
    if (success == 1){
        printf("An error occurred freeing list memory\n");
        return 1;
    }
    
    return 0;
}

int massive_suicide(dll_student* list, int k){

    printf("\nExecuting mass suicide...\n");

    student_node* temp = list->centi->next;
    student killed;

    int i = 0;
    while (list->last != 2){
        while(i < k){
            if(temp == list->centi) temp = temp->next;
            temp = temp->next;
            i++;
        }
        if(temp == list->centi->next) temp = temp->next;

        killed = student_kill(list, temp->prev->data.pos);
        i = 0;
    }

    while(i < k){
        if(temp == list->centi) temp = temp->next;
        temp = temp->next;
        i++;
    }
    if(temp == list->centi->next) temp = temp->next;

    return temp->data.original_pos;
}

