#include <stdio.h>
#define BUFSIZE 10

void strcat(char *s, char *t) {
    char *temp;
    temp = s;
    
    for (;*s;s++)
        ;
    

    if ((s-temp) < BUFSIZE)
        while ((*s++ = *t++) && (s-temp) < BUFSIZE)
            ;
}

int main()
{
    char cont[BUFSIZE];
    char str1[] = "Nama, ";
    char str2[] = "Saya ";
    char str3[] = "Reno";

    strcat(cont, str1);
    printf("Concat: %s\n", cont);
    strcat(cont, str2);
    printf("Concat: %s\n", cont);
    strcat(cont, str3);
    printf("Concat: %s\n", cont);
    return 0;
}
