#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void reverse(char s[]) {
    int c, i, j;

    /*Comma operators used to initialize and loop the value together*/
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    

}

int itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    do
    {
        s[i++] = (n % 10) + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

int main(int argc, char *argv[])
{
    int num = -256;
    char str[MAX_LEN];

    itoa(num, str);

    printf("%s", str);
    return 0;
}
