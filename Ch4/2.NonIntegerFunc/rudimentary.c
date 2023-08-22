#include <stdio.h>
#include <ctype.h>
#define MAX_LINE 1000

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = s[i] == '-' ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

int getlines(char s[], int lim) {
    int i, c;

    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c = '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
    
}

int main(int argc, char *argv[])
{
    double sum, atof(char s[]);
    char line[MAX_LINE];
    int getlines(char line[], int max);

    sum = 0;
    while (getlines(line, MAX_LINE) > 0)
    {
        printf("\t%g\n", sum += atof(line));
    }
    
    return 0;
}
