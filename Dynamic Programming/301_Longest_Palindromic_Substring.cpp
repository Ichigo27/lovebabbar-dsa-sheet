// 301 Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=fxwvVnBMN6I
// https://www.youtube.com/watch?v=XYQecbcd6_c

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(1) + O(n) for recursive stack
// string solve(string s, int start, int end)
// {
//     if (start > end)
//         return "";

//     if (start == end)
//         return string(1, s[start]);

//     // Check if first and last characters are equal
//     if (s[start] == s[end])
//     {
//         string inner = solve(s, start + 1, end - 1);

//         // If inner substring is also a palindrome,
//         // then current substring from start to end is a palindrome
//         if (inner.length() == (end - start - 1))
//             return s.substr(start, end - start + 1);
//     }

//     // Recursively check for palindromic substrings by excluding one character at a time
//     string left = solve(s, start + 1, end);
//     string right = solve(s, start, end - 1);

//     // Return the longest palindromic substring among left and right substrings
//     return (left.length() > right.length()) ? left : right;
// }

// string longestPalindrome(string s)
// {
//     return solve(s, 0, s.length() - 1);
// }


// Memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n) for recursive stack
// string solve(string s, int start, int end, vector<vector<string>> &dp)
// {
//     if (start > end)
//         return "";
//     if (start == end)
//         return string(1, s[start]);
//     if (dp[start][end] != "")
//         return dp[start][end];
//     if (s[start] == s[end])
//     {
//         string inner = solve(s, start + 1, end - 1, dp);
//         if (inner.length() == (end - start - 1))
//             return s.substr(start, end - start + 1);
//     }
//     string left = solve(s, start + 1, end, dp);
//     string right = solve(s, start, end - 1, dp);
//     return (left.length() > right.length()) ? left : right;
// }

// string longestPalindrome(string s)
// {
//     vector<vector<string>> dp(s.length(), vector<string>(s.length(), ""));
//     return solve(s, 0, s.length() - 1, dp);
// }


// Tabulation
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// string longestPalindrome(string s)
// {
//     int n = s.length();
//     vector<vector<bool>> dp(n, vector<bool>(n, false));
//     string ans = "";
//     int maxLen = 0;
//     for(int l = 1; l <= n; l++)
//     {
//         for(int i = 0; i <= n - l; i++)
//         {
//             int j = i + l - 1;
//             if(l == 1)
//                 dp[i][j] = true;
//             else if(l == 2)
//                 dp[i][j] = (s[i] == s[j]);
//             else
//                 dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];

//             if(dp[i][j] && l > maxLen)
//             {
//                 maxLen = l;
//                 ans = s.substr(i, l);
//             }
//         }
//     }
//     return ans;
// }

// Another Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
string longestPalindrome(string s)
{
    string res = "";
    int maxLen = 0;
    for(int i = 0; i < s.length(); i++)
    {
        // Odd length palindromes
        int l = i, r = i;
        while(l >= 0 && r < s.length() && s[l] == s[r])
        {
            if(r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                res = s.substr(l, maxLen);
            }
            l--;
            r++;
        }

        // Even length palindromes
        l = i, r = i + 1;
        while(l >= 0 && r < s.length() && s[l] == s[r])
        {
            if(r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                res = s.substr(l, maxLen);
            }
            l--;
            r++;
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}