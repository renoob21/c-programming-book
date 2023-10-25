#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char * lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void reverse(char *s[], int len);

void qsorts(void *lineptr[], int left, int right, int (*comp)(void *, void*));
int numcmp(const char *, const char *);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0, rev = 0, c;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch (c) {
                case 'n':
                    numeric =1;
                    break;
                case 'r':
                    rev = 1;
                    break;
                default:
                    printf("Unknown option: %c", c);
                    argc = -1;
                    break;
            }
        }
        
    }
    

    // if (argc > 1 && strcmp(argv[1], "-n") == 0)
    //     numeric = 1;
    if (argc != 0) {
        printf("Usage: Sort -n -r");
        return 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsorts((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        if (rev)
            reverse(lineptr, nlines);
        printf("\nSorted (%s):\n", (rev ? "dsc" : "asc"));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }

    return 0;
}

void qsorts(void *v[], int left, int right, int (*comp)(void *, void*)) {
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        return;
    swap(v, left, (left+right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i],v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsorts(v, left, last-1,comp);
    qsorts(v, last+1, right, comp);
}

#include <stdlib.h>

int numcmp(const char *s1, const char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i =0; i<nlines; i++)
        printf("%s\n", lineptr[i]);
}

#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    char *l = line;
    size_t maxlen = 1000;

    nlines = 0;
    while ((len = getline(&l, &maxlen, stdin)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void reverse(char *s[], int len) {
    int i, j;
    char *str;
    
    for (i = 0, j =len-1; i < j; i++, j--) {
        str = s[i];
        s[i] = s[j];
        s[j] = str; 
    }
}