#include <stdio.h>
#include <stdlib.h>
#define BUFF 10

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap/=2) {
        for (i = gap; i < n; i++) {
            for (j = i-gap;j>=0 && v[j] > v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int vector[BUFF], i;
    for (i = 0; i < BUFF; i++) {
        vector[i] = atoi(argv[i+1]);
    }

    printf("Original: ");
    for (i = 0; i < BUFF; i++) {
        printf("%d ", vector[i]);
    }

    shellsort(vector, BUFF);

    printf("\nSorted  : ");
    for (i = 0; i < BUFF; i++) {
        printf("%d ", vector[i]);
    }
    return 0;
}
