#include <stdio.h>

int main (int argc, char **argv) {
    int i;
    int total = 0;
    int limit = 1000;
    for (i = 0; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            total += i;
        }
    }
    printf("Total: %d\n", total);
    return 0;
}
