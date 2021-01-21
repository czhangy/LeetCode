#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 746. Min Cost Climbing Stairs - Easy - Array/Dynamic Programming
// -------------------------------------------------------------
// On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
// Once you pay the cost, you can either climb one or two steps.
// You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
// -------------------------------------------------------------
// Solve #1 | 09/10/20 | Time: 5:57 | Avg. Runtime: 11.2ms

int minCostClimbingStairs(vector<int> &cost) { // O(N) time, O(N) space
    // Initialize
    int size = cost.size();
    vector<int> memo(size);
    // Set initial entries into DP array
    memo[0] = cost[0];
    memo[1] = cost[1];
    // Iteratively populate DP array
    for (int i = 2; i < size; i++)
        // Choose to jump from 2nd to last stair or last stair
        memo[i] = min(memo[i - 2], memo[i - 1]) + cost[i];
    // Return the minimum of the top stair or second-top stair
    return min(memo[size - 1], memo[size - 2]);
}
