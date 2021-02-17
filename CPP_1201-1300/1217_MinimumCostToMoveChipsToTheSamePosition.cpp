#include "errors.h"
#include <vector>

using namespace std;

// 1217. Minimum Cost To Move Chips To The Same Position - Easy - Array/Math/Greedy
// -------------------------------------------------------------
// We have n chips, where the position of the ith chip is position[i].
// We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:
// - position[i] + 2 or position[i] - 2 with cost = 0.
// - position[i] + 1 or position[i] - 1 with cost = 1.
// Return the minimum cost needed to move all the chips to the same position.
// -------------------------------------------------------------
// Solve #1 | 02/16/21 | Time: 1:48 | Avg. Runtime: 4ms

int minCostToMoveChips(vector<int> &position) { // O(N) time, O(1) space
    // Initialize
    int odd = 0, size = position.size();
    // Handle 1-element list edge case
    if (size < 2)
        return 0;
    // Iterate through the position vector
    for (int x : position)
        // Count the number of odd positions
        if (x & 1)
            odd++;
    // Return the minimum of the number of odd positions and even positions
    return min(odd, size - odd);
}
