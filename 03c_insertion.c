#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
void insertionsort(int arr[], int n, char filename[])
{
    int count = 0;
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            count++;
            if (arr[j] < k)
                break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = k;
    }
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
        insertionsort(arr, n, "count_best.txt");
        for (i = 0; i < n; i++)
            arr[i] = n - i;
        insertionsort(arr, n, "count_worst.txt");
        for (i = 0; i < n; i++)
            arr[i] = rand() % 5;
        insertionsort(arr, n, "count_average.txt");
    }
}
