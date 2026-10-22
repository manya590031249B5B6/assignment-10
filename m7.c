#include <stdio.h>

int checkSymmetric(int a[10][10], int n, int i, int j)
{
    if (i == n)
        return 1;

    if (j == n)
        return checkSymmetric(a, n, i + 1, 0);

    if (a[i][j] != a[j][i])
        return 0;

    return checkSymmetric(a, n, i, j + 1);
}

int main()
{
    int a[10][10], n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if (checkSymmetric(a, n, 0, 0))
        printf("Matrix is symmetric");
    else
        printf("Matrix is not symmetric");

    return 0;
}