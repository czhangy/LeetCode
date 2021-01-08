#include "errors.h"
#include <vector>

using namespace std;

// 63. Unique Paths II - Medium - Array/Dynamic Programming
// -------------------------------------------------------------
// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// Now consider if some obstacles are added to the grids.
// How many unique paths would there be?
// An obstacle and space is marked as 1 and 0 respectively in the grid.
// -------------------------------------------------------------
// Solve #1 | 01/05/21 | Time: 10:11 | Avg. Runtime: 3.2ms

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) { // O(N * M) time, O(N * M) space
    // Initialize
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    // Initialize DP array
    vector<vector<int>> dp(m, vector<int>(n));
    // Fill columns
    for (int i = 0; i < m; i++) {
        // Fill rows
        for (int j = 0; j < n; j++) {
            // 0 ways to get to a square blocked by an obstacle
            if (obstacleGrid[i][j])
                dp[i][j] = 0;
            // Set start --> assume start never has an obstacle
            else if (!i && !j)
                dp[i][j] = 1;
            // Set DP entry, account for possibility of first row/column
            else
                dp[i][j] = (i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0);
        }
    }
    // Last entry represents paths from start to finish
    return dp[m - 1][n - 1];
}
