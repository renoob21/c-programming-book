#include <stdio.h>

#define BUFSIZE 100

void strcop(char *s, char *t) {
    while ((*s++ = *t++))
        ;
}

int main()
{
    char str[] = "Halo, Nama saya Reno";
    char cpy[BUFSIZE];


    printf("Original: %s\n", str);
    strcop(cpy, str);
    printf("Copy: %s\n", cpy);

    return 0;
}
