#include <stdio.h>
#include "printbits.h"

int setbits(int x, int p, int n, int y) {
    int modified = (x | (~(~0 << n) << (p+1-n))) & ~(~(~0 << n) << (p+1-n));
    int masked = (y & ~(~0 << n)) << (p+1-n);
    return modified | masked;
}

int main(int argc, char *argv[])
{
    int num = 90;
    int mod = 31;
    int changed = setbits(num, 4, 3, mod);
    printf("Ori: %d\t", num);
    printbits(num);
    printf("\nMod: %d\t", mod);
    printbits(mod);
    printf("\nChg: %d\t", changed);
    printbits(changed);
    return 0;
}
