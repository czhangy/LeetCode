#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 976. Largest Perimeter Triangle - Easy - Math/Sort
// -------------------------------------------------------------
// Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.
// If it is impossible to form any triangle of non-zero area, return 0.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 6:49 | Avg. Runtime: 85.6ms

int largestPerimeter(vector<int> &A) { // O(N log N) time, O(1) space
    // Sort to get easy access to largest lengths
    sort(A.begin(), A.end());
    // Iterate through the vector backwards to check longest lengths first
    for (int i = A.size() - 1; i - 2 >= 0; i--) {
        // Check if lengths satisfy the triangle formula
        if ((abs(A[i] - A[i - 1]) < A[i - 2]) && (A[i - 2] < A[i] + A[i - 1]))
            return A[i] + A[i - 1] + A[i - 2];
    }
    // No valid triangle found
    return 0;
}
