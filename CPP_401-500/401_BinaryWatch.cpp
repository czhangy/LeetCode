// 401. Binary Watch - Easy - Backtracking/Bit Manipulation
// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
// Each LED represents a zero or one, with the least significant bit on the right.
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

// Solve #2 - 8/5/20 - Time: 8:01 - Avg. Runtime: 2.4ms

vector<string> readBinaryWatch(int num) { // O(1) time, Undefined space complexity
    // Initialize
    vector<string> res;
    // Iterate through hours
    for (int i = 0; i < 12; i++) {
        // Iterate through minutes
        for (int j = 0; j < 60; j++) {
            // Possible match found
            if (numBits(i) + numBits(j) == num) {
                // Build string, initializing with hour and colon
                string time = to_string(i) + ':';
                // Handle edge case of adding 0 before single digit minute values
                if (j < 10)
                    time += '0';
                // Concatenate rest of minute value and place into result
                time += to_string(j);
                res.push_back(time);
            }
        }
    }
    return res;
}

// Helper function - counts number of 1 bits in a number
int numBits(unsigned int num) { // O(1) time, O(1) space
    // Initialize
    int count = 0;

    // Counts number of bits that are 1
    while (num) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}