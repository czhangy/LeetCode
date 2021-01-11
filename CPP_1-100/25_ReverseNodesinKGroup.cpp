#include "errors.h"

// 25. Reverse Nodes in K Group - Hard - Linked List
// -------------------------------------------------------------
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes itself may be changed.
// -------------------------------------------------------------
// Solve #2 | 01/10/21 | Time: 21:56 | Avg. Runtime: 29.6ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Reverses a given list from head to tail
ListNode *reverseList(ListNode *head, ListNode *tail) { // O(N) time, O(1) space
    // Initialize
    ListNode *prev = nullptr, *cur = head, *next, *res = tail->next;
    // Reverse contents
    while (prev != tail) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    // Return the next node to be processed
    return res;
}

ListNode *reverseKGroup(ListNode *head, int k) { // O(N) time, O(1) space
    // Initialize
    ListNode *cur = head, *tail = head, *prev;
    head = nullptr;
    // While segments still need to be processed
    while (tail) {
        // Position tail at end of current segment
        for (int i = 0; i < k - 1 && tail; i++, tail = tail->next) {}
        // Catch remainder
        if (!tail)
            break;
        // Reverse segment and link to next segment
        cur->next = reverseList(cur, tail);
        // Set new head if needed
        if (!head)
            head = tail;
        // Otherwise, re-establish link from previous segment
        else
            prev->next = tail;
        // Move to next segment
        prev = cur;
        cur = cur->next;
        tail = cur;
    }
    return head;
}
