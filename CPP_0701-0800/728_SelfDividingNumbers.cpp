#include "errors.h"
#include <vector>

using namespace std;

// 728. Self Dividing Numbers - Easy - Math
// -------------------------------------------------------------
// A self-dividing number is a number that is divisible by every digit it contains.
// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
// Also, a self-dividing number is not allowed to contain the digit zero.
// Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
// -------------------------------------------------------------
// Solve #1 | 09/09/20 | Time: 4:22 | Avg. Runtime: 0ms

vector<int> selfDividingNumbers(int left, int right) { // O(N) time, O(N) space
    // Initialize
    vector<int> res;
    // Iteratively check the desired region
    for (int i = left; i <= right; i++) {
        // Get the current number to be checked
        int num = i;
        // Iteratively check each digit
        while (num) {
            // Get current digit
            int digit = num % 10;
            // Break on undividable numbers and 0s
            if (!digit || i % digit)
                break;
            num /= 10;
        }
        // If all digits were looped through, insert into answer
        if (!num)
            res.push_back(i);
    }
    return res;
}
