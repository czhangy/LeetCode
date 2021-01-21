#include "errors.h"
#include <unordered_map>
#include <vector>

using namespace std;

// 961. N Repeated Element In Size N Array - Easy - Hash Table
// -------------------------------------------------------------
// n a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
// Return the element repeated N times.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 2:15 | Avg. Runtime: 56.8ms

int repeatedNTimes(vector<int> &A) { // O(N) time, O(N) space
    // Initialize
    unordered_map<int, int> nums;
    int size = A.size();
    // Iterate through the vector
    for (int i = 0; i < size; i++)
        // Non-unique element found
        if (nums[A[i]]++)
            return A[i];
    // This value will never be returned --> a solution is guaranteed to exist
    return 1;
}
