#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue {
    int rear, front, capacity, size;
    int *arr;
};

struct queue* create_queue(int cap);
int is_empty(struct queue* q);
int is_full(struct queue* q);
void enqueue(struct queue* q);
int dequeue(struct queue* q);

int main() {
    struct queue *q1 = NULL;
    int cap, op;

    printf("enter capacity \n");
    scanf("%i", &cap);
    q1 = create_queue(cap);
    printf(" meta data rear %d front %d capacity %d address %p size %d\n", q1->rear, q1->front, q1->capacity, (void*)q1->arr, q1->size);
    enqueue(q1);

    printf(" after meta data rear %d front %d capacity %d address %p size %d\n", q1->rear, q1->front, q1->capacity, (void*)q1->arr, q1->size);
    printf("arr : %d\n", q1->arr[q1->rear]);
    printf("data after dequeue : %d\n", dequeue(q1));

    free(q1->arr); // Free the allocated memory for the array
    free(q1); // Free the allocated memory for the queue

    return 0;
}

struct queue* create_queue(int cap) {
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("cannot allocate q \n");
        exit(0);
    }
    q->capacity = cap;
    q->rear = (q->capacity) - 1;
    q->front = 0;
    q->size = 0;
    q->arr = malloc(sizeof(int) * q->capacity);
    if (q->arr == NULL) {
        printf("cannot allocate arr address \n");
        exit(0);
    }
    return q;
}

int is_empty(struct queue* q) {
    return q->size == 0;
}

int is_full(struct queue* q) {
    return q->size == q->capacity;
}

void enqueue(struct queue* q) {
    int data;
    if (is_full(q) == 1) {
        printf("overflow in function enqueue\n");
        return;
    } else {
        printf("enter data \n");
        scanf("%d", &data);
        q->rear = (q->rear + 1) % q->capacity;
        q->arr[q->rear] = data;
        q->size++;
    }
}

int dequeue(struct queue* q) {
    if (is_empty(q) == 1) {
        printf("underflow \n");
        return INT_MIN;
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return data;
}
