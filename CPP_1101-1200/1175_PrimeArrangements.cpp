#include "errors.h"
#include <unordered_set>

using namespace std;

// 1175. Prime Arrangements - Easy - Math
// -------------------------------------------------------------
// Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
// (Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)
// Since the answer may be large, return the answer modulo 10^9 + 7.
// -------------------------------------------------------------
// Solve #1 | 02/11/21 | Time: 18:08 | Avg. Runtime: 0ms

// Helper function to calculate x!
long long factorial(int x) {
    if (!x)
        return 1;
    return x * factorial(x - 1) % 1000000007;
}

int numPrimeArrangements(int n) { // O(N) time, O(N) space
    // Hard code prime numbers based on problem bounds
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    // Initialize
    int numPrimes = 0;
    // Count the number of primes
    for (int i = 1; i <= n; i++)
        if (primes.count(i))
            numPrimes++;
    // Calculate the number of permutations
    long long tot = (factorial(n - numPrimes) % 1000000007) * (factorial(numPrimes) % 1000000007);
    return tot % 1000000007;
}
