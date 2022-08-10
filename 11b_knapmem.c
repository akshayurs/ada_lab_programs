#include <stdio.h>
int table[100][100];
int val[100], wt[100];
int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int i, int j)
{
    if (i < 0)
        return 0;
    if (table[i][j] != -1)
        return table[i][j];
    if (wt[i - 1] > j)
        table[i][j] = knapsack(i - 1, j);
    else
        table[i][j] = max(val[i - 1] + knapsack(i - 1, j - wt[i - 1]), knapsack(i - 1, j));
    return table[i][j];
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value and weight for %d item: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= capacity; j++)
            table[i][j] = -1;
    printf("Max value: %d\n", knapsack(n, capacity));
}
