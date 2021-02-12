#include "errors.h"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// 1184. Distance Between Bus Stops - Easy - Array
// -------------------------------------------------------------
// A bus has n stops numbered from 0 to n - 1 that form a circle.
// We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.
// The bus goes along both directions i.e. clockwise and counterclockwise.
// Return the shortest distance between the given start and destination stops.
// -------------------------------------------------------------
// Solve #1 | 02/11/21 | Time: 6:33 | Avg. Runtime: 3.2ms

int distanceBetweenBusStops(vector<int> &distance, int start, int destination) { // O(N) time, O(1) space
    // Initialize
    int i = start, dist = 0, size = distance.size();
    // Get total distance of a circlw
    int totDist = accumulate(distance.begin(), distance.end(), 0);
    // Get distance from start to destination clockwise
    while (i != destination) {
        dist += distance[i];
        i++;
        // Loop to start
        if (i == size)
            i = 0;
    }
    // Return minimum of clockwise and anticlockwise distance
    return min(dist, totDist - dist);
}
