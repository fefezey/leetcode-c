#include <stdio.h>
#include <stdlib.h>

// Editörün/Derleyicinin yapıyı tanıması için struct tanımı en üstte olmalı:
struct ListNode {
    int val;
    struct ListNode *next;
};

// qsort için karşılaştırma fonksiyonu
int cmp(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0) return NULL;

    int arr[10000];
    int size = 0;

    // Tüm bağlı listelerdeki elemanları diziye topluyoruz
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* cur = lists[i];
        while (cur != NULL) {
            arr[size++] = cur->val;
            cur = cur->next;
        }
    } 

    if (size == 0) return NULL;

    // Dizi elemanlarını küçükten büyüğe sıralıyoruz
    qsort(arr, size, sizeof(int), cmp);

    // Sıralı diziden yeni bağlı listeyi oluşturuyoruz
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode *tail = head;

    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return head;
}