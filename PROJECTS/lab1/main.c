#include <stdio.h>
#include <stdlib.h>

int main()
{

  /*int num;
        printf("enter   a number \n");
        scanf("%i",&num);

        for(int i=num;i>=0;i--){

           printf("%i \n",i);
        }*/

        /*int n;
        int  p=0;
        printf("enter number \n");
        scanf("%i",&n);
        printf("---------------------------------------------------\n");

        if( n==1 || n==2 ){
            p=1;
        }
        else if(n<0)
            {
              printf("negative number ");
              p=2;
        }
        else
        {
        for(int i=2;i<n;i++)
            {
                if(n%i==0)
                 {
                   p=0;
                   break;
                 }
               else
                {
                   p==1;
                }
            }
        }
                if( p==0 )
                {
                    printf("number is  not prime");
                }
                else if(p==1)
                {
                    printf("number is prime");
                }
                else{
                   printf("enter valid number \n");
                }*/

        int n,z,count,sum=0;
        printf("enter   a number \n");
        scanf("%i",&n);

        while (n > 0) {
            z = n / 10;
            count=n % 10;
            sum= sum+z+count;
             n--;
         }
        printf("count of digits %i",sum);




   return 0;
}
