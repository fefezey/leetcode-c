#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right) { 
        int width = right - left; // "widht" yazım hatası "width" olarak düzeltildi
    
        int h = (height[left] < height[right]) 
                ? height[left] 
                : height[right];
            
        int area = width * h;
        if (area > max) {
            max = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max;
}