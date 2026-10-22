#include <stdio.h>

int findMax(int a[], int n)
{
    int max;

    if (n == 1)
        return a[0];

    max = findMax(a, n - 1);

    if (a[n - 1] > max)
        return a[n - 1];

    return max;
}

int countMax(int a[], int n, int max)
{
    if (n == 0)
        return 0;

    if (a[n - 1] == max)
        return 1 + countMax(a, n - 1, max);

    return countMax(a, n - 1, max);
}

int main()
{
    int a[100], n, i, max, count;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = findMax(a, n);
    count = countMax(a, n, max);

    printf("Maximum element = %d\n", max);
    printf("Occurrences = %d", count);

    return 0;
}