#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
int count;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        count++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
    {
        count++;
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        count++;
        arr[k++] = R[j++];
    }
}
void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void main()
{
    int i, n;
    system("rm -f count_*.txt");
    FILE *fp = fopen("count_average.txt", "a");
    srand(time(NULL));
    for (n = START; n <= END; n += INCR)
    {
        int arr[n];
        for (i = 0; i < n; i++)
            arr[i] = rand() % 5;
        mergesort(arr, 0, n - 1);
        fprintf(fp, "%d\t%d\n", n, count);
    }
}
