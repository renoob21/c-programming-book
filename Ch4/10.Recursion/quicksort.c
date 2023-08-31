#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);

int main()
{
    int n, i;
    int arr[] = {5 , 25, 7, 78, 50, 31};
    n = 6;
    qsort(arr, 0, 5);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

void qsort(int v[], int left, int right) {
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);

    last = left;
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, left+1, right);
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] =  temp;
}