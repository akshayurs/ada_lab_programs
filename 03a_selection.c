#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
void selectionsort(int arr[], int n, char filename[])
{
    int count = 0;
    int i, j, min_pos, temp;
    for (i = 0; i < n; i++)
    {
        min_pos = i;
        for (j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[min_pos])
                min_pos = j;
        }
        temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;
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
            arr[i] = rand() % n;
        selectionsort(arr, n, "count_average.txt");
    }
}
