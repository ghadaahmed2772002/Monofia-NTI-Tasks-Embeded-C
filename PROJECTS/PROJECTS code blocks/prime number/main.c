#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
boolis_number_prime(int n);
void prime_number(int n);
int main()
{
   int num;
   printf("Enter Number to check \t");
   scanf("%i",&num);
   printf("\n");
   printf("all prime numbers \n");
   prime_number(num);

   printf("all  not prime numbers \n");
   not_prime_number(num);

    return 0;
}


// check
bool is_number_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// print prime
void prime_number(int n) {
    for (int i = 2; i < n; i++) {
        if (is_number_prime(i)) {
            printf("%i \t", i);
        }
    }
    printf("\n");
}
void not_prime_number(int n) {
    printf("\t 1  \t");
    for (int i = 2; i < n; i++) {
        if (!is_number_prime(i)) {
            printf("%i \t", i);
        }
    }
    printf("\n");
}
