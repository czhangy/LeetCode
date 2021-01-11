#include "errors.h"
#include <string>

using namespace std;

// 258. Add Digits - Easy - Math
// -------------------------------------------------------------
// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
// -------------------------------------------------------------
// Solve #1 | 07/16/20 | Time: 3:35 | Avg. Runtime: 3.2ms

int addDigits(int num) { // Undefined time complexity, Undefined space complexity
    // Initialize
    string str = to_string(num);
    // Base case
    if (str.size() == 1)
        return num;
    else {
        int sum = 0;
        // Sum up digits
        for (int i = 0; i < str.size(); i++)
            sum += str[i] - '0';
        // Recursively call this function with the new value
        return addDigits(sum);
    }
}
