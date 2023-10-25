#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tail(char *str, int num) {
    int len = strlen(str) -1;
    
    if (num > len)
        printf("String must be at least %d Characters\n", num);
    else
        printf("%s", str + len - num);
}

int main(int argc, char *argv[])
{
    char buffer[1000];
    char *line = buffer;
    size_t maxlen = 1000;
    int n = 10, c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0])
        {
            switch (c) {
                case 'n':
                    if (argc > 1) {
                    n = atoi(*++argv);
                    argc--;
                    } else {
                        printf("Option -n requires an argument");
                        return 1;
                    }
                    break;
                default:
                    break;
            }
        }
        
    }

    while (getline(&line, &maxlen, stdin) > 0)
    {
        tail(line, n);
    }
    
    return 0;
}
