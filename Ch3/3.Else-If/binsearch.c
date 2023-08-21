#include <stdio.h>

int binsearch(int x, int v[], int n) {
    /*this will return the index of an array where it is found in an array
    else, it will return -1*/
    int low, high, mid;
    low = 0;
    high = n-1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid-1;
        } else if (x > v[mid])
        {
            low = mid+1;
        } else {
            return mid;
        }
        
    }

    return -1;
    
}

int main(int argc, char const *argv[])
{
    int num = 25;
    int vec[] = {1, 3, 5, 9, 15, 20, 31};

    int index = binsearch(num, vec, 7);

    if (index >= 0) {
        printf("The number %d is found on index no %d", num, index);
    } else {
        printf("The number %d is not found in the array", num);
    }

    return 0;
}
