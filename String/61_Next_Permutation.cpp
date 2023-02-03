// 61 Find next greater number with same set of digits. [Very Very IMP]

// Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*logN)
// Auxiliary Space: O(1)
vector<int> nextPermutation(int N, vector<int> arr)
{
    // code here
    vector<int> ans = arr;
    if (N < 2)
        return ans;
    int i = N - 2;
    while (i >= 0 && ans[i] >= ans[i + 1])
        i--;
    if (i >= 0)
    {
        int j = N - 1;
        while (j > i && ans[i] >= ans[j])
            j--;
        swap(ans[i], ans[j]);
        reverse(ans.begin() + i + 1, ans.end());
    }
    else
        reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = nextPermutation(n, arr);
    for (auto ele : ans)
        cout << ele << ' ';
}