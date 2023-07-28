#include <stdio.h>

int atoi(char c[]) {
    int n = 0;

    for (int i = 0; c[i] != '\0' && c[i] >= '0' && c[i] <= '9'; ++i) {
        n = (10 * n) + (c[i] - '0');
    }

    return n;
}

int main(int argc, char const *argv[])
{
    printf("unconverted : %d\n", "1000");
    printf("unconverted : %d", atoi("1000"));
    return 0;
}
