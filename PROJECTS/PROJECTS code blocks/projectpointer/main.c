#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,min,max;
    float sum,avg;
    printf("enter size of arr : \t");
    scanf("%d",&n);
    printf("\n");
    int arr[n];

    arr_init(arr,n);
    arr_display(arr,n);
    arr_sum_avg(arr,&sum,&avg,n);
    printf(" sum : %f \n",sum);
    printf(" avg : %f \n",avg);
    arr_min_max(arr,n,&min,&max);
    printf(" min : %i  \n",min);
    printf(" max : %i  \n",max);



    return 0;
}

void arr_init(int *ptr,int size){
     int i;
  for(i =0;i< size;i++){
    printf("enter  element %i \n",i+1);
    scanf("%d",ptr+i);

  }
}

void arr_display(int *ptr,int n){
     int i;
  for(i =0;i< n;i++){
    printf(" element %i : %i  \n",i+1,*(ptr+i));
  }
}

void arr_sum_avg(int *ptr,float *sum,float *avg,int size){
   int i;
  for (i=0;i<size;i++){
      *sum += *ptr;
      ptr++;
  }

   *avg = *sum / size;
}

void arr_min_max(int *ptr,int size,int *min,int *max){
    *min = *ptr;
    *max = *ptr;
    int i;
   for(i=0;i<size;i++){
    if (*(ptr+i) < *min ){
            *min=*(ptr+i);
        }

    if (*(ptr+i) > *max) {
            *max=*(ptr+i);
        }

   }


}
