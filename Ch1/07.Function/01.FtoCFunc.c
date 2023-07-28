#include <stdio.h>
#include <stdlib.h>

float ftoc(float fahr) {
    float celc = (fahr - 32) * 5 / 9;
    return celc;
}

int main(int argc, char const *argv[])
{
    float fahr = atof(argv[1]);

    printf("Fahrenheit = %6.2f\nCelcius = %6.2f", fahr, ftoc(fahr));
    return 0;
}
