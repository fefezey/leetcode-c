int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **result;

    result = malloc(numRows * sizeof(int *));
    *returnColumnSizes = malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++)
    {
        int size = i + 1;

        result[i] = malloc(size * sizeof(int));
        (*returnColumnSizes)[i] = size;

        result[i][0] = 1;
        result[i][size - 1] = 1;

        for (int j = 1; j < size - 1; j++)
        {
            result[i][j] = result[i - 1][j - 1]
                         + result[i - 1][j];
        }
    }

    *returnSize = numRows;

    return result;
}