#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10

void patternmatch(int text[], int pattern[], int n, int m, char filename[])
{
    int count = 0, i, j;
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            count++;
            if (pattern[j] != text[i + j])
                break;
        }
        if (j == m)
            break;
    }
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%d\t%d\n", n, count);
}
void main()
{
    int i, n, m = 4, text[END] = {0}, pattern[m];
    system("rm -f count_*.txt");
    srand(time(NULL));
    for (n = START; n <= END; n += INCR)
    {
        for (i = 0; i < m; i++)
            pattern[i] = 0;
        patternmatch(text, pattern, n, m, "count_best.txt");
        pattern[m - 1] = 1;
        patternmatch(text, pattern, n, m, "count_worst.txt");
        for (i = 0; i < m; i++)
            pattern[i] = rand() % 2;
        patternmatch(text, pattern, n, m, "count_average.txt");
    }
}
