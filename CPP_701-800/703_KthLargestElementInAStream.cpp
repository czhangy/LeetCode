#include "errors.h"
#include <queue>
#include <vector>

using namespace std;

// 703. Kth Largest Element in a Stream - Easy - Heap
// -------------------------------------------------------------
// Design a class to find the kth largest element in a stream.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Implement KthLargest class:
// - KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// - int add(int val) Returns the element representing the kth largest element in the stream.
// -------------------------------------------------------------
// Solve #2 | 09/11/21 | Time: 22:00 | Avg. Runtime: 68.8ms

class KthLargest {
public:
    // Constructor
    KthLargest(int k, vector<int>& nums) { // O(N log N) time, O(k) space
        // Initialize
        int i = 0, size = nums.size();
        m_k = k;
        // Push nums into priority queue
        while (m_pq.size() != k && i < nums.size()) {
            m_pq.push(nums[i]);
            i++;
        }
        // If still numbers in nums, push into heap and update
        for (; i < size; i++)
            if (nums[i] > m_pq.top()) {
                m_pq.pop();
                m_pq.push(nums[i]);
            }
    }

    int add(int val) { // O(N log N) time, O(k) space
        // If capacity k still not reached
        if (m_pq.size() < m_k)
            m_pq.push(val);
        // If new top-k number found
        else if (val > m_pq.top()) { 
            m_pq.pop();
            m_pq.push(val);
        }
        // Returns kth highest value
        return m_pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> m_pq; // Set up min heap priority queue
    int m_k; // Use to communicate k value to add() function
};