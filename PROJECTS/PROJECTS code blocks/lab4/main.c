#include <stdio.h>

int main() {
    int r1,c1;
     int i, j, k;
    printf("enter  rows number in array 1\t");
    scanf("%d", &r1);
    printf("\n");

    printf("enter  columns number in array 1\t");
    scanf("%d", &c1);
    printf("\n");

    int arr1[r1][c1];

    //create array 2
    int r2,c2;
    printf("enter  rows number in arr2\t");
    scanf("%d", &r2);
    printf("\n");

    printf("enter  columns number in arr2\t");
    scanf("%d", &c2);
    printf("\n");

    int arr2[r2][c2];


    printf("....take element for array 1..........\n");
    printf("\n");
    for (int i = 0; i < r1 ; ++i) {
            for (int j = 0; j < c1 ; ++j) {

                printf("arr 1 element %i row and  %i col \t",i,j);
                scanf("%i", &arr1[i][j]);
                printf("\n");
            }
            printf("\n");
    }
    printf("....take element for array 2..........\n");
    printf("\n");
    for (int i = 0; i < r2 ; ++i) {
            for (int j = 0; j < c2 ; ++j) {

                printf("arr 2 element %i row and  %i col \t",i,j);
                scanf("%i", &arr2[i][j]);
                printf("\n");
            }
            printf("\n");
    }



  printf(".................array 1.................\n");
     for (i = 0; i < r1; ++i) {
        for (j = 0; j < c1; ++j) {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    printf(".................array 2.................\n");
     for (i = 0; i < r2; ++i) {
        for (j = 0; j < c2; ++j) {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

  if(c1!=r2){
        printf("multiplication not available enter  2 matrix that have row number in first equal col in second  \n");
   }
  else{
       int mult[c1][r2];

    // initial multiplication matrix ---0
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            mult[i][j] = 0;
        }
    }

    // multiplication = array 1 *array 2
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            for (k = 0; k < r2; ++k) {
                mult[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

     printf(".................multiplication array.................\n");
    //display multiplication  array
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            printf("%d\t", mult[i][j]);
        }
        printf("\n");
    }



    }

    return 0;
}
