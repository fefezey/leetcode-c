char *longestPalindrome(char *s)
{
    int n = strlen(s), start = 0, max = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int l = i, r = j;

            while (l < r && s[l] == s[r])
            {
                l++;
                r--;
            }

            if (l >= r && j - i + 1 > max)
            {
                start = i;
                max = j - i + 1;
            }
        }
    }

    s[start + max] = '\0';
    return s + start;
}