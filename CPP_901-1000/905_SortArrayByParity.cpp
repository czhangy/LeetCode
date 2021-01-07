#include "errors.h"

// 905. Sort Array By Parity - Easy - Array
// -------------------------------------------------------------
// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
// You may return any answer array that satisfies this condition.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 11:30 | Avg. Runtime: 14.4ms

vector<int> sortArrayByParity(vector<int>& A) { // O(N) time, O(1) space
    // Initialization
    int size = A.size();
    for (int i = 0, j = 0; i < size && j < size; i++) {
        // Odd parity value found, move behind even values
        if (A[i] & 1) {
            // Have j point to the next even value, if it exists
            while (j < size && A[j] & 1) 
                j++;
            // Swap values if even value found
            if (j < size) 
                swap(A[i], A[j]);
        }
        // Make sure j always points in front of i
        if (j < i + 1)
            j = i + 1;
    }
    // Transformations done in place --> return original vector
    return A;
}