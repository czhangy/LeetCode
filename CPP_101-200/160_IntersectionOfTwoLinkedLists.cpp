#include "errors.h"

// 160. Intersection Of Two Linked Lists - Easy - Linked List
// -------------------------------------------------------------
// Write a program to find the node at which the intersection of two singly linked lists begins.
// -------------------------------------------------------------
// Solve #2 | 07/09/20 | Time: 2:38 | Avg. Runtime: 67.2ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { // O(N) time, O(1) space
    // Initialize
    ListNode *ptrA = headA, *ptrB = headB;
    // While intersection not found
    while (ptrA != ptrB) {
        // If at end of list A, move to beginning of list B
        if (!ptrA)
            ptrA = headB;
        // Move pointer forwards
        else
            ptrA = ptrA->next;
        // If at end of list B, move to beginning of list A
        if (!ptrB)
            ptrB = headA;
        // Move pointer forwards
        else
            ptrB = ptrB->next;
    }
    return ptrA;
}
