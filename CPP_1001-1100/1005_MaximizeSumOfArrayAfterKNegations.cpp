#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 1005. Maximize Sum Of Array After K Negations - Easy - Greedy
// -------------------------------------------------------------
// Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.
// (We may choose the same index i multiple times.)
// Return the largest possible sum of the array after modifying it in this way.
// -------------------------------------------------------------
// Solve #1 | 12/25/20 | Time: 13:28 | Avg. Runtime: 12ms

int largestSumAfterKNegations(vector<int>& A, int K) { // O(N log N) time, O(1) space
        // Sort to get easy access to largest values
        sort(A.begin(), A.end());
        // Initialize
        int i = 0, sum = 0, size = A.size();
        // Reverse up to K negatives --> smallest values will be at start
        while (i < size && A[i] < 0 && K > 0) {
            A[i] = -A[i];
            i++;
            K--;
        }
        // Sum the values of the array
        for (int val : A)
            sum += val;
        // Sort again to adjust for negations
        sort(A.begin(), A.end());
        // Negate smallest positive value if necessary
        return K & 1 ? sum - 2 * A[0] : sum;
    }
