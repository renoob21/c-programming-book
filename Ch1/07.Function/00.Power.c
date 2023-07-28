#include <stdio.h>
#include <stdlib.h>

float power(float m, float n) {
    float result = 1;

    if (n >= 0) {
        for (int i = 0; i < n; i++) {
            result *= m;
        }
    } else {
        for (int i = 0; i < abs(n);i++) {
            result /= m;
        }
    }


    return result;
}

void main(int argc, char *argv[2]) {
    int num, pow;
    num = atoi(argv[1]);
    pow = atoi(argv[2]);

    
    printf("%d to the power of %d equals %3.2f",num, pow, power(num, pow));
}