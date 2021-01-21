#include "errors.h"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 929. Unique Email Addresses - Easy - String
// -------------------------------------------------------------
// Every email consists of a local name and a domain name, separated by the @ sign.
// For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
// Besides lowercase letters, these emails may contain '.'s or '+'s.
// If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.
// For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
// (Note that this rule does not apply for domain names).
// If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
// This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.
// (Again, this rule does not apply for domain names).
// It is possible to use both of these rules at the same time.
// Given a list of emails, we send one email to each address in the list.
// How many different addresses actually receive mails?
// -------------------------------------------------------------
// Solve #1 | 09/27/20 | Time: 7:34 | Avg. Runtime: 29.4ms

int numUniqueEmails(vector<string> &emails) { // O(N) time, O(N) space
    // Initialize
    unordered_set<string> uniques;
    // Iterate through vector
    for (string email : emails) {
        // Initialize
        string str;
        bool domain = false;
        int size = email.size();
        // Iterate through email
        for (int i = 0; i < size; i++) {
            // Set flag when domain starts
            if (email[i] == '@')
                domain = true;
            // If in the domain or an alphabetic character, append it to the string
            if (domain || (!domain && email[i] != '.' && email[i] != '+'))
                str += email[i];
            // '+' found in local name, ignore all characters until the domain is found
            if (!domain && email[i] == '+')
                while (email[i + 1] != '@')
                    i++;
        }
        // Hash set handles duplicate entries
        uniques.insert(str);
    }
    // Size of the hash set reflects the number of unique addresses
    return uniques.size();
}
