#include "errors.h"
#include <vector>

using namespace std;

// 1037. Valid Boomerang - Easy - Math
// -------------------------------------------------------------
// A boomerang is a set of 3 points that are all distinct and not in a straight line.
// Given a list of three points in the plane, return whether these points are a boomerang.
// -------------------------------------------------------------
// Solve #1 | 01/10/21 | Time: 11:34 | Avg. Runtime: 4.8ms

bool isBoomerang(vector<vector<int>> &points) { // O(1) time, O(1) space
    // Catch division by 0 and duplicate point edge cases
    if (points[1][0] == points[0][0])
        return points[2][0] != points[1][0] && points[1][1] != points[0][1];
    // Calculate the slope and y-intercept between the first 2 points
    double m = (points[1][1] - points[0][1]) / static_cast<double>(points[1][0] - points[0][0]);
    double b = points[0][1] - m * points[0][0];
    // Return whether 3rd point doesn't fall on the previously calculated line
    return points[2][1] != m * points[2][0] + b;
}
