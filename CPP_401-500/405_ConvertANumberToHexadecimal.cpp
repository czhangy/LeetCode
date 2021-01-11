#include "errors.h"
#include <string>

using namespace std;

// 405. Convert A Number To Hexadecimal - Easy - Bit Manipulation
// -------------------------------------------------------------
// Given an integer, write an algorithm to convert it to hexadecimal.
// For negative integers, two’s complement method is used.
// - All letters in hexadecimal (a-f) must be in lowercase.
// - The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// - The given number is guaranteed to fit within the range of a 32-bit signed integer.
// - You must not use any method provided by the library which converts/formats the number to hex directly.
// -------------------------------------------------------------
// Solve #2 | 08/05/20 | Time: 4:03 | Avg. Runtime: 0.8ms

string toHex(int num) { // O(1) time, O(1) space
    // Initialize
    string res;
    unsigned int x = num;
    // Catch 0 edge case
    if (!x)
        return "0";
    // Break down the value by bytes
    while (x) {
        // Extract last byte
        int cur = x & 15;
        // Append 0 for values under 10
        if (cur < 10)
            res += '0' + cur;
        // Get correct hex digit
        else
            res += 'a' + cur - 10;
        // Iterate to next byte
        x >>= 4;
    }
    // Account for reversed build of string
    reverse(res.begin(), res.end());
    return res;
}
