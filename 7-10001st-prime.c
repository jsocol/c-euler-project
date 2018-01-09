#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int max_primes = 10001;
    int total_primes = 1;
    int primes[max_primes];
    primes[0] = 2;

    long i = 1;
    int j;
    int is_prime = 0;
    while (total_primes < max_primes) {
        i += 2;
        printf("Testing %ld for primality... ", i);
        is_prime = 1;
        for (j = 0; j < total_primes; j++) {
            if (i % primes[j] == 0) {
                printf("%ld is divisible by %d (%dth prime), not prime!\n", i, primes[j], (j + 1));
                is_prime = 0;
                break;
            }
        }
        if (!is_prime) {
            continue;
        }
        printf("seems prime!\n");
        primes[total_primes] = i;
        total_primes++;
        printf("Found %d primes. Last prime found: %d\n", total_primes, primes[total_primes - 1]);
    }

    return 0;
}
