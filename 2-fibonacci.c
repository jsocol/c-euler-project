#include <stdio.h>

int main(int argc, char **argv) {
    int a = 1, b = 2;
    int total = 0;

    while (a < 4000000) {
        if (a % 2 == 0) {
            total += a;
        }
        b = a + b;
        a = b - a;
    }
    printf("Total: %d\n", total);
    return 0;
}
