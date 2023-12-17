#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}


int main() {
    int a, b;
    printf("Enter first number \n");
    scanf("%i", &a);
    printf("Enter second number \n");
    scanf("%i", &b);

    int (*p[])(int,int)={add,sub,mult};
    printf("0--> add \n1-->multiply \n2-->subtract \n3-->continue \n");
    while(1){
            char choice;
            printf("Enter character \n");
            scanf(" %c", &choice);

            if (choice < '0' || choice > '3') {
                printf("Invalid input. Please enter a valid option.\n");
                continue;
            }
            printf("%d\n", (*p[choice - '0'])(a, b));
    }
    return 0;
}


