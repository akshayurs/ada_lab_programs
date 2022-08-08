#include <stdio.h>
void main()
{
    int m, n, count = 0, rem;
    printf("Enter m and n : ");
    scanf("%d%d", &m, &n);
    while (n != 0)
    {
        rem = m % n;
        m = n;
        n = rem;
        count++;
    }
    printf("GCD : %d\n", m);
    printf("count : %d\n", count);
}
