// 75 Find the first repeated word in string.

// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

// Note: No two strings are the second most repeated, there will be always a single string.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), where N represents the size of the given vector.
// Auxiliary Space: O(N), where N represents the size of the given vector.
string secFrequent(string arr[], int n)
{
    string ans = "";
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int fmax = -1, smax = -1;
    for(auto &ele: mp)
    {
        if(ele.second > fmax)
        {
            smax = fmax;
            fmax = ele.second;
        }
        else if(ele.second > smax && ele.second != fmax)
        {
            smax = ele.second;
        }
    }
    for(auto &ele: mp)
    {
        if(ele.second == smax)
            ans = ele.first;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << secFrequent(arr, n);
}