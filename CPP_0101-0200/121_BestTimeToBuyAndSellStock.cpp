#include <algorithm>
#include <vector>

using namespace std;

// 121. Best Time To Buy And Sell Stock - Easy - Array/Dynamic Programming
// -------------------------------------------------------------
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0.
// -------------------------------------------------------------
// Solve #2 | 02/19/21 | Time: 7:05 | Avg. Runtime: 108.8ms

int maxProfit(vector<int> &prices) { // O(N) time, O(1) space
    // Initialize
    int minPrice = INT_MAX, maxProfit = 0;
    // Iterate through the prices
    for (int x : prices) {
        // Get the minimum price so far
        minPrice = min(minPrice, x);
        // Get the maximum profit so far
        maxProfit = max(maxProfit, x - minPrice);
    }
    return maxProfit;
}
