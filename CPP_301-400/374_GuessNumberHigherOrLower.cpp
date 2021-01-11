#include "errors.h"

// 374. Guess Number Higher Or Lower - Easy - Binary Search
// -------------------------------------------------------------
// We are playing the Guess Game.
// The game is as follows:
// I pick a number from 1 to n.
// You have to guess which number I picked.
// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
// You call a pre-defined API int guess(int num), which returns 3 possible results:
// - -1: The number I picked is lower than your guess (i.e. pick < num).
// - 1: The number I picked is higher than your guess (i.e. pick > num).
// - 0: The number I picked is equal to your guess (i.e. pick == num).
// Return the number that I picked.
// -------------------------------------------------------------
// Solve #1 | 07/24/20 | Time: 3:17 | Avg. Runtime: 2.4ms

// Prototype
int guess(int num);

int guessNumber(int n) { // O(log N) time, O(1) space
    // Initialize bounds
    int left = 1, right = n;
    // Binary search
    while (left < right) {
        // Calculate mid index, protecting against overflow
        int mid = left + (right - left) / 2, res = guess(mid);
        // Guess is too low --> move left bound right
        if (res == 1)
            left = mid + 1;
        // Guess is too high --> move right bound left
        else
            right = mid;
    }
    return left;
}
