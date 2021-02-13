#include "errors.h"
#include <string>
#include <vector>

using namespace std;

// 1185. Day Of The Week - Easy - Array
// -------------------------------------------------------------
// Given a date, return the corresponding day of the week for that date.
// The input is given as three integers representing the day, month and year respectively.
// Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
// -------------------------------------------------------------
// Solve #1 | 02/12/21 | Time: 25:35 | Avg. Runtime: 0ms

// Helper function to check if the year is a leap year
bool isLeapYear(int year) {
    return ((!(year % 4) && year % 100) || (year == 2000));
}

string dayOfTheWeek(int day, int month, int year) { // O(N) time, O(1) space
    // Hard-code information
    vector<string> days = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    vector<int> monthDays = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    // Initialize --> use total number of days in current month
    int numDays = (isLeapYear(year) && month > 2 ? 1 : 0) + day;
    // Get number of days up until current year
    for (int i = 1971; i < year; i++)
        numDays += (isLeapYear(i)) ? 366 : 365;
    // Get number of days up until current month
    numDays += monthDays[month - 1] - 1;
    // Translate number of days into a day
    return days[numDays % 7];
}
