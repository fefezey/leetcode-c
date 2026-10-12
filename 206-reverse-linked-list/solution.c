
#include <stdio.h>
#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;

    while (current != NULL)
    {
        struct ListNode *next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main(void)
{
    struct ListNode third = {3, NULL};
    struct ListNode second = {2, &third};
    struct ListNode first = {1, &second};

    struct ListNode *result = reverseList(&first);

    while (result != NULL)
    {
        printf("%d", result->val);

        if (result->next != NULL)
            printf(" -> ");

        result = result->next;
    }

    printf("\n");
    return 0;
}
