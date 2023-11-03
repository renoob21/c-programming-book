#include <stdio.h>
#include "point.h"


struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}