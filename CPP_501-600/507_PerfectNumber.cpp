// 507. Perfect Number - Easy - Math
// A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.
// A divisor of an integer x is an integer that can divide x evenly.
// Given an integer n, return true if n is a perfect number, otherwise return false.

// Solve #1 - 8/7/20 - Time: 7:50 - Avg. Runtime: 0ms

bool checkPerfectNumber(int num) { // O(sqrt(N)) time, O(1) space
    // Handle edge case of num = 1
    if (num == 1)
        return false;
    
    // Initialize
    int i, temp = num;

    // Loop through possible divisors
    for (i = 2; i * i <= temp; i++)
        // Divisor found, subtract from num
        if (!(temp % i))
            num -= (i + temp / i);

    // Return true if result - 1 (1 was not checked) is 0, false otherwise
    return !(num - 1);
}