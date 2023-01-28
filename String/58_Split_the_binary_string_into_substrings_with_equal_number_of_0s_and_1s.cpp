// 58 Split the Binary string into two substring with equal 0’s and 1’s

// Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N) where N is the length of string
// Space Complexity: O(1)
int maxSubStr(string str)
{
    int ans = 0, zeros = 0, ones = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            zeros++;
        if (str[i] == '1')
            ones++;
        if (zeros == ones)
            ans++;
    }
    if (zeros != ones)
        return -1;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << maxSubStr(s);
}