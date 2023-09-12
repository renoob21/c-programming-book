#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /*Storage for alloc*/
static char *allocp = allocbuf; /*pointer to next free position*/

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}