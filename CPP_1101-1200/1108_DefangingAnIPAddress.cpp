#include "errors.h"
#include <string>

using namespace std;

// 1108. Defanging An IP Address - Easy - String
// -------------------------------------------------------------
// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".
// -------------------------------------------------------------
// Solve #1 | 01/20/21 | Time: 2:35 | Avg. Runtime: 0ms

string defangIPaddr(string address) { // O(N) time, O(N) space
    // Intialize
    string res;
    // Iterate through IP address
    for (char c : address) {
        // Replace periods with bracketed periods
        if (c == '.')
            res += "[.]";
        else
            res += address[i];
    }
    return res;
}
