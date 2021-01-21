#include "errors.h"
#include <vector>

using namespace std;

// 1103. Distribute Candies To People - Easy - Math
// -------------------------------------------------------------
// We distribute some number of candies, to a row of n = num_people people in the following way:
// We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.
// Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.
// This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.
// The last person will receive all of our remaining candies (not necessarily one more than the previous gift).
// Return an array (of length num_people and sum candies) that represents the final distribution of candies.
// -------------------------------------------------------------
// Solve #1 | 01/20/21 | Time: 22:03 | Avg. Runtime: 0ms

vector<int> distributeCandies(int candies, int num_people) { // O(N) time, O(M) space
    // Intialize
    vector<int> res(num_people, 0);
    // Populate array
    for (int i = 0, val = 1; candies; i++, val++) {
        // Handle looping around
        if (i == num_people)
            i = 0;
        // Common case, give next number of candies
        if (val <= candies) {
            res[i] += val;
            candies -= val;
        }
        // Handle remaining candies edge case
        else {
            res[i] += candies;
            break;
        }
    }
    return res;
}
