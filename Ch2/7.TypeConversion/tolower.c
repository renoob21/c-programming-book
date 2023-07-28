#include <stdio.h>

const char* lower(char s[]) {
    char low[100];
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            low[i] = s[i] - 'A' + 'a';
            ++i;
        } else {
            low[i] = s[i];
            ++i;
        }
    }

    ++i;
    low[i] = '\0';

    return low;
}

int main(int argc, char const *argv[])
{
    printf("Before : %s\nAfter : %s", "HalLo", lower("HalLo"));
    return 0;
}
