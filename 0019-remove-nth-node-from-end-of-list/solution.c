#include <stdio.h>
#include <stdlib.h>

// VS Code / Derleyicinin yapıyı tanıması için struct tanımı aktif olmalı:
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // Fast pointer'ı n adım öne taşıyoruz
    for (int i = 0; i < n; i++) {
        if (fast->next == NULL) {
            return head; // Güvenlik kontrolü: n listenin uzunluğundan büyükse
        }
        fast = fast->next;
    } 

    // Fast sona ulaşana kadar ikisini de ilerletiyoruz
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Hedef düğümü listeden çıkarıp belleği serbest bırakıyoruz
    struct ListNode *toDelete = slow->next;
    if (toDelete != NULL) {
        slow->next = toDelete->next;
        free(toDelete); // Bellek sızıntısını (Memory Leak) önler
    }

    return dummy.next;
}