#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

int fibo(int MAX) {
    int i;
    int *ptr;

    ptr = (int*) malloc(MAX * sizeof(int));
    ptr[0] = 0;
    ptr[1] = 1;
    for (i=2; i<MAX; i++) ptr[i] = ptr[i-2] + ptr[i-1];
    for (i=2; i<MAX; i++) printf("\n%d", ptr[i]);
    return 0;
}

int main() {
    fibo(10);
    return 0;
}