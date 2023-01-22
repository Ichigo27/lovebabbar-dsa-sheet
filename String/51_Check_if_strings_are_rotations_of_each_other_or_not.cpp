// 51 Write a Code to check whether one string is a rotation of another

// Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

#include <bits/stdc++.h>
using namespace std;

// Naive Approach
// Time Complexity: O(N*N)
// Space Complexity: O(N)
// bool areRotations(string s1, string s2)
// {
//     int n = s1.size();
//     string s = s1 + s1;
//     for (int i = 0; i < n; i++)
//     {
//         if(s.substr(i, n) == s2)
//         return true;
//     }
//     return false;
// }

// Efficient Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
bool areRotations(string s1, string s2)
{
    int n = s1.size();
    string s = s1 + s1;
    return (s.find(s2) != string::npos);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << areRotations(s1, s2);
}