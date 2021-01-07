#include errors.h

// 7. Reverse Integer - Easy - Math
// -------------------------------------------------------------
// Given a 32-bit signed integer, reverse digits of an integer.
// -------------------------------------------------------------
// Solve #1 | 6/25/20 | Time: 31:08 | Avg. Runtime: 4ms

int reverse(int x) {
    // Initialization
    int ans = 0;
    while (x) {
        // Calculate
        int temp = ans * 10 + x % 10;
        // Check for overflow
        if (temp / 10 != ans)
            return 0;
        // Iterate forwards
        ans = temp;
        x /= 10;
    }
    return ans;
}
