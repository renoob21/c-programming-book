#include <stdio.h>
#define BUFF 10

int htoi(char s[]) {
    int n = 0;

    if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
        for (int i = 2; i <= BUFF + 1 && s[i] != '\0'; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                n = 16 * n + (s[i] - '0');
            } else if (s[i] >= 'A' && s[i] <= 'F')
            {
                n = 16 * n + (s[i] - 'A' + 10);
            } else if (s[i] >= 'a' && s[i] <= 'f')
            {
                n = 16 * n + (s[i] - 'a' + 10);
            } else {
                break;
            }
        }
        return n;
    } else {
        printf("Please use hexadecimal format!");
    }
    
}

int main(int argc, char * argv[])
{
    
    int num = htoi(argv[1]);

    printf("Hex: %s\nInt: %d", argv[1], num);
    return 0;
}