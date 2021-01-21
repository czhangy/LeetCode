#include "errors.h"
#include <algorithm>

using namespace std;

// 868. Binary Gap - Easy - Bit Manipulation
// -------------------------------------------------------------
// Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n.
// If there are no two adjacent 1's, return 0.
// Two 1's are adjacent if there are only 0's separating them (possibly no 0's).
// The distance between two 1's is the absolute difference between their bit positions.
// For example, the two 1's in "1001" have a distance of 3.
// -------------------------------------------------------------
// Solve #1 | 09/17/20 | Time: 6:01 | Avg. Runtime: 0ms

int binaryGap(int N) { // O(N) time, O(1) space
    // Initialize
    int cont = 0, longest = 0, twoOnes = 0;
    // Get to the least significant 1
    while (!(N & 1))
        N >>= 1;
    // While there are still 1s to process
    while (N) {
        // Increase distance 
        cont++;
        // 1 found, update distances and maximums
        if (N & 1) {
            longest = max(longest, cont);
            cont = 0;
            twoOnes++;
        }
        N >>= 1;
    }
    // Check to see if adjacent 1s existed
    return twoOnes > 1 ? longest : 0;
}
