#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter element to get factorial of it : \t");
    scanf("%d",&n);
    printf("\n");
    int f= factorial(n);
    printf("factorial of %i : %i ",n,f);
    return 0;
}
int factorial(int n)
{
  if (n>1){
    return  n * factorial(n-1);
  }else
     return n;

}
