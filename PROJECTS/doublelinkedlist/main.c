#include <stdio.h>
#include <stdlib.h>

/* create studentlist data type...................... */
typedef struct studentlist {
    int score;
    struct studentlist *prev;
    struct studentlist *next;
};

/* functions define ....................... */
struct studentlist* createfirst();
void createother(struct studentlist *listptr, int size);
struct studentlist *createlist(int size);
void displaylist(struct studentlist *listptr);
int countnode(struct studentlist *list);
struct studentlist *sumlist(struct studentlist *l1, struct studentlist *l2);
void displaylist_backward(struct studentlist *listptr);


/*main project.......................................*/
int main() {
    struct studentlist *l1=NULL,*l2=NULL,*l3=NULL;
    int n;
    printf("enter number of student: \t");
    scanf("%i", &n);
    printf("\n");
    printf("create list 1........................\n");
    l1 = createlist(n);
    displaylist(l1);
    printf("display  list 1 back ........................\n");
    displaylist_backward(l1);

    printf("create list 2........................\n");
    l2 = createlist(n);
    displaylist(l2);
     printf("display  list 2 back ........................\n");
    displaylist_backward(l2);

    printf("create list 3........................\n");
    l3 = sumlist(l1,l2);
    displaylist(l3);
     printf("display  list 3 back ........................\n");
    displaylist_backward(l3);
    return 0;
}

/* create first .........................................................................*/
struct studentlist* createfirst() {
    char option;
    int x;
    struct studentlist *listptr = (struct studentlist*)malloc(sizeof(struct studentlist));
    if (listptr == NULL)
        printf("cannot allocate for the first node create \n");
    printf("enter y to create n to initial skip \n");
    scanf(" %c", &option);
    if (option == 'n');
    else {
        printf("enter score 1 for student \n");
        scanf("%i", &x);
        listptr->score = x;
    }
    listptr->next = NULL;
    listptr->prev = NULL;

    return listptr;
}

/* create other ........................................................................*/
void createother(struct studentlist *listptr, int size) {
    struct studentlist *listptr2 = listptr;
    char option;
    int x;

    for (int i = 1; i < size; i++) {
        struct studentlist *node = (struct studentlist*)malloc(sizeof(struct studentlist));
        if (node == NULL)
            printf("Unable to allocate memory for a new node.\n");

        printf("Enter y to create, n to initialize (skip) student %i: ", i);
        scanf(" %c", &option);
        if (option == 'n') {
            node->next = NULL;
            node->prev = NULL;
        } else {
            printf("Enter score %i for student: ", i + 1);
            scanf("%i", &x);
            node->score = x;
            printf("\n");
        }
        node->next = NULL;
        node->prev = listptr2;  // Link the new node to the existing list
        listptr2->next = node;
        listptr2 = listptr2->next;
    }
}

/* create list double */
struct studentlist *createlist(int size) {
    struct studentlist *listptr = createfirst();
    createother(listptr, size);
    return listptr;
}


/*display function */
void displaylist(struct studentlist *listptr) {
    while (listptr != NULL) {
        printf("Student score: %i\n", listptr->score);
        listptr = listptr->next;
    }
}

/*count nodes*/
int countnode(struct studentlist *list){
 int c=0;
 while(list!=NULL){
    c++;
    list=list->next;
 }
return c;
}

/*sum of two nodes*/
struct studentlist *sumlist(struct studentlist *l1, struct studentlist *l2) {
    int size = countnode(l1);
    printf("Start creating an empty destination list...\n");
    struct studentlist *sumlist = createlist(size);
    struct studentlist *l3 = l1, *l4 = l2, *sumlist2 = sumlist;

    while (l3 != NULL) {
        sumlist->score = l3->score + l4->score;
        if (l3->next != NULL) {
            sumlist->next = createlist(1);
            sumlist->next->prev = sumlist;
            sumlist = sumlist->next;
        }
        if (l3->next != NULL) {
            l3->next->prev = sumlist;
            l4->next->prev = sumlist;
        }
        l3 = l3->next;
        l4 = l4->next;
    }

    return sumlist2;
}


/* display function */
void displaylist_backward(struct studentlist *listptr) {
    struct studentlist *localptr=listptr;
    struct studentlist *lastNode = NULL;
    while(localptr->next!=NULL){
       localptr = localptr->next;
       lastNode = localptr;
    }


    while (lastNode != NULL) {
        printf("student score: %i \n", lastNode->score);
        lastNode = lastNode->prev;
    }
}

/* insert first */
struct studentlist *insertatfirst(struct  studentlist * listptr)
{
   int val;
   struct studentlist *newnode=(struct studentlist *)malloc(sizeof(struct studentlist));
   if(newnode==NULL)
      printf("cannot allocate \n  ");
      printf("enter new val to insert at first \n");
      scanf("%i",&val);
     newnode->score=val;

   newnode->next=listptr;


return newnode;

}


