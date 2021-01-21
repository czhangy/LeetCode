#include "errors.h"
#include <vector>

using namespace std;

// 985. Sum Of Even Numbers After Queries - Easy - Array
// -------------------------------------------------------------
// We have an array A of integers, and an array queries of queries.
// For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].
// Then, the answer to the i-th query is the sum of the even values of A.
// (Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A).
// Return the answer to all queries.
// Your answer array should have answer[i] as the answer to the i-th query.
// -------------------------------------------------------------
// Solve #1 | 12/23/20 | Time: 14:56 | Avg. Runtime: 190.4ms

vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) { // O(N + M) time, O(M) space
    // Initialize
    int sum = 0, size = queries.size();
    vector<int> res(size);
    // Iterate through the vector of integers
    for (int x : A)
        // Get the sum of all even values
        if (!(x & 1))
            sum += x;
    // Iterate through the vector of queries
    for (int i = 0; i < size; i++) {
        // Intialize
        int base = A[queries[i][1]], val = queries[i][0];
        // Get running sum of values in A
        sum -= base & 1 ? 0 : base;
        sum += (base + val) & 1 ? 0 : base + val;
        // Update vectors
        A[queries[i][1]] += val;
        res[i] = sum;
    }
    return res;
}
