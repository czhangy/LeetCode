#include "errors.h"
#include <unordered_map>
#include <vector>

using namespace std;

// 1128. Number Of Equivalent Domino Pairs - Easy - Array
// -------------------------------------------------------------
// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.
// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
// -------------------------------------------------------------
// Solve #1 | 01/23/21 | Time: 22:01 | Avg. Runtime: 40.8ms

int numEquivDominoPairs(vector<vector<int>> &dominoes) { // O(N) time, O(N) space
    // Initialize
    unordered_map<int, int> m;
    int pairs = 0;
    // Iterate through the dominoes
    for (auto &domino : dominoes)
        // Map the dominoes as a unique value and increment the number of pairs based on that unique value
        pairs += m[max(domino[0], domino[1]) * 10 + min(domino[0], domino[1])]++;
    return pairs;
}
