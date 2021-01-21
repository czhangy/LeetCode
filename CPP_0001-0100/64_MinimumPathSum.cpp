#include "errors.h"
#include <vector>

using namespace std;

// 64. Minimum Path Sum - Medium - Array/Dynamic Programming
// -------------------------------------------------------------
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.
// -------------------------------------------------------------
// Solve #1 | 01/10/21 | Time: 6:30 | Avg. Runtime: 32ms

int minPathSum(vector<vector<int>> &grid) { // O(N^2) time, O(N^2) space
    // Initialize
    int m = grid.size(), n = grid[0].size();
    // Initialize DP vector
    vector<vector<int>> dp(m, vector<int>(n));
    // Initialize top-left value
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            // Skip the top-left square
            if (!i && !j)
                continue;
            // Values in the first row have only 1 path
            if (!i)
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            // Values in the first column have only 1 path
            else if (!j)
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            // Set cost of current square to minimum of vertical approach and horizontal approach
            else
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    // The last entry holds the minimum cost of reaching the bottom right square
    return dp[m - 1][n - 1];
}
