#include "errors.h"
#include <vector>

using namespace std;

// 999. Available Captures For Rook - Easy - Array
// -------------------------------------------------------------
// On an 8 x 8 chessboard, there is one white rook.
// There also may be empty squares, white bishops, and black pawns.
// These are given as characters 'R', '.', 'B', and 'p' respectively.
// Uppercase characters represent white pieces, and lowercase characters represent black pieces.
// The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies. \
// Also, rooks cannot move into the same square as other friendly bishops.
// Return the number of pawns the rook can capture in one move.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 12:19 | Avg. Runtime: 1.6ms

int numRookCaptures(vector<vector<char>> &board) { // O(1) time, O(1) space
    // Initialize
    int caps = 0, x = -1, y = -1;
    // Find the coordinates of the rook
    for (int i = 0; i < 8; i++) {
        if (x != -1)
            break;
        for (int j = 0; j < 8; j++)
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
    }
    // Check below the rook
    int i = x - 1;
    while (i >= 0 && board[i][y] == '.')
        i--;
    if (i >= 0 && board[i][y] == 'p')
        caps++;
    // Check above the rook
    i = x + 1;
    while (i < 8 && board[i][y] == '.')
        i++;
    if (i < 8 && board[i][y] == 'p')
        caps++;
    // Check left of the rook
    i = y - 1;
    while (i >= 0 && board[x][i] == '.')
        i--;
    if (i >= 0 && board[x][i] == 'p')
        caps++;
    // Check right of the rook
    i = y + 1;
    while (i < 8 && board[x][i] == '.')
        i++;
    if (i < 8 && board[x][i] == 'p')
        caps++;
    return caps;
}
