#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    int square_sum = 0;
    int sum_squares = 0;
    for (i = 0; i <= 100; i++) {
        sum_squares += i * i;
        square_sum += i;
    }
    square_sum *= square_sum;
    printf("Diff: %d\n", square_sum - sum_squares);
    return 0;
}
