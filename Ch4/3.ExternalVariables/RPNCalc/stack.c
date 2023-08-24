#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /*max depth of the stack*/

int sp = 0; /*next free stack position*/
double val[MAXVAL]; /*the stack*/

/*push : push the value f to the stack*/ 
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, can't push %g\n", f);
    
}

/*pop : remove the last value of the stack and return it*/
double pop(void) {
    if (sp > 0) 
        return val[--sp];
    else
        printf("error: stack empty\n");
    return 0.0;
}