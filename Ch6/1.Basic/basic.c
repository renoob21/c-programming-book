#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;

};


int main(int argc, char const *argv[])
{
    struct point pt;
    struct point maxpt = {320, 200};

    struct rect screen = {{10,100}, {100,10}};

    printf("Pt1:\n\tX: %d\n\tY: %d\n", screen.pt1.x, screen.pt1.y);
    printf("Pt2:\n\tX: %d\n\tY: %d\n", screen.pt2.x, screen.pt2.y);
    return 0;
}