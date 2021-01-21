#include "errors.h"
#include <algorithm>
#include <vector>

using namespace std;

// 475. Heaters - Easy - Binary Search
// -------------------------------------------------------------
// Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
// Every house can be warmed, as long as the house is within the heater's warm radius range.
// Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
// Notice that all the heaters follow your radius standard, and the warm radius will the same.
// -------------------------------------------------------------
// Solve #2 | 08/05/20 | Time: 12:37 | Avg. Runtime: 188.8ms

int findRadius(vector<int> &houses, vector<int> &heaters) { // O(N log N + M log M) time, O(N) space
    // Sort vectors to allow for binary search approach
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    // Intitialize
    vector<int> radii(houses);
    int houseSize = houses.size(), heaterSize = heaters.size();
    // Fill radius information based on left -> right pass
    for (int i = 0, j = 0; i < houseSize; i++) {
        while (j < heaterSize && houses[i] > heaters[j])
            j++;
        radii[i] = j == heaterSize ? INT_MAX : heaters[j] - houses[i];
    }
    // Fill radius information based on right -> left pass
    for (int i = houseSize - 1, j = heaterSize - 1; i >= 0; i--) {
        while (j >= 0 && houses[i] < heaters[j])
            j--;
        if (j < 0)
            break;
        // Get minimum necessary radius
        radii[i] = min(radii[i], houses[i] - heaters[j]);
    }
    // Get the maximum radius out of the necessary radii
    return *max_element(radii.begin(), radii.end());
}
