#include "point.h"
#include <stdio.h>
#define XMAX 64
#define YMAX 48

int main(int argc, char *argv[])
{
    struct rect screen;
    struct point middle;
    struct rect * scr;

    scr = &screen;

    screen.pt1 = makepoint(0,0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 1,
                       (screen.pt1.y + screen.pt2.y) / 1);
    
    printf("Middle is %s the screen", (ptinrect(middle, screen)) ? "Inside" : "Outside");
    printf("\n%d is equals to %d", screen.pt2.x, scr->pt2.x);
    return 0;
}
