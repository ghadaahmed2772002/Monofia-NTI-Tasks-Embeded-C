#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return -1; //invalid
}

int my_isalnum(int c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
}

int main() {
    char exp[MAX_SIZE];
    char *ptr, x;
    int count = 0;

    printf(":: enter expression (infix) : ");
    scanf("%s", exp);

    // unmatched (  )
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            count++;
        else if (exp[i] == ')')
            count--;

        if (count < 0) { //close
            printf("error  unmatched parenthesis   \n");
            return 1;
        }
    }

    if (count != 0) { //open
        printf("error unmatched parenthesis \n");
        return 1;
    }

    ptr = exp;
    printf("expression (prefix): ");
    while (*ptr != '\0') {
        // 1
        if (my_isalnum(*ptr))
            printf("%c", *ptr);
        // 2
        else if (*ptr == '(')
            push(*ptr);
        // 3
        else if (*ptr == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        // 4
        else {
            while (top != -1 && priority(stack[top]) >= priority(*ptr)) {
                printf("%c", pop());
            }
            push(*ptr);
        }
        ptr++;
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
