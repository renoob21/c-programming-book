#include <stdio.h>
#define BUFSIZE 100

int strleng(char *s) {
    char *p;
    p = s;

    for (;*p;p++)
        ;
    
    return p - s;
}

int main()
{
    char str[BUFSIZE], *pst;
    int i, c;

    for (i = 0, pst = str; (c = getchar()) != EOF && i < BUFSIZE; i++)
        *(pst + i) = c;
    
    printf("\nLength: %d", strleng(str));
    return 0;
}
