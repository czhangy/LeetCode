#include "errors.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// 914. X Of A Kind In A Deck Of Cards - Easy - Array/Math
// -------------------------------------------------------------
// In a deck of cards, each card has an integer written on it.
// Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
// - Each group has exactly X cards.
// - All the cards in each group have the same integer.
// -------------------------------------------------------------
// Solve #1 | 09/18/20 | Time: 18:18 | Avg. Runtime: 38.4ms

bool hasGroupsSizeX(vector<int> &deck) { // O(N) time, O(N) space
    // Initialize
    unordered_map<int, int> cards;
    int minAmnt = INT_MAX, i = 2, gcf = -1;;
    // Map all integers to their number of occurrences
    for (int x : deck)
        cards[x]++;
    // Get the minimum number of occurrences of any integer
    for (auto &iter : cards)
        minAmnt = min(iter.second, minAmnt);
    // If there are any unique integers --> failure condition
    if (minAmnt < 2)
        return false;
    // Calculate the greatest common factor
    while (i <= minAmnt) {
        bool divide = true;
        // Iterate through the hash map
        for (auto &iter : cards)
            if (iter.second % i) {
                divide = false;
                break;
            }
        // Set GCF if needed
        if (divide)
            gcf = i;
        i++;
    }
    // Check if a GCF exists
    return gcf > 1;
}
