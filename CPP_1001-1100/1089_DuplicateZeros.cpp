#include "errors.h"
#include <vector>

using namespace std;

// 1089. Duplicate Zeros - Easy - Array
// -------------------------------------------------------------
// Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
// Note that elements beyond the length of the original array are not written.
// Do the above modifications to the input array in place, do not return anything from your function.
// -------------------------------------------------------------
// Solve #1 | 01/19/21 | Time: 2:56 | Avg. Runtime: 23.2ms

void duplicateZeros(vector<int> &arr) { // O(N^2) time, O(N) space
    // Initialize
    int size = arr.size();
    // Iterate through the vector
    for (int i = 0; i < size; i++)
        // Zero found
        if (!arr[i]) {
            // Insert the zero and move forwards
            arr.insert(arr.begin() + i, 0);
            i++;
        }
    // Reduce vector to original size
    while (arr.size() > size)
        arr.pop_back();
}
