#include <stdio.h>
#include <stdlib.h>

float ctof(float celc) {
    float fahr = (celc * 9 / 5) + 32;
    return fahr;
}

int main(int argc, char const *argv[1])
{
    float celc = atof(argv[1]);

    printf("Celcius = %3.2f\nFahreheit = %3.2f", celc, ctof(celc));
    return 0;
}
