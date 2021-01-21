#include "errors.h"
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 893. Groups Of Special-Equivalent Strings - Easy - String
// -------------------------------------------------------------
// You are given an array A of strings.
// A move onto S consists of swapping any two even indexed characters of S, or any two odd indexed characters of S.
// Two strings S and T are special-equivalent if after any number of moves onto S, S == T.
// For example, S = "zzxy" and T = "xyzz" are special-equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz" that swap S[0] and S[2], then S[1] and S[3].
// Now, a group of special-equivalent strings from A is a non-empty subset of A such that:
//  - Every pair of strings in the group are special equivalent, and;
//  - The group is the largest size possible (ie., there isn't a string S not in the group such that S is special equivalent to every string in the group)
// Return the number of groups of special-equivalent strings from A.
// -------------------------------------------------------------
// Solve #1 | 09/19/20 | Time: 4:41 | Avg. Runtime: 17.6ms

int numSpecialEquivGroups(vector<string> &A) { // O(N) time, O(N) space
    // Initialize
    set<string> groups;
    int size = A.size();
    // Iterate through vector
    for (int i = 0; i < size; i++) {
        // Initialize
        string str1, str2;
        // Iterate through strings
        for (int j = 0; j < A[i].size(); j++) {
            // Separate characters by index parity
            if (j & 1)
                str1 += A[i][j];
            else
                str2 += A[i][j];
        }
        // Sort strings to check for special-equivalency
        sort(str1.begin(), str1.end()); 
        sort(str2.begin(), str2.end());
         // Format string and insert into set
        groups.insert(str1 + ' ' + str2);
    }
    return groups.size();
}
