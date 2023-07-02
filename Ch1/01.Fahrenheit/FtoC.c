#include <stdio.h>

void main() {
    int fahr, celc;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("fahr\tcelc\n");

    while (fahr <= upper)
    {
        celc = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celc);
        fahr += step;
    }
    
}