#include <stdio.h>
#include <stdbool.h>

void siralaVeYazdir() {
    int dizi[] = {8, 3, 1, 7, 4, 2, 6, 5};
    int n = sizeof(dizi) / sizeof(dizi[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dizi[i] > dizi[j]) {
                int temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }

    printf("Sıralı dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}