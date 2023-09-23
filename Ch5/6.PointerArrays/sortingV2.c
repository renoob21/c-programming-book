#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
char linestore[MAXLINES * MAXLEN];

int readlines(char *lineptr[], char linestore[], int maxlines, int maxlen); // get str pointers, store in lineptr, return num of lines
void writelines(char * lineptr[], int nlines);
void qsorts(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, linestore, MAXLINES, MAXLEN)) >= 0) {
        qsorts(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getlines(char *line, int maxlen) {
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && c != '\n' && i < maxlen; i++)
        *(line + i) = c;
    
    *(line + i) = '\0';

    return i;
    
}

int readlines(char *lineptr[], char linestore[], int maxlines, int maxlen) {
    char line[MAXLEN];
    static int storesize = 0;
    int nlines, len;

    len = 0;
    nlines = 0;
    while ((len = getlines(line, MAXLEN)) > 0) {
        if (nlines >= MAXLINES) {
            return -1;
        } else {
            strcpy((linestore + storesize), line);
            lineptr[nlines++] = linestore + storesize;
            storesize += len;
        }
    }
    return nlines;
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

void printstr(char *s) {
    for (;*s != '\0'; s++)
        putchar(*s);
    putchar('\n');
}

void writelines(char * lineptr[], int nlines) {
    while (nlines-- > 0)
    {
        printstr(*lineptr++);
    }
    
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] =  temp;
}