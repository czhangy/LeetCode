#include <vector>

using namespace std;

// 119. Pascals Triangle II - Easy - Array
// -------------------------------------------------------------
// Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
// -------------------------------------------------------------
// Solve #2 | 02/17/21 | Time: 3:54 | Avg. Runtime: 0ms

vector<int> getRow(int rowIndex) { // O(N^2) time, O(N) space
    // Initialize
    vector<int> res(rowIndex + 1, 0);
    res[0] = 1;
    // Iterate through rows of Pascal's Triangle
    for (int i = 1; i < rowIndex + 1; i++)
        // Update the row by iterating backwards
        for (int j = i; j >= 1; j--)
            res[j] += res[j - 1];
    return res;
}
