#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 944. Delete Columns To Make Sorted - Easy - Greedy
// -------------------------------------------------------------
// We are given an array A of N lowercase letter strings, all of the same length.
// Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.
// For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"], and the remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].
// (Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]]).
// Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in non-decreasing sorted order.
// Return the minimum possible value of D.length.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 2:52 | Avg. Runtime: 46.4ms

int minDeletionSize(vector<string> &A) { // O(NM) time, O(1) space
    // Initialize
    int strLen = A[0].size(), size = A.size(), num = 0;
    // Iterate through strings
    for (int i = 0; i < strLen; i++)
        // Iterate through the vector
        for (int j = 0; j + 1 < size; j++)
            // Delete column if needed
            if (A[j][i] > A[j + 1][i]) {
                num++;
                break;
            }
    return num;
}
