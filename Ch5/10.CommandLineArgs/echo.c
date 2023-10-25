#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    while (--argc)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");

    return 0;
}
