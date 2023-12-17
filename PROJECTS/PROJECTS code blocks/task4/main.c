#include <stdlib.h>
#include <stdio.h>

int main() {
    int size;
    int arr[size];
    int t;

    printf("enter  size \n ");
    scanf("%i", &size);

    for (int i = 0; i <= size ; i++) {
        printf("arr element %i \n",i+1);
        scanf("%i" , &arr[i]);
    }
    for (int i = 0; i != size - 1 ; i++) {

           t=arr[i];
           arr[i]=arr[size-i];
           arr[size-i]=t;


    }



    for (int i = 0; i <= size ; i++) {
       printf("arr element %i  = %i \n", i+1 , arr[i]);
    }





    return 0;
}
