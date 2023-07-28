#include <stdio.h>

void main() {
    int c, i, nwhite, nother;
    int ndigit[10];

    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    nwhite = nother = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }
        
    }

    printf("ndigits = ");
    for (i = 0; i < 10; i++) {
        printf("%d",ndigit[i]);
    }

    printf(" nwhites = %d ", nwhite);
    printf("nothers = %d", nother);
    
}