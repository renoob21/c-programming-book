#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;

    /*Comma operators used to initialize and loop the value together*/
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    

}

int main(int argc, char *argv[])
{
    char str[] = "Halo, nama saya Reno!";

    printf("Original : %s\n", str);
    reverse(str);
    printf("Reversed : %s\n", str);
    return 0;
}
