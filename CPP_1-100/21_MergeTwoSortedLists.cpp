#include "errors.h"

// 21. Merge Two Sorted Lists - Easy - Linked List/Recursion
// -------------------------------------------------------------
// Merge two sorted linked lists and return it as a sorted list.
// The list should be made by splicing together the nodes of the first two lists.
// -------------------------------------------------------------
// Solve #2 | 01/16/21 | Time: 8:18 | Avg. Runtime: 6.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) { // O(N + M) time, O(1) space
    // Initialize
    ListNode *ptr1 = l1, *ptr2 = l2, *head = nullptr, *prev = nullptr;
    // Catch empty list edge cases
    if (!ptr1)
        return ptr2;
    if (!ptr2)
        return ptr1;
    // While either of the lists are unprocessed
    while (ptr1 || ptr2) {
        // Set the head if necessary
        if (!head) {
            if (ptr1->val < ptr2->val) {
                head = ptr1;
                ptr1 = ptr1->next;
            } else {
                head = ptr2;
                ptr2 = ptr2->next;
            }
            prev = head;
        // Catch 1 active list edge case
        } else if (!ptr1) {
            prev->next = ptr2;
            break;
        } else if (!ptr2) {
            prev->next = ptr1;
            break;
        // Handle comparison and merge
        } else if (ptr1->val < ptr2->val) {
            prev->next = ptr1;
            ptr1 = ptr1->next;
            prev = prev->next;
        } else {
            prev->next = ptr2;
            ptr2 = ptr2->next;
            prev = prev->next;
        }
    }
    return head;
}
