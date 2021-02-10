#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 1154. Day Of The Year - Easy - Math
// -------------------------------------------------------------
// Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.
// -------------------------------------------------------------
// Solve #2 | 02/09/21 | Time: 8:25 | Avg. Runtime: 0ms

int dayOfYear(string date) { // O(1) time, O(1) space
    // Hard code number of days passed by month
    vector<int> daysPerMonth = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    // Extract year from string and get raw number of days passed
    int year = stoi(date.substr(0, 4)), num = daysPerMonth[stoi(date.substr(5, 2)) - 1] + stoi(date.substr(8, 2));
    // Check if we need to account for leap years
    num += ((!(year % 4) && year % 100) || !(year % 400)) && stoi(date.substr(5, 2)) > 2 ? 1 : 0;
    return num;
}
