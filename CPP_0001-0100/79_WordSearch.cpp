#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 79. Word Search - Medium - Array/Backtracking
// -------------------------------------------------------------
// Given an m x n board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.
// -------------------------------------------------------------
// Solve #2 | 02/13/21 | Time: 45:46 | Avg. Runtime: 23.2ms

// Recursive helper function to perform depth-first search
bool dfs(vector<vector<char>> &board, string &word, int ind, int i, int j, int &m, int &n) {
    // Check if out of bounds or character mismatch
    if (i < 0 || j < 0 || i == m || j == n || board[i][j] != word[ind])
        return false;
    // Final character found --> word found
    if (ind == word.size() - 1)
        return true;
    // Mark current space as discovered
    board[i][j] = '*';
    // Check up, down, left, and right
    bool wordFound = dfs(board, word, ind + 1, i - 1, j, m, n) ||
                     dfs(board, word, ind + 1, i + 1, j, m, n) ||
                     dfs(board, word, ind + 1, i, j + 1, m, n) ||
                     dfs(board, word, ind + 1, i, j - 1, m, n);
    // Backtrack
    board[i][j] = word[ind];
    return wordFound;
}

bool exist(vector<vector<char>> &board, string word) { // O(NM) time, O(M) space
    // Initialize
    int m = board.size(), n = board[0].size();
    // Iterate through board
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            // Matching starting character found, begin recursion
            if (board[i][j] == word[0] && dfs(board, word, 0, i, j, m, n))
                return true;
    return false;
}
