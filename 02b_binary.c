#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
int count;
int binarysearch(int arr[], int key, int low, int high)
{
    int mid = (low + high) / 2;
    count++;
    if (low > high)
        return -1;
    else if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        binarysearch(arr, key, low, mid - 1);
    else
        binarysearch(arr, key, mid + 1, high);
}

void bs(int arr[], int n, int key, char filename[])
{
    count = 0;
    FILE *fp = fopen(filename, "a");
    binarysearch(arr, key, 0, n - 1);
    fprintf(fp, "%d\t%d\n", n, count);
}

void main()
{
    int i, n;
    system("rm -f count_*.txt");
    srand(time(NULL));
    for (n = START; n <= END; n += INCR)
    {
        int arr[n];
        for (i = 0; i < n; i++)
            arr[i] = i;
        bs(arr, n, arr[(n - 1) / 2], "count_best.txt");
        bs(arr, n, 999, "count_worst.txt");
        bs(arr, n, arr[rand() % n], "count_average.txt");
    }
}
