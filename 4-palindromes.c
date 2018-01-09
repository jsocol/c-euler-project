#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_palindrome(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i <= j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int i, j;
    char product[10];
    for (i = 999; i > 99; i--) {
        for (j = i; j > i - 100; j--) {
            sprintf(product, "%d", i * j);
            if (is_palindrome(product)) {
                printf("Found it! %d * %d = %s\n", i, j, product);
                return 0;
            }
        }
    }
    printf("%s %d\n", "cat", is_palindrome("cat"));
    printf("%s %d\n", "tacocat", is_palindrome("tacocat"));
    return 1;
}
