#include "errors.h"
#include <vector>

using namespace std;

// 905. Sort Array By Parity - Easy - Array
// -------------------------------------------------------------
// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
// You may return any answer array that satisfies this condition.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 11:30 | Avg. Runtime: 14.4ms

vector<int> sortArrayByParity(vector<int> &A) { // O(N) time, O(1) space
    // Initialize
    int size = A.size();
    // Iterate through the vector
    for (int i = 0, j = 0; i < size && j < size; i++) {
        // Odd parity found
        if (A[i] & 1) { 
            // Move j to the next even value
            while (j < size && A[j] & 1)
                j++;
            // Swap values when even value found
            if (j < size)
                swap(A[i], A[j]);
        }
         // Point j in front of i if it isn't already
        if (j < i + 1)
            j = i + 1;
    }
    return A;
}
