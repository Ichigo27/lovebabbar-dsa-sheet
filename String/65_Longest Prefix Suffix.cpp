// 65 KMP Algo

// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

// NOTE : Prefix and suffix can be overlapping but they should not be equal to the entire string.

#include <bits/stdc++.h>
using namespace std;

// Efficient Solution: The idea is to use the preprocessing algorithm KMP search.
// Time Complexity : O(n)
// Auxiliary Space : O(n)

int lps(string s)
{
    int n = s.length();
    int kmp[n];
    kmp[0] = 0;
    int len = 0, i = 1;
    while(i < n)
    {
        if(s[i] == s[len])
        {
            len++;
            kmp[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = kmp[len - 1];
            }
            else
            {
                kmp[i] = 0;
                i++;
            }
        }
    }
    return kmp[n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << lps(s);
}