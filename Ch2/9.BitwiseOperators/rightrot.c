#include <stdio.h>
#include "printbits.h"
#define BIT_NUM 8

int rightrot(int x, int n) {
    int res = x;

    for (int i =0;i<n;++i) {
        int lastbit = res & 1;
        res = (res >> 1) | (lastbit << (BIT_NUM - 1));
    }

    return res;
}

int main(int argc, char *argv[])
{
    int num = 90;
    int rot = rightrot(num, 3);

    printf("Ori: %d\t", num);
    printbits(num);
    printf("\nRot: %d\t", rot);
    printbits(rot);
    return 0;
}
