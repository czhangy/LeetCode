#include "errors.h"
#include <vector>

using namespace std;

// 443. String Compression - Medium - String
// -------------------------------------------------------------
// Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// - If the group's length is 1, append the character to s.
// - Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead be stored in the input character array chars.
// Note that group lengths that are 10 or longer will be split into multiple characters in chars.
// After you are done modifying the input array, return the new length of the array.
// -------------------------------------------------------------
// Solve #1 | 07/30/20 | Time: 17:39 | Avg. Runtime: 11.2ms

int compress(vector<char> &chars) { // O(N) time, O(1) space
    // Iterate through the vector
    for (int i = 0; i < chars.size(); i++) {
        // Initialize
        int j = i, count = 0, size = chars.size();
        // Get duplicate chars
        while (j < size && chars[j] == chars[i]) {
            count++;
            j++;
        }
        // Move to the next iteration if no compression occurs
        if (count == 1)
            continue;
        // Remove the consecutive characters
        chars.erase(chars.begin() + i + 1, chars.begin() + j);
        int temp = i;
        // Insert the number of consecutive characters
        while (count) {
            char insert = '0' + count % 10;
            chars.insert(chars.begin() + temp + 1, insert);
            count /= 10;
            i++;
        }
    }
    return chars.size();
}
