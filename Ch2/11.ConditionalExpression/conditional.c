#include <stdio.h>

int main(int argc, char const *argv[])
{
    int z, a, b;

    a == 11;
    b = 25;

    if (a>b) {
        z = a;
    } else {
        z = b;
    }

    printf("%d\n", z);

    z = (a>b) ? a : b;
    printf("%d", z);
    return 0;
}
