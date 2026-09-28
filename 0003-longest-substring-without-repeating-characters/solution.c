int lengthOfLongestSubstring(char* s)
{
    int max = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        for (int j = start; j < i; j++)
        {
            if (s[j] == s[i])
            {
                start = j + 1;
                break;
            }
        }

        if (i - start + 1 > max)
            max = i - start + 1;
    }

    return max;
}