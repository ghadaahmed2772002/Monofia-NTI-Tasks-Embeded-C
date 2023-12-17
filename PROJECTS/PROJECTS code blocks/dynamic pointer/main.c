/*
   int s=5;
    char a[5];
    char *p;
    p=(char*)calloc(5,sizeof(char));    // p= type of array that call return  calloc( count of element , size of var in array)
    // same malloc(5*sizeof(char))
    // free(ptr) ---> free space    give (index where start to free)*/


#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Enter Length of array: ");
    scanf("%i", &n);



    char *ptr = (char *)calloc((n+1) , sizeof(char));

    if (ptr == NULL) {
        printf("Fail \n");
    } else {
        printf("success \n");
        int i;
        for (i = 0; i < n+1 ; i++) {
                       scanf("%c",ptr+i);

        }


        for (i = 0; i < (n + 1); i++) {
                        printf("%c", *(ptr+i));

        }



        free(ptr);
    }

    return 0;
}
