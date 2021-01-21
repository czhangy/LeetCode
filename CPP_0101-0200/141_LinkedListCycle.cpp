#include "errors.h"

// 141. Linked List Cycle - Easy - Linked List/Two Pointers
// -------------------------------------------------------------
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
// Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list.
// Otherwise, return false.
// -------------------------------------------------------------
// Solve #1 | 07/09/20 | Time: 5:04 | Avg. Runtime: 14.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) { // O(N) time, O(1) space
    // Initialize
    ListNode *lead = head, *follow = head;
    // Continually check
    while (true) {
        // If the end of the list has been reached
        if (!lead || !lead->next)
            return false;
        // Move lead forward fast, follow forward slow
        lead = lead->next->next;
        follow = follow->next;
        // If a cycle exists, lead will eventually wrap around and lap follow
        if (lead == follow)
            return true;
    }
}
