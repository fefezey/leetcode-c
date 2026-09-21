#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int a = 0;
        int b = 0;

        if (l1 != NULL)
        {
            a = l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            b = l2->val;
            l2 = l2->next;
        }

        int sum = a + b + carry;
        carry = sum / 10;

        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));

        node->val = sum % 10;
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    if (carry != 0)
    {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));

        node->val = carry;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return head;
}