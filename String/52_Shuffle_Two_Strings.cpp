// 52 Write a Program to check whether a string is a valid shuffle of two strings or not

// You are given three strings “A”, “B” and “C”. Your task is to check whether “C” is formed by an interleaving of A and B. C is said to be interleaving “A” and “B”, if the length of “C” is equal to the sum of the length of A and length of B, all the characters of “A” and “B” are present in “C”, and the order of all these characters remains the same in all three strings.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O((M+N)log(M+N))
// Space Complexity: O(1)
bool isInterleave(string a, string b, string c)
{
    if (a.length() + b.length() != c.length())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int i = 0, j = 0, k = 0;
    while (k != c.length())
    {
        if (i < a.length() && a[i] == c[k])
            i++;
        else if (j < b.length() && b[j] == c[k])
            j++;
        else
            return false;
        k++;
    }
    if (i < a.length() || j < b.length())
        return false;
    return true;
}

int main()
{
    string s1, s2, result;
    cin >> s1 >> s2 >> result;
    cout << isInterleave(s1, s2, result);
}