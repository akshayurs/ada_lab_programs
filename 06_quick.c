#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
int count;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r)
{
    int p = arr[l];
    int i = l;
    int j = (r + 1);
    do
    {
        do
        {
            count++;
            i++;
        } while (arr[i] < p);
        do
        {
            count++;
            j--;
        } while (arr[j] > p);
        swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[i], &arr[j]);
    swap(&arr[l], &arr[j]);
    return j;
}
void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int s = partition(arr, l, r);
        quicksort(arr, l, s - 1);
        quicksort(arr, s + 1, r);
    }
}
void bestswap(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        bestswap(arr, l, mid - 1);
        bestswap(arr, mid + 1, r);
        swap(&arr[l], &arr[mid]);
    }
}
void sort(int arr[], int n, char filename[])
{
    count = 0;
    quicksort(arr, 0, n - 1);
    FILE *fp = fopen(filename, "a");
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
        sort(arr, n, "count_worst.txt");
        bestswap(arr, 0, n - 1);
        sort(arr, n, "count_best.txt");
        for (i = 0; i < n; i++)
            arr[i] = rand() % n;
        sort(arr, n, "count_average.txt");
    }
}
