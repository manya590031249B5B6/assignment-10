#include <stdio.h>

int binarySearch(int a[], int low, int high, int key)
{
    int mid;

    if (low > high)
        return -1;

    mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;

    if (key < a[mid])
        return binarySearch(a, low, mid - 1, key);

    return binarySearch(a, mid + 1, high, key);
}

int main()
{
    int a[100], n, i, key, result;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    result = binarySearch(a, 0, n - 1, key);

    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);

    return 0;
}