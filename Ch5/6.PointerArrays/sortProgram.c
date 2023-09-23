#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char * lineptr[], int nlines);

void qsorts(char *lineptr[], int left, int right);

int main()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsorts(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    
}

#define MAXLEN 1000
// int getline(char *, int);
// char *alloc(int);

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

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsorts(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    
    if (left >= right)
        return;
    
    swap(v, left, (left+right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    
    swap(v, left, last);
    qsorts(v, left, last-1);
    qsorts(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}