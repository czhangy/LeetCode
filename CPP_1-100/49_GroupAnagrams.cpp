#include "errors.h"
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 49. Group Anagrams - Medium - Hash Table/String
// -------------------------------------------------------------
// Given an array of strings strs, group the anagrams together.
// You can return the answer in any order.
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// -------------------------------------------------------------
// Solve #2 | 10/06/20 | Time: 3:11 | Avg. Runtime: 52.8ms

vector<vector<string>> groupAnagrams(vector<string> &strs) { // O(N) time, O(N) space
    // Initialize
    vector<vector<string>> res;
    unordered_map<string, vector<string>> groupings;
    // Iterate through all strings
    for (string str : strs) {
        // Insert into hash map, using sorted string as a key and original word as a value
        string temp = str;
        sort(temp.begin(), temp.end());
        groupings[temp].push_back(str);
    }
    // Push vector of words based on sorted string into result
    for (auto &iter : groupings)
        res.push_back(iter.second);
    return res;
}
