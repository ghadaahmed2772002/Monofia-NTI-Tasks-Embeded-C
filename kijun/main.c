#include <stdio.h>
#include <stdlib.h>

typedef struct studentlist {
    int score;
    struct studentlist *next;
} StudentList;

StudentList* createListFromFirstNode();
StudentList* createListFromSecondNode(StudentList *listptr, int size);
StudentList* createList(int size);
int countNodes(StudentList *list);
StudentList* sumLists(StudentList *l1, StudentList *l2);
void displayList(StudentList *listptr);
