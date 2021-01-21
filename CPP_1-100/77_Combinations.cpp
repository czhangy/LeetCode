#include "errors.h"
#include <vector>

using namespace std;

// 77. Combinations - Medium - Backtracking
// -------------------------------------------------------------
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// You may return the answer in any order.
// -------------------------------------------------------------
// Solve #2 | 01/20/21 | Time: 14:34 | Avg. Runtime: 6.4ms

vector<vector<int>> combine(int n, int k) { // O(MN!/M!(N - M)!) time, O(M) space
    // Initialize
    vector<vector<int>> res;
    vector<int> cur(k);
    // Build initial combination
    for (int i = 0; i < k; i++)
        cur[i] = i + 1;
    // While valid combinations exist
    while (cur[0] <= n - k + 1) {
        // Place the current combination into the result
        res.push_back(cur);
        // Move to the next combination
        cur[k - 1]++;
        // If the next combination is out of bounds
        if (cur[k - 1] > n) {
            // Initialize
            int i = k - 1;
            // Find the rightmost digit that can be incremented
            while (i && cur[i] > n - (k - i) + 1) {
                cur[i - 1]++;
                i--;
            }
            // Fill in the rest of the combination behind the incremented digit
            while (i + 1 < k) {
                cur[i + 1] = cur[i] + 1;
                i++;
            }
        }
    }
    return res;
}
