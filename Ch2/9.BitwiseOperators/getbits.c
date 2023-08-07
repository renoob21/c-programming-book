#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main(int argc, char const *argv[])
{
    printf("%d", getbits('x', 4,3));
    return 0;
}
