#include <stdio.h>

int a[10][10], rows, cols;

int columnSum(int col, int row)
{
    if (row == rows)
        return 0;

    return a[row][col] + columnSum(col, row + 1);
}

int findColumn(int col, int minCol, int minSum)
{
    int sum;

    if (col == cols)
        return minCol;

    sum = columnSum(col, 0);

    if (sum < minSum)
        return findColumn(col + 1, col, sum);

    return findColumn(col + 1, minCol, minSum);
}

int main()
{
    int i, j, minCol, minSum;

    scanf("%d %d", &rows, &cols);

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    minSum = columnSum(0, 0);
    minCol = findColumn(1, 0, minSum);

    printf("Column with minimum sum = %d\n", minCol + 1);
    printf("Minimum column sum = %d", columnSum(minCol, 0));

    return 0;
}