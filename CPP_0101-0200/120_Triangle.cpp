#include "errors.h"
#include <algorithm>
#include <vector>

// 120. Triangle - Medium - Array/Dynamic Programming
// -------------------------------------------------------------
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. 
// More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// -------------------------------------------------------------
// Solve #1 | 02/09/21 | Time: 16:01 | Avg. Runtime: 6.4ms

int minimumTotal(vector<vector<int>> &triangle) { // O(N^2) time, O(N^2) space
    // Initialize DP array
    int rows = triangle.size();
    vector<vector<int>> dp(rows);
    dp[0].push_back({triangle[0][0]});
    // Iterate through the rows
    for (int i = 1; i < rows; i++) {
        // Initialize current row in DP array
        dp[i] = vector<int>(i + 1);
        // Iterate through the current row
        for (int j = 0; j < i + 1; j++) {
            // Initialize
            int val = INT_MAX;
            // Account for i + 1 step
            if (j - 1 >= 0)
                val = dp[i - 1][j - 1];
            // Account for i step
            if (j < i)
                val = min(val, dp[i - 1][j]);
            // Fill DP entry with shortest path to entry i, j
            dp[i][j] = val + triangle[i][j];
        }
    }
    // Get the minimum entry in the bottom row
    return *min_element(dp[rows - 1].begin(), dp[rows - 1].end());
}
