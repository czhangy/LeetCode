#include "errors.h"
#include <vector>

using namespace std;

// 812. Largest Triangle Area - Easy - Math
// -------------------------------------------------------------
// You have a list of points in the plane.
// Return the area of the largest triangle that can be formed by any 3 of the points.
// -------------------------------------------------------------
// Solve #2 | 09/19/20 | Time: 4:41 | Avg. Runtime: 41.6ms

double largestTriangleArea(vector<vector<int>> &points) { // O(N^3) time, O(1) space
    // Initialize
    double maxA = 0;
    // Apply canonical formula for a triangle
    for (auto &i : points)
        for (auto &j : points)
            for (auto &k : points)
                maxA = max(maxA, 0.5 * abs(i[0] * (j[1] - k[1]) + j[0] * (k[1] - i[1]) + k[0] * (i[1] - j[1])));
    return maxA;
}
