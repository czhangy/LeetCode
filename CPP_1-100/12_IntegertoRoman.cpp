#include "errors.h"
#include <string>

using namespace std;

// 12. Integer to Roman - Medium - Math/String
// -------------------------------------------------------------
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII.
// Instead, the number four is written as IV, because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX.
// There are six instances where subtraction is used:
// - I can be placed before V (5) and X (10) to make 4 and 9.
// - X can be placed before L (50) and C (100) to make 40 and 90.
// - C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.
// -------------------------------------------------------------
// Solve #1 | 09/24/20 | Time: 8:15 | Avg. Runtime: 6.4ms

string intToRoman(int num) { // O(N) time, O(1) space
    // Initialization
    string res;
    // Break num down digit-by-digit
    while (num) {
        if (num >= 1000) {
            res += 'M';
            num -= 1000;
        } else if (num >= 900) {
            res += "CM";
            num -= 900;
        } else if (num >= 500) {
            res += 'D';
            num -= 500;
        } else if (num >= 400) {
            res += "CD";
            num -= 400;
        } else if (num >= 100) {
            res += 'C';
            num -= 100;
        } else if (num >= 90) {
            res += "XC";
            num -= 90;
        } else if (num >= 50) {
            res += 'L';
            num -= 50;
        } else if (num >= 40) {
            res += "XL";
            num -= 40;
        } else if (num >= 10) {
            res += 'X';
            num -= 10;
        } else if (num >= 9) {
            res += "IX";
            num -= 9;
        } else if (num >= 5) {
            res += 'V';
            num -= 5;
        } else if (num >= 4) {
            res += "IV";
            num -= 4;
        } else {
            res += 'I';
            num--;
        }
    }
    return res;
}