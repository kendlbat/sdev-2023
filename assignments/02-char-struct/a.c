#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char* z;

    z = (char*) malloc(20);

    strcpy(z, "HelloWorld\0");

    printf("%s %p\n", z, z);

    realloc(z, 18);

    printf("%s %p\n", z, z);

}