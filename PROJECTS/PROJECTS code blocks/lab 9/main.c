#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void print_n_primes(int n) {
    int count ;
    int start_number = 2;   // range print start from 2 to count as you want

 for(count=0 ; count < n ; count++) {
        if (is_prime(start_number)) {
            printf("%d\n", start_number);
            count++;
        }
        start_number++;
    }
}

int main() {
    print_50_primes();

    return 0;
}
