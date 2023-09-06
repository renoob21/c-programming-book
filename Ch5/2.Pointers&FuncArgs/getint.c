#include <stdio.h>
#include <ctype.h>

void printarr(int v[], int n) {
    int i;
    printf("Your array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n\n");
}


#define BUFF 100
int ipt[BUFF];

char buf[BUFF]; /*buffer for ungetch*/
int bufp = 0; /*next free position for buf*/

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFF)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }


    sign = (c == '-') ? -1 : 1;

    if (c == '-' || c == '+')
        while (!isdigit(c = getch()))
            ;
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    
    return c;
}


int main()
{
    int n, array[BUFF];
    for (n = 0; n < BUFF && getint(&array[n]) != EOF; n++)
        ;
    
    printarr(array, n);
    return 0;
}
