#include <stdio.h>

void reverse(int a[], int start, int end)
{
    int temp;

    if (start >= end)
        return;

    temp = a[start];
    a[start] = a[end];
    a[end] = temp;

    reverse(a, start + 1, end - 1);
}

int main()
{
    int a[100], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    reverse(a, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
