#include <cctype>
#include <string>

using namespace std;

// 125. Valid Palindrome - Easy - Two Pointers/String
// -------------------------------------------------------------
// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// -------------------------------------------------------------
// Solve #2 | 02/19/21 | Time: 4:10 | Avg. Runtime: 5.6ms

bool isPalindrome(string s) { // O(N) time, O(1) space
    // Iterate 2 pointers through the string
    for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
        // Position left at the next alphanumeric character
        while (left < right && !isalnum(s[left]))
            left++;
        // Position right at the next alphanumeric character
        while (left < right && !isalnum(s[right]))
            right--;
        // Compare characters and see if they are palindromic
        if (tolower(s[left]) != tolower(s[right]))
            return false;
    }
    return true;
}
