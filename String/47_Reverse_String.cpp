// 47 Reverse a String

// Write a function that reverses a string. The input string is given as an array of characters. You must do this by modifying the input array in - place with O(1) extra memory.

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Auxiliary Space: O(1)
void reverseString(vector<char> &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    reverseString(s);
    for (int i = 0; i < n; i++)
        cout << s[i];
}