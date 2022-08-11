#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10

void linearsearch(int arr[], int n, int key, char filename[])
{
    int count = 0, i;
    for (i = 0; i < n; i++)
    {
        count++;
        if (arr[i] == key)
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

        linearsearch(arr, n, arr[0], "count_best.txt");
        linearsearch(arr, n, arr[n - 1], "count_worst.txt");
        linearsearch(arr, n, arr[rand() % n], "count_average.txt");
    }
}
