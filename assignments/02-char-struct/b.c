#include <stdlib.h>
#include <stdio.h>

struct struktur {
    char c0;
    long l0;
    char c1;
    long l1;
    char c2;
};

int main() {
    struct struktur* s;

    printf("%d\n", sizeof(struct struktur));

    return 0;
}

// Es wird mehr oder weniger alloziert - warum? _ich weiß es nicht_
// Siehe https://stackoverflow.com/a/1732454