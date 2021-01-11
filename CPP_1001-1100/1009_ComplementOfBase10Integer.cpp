#include "errors.h"
#include <string>

using namespace std;

// 1009. Complement Of Base 10 Integer - Easy - Math
// -------------------------------------------------------------
// Every non-negative integer N has a binary representation.
// For example, 5 can be represented as "101" in binary, 11 as "1011" in binary, and so on.
// Note that except for N = 0, there are no leading zeroes in any binary representation.
// The complement of a binary representation is the number in binary you get when changing every 1 to a 0 and 0 to a 1.
// For example, the complement of "101" in binary is "010" in binary.
// For a given number N in base-10, return the complement of it's binary representation as a base-10 integer.
// -------------------------------------------------------------
// Solve #1 | 12/25/20 | Time: 9:24 | Avg. Runtime: 0ms

int bitwiseComplement(int N) { // O(1) time, O(1) space
    // Catch 0 edge case
    if (!N)
        return 1;
    // Initialize
    string bits;
    unsigned int x = N;
    int res = 0;
    // Complement x
    for (unsigned int x = N; x; x >>= 1)
        bits += x & 1 ? "0" : "1";
    // Manually convert binary from above to decimal
    for (int i = bits.size() - 1; i >= 0; i--)
        res += (bits[i] - '0') * pow(2, i);
    return res;
}
