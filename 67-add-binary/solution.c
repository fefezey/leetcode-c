#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;
    int k = 0;
    int max_len = (i > j ? i : j) + 3;
    char *result = malloc(max_len);

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';

    for (int left = 0, right = k - 1; left < right; left++, right--)
    {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }

    return result;
}