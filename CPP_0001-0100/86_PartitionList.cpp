#include "errors.h"

// 86. Partition List - Medium - Linked List/Two Pointers
// -------------------------------------------------------------
// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.
// -------------------------------------------------------------
// Solve #1 | 01/21/21 | Time: 8:59 | Avg. Runtime: 6.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x) { // O(N) time, O(1) space
    // Initiailize pointers
    ListNode *h1 = nullptr, *h2 = nullptr, *t1 = nullptr, *t2 = nullptr, *cur = head;
    // Iterate through the original linked list
    while (cur) {
        // If cureent node belongs in left sublist
        if (cur->val < x) {
            // Extend left sublist
            if (h1) {
                t1->next = cur;
                t1 = cur;
            // Catch first insertion edge case
            } else {
                h1 = cur;
                t1 = cur;
            }
        // If current node belongs in right sublist
        } else {
            // Extend right sublist
            if (h2) {
                t2->next = cur;
                t2 = cur;
            // Catch first insertion edge case
            } else {
                h2 = cur;
                t2 = cur;
            }
        }
        cur = cur->next;
    }
    // Connect sublists
    if (t1)
        t1->next = h2;
    else
        return h2;
    // Set tail
    if (t2)
        t2->next = nullptr;
    return h1;
}
