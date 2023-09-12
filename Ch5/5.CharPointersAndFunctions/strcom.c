#include <stdio.h>

int strcom(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int main()
{
    char str1[] = "Sembrono";
    char str2[] = "Sembarang";

    printf("%d", strcom(str1, str2));
    return 0;
}
