#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    
    bool* dp = (bool*)calloc(len + 1, sizeof(bool));
    dp[0] = true; 

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
           
            if (dp[j]) {
                int subLen = i - j; 
                
                for (int k = 0; k < wordDictSize; k++) {
                    if (strlen(wordDict[k]) == subLen && strncmp(s + j, wordDict[k], subLen) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) {
                break; 
            }
        }
    }

    bool result = dp[len];
    free(dp); 
    return result;
}