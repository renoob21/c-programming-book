#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, i, nwhite, nother, ndigit[10];

    for (i = 0; i<10; i++) {
        ndigit[i] = 0;
    }

    nwhite = nother = 0;

    while ((c=getchar()) != EOF)
    {
        switch (c)
        {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ndigit[c-'0']++;
            break;
        case '\n':
        case ' ':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    
    printf("Digits:\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d", ndigit[i]);
    }
    printf("\nWhite:\t%d", nwhite);
    printf("\nOther:\t%d", nother);

    
    return 0;
}
