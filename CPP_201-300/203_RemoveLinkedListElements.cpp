#include "errors.h"

// 203. Remove Linked List Elements - Easy - Linked List
// -------------------------------------------------------------
// Remove all elements from a linked list of integers that have value val.
// -------------------------------------------------------------
// Solve #1 | 07/10/20 | Time: 9:23 | Avg. Runtime: 35.2ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val) { // O(N) time, O(1) space
    // Initialize
    ListNode *prev = head, *cur = head;
    // Iterate through the list
    while (cur) {
        // Handle head removal edge case
        if (cur->val == val && cur == head) {
            head = head->next;
            prev = head;
            cur = head;
        // Remove node if its value matches val
        } else if (cur->val == val) {
            prev->next = cur->next;
            cur = cur->next;
        // Advance pointers
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
