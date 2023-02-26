// 87 Transform One String to Another using Minimum Number of Given Operation

// Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

#include <bits/stdc++.h>
using namespace std;

// Expected Time Complexity: O(N) where N is max(length of A, length of B)
// Expected Auxiliary Space: O(1)
int transform(string A, string B)
{
    int ans = 0;
    int max_char = 256;
    int check[max_char];
    memset(check, 0, sizeof(check));
    int n = A.size();
    int m = B.size();
    if (n != m)
        return -1;
    for (int i = 0; i < n; i++)
        check[A[i]]++;
    for (int i = 0; i < m; i++)
        check[B[i]]--;
    for (int i = 0; i < max_char; i++)
        if (check[i] != 0)
            return -1;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] == B[j])
        {
            i--;
            j--;
            continue;
        }
        ans++;
        i--;
    }
    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << transform(a, b);
}