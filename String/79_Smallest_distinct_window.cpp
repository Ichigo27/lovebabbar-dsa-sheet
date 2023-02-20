// 79 Write a program tofind the smallest window that contains all characters of string itself.

// Given a string 's'.The task is to find the smallest window length that contains all the characters of the given string at least one time.For eg.A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach:
// Create all the sub-strings and check if there exist all the unique characters.
// Time Complexity O(N*N*60) - Total Number of sub-strings will be N*(N-1). Each string contains at most 56 unique character as small case and upper case letters are included.
// Space Complexity O(N*N) - To store all the sub-strings.

// Expected Approach:
// By using sliding window technique we can find the minimum window which contains all the unique elements.
// Time Complexity O(N*256) -  Traversing the whole string and removing the characters.
// Space Complexity O(256) - Total number of characters are 256 and we are just hashing the pattern and given string.
int findSubString(string str)
{
    unordered_set<char> s;
    for (int i = 0; i < str.size(); i++)
        s.insert(str[i]);
    int n = s.size();
    int ans = str.size();
    unordered_map<char, int> mp;
    int i = 0, j = 0, cnt = 0;
    while (j < str.size())
    {
        if (cnt < n)
        {
            if (mp[str[j]] == 0)
                cnt++;
            mp[str[j++]]++;
        }
        while (i < j && cnt == n)
        {
            ans = min(ans, j - i);
            if (mp[str[i]] == 1)
                cnt--;
            mp[str[i++]]--;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << findSubString(s);
}