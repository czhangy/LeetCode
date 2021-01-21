#include "errors.h"

// 82. Remove Duplicates From Sorted List II - Medium - Linked List
// -------------------------------------------------------------
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// Return the linked list sorted as well.
// -------------------------------------------------------------
// Solve #1 | 01/21/21 | Time: 10:27 | Avg. Runtime: 6.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) { // O(N) time, O(1) space
    // Initialize pointers
    ListNode *cur, *prev, *next;
    // Iterate through the linked list
    for (cur = head; cur; cur = next) {
        // Get next node
        next = cur->next;
        // If next node is a duplicate
        if (next && cur->val == next->val) {
            // Traverse to next non-matching node, or end of list
            while (next && cur->val == next->val)
                next = next->next;
            // Catch head node edge case
            if (cur == head)
                head = next;
            // Skip over all duplicates
            else
                prev->next = next;
        }
        // Otherwise, traverse the list normally
        else
            prev = cur;
    }
    return head;
}
