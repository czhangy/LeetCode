#include "errors.h"
#include <queue>
#include <vector>

using namespace std;

// 23. Merge K Sorted Lists - Hard - Linked List/Divide and Conquer/Heap
// -------------------------------------------------------------
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.
// -------------------------------------------------------------
// Solve #2 | 01/05/21 | Time: 17:08 | Avg. Runtime: 38.4ms

// Given ListNode definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Create custom priority queue comparison to sort ListNode*s in increasing order of val
struct Comp {
    bool operator()(ListNode *l1, ListNode *l2) {
        return l1->val > l2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) { // O(N) time, O(M) space --> M is lists.size()
    // Initialize
    priority_queue<ListNode *, vector<ListNode *>, Comp> pq;
    int size = lists.size();
    // Push list heads into priority queue if they're valid
    for (int i = 0; i < size; i++)
        if (lists[i])
            pq.push(lists[i]);
    // Catch nullptr edge cases
    if (pq.empty())
        return nullptr;
    // Handle first node --> assign head
    ListNode *prev = nullptr, *cur = pq.top(), *head = cur;
    if (cur->next)
        pq.push(cur->next);
    pq.pop();
    // While there are nodes that still need to be processed
    while (!pq.empty()) {
        prev = cur;
        // Get next node off heap
        cur = pq.top(); 
        // Remove node from heap
        pq.pop();
        // Get next node added to heap
        if (cur->next) 
            pq.push(cur->next);
        // Establish new link
        prev->next = cur;
    }
    return head;
}
