#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void getalpha(int start, int end, char s2[]) {
    int j, c;

    for (j = 0, c = start; c <= end; j++, c++) {
        s2[j] = c;
    }
}

void expand(char s1[], char s2[]) {
    int i;
    
    for (i =0; i < strlen(s1); i++) {
        if (s1[i] == '-') {
            getalpha(s1[i-1], s1[i+1], s2);
        } else
        {
            continue;
        }
        
    }
}

int main(int argc, char *argv[])
{
    char expanded[MAX_LEN];
    expand(argv[1], expanded);

    printf("%s", expanded);


    return 0;
}
