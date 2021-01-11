#include "errors.h"

// 1025. Divisor Game - Easy - Math/Dynamic Programming
// -------------------------------------------------------------
// Alice and Bob take turns playing a game, with Alice starting first.
// Initially, there is a number N on the chalkboard.
// On each player's turn, that player makes a move consisting of:
// - Choosing any x with 0 < x < N and N % x == 0.
// - Replacing the number N on the chalkboard with N - x.
// Also, if a player cannot make a move, they lose the game.
// Return true if and only if Alice wins the game, assuming both players play optimally.
// -------------------------------------------------------------
// Solve #1 | 01/05/21 | Time: 3:08 | Avg. Runtime: 0ms

bool divisorGame(int N) { // O(1) time, O(1) space
    // Whoever starts with the odd value loses the game
    return !(N & 1);
}
