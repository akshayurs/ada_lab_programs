#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
void bubblesort(int arr[], int n, char filename[])
{
    int count = 0;
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 1;
        for (j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag)
            break;
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
        bubblesort(arr, n, "count_best.txt");
        for (i = 0; i < n; i++)
            arr[i] = n - i;
        bubblesort(arr, n, "count_worst.txt");
        for (i = 0; i < n; i++)
            arr[i] = rand() % 5;
        bubblesort(arr, n, "count_average.txt");
    }
}
