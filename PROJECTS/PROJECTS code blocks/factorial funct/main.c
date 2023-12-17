#include <stdio.h>
#include <stdlib.h>
void factorial(int num);
int main()
{

   int num;
   printf("Enter Number To Get Factorial of it \t");
   scanf("%i",&num);
   printf("\n");
   factorial(num);
    return 0;
}

void factorial(int n){
   int fact=1;
   for(int i=1;i<=n;i++){
     fact*=i;
   }
  printf(" Factorial  Equal %i",fact);

}
