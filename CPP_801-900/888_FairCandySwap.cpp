#include "errors.h"
#include <unordered_set>
#include <vector>

using namespace std;

// 888. Fair Candy Swap - Easy - Array
// -------------------------------------------------------------
// Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.
// Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.
// (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
// Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.
// If there are multiple answers, you may return any one of them.
// It is guaranteed an answer exists.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 12:55 | Avg. Runtime: 192ms

vector<int> fairCandySwap(vector<int> &A, vector<int> &B) { // O(N + M) time, O(M) space
    // Initialize
    int aSum = 0, bSum = 0;
    unordered_set bSet(B.begin(), B.end());
    // Get sums of vectors
    for (int num : A)
        aSum += num;
    for (int num : B)
        bSum += num;
    // Get the distance from the average
    int dist = abs(((aSum + bSum) >> 1) - aSum);
    // Iterate through A
    for (int num : A) {
        // If B has more, search for pairing with larger B with required distance
        if (bSum > aSum && bSet.count(num + dist))
            return {num, num + dist};
        // If A has more, search for pairing with smaller B with required distance
        if (aSum > bSum && bSet.count(num - dist)) 
            return {num, num - dist};
    }
    // Return statement never executes, an answer is guaranteed
    return {};
}
