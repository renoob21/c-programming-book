#include <stdio.h>
#define BUFF 100

int strleng(char *ps) {
    int n;

    for (n = 0; *ps != '\0'; ps++)
        n++;
    
    return n;
}


void main(int argc, char argv[]) {
    char str[BUFF];
    int i, c;
    char *pst;

    for (i = 0, pst = &str[0]; (c = getchar()) != EOF && i < BUFF; i++)
        *(pst + i) = c;
    *(pst + i) = '\0';

    printf("\nLength: %d", strleng(str));
}