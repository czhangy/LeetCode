#include <vector>

using namespace std;

// 122. Best Time To Buy And Sell Stock II - Easy - Array/Dynamic Programming
// -------------------------------------------------------------
// You are given an array prices for which the ith element is the price of a given stock on day i.
// Find the maximum profit you can achieve.
// You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
// -------------------------------------------------------------
// Solve #1 | 02/19/21 | Time: 2:14 | Avg. Runtime: 7.2ms

int maxProfit(vector<int> &prices) { // O(N) time, O(1) space
    // Initialize
    int profit = 0, size = prices.size();
    // Iterate through the prices
    for (int i = 0; i + 1 < size; i++)
        // Sell stock if a profit can be made
        if (prices[i] < prices[i + 1])
            profit += prices[i + 1] - prices[i];
    return profit;
}
