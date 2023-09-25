#include <stdio.h>

#include <stdlib.h>

char funk(char zeichen, int *zahl);

int main() {

    char b[26];

    char* pb = b;

    int z[10];

    int* pz = z;

    int i;

    for (i = 0; i < 10; i++)
        z[i] = 2 * i + 1;

    for (i = 0; i < 26; i++)
        b[i] = i + 97;


    /*
    Ausgabe:
    b : addr of beginning of b
    &b[0] : addr of beginning of b
    *b : 97
    b[0] : 97
    (char) *b : a
    (char) b[0] : a
    */
    printf("\n%d %d %d %d %c %c", b, &b[0], *b, b[0], *b, b[0]);

    /*
    Ausgabe:
    &pb : addr of pb
    pb : addr of beginning of b
    pb[0] : 97
    *pb : 97
    (char) pb[0] : a
    (char) *pb : a
    */
    printf("\n%d %d %d %d %c %c", &pb, pb, pb[0], *pb, pb[0], *pb);

    /*
    Ausgabe:
    z : addr of beginning of z
    &z[0] : addr of beginning of z
    *z : 1
    z[0] : 1
    *z : 1
    *(&z[0]) : 1
    */
    printf("\n%d %d %d %d %d %d", z, &z[0], *z, z[0], *z, *(&z[0]));

    // Params: 'a', addr of beginning of z
    b[0] = funk(*pb, pz);

    /*
    Ausgabe:
    z : addr of beginning of z
    &z[0] : addr of beginning of z
    *z : 2
    z[0] : 2
    *z : 2
    *(&z[0]) : 2
    */
    printf("\n%d %d %d %d %d %d", z, &z[0], *z, z[0], *z, *(&z[0]));

    /*
    Ausgabe:
    &pz : addr of pz
    pz : addr of beginning of z
    pz[0] : 2
    *pz : 2
    */
    printf("\n%d %d %d %d", &pz, pz, pz[0], *pz);

    pz = (int*) malloc(sizeof(int) * 10);

    for (i = 0; i < 10; i++)
        *(pz + i * sizeof(int)) = z + i * sizeof(int);

    realloc(pz, sizeof(int) * 20);

    return 0;
}

char funk(char c, int *u) {
    /*
    Ausgabe:
    &c : addr of c (different address, because call by value not by addr)
    c : 97
    */
    printf("\n%d %d", &c, c);

    c++;

    /*
    Ausgabe:
    &c : addr of c
    (int) c : 98
    (char) c : b
    */
    printf("\n%d %d %c", &c, c, c);

    (*u)++;

    return c;
}