#include "errors.h"

// 19. Remove Nth Node From End Of List - Medium - Linked List/Two Pointers
// -------------------------------------------------------------
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// -------------------------------------------------------------
// Solve #1 | 09/26/20 | Time: 9:41 | Avg. Runtime: 5.6ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) { // O(N) time, O(1) space
    // Initialize
    ListNode *ptr1 = head, *ptr2 = head;
    // Space out pointers by n nodes
    for (int i = 0; i < n; i++)
        ptr2 = ptr2->next;
    // Edge case, n is the size of the list --> cut off head
    if (!ptr2) 
        return head->next;
    // Position ptr1 n from the end of the list using pre-positioning of ptr2
    while (ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // Perform node deletion, freeing memory
    ListNode *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;
    return head;
}