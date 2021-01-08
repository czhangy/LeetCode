#include "errors.h"

// 83. Remove Duplicates From Sorted List - Easy - Linked List
// -------------------------------------------------------------
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.
// -------------------------------------------------------------
// Solve #1 | 06/30/20 | Time: 4:08 | Avg. Runtime: 9.6ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
    // Iterate through list
    for (ListNode *ptr = head; ptr && ptr->next;) {
        // Skip over duplicate value nodes, do not advance ptr
        if (ptr->next->val == ptr->val)
            ptr->next = ptr->next->next;
        // Advance ptr if unique value
        else
            ptr = ptr->next;
    }
    return head;
}
