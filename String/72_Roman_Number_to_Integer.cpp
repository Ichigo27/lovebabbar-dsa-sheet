// 72 Converting Roman Numerals to Decimal

// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

#include <bits/stdc++.h>
using namespace std;


// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

//     I can be placed before V (5) and X (10) to make 4 and 9.
//     X can be placed before L (50) and C (100) to make 40 and 90.
//     C can be placed before D (500) and M (1000) to make 400 and 900.

// Time complexity - O(N)
// Auxiliary Space - O(1)
int romanToDecimal(string &str)
{
    int ans = 0;
    unordered_map<char, int> convert = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    for (int i = 0; i < str.length(); i++)
    {
        if (i + 1 < str.length() && convert[str[i]] < convert[str[i + 1]])
            ans -= convert[str[i]];
        else
            ans += convert[str[i]];
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << romanToDecimal(s);
}