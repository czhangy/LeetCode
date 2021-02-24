#include <vector>

using namespace std;

// 134. Gas Station - Medium - Greedy
// -------------------------------------------------------------
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
// You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
// If there exists a solution, it is guaranteed to be unique
// -------------------------------------------------------------
// Solve #1 | 02/24/21 | Time: 36:47 | Avg. Runtime: 4ms

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) { // O(N) time, O(1) space
    // Initialize
    int size = gas.size(), cur = 0, val = INT_MAX, start = 0;
    // Iterate through the given vectors
    for (int i = 0; i < size; i++) {
        // Calculate the current gas differentia;
        cur += gas[i] - cost[i];
        // Locate the index
        if (cur < val) {
            val = cur;
            start = i + 1;
        }
    }
    // Check if completing the loop is possible
    return cur < 0 ? -1 : start % size;
}
