#include <stdio.h>
#include "printbits.h"

int invert(int x, int p, int n) {
    int mask = (~(~0 << n)) << (p+1-n);
    return x ^ mask;
}

int main(int argc, char *argv[])
{
    int num = 255;
    int changed = invert(num, 4, 3);
    printf("Ori: %d\t", num);
    printbits(num);
    printf("\nChg: %d\t", changed);
    printbits(changed);
    return 0;
}
