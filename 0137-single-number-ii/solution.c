#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < 32; i++) {
        int sum = 0;

        for (int j = 0; j < numsSize; j++) {
            if ((nums[j] >> i) & 1) { // i. bit 1 mi?
                sum++;
            }
        } 
        
        // Eğer 1'lerin sayısı 3'ün katı değilse, aradığımız sayının i. biti 1'dir.
        if (sum % 3 != 0) {
            result |= (1U << i);
        }
    } 

    return result;
}