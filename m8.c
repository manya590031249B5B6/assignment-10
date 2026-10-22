#include <stdio.h>

int a[10][10], b[10][10], c[10][10];
int r1, c1, r2, c2;

void multiply(int i, int j, int k)
{
    if (i == r1)
        return;

    if (j == c2)
    {
        multiply(i + 1, 0, 0);
        return;
    }

    if (k == c1)
    {
        multiply(i, j + 1, 0);
        return;
    }

    c[i][j] += a[i][k] * b[k][j];

    multiply(i, j, k + 1);
}

int main()
{
    int i, j;

    scanf("%d %d", &r1, &c1);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    scanf("%d %d", &r2, &c2);

    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    if (c1 != r2)
    {
        printf("Matrix multiplication not possible");
        return 0;
    }

    multiply(0, 0, 0);

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d ", c[i][j]);

        printf("\n");
    }

    return 0;
}