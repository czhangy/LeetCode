#include <vector>

using namespace std;

// 1266. Minimum Time Visiting All Points - Easy - Array/Geometry
// -------------------------------------------------------------
// On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi].
// Return the minimum time in seconds to visit all the points in the order given by points.
// You can move according to these rules:
// In 1 second, you can either:
// - move vertically by one unit,
// - move horizontally by one unit, or
// - move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
// You have to visit the points in the same order as they appear in the array.
// You are allowed to pass through points that appear later in the order, but these do not count as visits.
// -------------------------------------------------------------
// Solve #1 | 02/22/21 | Time: 7:04 | Avg. Runtime: 10.4ms

int minTimeToVisitAllPoints(vector<vector<int> > &points) { // O(N) time, O(1) space
    // Initialize
    int time = 0, size = points.size();
    // Iterate through the points
    for (int i = 0; i + 1 < size; i++) {
        // Calculate dx and dy
        int dx = abs(points[i + 1][0] - points[i][0]);
        int dy = abs(points[i + 1][1] - points[i][1]);
        // Account for optimal diagonal movement + residual movement
        time += min(dx, dy) + abs(dx - dy);
    }
    return time;
}
