#include "errors.h"
#include <queue>
#include <vector>

using namespace std;

// 1046. Last Stone Weight - Easy - Heap/Greedy
// -------------------------------------------------------------
// We have a collection of stones, each stone has a positive integer weight.
// Each turn, we choose the two heaviest stones and smash them together.
// Suppose the stones have weights x and y with x <= y.
// The result of this smash is:
// - If x == y, both stones are totally destroyed;
// - If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
// At the end, there is at most 1 stone left.
// Return the weight of this stone (or 0 if there are no stones left.)
// -------------------------------------------------------------
// Solve #1 | 01/15/21 | Time: 13:24 | Avg. Runtime: 0.8ms

int lastStoneWeight(vector<int> &stones) { // O(N log N) time, O(N) space
    // Initialize --> use heap for fast access
    priority_queue<int, vector<int>> pq;
    // Push all stones into priority queue
    for (int x : stones)
        pq.push(x);
    // Smash rocks together
    while (pq.size() >= 2) {
        // Get weights
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        // If not equal weights, push resulting stone back into heap
        if (y - x)
            pq.push(y - x);
    }
    // Return 0 if the priority queue is empty, return the only element otherwise
    return !pq.empty() ? pq.top() : 0;
}
