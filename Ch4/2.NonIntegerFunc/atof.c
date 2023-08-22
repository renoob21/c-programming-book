#include <stdio.h>
#include <ctype.h>


double atof(char s[]) {
    double val, power, pow;
    int i, sign, sci, exp, j;

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

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    
    sci = (s[i] == '-') ? 0 : 1;

    if (s[i] == '-' || s[i] == '+')
        i++;
    
    for (exp = 0; isdigit(s[i]); i++)
    {
        exp = 10 * exp + (s[i] - '0');
    }

    if (sci) {
        for (pow = 1.0, j=0;j < exp; j++ )
            pow *= 10.0;
    } else {
        for (pow = 1.0, j=0;j < exp; j++ )
            pow /= 10.0;
    }
    
    


    return sign * val / power * pow;
}

int main(int argc, char *argv[])
{
    printf("%g", atof(argv[1]));
    return 0;
}
