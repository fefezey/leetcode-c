char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)return "";

    char *first =strs[0];
    int len =strlen(first);

    for (int i = 0; i< len; i++){
        char current = first[i];
        for (int j=1; j<strsSize;j++){
            if (strs[j][i]== '\0' || strs[j][i] != current){

                char *result = malloc(i+1);
                strncpy(result,first,i);
                result[i] = '\0';
                return result;
            }
        }
    }
    char *result=malloc(len + 1);
    strcpy(result,first);
    return result;  
}