// 48 Check whether a String is Palindrome or not

// Given a string S, check if it is palindrome or not.

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Auxiliary Space: O(1)
int isPalindrome(string S)
{
    int n = S.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (S[i] != S[n - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    string s;
    cin >> s;
    cout << isPalindrome(s);
}