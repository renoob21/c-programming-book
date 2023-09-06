#include <stdio.h>
#include <ctype.h>

void printarr(double *pa, int n) {
    int i;
    printf("Your array: ");
    for (i = 0; i < n; i++, pa++) {
        printf("%g ", *pa);
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

int getfloat(double *pn) {
    int c, sign, pow;

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
    
    if (!isdigit(c) && c != '.')
        return c;
    
    if (c == '.')
        c = getch();
    
    for (pow = 1; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
        pow *= 10;
    }

    *pn = *pn * sign / pow;

    if (c != EOF)
        ungetch(c);
    
    return c;
    
}

int main()
{
    int n;
    double array[BUFF];
    for (n = 0; n < BUFF && getfloat(&array[n]) != EOF; n++)
        ;
    
    printarr(&array[0], n);
    return 0;
}