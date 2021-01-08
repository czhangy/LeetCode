#include "errors.h"

// 61. Rotate List - Medium - Linked List/Two Pointers
// -------------------------------------------------------------
// Given the head of a linked list, rotate the list to the right by k places.
// -------------------------------------------------------------
// Solve #1 | 01/04/21 | Time: 5:28 | Avg. Runtime: 9.6ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k) { // O(N) time, O(1) space
    // Handle empty list edge case
    if (!head)
        return nullptr;
    // Initialize
    int size = 1;
    ListNode *ptr = head, *ptr2 = head;
    // Get size of list
    while (ptr->next) {
        size++;
        ptr = ptr->next;
    }
    // Reduce k based on list size
    k %= size;
    // Reset ptr
    ptr = head;
    // Position ptr2 based on k
    while (k) {
        ptr2 = ptr2->next;
        k--;
    }
    // Position ptr based on ptr2 prepositioning
    while (ptr2->next) {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    // Reroute head/tail
    ptr2->next = head;
    ptr2 = ptr->next;
    ptr->next = nullptr;
    return ptr2;
}
