#include <stdio.h>

int main()
{
    int x = 1, y = 2, z[10];
    int *ip;

    printf("x = %d\ny = %d\n\n", x, y);
    ip = &x;
    y = *ip;

    printf("x = %d\ny = %d\n\n", x, y);

    *ip = 12;

    printf("x = %d\ny = %d\n\n", x, y);

    x = 10;

    printf("x = %d\ny = %d\n\n", x, y);

    return 0;
}
