#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *add_two_numbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *res = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *pos = res;
    int current = 0;
    int carry = 0;
    res->val = -1;
    res->next = NULL;

    while (l1 != NULL || l2 != NULL) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        current = (x + y + carry) % 10;
        carry = (x + y + carry) / 10;
        pos->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->val = current; 
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }
    if (carry) {
        pos->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pos = pos->next;
        pos->val = 1;
        pos->next = NULL;
    } else {
        pos->next = NULL;
    }
    return res->next;
}

void main()
{
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* p = l1;
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    int nums1[3] = {1, 9, 9};
    int nums2 = 9;
    int i = 0;
    while (i < 3) {
        p->val = nums1[i];
        if (i <= 1) {
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p=p->next;
        } else {
            p->next = NULL;
        }
        i++;
    }
    l2->val = nums2;
    l2->next = NULL;
    struct ListNode* res = add_two_numbers(l1, l2);
    while (res != NULL) {
        printf("%d\n", res->val);
        res = res->next;
    }
    getchar();
}