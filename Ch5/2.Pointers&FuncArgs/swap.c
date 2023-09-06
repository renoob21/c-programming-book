#include <stdio.h>

void swap1(int a, int b) {
    int temp = a;
    b = a;
    a = b;
}

void swap2(int *pa, int *pb) {
    int temp = *pb;
    *pb = *pa;
    *pa = temp;

}

int main()
{
    int x = 100;
    int y = 20;
    printf("x = %d\ny = %d\n\n", x, y);

    swap1(x, y);
    printf("x = %d\ny = %d\n\n", x, y);

    swap2(&x,&y);
    printf("x = %d\ny = %d\n\n", x, y);

    return 0;
}
