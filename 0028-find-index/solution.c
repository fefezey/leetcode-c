int strStr(char* haystack, char* needle) {
    int i;
    int j;

    i = 0;

    if (needle[0] == '\0')
        return (0);

    while (haystack[i])
    {
        j= 0;

    while (haystack[i+j] == needle[j] && needle[j] != '\0')
    {
        j++;
    }
    if (needle[j] == '\0')
        return (i);

        i++;
    }
    return (-1);
}