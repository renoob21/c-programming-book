#include <stdio.h>

int main() {
    float celc, fahr;
    int lower, step, upper;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celc\tFahr\n");

    celc = lower;
    while (celc <= upper) {
        fahr = (9 * celc / 5) + 32;
        printf("%3.1f\t%6.1f\n", celc, fahr);
        celc+=step;
    }
    return 0;
}