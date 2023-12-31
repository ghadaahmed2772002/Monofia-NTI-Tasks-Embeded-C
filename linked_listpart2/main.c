#include <stdio.h>
#include <stdlib.h>
/* create new data type................................................................................. */
typedef struct studentlist {
int score;
struct studentlist *next;
};

/* define............................................................................................... */
struct studentlist *createlist(int size);
void createother(struct studentlist *listptr, int size);
struct studentlist *createlist(int size);
int countnode(struct studentlist *list);
struct studentlist *sumlist(struct studentlist *l1,struct studentlist *l2);
void displaylist(struct studentlist *listptr);
struct studentlist *insertatfirst(struct  studentlist * listptr);
void *insertatlast(struct  studentlist * listptr);
int *insertatmid(struct  studentlist * listptr,int pos);
struct studentlist  *deleteatfirst(struct  studentlist * listptr);
struct studentlist  *deleteatlast(struct  studentlist * listptr);
void deleteatmid(struct studentlist* listptr, int pos);
struct studentlist*  reverselist(struct studentlist* listptr) ;
/* project description :        */

/* create two student list then sum and grade of list............................................ */

int main()
{
/*create 2 list for scores & third for sum...................................................... */
struct studentlist *l1=NULL,*l2=NULL,*l3=NULL;
int n;
printf("enter number of student : \t");
scanf("%i",&n);
printf("\n");
printf("create list 1........................\n");
l1=createlist(n);
displaylist(l1);
printf("list 1. after reverse .......................\n");
l1=reverselist(l1);
displaylist(l1);
printf("create list 2........................\n");
l2=createlist(n);
printf("start sum list.......................................................................\n");
l3=sumlist(l1,l2);



printf("list 2........................\n");
displaylist(l2);
printf("list 3........................\n");
displaylist(l3);
/*now display insert*/
/*printf("list 1 after insert first ....................\n");
l1=insertatfirst(l1);
printf("list 1 after insert. mid...................\n");
insertatmid(l1,3);
printf("list 1 after insert. last...................\n");
insertatlast(l1);*/


/*displaylist(l1);

printf("list 2 after insert first...................\n");
l2=insertatfirst(l2);
printf("list 1 after insert. mid...................\n");
insertatmid(l2,2);
printf("list 2 after insert. last...................\n");
insertatlast(l2);
displaylist(l2);

printf("list 3  sum after insert first...................\n");
l3=sumlist(l1,l2);
printf("list 3 display after ...................\n");
displaylist(l3);*/
/*printf("list 1  delete mid...................\n");
deleteatmid(l1,2);

displaylist(l1);


printf("list 2  delete last...................\n");
l2 = deleteatlast(l2);
displaylist(l2);

printf("list 3  ...................\n");
l3=sumlist(l1,l2);
displaylist(l3);

*/
    return 0;
}

struct studentlist* createfirst(){
    char option;
    int x;
  struct studentlist *listptr=(struct studentlist*)malloc(sizeof(struct studentlist));
  if(listptr==NULL)
    printf("cannot allocate for first node create \n");
  printf("enter y to create n to initial skip \n");
  scanf(" %c",&option);
  if(option=='n');
  else {
    printf("enter score  1 for student \n");
    scanf("%i",&x);
    listptr->score=x;
  }
   listptr->next=NULL;

return listptr;

}

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
        } else {
            printf("Enter score  %i for student : ", i+1);
            scanf("%i", &x);
            node->score = x;
            printf("\n");
        }
            node->next = NULL;
            listptr2->next = node;  // Fix: Link the new node to the existing list
            listptr2 = listptr2->next;
    }


}



struct studentlist *createlist(int size){

      struct studentlist *listptr=createfirst();
     createother(listptr,size);

return listptr;

}


int countnode(struct studentlist *list){
 int c=0;
 while(list!=NULL){
    c++;
    list=list->next;
 }
return c;
}

struct studentlist *sumlist(struct studentlist *l1,struct studentlist *l2){
      int size=countnode(l1);
      printf("start create empty destination \n");
      struct studentlist *sumlist=createlist(size);
      struct studentlist *l3=l1,*l4=l2,*sumlist2=sumlist;

      while(l3!=NULL)
      {
          sumlist->score=l3->score+l4->score;
          l3=l3->next;
          l4=l4->next;
          sumlist=sumlist->next;
      }


return sumlist2;

}

void displaylist(struct studentlist *listptr){
    int i=1;
while(listptr!=NULL){
         printf("student score %i : %i ", i, listptr->score);
         listptr = listptr->next;
         printf("\n");
        i++;
    }

}
/*insert node at first */
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


/*insert node at mid */
int *insertatmid(struct  studentlist * listptr,int pos)
{
    struct studentlist * local=listptr;
   int size =countnode(local);
   int val;
   if(pos <2 || pos>size-1){
    printf("pos invalid \n");
    return(-1);
   }
   else{
       struct studentlist * mid_node=(struct studentlist *)malloc(sizeof(struct studentlist));
        printf("enter new val to insert at last \n");
        scanf("%i",&val);
        mid_node->score=val;

   int i=1;
   while(i<pos)
   {
       local=local->next;
   }

      mid_node->next=local->next;
      local->next=mid_node;

   }

}


/*insert node at last */

void *insertatlast(struct  studentlist * listptr)
{
   int val;
   char o;
   struct studentlist *local=listptr;
   struct studentlist *newnode=(struct studentlist *)malloc(sizeof(struct studentlist));
   if(newnode==NULL)
      printf("cannot allocate \n  ");

      printf("enter new val to insert at last \n");
      scanf("%i",&val);
      newnode->score=val;

   newnode->next=NULL;
   while(local->next!=NULL)
   {
       local=local->next;
   }
   local->next=newnode;
}






/*delete node at first */
struct studentlist *deleteatfirst(struct studentlist *listptr) {
    struct studentlist *head = listptr;
    head = listptr->next;
    free(listptr);
    return head;
}




/*delete node at last */
struct studentlist* deleteatlast(struct studentlist* listptr) {
    if (listptr == NULL || listptr->next == NULL) {
        free(listptr);
        return NULL;
    }

    struct studentlist* head = listptr;
    while (head->next->next != NULL) {
        head = head->next;
    }

    struct studentlist* tail = head->next;
    head->next = NULL;
    free(tail);
    return listptr;
}




/*delete node at mid */
void deleteatmid(struct studentlist* listptr, int pos) {
    struct studentlist* head = listptr;
    /* If the position is < 2 or the list is empty */
    if (pos < 2 || listptr == NULL) {
        return;
    }

    for (int i = 1; i < pos - 1 && head != NULL; i++) {
        head = head->next;
    }

    // If the position is greater than the number of nodes, return
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Node to be deleted is at position 'pos'
    struct studentlist* deleteptr = head->next;
    head->next = deleteptr->next;
    free(deleteptr);
}


/*reverse linked list addresses in single linked list */
struct studentlist*  reverselist(struct studentlist* listptr) {
    struct studentlist *l1,*l2 ;
    if(listptr!=NULL)
    {
        l1=listptr;
        l2=listptr->next;
        listptr=listptr->next;
        l1->next=NULL;


    while(listptr!=NULL)
    {
        listptr=listptr->next;
        l2->next=l1;
        l1=l2;
        l2=listptr;



    }
    listptr=l1;

    }
return listptr;
}
