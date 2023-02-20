// 81 Minimum characters to be added at front to make string palindrome

// Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
// Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

#include <bits/stdc++.h>
using namespace std;

int kmp(string str)
{
    int n = str.size();
    int len = 0;
    int lps[n];
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len != 0)
        {
            len = lps[len - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
    return lps[n - 1];
}

int minChar(string str)
{
    int n = str.size();
    string rev = str;
    reverse(rev.begin(), rev.end());
    str = str + "$" + rev;
    return n - kmp(str);
}

int main()
{
    string s;
    cin >> s;
    cout << minChar(s);
}