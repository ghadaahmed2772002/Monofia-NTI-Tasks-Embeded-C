#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct student {
    int score;
};

struct queue {
    int rear, front, capacity, size;
    struct student* arrStudents;
};

struct queue* create_queue(int cap);
int is_empty(struct queue* q);
int is_full(struct queue* q);
void enqueue(struct queue* q, int score);
void print_queue(struct queue* q);

int main() {
    struct queue* score_queue = NULL;
    int cap, numStudents, score;

    printf(":Enter the capacity of the queue: ");
    scanf("%d", &cap);

    score_queue = create_queue(cap);

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; ++i) {
        printf("Enter the score for student %d: ", i + 1);
        scanf("%d", &score);
        enqueue(score_queue, score);
    }

    printf("queue priority  :\n");
    print_queue(score_queue);

    return 0;
}

struct queue* create_queue(int cap) {
    struct queue* q = malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Cannot allocate queue\n");
        exit(0);
    }

    q->capacity = cap;
    q->rear = -1;
    q->front = 0;
    q->size = 0;

    q->arrStudents = malloc(sizeof(struct student) * q->capacity);
    if (q->arrStudents == NULL) {
        printf("Cannot allocate student array\n");
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

void enqueue(struct queue* q, int score) {
    if (is_full(q) == 1) {
        printf("overflow in function enqueue\n");
        return;
    } else {
        q->rear = (q->rear + 1) % q->capacity;
        q->arrStudents[q->rear].score = score;
        q->size++;
    }
}

void print_queue(struct queue* q) {
    if (is_empty(q) == 1) {
        printf(" underflow queue is empty.\n");
        return;
    }


    int i = q->front;
    do {
        printf("Student %d: Score %d\n", i + 1, q->arrStudents[i].score);
        i = (i + 1) % q->capacity;
    } while (i != (q->rear + 1) % q->capacity);
}
