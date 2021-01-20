#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 1051. Height Checker - Easy - Array
// -------------------------------------------------------------
// Students are asked to stand in non-decreasing order of heights for an annual photo.
// Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.
// Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students remain on their seats.
// -------------------------------------------------------------
// Solve #1 | 01/18/21 | Time: 8:34 | Avg. Runtime: 1.6ms

int heightChecker(vector<int> &heights) { // O(N log N) time, O(N) space
    // Initialize
    vector<int> temp(heights);
    int count = 0, size = heights.size();
    // Get correct ordering
    sort(temp.begin(), temp.end());
    // Iterate through the vectors
    for (int i = 0; i < size; i++)
        // Count the number of differences between the unsorted and sorted vector
        count += heights[i] == temp[i] ? 0 : 1;
    return count;
}
