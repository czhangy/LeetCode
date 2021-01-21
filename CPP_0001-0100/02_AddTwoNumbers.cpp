#include "errors.h"

// 2. Add Two Numbers - Medium - Linked List/Math/Recursion
// -------------------------------------------------------------
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// -------------------------------------------------------------
// Solve #1 | 09/21/20 | Time: 15:25 | Avg. Runtime: 38.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { // O(N + M) time, O(1) space
    // Initialize
    int carry = 0;
    // While a pointer or carry is active
    for (ListNode *ptr1 = l1, *ptr2 = l2; carry || ptr1 || ptr2;) {
        // Common case
        if (ptr1) {
            // Get sum
            int val = ptr1->val + carry;
            val += ptr2->val;
             // Reset carry
            carry = 0;
            // Assign carry
            if (val >= 10) {
                carry = val / 10;
                val %= 10;
            }
            // Set digit
            ptr1->val = val;
            // Switch to longer list
            if (!ptr1->next && ptr2 && ptr2->next) {
                ptr1->next = ptr2->next;
                ptr2->next = nullptr;
            }
        }
        // Out of nodes, but the carry still exists
        if (ptr1 && !ptr1->next && carry) {
            // Allocate new node to hold carry
            ListNode *nextNode = new ListNode(carry);
            ptr1->next = nextNode;
            return l1;
        }
        // Advance nodes
        if (ptr1)
            ptr1 = ptr1->next;
        if (ptr2)
            ptr2 = ptr2->next;
    }
    return l1;
}
