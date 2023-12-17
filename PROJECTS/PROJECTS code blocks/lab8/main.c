#include <stdio.h>
#include <stdbool.h>

/*int power(int x,int y) {
   if (y==0)
      return 1;
   else
      return x*power(x,y-1);
}
int sum(int x){
    if(x==1)
        return 1;
    else
      return x+sum(x-1);


}*/

int fib(int x){
   if (x==1  || x==0)
     return x;
   else
   return fib(x-1)+fib(x-2);

}


void print(int x){
    int i=0;
  while(i<x){
    printf(" fib %i , ", fib(i));
    i++;
  }
}
int main() {
    /*int x,y;
    printf("enter base of number \n");
    scanf("%i",&x);

    printf("enter exponent of number \n");
    scanf("%i",&y);
    int p=power(x,y);
    printf("%i ^ %i = %i ",x,y,p);*/

    int n,s;
    printf("enter a number \n");
    scanf("%i",&n);
    s=fib(n);
    printf("fibonicial : %i \n",s);
    print(n);

    return 0;
}
