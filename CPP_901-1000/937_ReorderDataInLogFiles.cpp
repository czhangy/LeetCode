#include "errors.h"
#include <set>
#include <string>
#include <vector>

using namespace std;

// 937. Reorder Data In Log Files - Easy - String
// -------------------------------------------------------------
// You have an array of logs.  Each log is a space delimited string of words.
// For each log, the first word in each log is an alphanumeric identifier.
// Then, either:
// - Each word after the identifier will consist only of lowercase letters, or;
// - Each word after the identifier will consist only of digits.
// We will call these two varieties of logs letter-logs and digit-logs.
// It is guaranteed that each log has at least one word after its identifier.
// Reorder the logs so that all of the letter-logs come before any digit-log.
// The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.
// The digit-logs should be put in their original order.
// Return the final order of the logs.
// -------------------------------------------------------------
// Solve #1 | 09/28/20 | Time: 18:09 | Avg. Runtime: 12.8ms

vector<string> reorderLogFiles(vector<string> &logs) { // O(N * M) time, O(N) space
    // Initialize
    set<string> letterLogs;
    vector<string> digitLogs, res;
    // Iterate through the vector
    for (string str : logs) {
        // Separate into letter-logs and digit-logs
        if (isdigit(str[str.find(' ') + 1]))
            digitLogs.push_back(str);
        else
            // Format for future search
            letterLogs.insert(str.substr(str.find(' ')) + '#' + str.substr(0, str.find(' ')));
    }
    for (auto &iter : letterLogs)
        // Decode formatting for result
        res.push_back(iter.substr(iter.find('#') + 1) + iter.substr(0, iter.find('#')));
    // Combine vectors
    res.insert(res.end(), digitLogs.begin(), digitLogs.end());
    return res;
}
