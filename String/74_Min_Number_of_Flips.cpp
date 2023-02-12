// 74 Number of flips to make binary string alternate

// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)
// Auxiliary Space: O(1)
int minFlips(string S)
{
    int ans1 = 0, ans2 = 0, curr;
    curr = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if ((int)(S[i] - '0') != curr % 2)
            ans1++;
        curr++;
    }
    curr = 1;
    for (int i = 0; i < S.size(); i++)
    {
        if ((int)(S[i] - '0') != curr % 2)
            ans2++;
        curr++;
    }
    return min(ans1, ans2);
}

int main()
{
    string s;
    cin >> s;
    cout << minFlips(s);
}