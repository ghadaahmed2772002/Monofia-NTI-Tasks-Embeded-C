#include <stdlib.h>

struct node{
int data ;
struct node *next_node;
};

void createNode(struct node *first1, int n);
void display(struct node *first);
struct node *insertFirst(struct node *first);
struct node *insertLast(struct node *first) ;

/* .........................create  single linked list .....................................*/
int main()
{
     char option;

    while (1) {
        printf("enter operation: if begin -> b, if stop -> s\n");
        scanf(" %c", &option);

        if (option == 'b') {
            struct node *first;
            create_List(first);
        } else if (option == 's') {
            printf("...done...\n");
            break;
        }
    }



    return 0;
}
/*create node except first node*/
void createNode(struct node *first,int n){
 struct node *first1 =first;
        for(int i=0;i<n;i++){ /*n-1 as the first allocated in previous step outside func*/

            /*memory for a new node*/
                struct node *node1 = (struct node *)malloc(sizeof(struct node));
                printf("enter student %d score : ", i+1 ); /*start with second std*/
                scanf("%d", &(node1->data));
                node1->next_node = NULL;
                first1->next_node = node1;
                first1 = first1->next_node;    /* same if  first1 = node1 */
        }

}

void display(struct node* first) {
    struct node* head = first;
    int i=1;
   while(head!=NULL){
        printf("Student %d score: %d\n", i , head->data);
        head = head->next_node;
        i++;
   }
}
struct node *insertFirst(struct node *first) {
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    printf("insert at first position  student score: " ); /*start with second std*/
    scanf("%d", &(node2->data));
    printf("\n");
    if(node2==NULL)
       printf("allocated \n");

    if(first==NULL){
        printf(" empty \n");
        node2->next_node=NULL;
        first=node2;
    }
    node2->next_node=first;
    first=node2;
   return first;
}

struct node *insertLast(struct node *first) {
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    printf("insert at last position  student score:  "); /* Start with the second student */
    scanf("%d", &(node3->data));
    printf("\n");
    if (node3 == NULL)
        printf("Allocation failed\n");

    if (first == NULL) {
        printf("empty and can insert \n");
        node3->next_node = NULL;
        first = node3;
    } else
     {
    struct node *node4 = first;


        while (node4->next_node != NULL) {
            node4 = node4->next_node;
        }


        node4->next_node = node3;
        node3->next_node = NULL;
    }

    return first;
}
void create_List(struct node*first1){
    struct node *first=NULL;
    /* create pointer to the first list  dynamic*/

    int user_score,n;
    printf("enter  student number \n");
    scanf("%d",&n);

    printf("enter  user score \n");
    scanf("%d",&user_score);


    struct node *ptr=(struct node*)malloc(sizeof(struct node ));
    /*.............. .........first should constant................... */
    first=ptr;
    struct node *head=first;
    ptr->data=user_score;
    ptr->next_node=NULL;
    /*..........................read list element.........................................*/
    if(first==NULL){
        printf("list is empty \n");
    }
    createNode(ptr,n);
    display(first);
    struct node*newnode=insertFirst(first);
    display(newnode);

    struct node*newnode2=insertLast(newnode);
    display(newnode2);

}
