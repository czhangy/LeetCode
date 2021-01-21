#include "errors.h"

// 24. Swap Nodes In Pairs - Medium - Linked List
// -------------------------------------------------------------
// Given a linked list, swap every two adjacent nodes and return its head.
// -------------------------------------------------------------
// Solve #1 | 09/27/20 | Time: 12:05 | Avg. Runtime: 2.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head) { // O(N) time, O(1) space
    // Catch nullptr and size-1 edge cases
    if (!head || !head->next)
        return head;
    // Move through list
    for (ListNode *ptr1 = head, *ptr2 = head->next, *old = nullptr; ptr1 && ptr2;) {
        // Swap head when necessary
        if (ptr1 == head)
            head = ptr2;
        // Skip node of ptr2
        ptr1->next = ptr2->next;
        // Place ptr2 node in front of ptr1 node
        ptr2->next = ptr1;
        // Check if past swap occurred
        if (old)
            // Reassign to correct path
            old->next = ptr2;
        // Advance pointers
        old = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr1 ? ptr1->next : ptr2;
    }
    return head;
}
