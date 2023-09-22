#include <stdlib.h>
#include <stdio.h>

int main(char* args) {
    int *x;
    x = (int*) malloc(sizeof(int));

    *x = 7;

    printf("*x = %d\n", *x);
    printf("x = %p\n", x);

    return 0;
}