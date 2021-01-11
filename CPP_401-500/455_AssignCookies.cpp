#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 455. Assign Cookies - Easy - Greedy
// -------------------------------------------------------------
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j].
// If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
// Your goal is to maximize the number of your content children and output the maximum number.
// -------------------------------------------------------------
// Solve #1 | 07/31/20 | Time: 3:44 | Avg. Runtime: 101.6ms

int findContentChildren(vector<int> &g, vector<int> &s) { // O(N log N + M log M) time, O(1) space
    // Sort to allow for greedy approach
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    // Initialize
    int i = 0, j = 0, gSize = g.size(), sSize = s.size();
    // Iterate through the arrays
    while (i < gSize && j < sSize) {
        // If next easiest to satisfy child can be satisfied by current cookie, do so
        if (g[i] <= s[j])
            i++;
        j++;
    }
    // Return number of children satisfied
    return i;
}
