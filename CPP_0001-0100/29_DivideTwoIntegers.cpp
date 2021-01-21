#include "errors.h"
#include <cstdlib>

using namespace std;

// 29. Divide Two Integers - Medium - Math/Binary Search
// -------------------------------------------------------------
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero, which means losing its fractional part.
// -------------------------------------------------------------
// Solve #2 | 01/05/21 | Time: 33:51 | Avg. Runtime: 1.6ms

int divide(int dividend, int divisor) {
    // Catch edge case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    // Initialize --> use long to handle overflow (not right)
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    // Get sign of answer
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    // Binary search
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        // Find number of times divided
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    // Apply sign to result
    return sign == 1 ? ans : -ans;
}
