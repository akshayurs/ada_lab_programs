#include <stdio.h>
void main()
{
    int i, min, m, n, count = 0;
    printf("Enter m and n : ");
    scanf("%d%d", &m, &n);
    min = m < n ? m : n;
    for (i = min; i > 1; i--)
    {
        count++;
        if (m % i == 0 && n % i == 0)
            break;
    }
    printf("GCD : %d\n", i);
    printf("count : %d\n", count);
}
