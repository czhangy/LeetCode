#include "errors.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 811. Subdomain Visit Count - Easy - Hash Table
// -------------------------------------------------------------
// A website domain like "discuss.leetcode.com" consists of various subdomains.
// At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com".
// When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
// Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address.
// An example of a count-paired domain might be "9001 discuss.leetcode.com".
// We are given a list cpdomains of count-paired domains.
// We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
// -------------------------------------------------------------
// Solve #1 | 09/13/20 | Time: 11:51 | Avg. Runtime: 30.4ms

vector<string> subdomainVisits(vector<string> &cpdomains) { // O(N * M) time, O(N) space
    // Initialize
    unordered_map<string, int> m;
    vector<string> res;
    // Iterate through the vector
    for (string str : cpdomains) {
        // Initialize
        int i = 0;
        string temp, curDomain = str;;
        // Get the visit count
        while (str[i] != ' ') {
            temp += str[i];
            i++;
        }
        // Adjust the index to account for the space
        i++;
        // Get the number of visits as an integer
        int visits = stoi(temp);
        // Iterate through URL
        for (; i < str.size(); i++) {
            // Isolate subdomain
            curDomain = str.substr(i, str.size() - i);
            // Add visits to map
            m[curDomain] += visits;                
            // Move to next subdomain    
            while (i < str.size() && str[i] != '.')
                i++;
        }
    }
    // Formatting
    for (auto &iter : m)
        res.push_back(to_string(iter.second) + " " + iter.first);
    return res;
}
