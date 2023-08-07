#include <stdio.h>

void printbits(int num) {
    for (int i = 0; i < 8; i++) {
        int bit = num & (1 << (7 - i));
        if (bit) {
            printf("1");
        } else {
            printf("0");
        }
    }
}