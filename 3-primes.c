#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int max_primes = 1000;
    int total_primes = 1;
    int *primes;
    int max_factors = 1000;
    int total_factors = 0;
    int *factors;
    primes = malloc(max_primes * sizeof(int));
    primes[0] = 2;
    
    factors = malloc(max_factors * sizeof(int));

    long i, j;
    int is_prime = 0;
    long MAX = 600851475143;
    for (i = 3; i <= MAX; i += 2) {
        //printf("Testing %ld for primality... ", i);
        is_prime = 1;
        for (j = 0; j < total_primes; j++) {
            if (i % primes[j] == 0) {
                //printf("%ld is divisible by %d (%ldth prime), not prime!\n", i, primes[j], (j + 1));
                is_prime = 0;
                break;
            }
        }
        if (!is_prime) {
            continue;
        }
        //printf("%ld seems prime!\n", i);
        if (total_primes >= max_primes) {
            max_primes *= 2;
            primes = realloc(primes, max_primes * sizeof(int));
        }
        primes[total_primes] = i;
        total_primes++;
        //printf("Found %d primes. Last prime found: %d\n", total_primes, primes[total_primes - 1]);

        //printf("Testing MAX of %ld... ", MAX);
        if (MAX % i == 0) {
            //printf("%ld is a factor of %ld!\n", i, MAX);
            if (total_factors >= max_factors) {
                max_factors *= 2;
                factors = realloc(factors, max_factors * sizeof(int));
            }
            factors[total_factors] = i;
            total_factors++;
            MAX = MAX / i;
            //printf("MAX is down to %ld...\n", MAX);
            //printf("Found %d factors. Last factor found: %d\n", total_factors, factors[total_factors - 1]);
        } else {
            //printf("%ld is not a factor.\n", i);
        }
    }

    printf("Prime factors are... ");
    long int re_multiply = 1;
    for (i = 0; i < total_factors; i++) {
        re_multiply *= (long int)factors[i];
        printf("%d", factors[i]);
        if (i < total_factors - 1) {
            printf(", ");
        }
    }
    printf(".\n");
    printf("And their product is... %ld\n", re_multiply);
    int largest_factor = factors[total_factors - 1];
    printf("Largest prime factor: %d\n", largest_factor);
    free(primes);
    free(factors);
    return 0;
}
