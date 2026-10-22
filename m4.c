#include <stdio.h>

void findLargest(int a[], int n, int i,
                 int *largest, int *second)
{
    if (i == n)
        return;

    if (a[i] > *largest)
    {
        *second = *largest;
        *largest = a[i];
    }
    else if (a[i] < *largest && a[i] > *second)
    {
        *second = a[i];
    }

    findLargest(a, n, i + 1, largest, second);
}

int main()
{
    int a[100], n, i;
    int largest, second;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    largest = a[0];
    second = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > largest)
            largest = a[i];
    }

    second = largest;

    for (i = 0; i < n; i++)
    {
        if (a[i] < largest)
        {
            second = a[i];
            break;
        }
    }

    if (second == largest)
    {
        printf("No second-largest distinct element");
        return 0;
    }

    findLargest(a, n, 0, &largest, &second);

    printf("Second largest element = %d", second);

    return 0;
}

