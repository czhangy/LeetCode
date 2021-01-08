#include "errors.h"
#include <vector>

using namespace std;

// 62. Unique Paths - Medium - Array/Dynamic Programming
// -------------------------------------------------------------
// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?
// -------------------------------------------------------------
// Solve #1 | 01/04/21 | Time: 6:43 | Avg. Runtime: 1.6ms

int uniquePaths(int m, int n) { // O(N * M) time, O(N * M) space
    // Initialize DP vector
    vector<vector<int>> dp(m, vector<int>(n));
    // Fill columns of DP vector
    for (int i = 0; i < m; i++)
        // Fill rows of DP vector
        for (int j = 0; j < n; j++) {
            // Initialize first column --> only 1 way to go straight down
            if (!i)
                dp[i][j] = 1;
            // Initialize first row --> only 1 way to go straight right
            else if (!j)
                dp[i][j] = 1;
            // Other values are ways to get to box above + ways to get to box left
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    // Final square represents paths from start to finish
    return dp[m - 1][n - 1];
}
