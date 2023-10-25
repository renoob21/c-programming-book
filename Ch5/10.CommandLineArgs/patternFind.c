#include <stdio.h>
#include<string.h>


int main(int argc, char *argv[])
{
    size_t MAXLINE = 1000;
    char buffer[1000];
    char *line = buffer;
    int found = 0;
    long lineno = 0;

    int c, except = 0, number = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'n':
                number =1;
                break;
            case 'x':
                except =1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }

    if (argc != 1)
        printf("Usage: Find -x -n Pattern\n");
    else
        while (getline(&line, &MAXLINE, stdin) > 0)
        {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
        
    return found;
}
