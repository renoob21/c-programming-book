#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* lower(char *s) {
    char *low = malloc(strlen(s));
    int i;

    for (i = 0;*s != '\0'; s++, low++, i++) {
        if (*s >= 'A' && *s <= 'Z')
            *low = *s - 'A' + 'a';
        else
            *low = *s;
    }

    *low = '\0';

    return low-i;
}

int main(int argc, char const *argv[])
{
    printf("Before : %s\nAfter : %s", "HalLo", lower("HalLo"));
    return 0;
}
