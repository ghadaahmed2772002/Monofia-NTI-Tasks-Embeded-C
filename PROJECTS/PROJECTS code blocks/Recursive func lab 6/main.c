#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter size of arr : \t");
    scanf("%d",&n);
    printf("\n");
    int arr[n];
    float avg=0;
    arr_init(&arr[0],n);

    char c;
    printf("\t if d ----> display array  \n\t if r-->reverse array \n\t if a-->average of array  \n");
    printf("enter choice : \t \n");
    scanf(" %c",&c);
    printf("\n");

while(1){
   switch(c){
case 'a':
    arr_avg(&arr[0],n,&avg);
    break;
case 'r':
    arr_reverse(&arr[0],n);
    break;
case 'd':
    arr_display(&arr[0],n);
    break;
default:
    exit(1);

   }

}
    return 0;
}


void arr_init(int *arr,int n){
     int i;
  for(i =0;i< n;i++){
    printf("enter  element %i \n",i+1);
    scanf("%d",&arr[i]);
  }
}

void arr_display(int *arr,int n){
     int i;
  for(i =0;i< n;i++){
    printf(" element %i : %i  \n",i+1,arr[i]);
  }
}

void arr_avg(int *arr,int n,float *avg){
     int i ;
     float  sum=0;
  for(i =0;i< n;i++){
    sum+=arr[i];
  }
  *avg=sum / n;
  printf(" sum : %f \n",sum);
  printf(" avg : %f \n",*avg);

}

void arr_reverse(int *arr,int n){
    int i = 0;
    int j = n - 1;
    int t;
    while (i < j) {
        t = arr[i];   //t=*(a+i)
        arr[i] = arr[j];
        arr[j] = t;
        i += 1;
        j -= 1;
    }

   printf("Array after reverse:\n");
    for (int k = 0; k < n; k++) {
        printf("Element %i: %i\n", k, arr[k]);
    }


}
