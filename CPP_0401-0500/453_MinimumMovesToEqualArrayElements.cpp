#include "errors.h"
#include <vector>

using namespace std;

// 453. Minimum Moves To Equal Array Elements - Easy - Math
// -------------------------------------------------------------
// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
// -------------------------------------------------------------
// Solve #1 | 08/05/20 | Time: 2:00 | Avg. Runtime: 132.8ms

int minMoves(vector<int> &nums) { // O(N) time, O(1) space
    // Initialize
    int min = nums[0], size = nums.size(), moves = 0;
    // Get minimum element
    for (int i = 1; i < size; i++)
        if (nums[i] < min)
            min = nums[i];
    // Incrementing n - 1 elements by 1 is the same as subtracting 1 from 1 element
    for (int i = 0; i < size; i++)
        moves += nums[i] - min;
    return moves;
}
