#ifndef POINT
#define POINT

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int, int);
int ptinrect(struct point, struct rect);

#endif

