#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *ilk_dugum = head;
    struct ListNode *ikinci_dugum = head->next;

   
    ilk_dugum->next = swapPairs(ikinci_dugum->next);
    ikinci_dugum->next = ilk_dugum;

    return ikinci_dugum;
}