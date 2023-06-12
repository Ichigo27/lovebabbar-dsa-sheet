// 216 Find the K-th Permutation Sequence of first N natural numbers

#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=wT7gcXLYoao
// Time Complexity: O(N2), As we are running a single loop for each index of the sequence so total time will be O(N2).
// Auxiliary Space: O(N), Space taken to store the factorial of each number.

string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        nums.push_back(i);
    }
    nums.push_back(n);
    string ans = "";
    k--; // zero based indexing

    // subnetting like problem
    while(true)
    {
        int q = k / fact;
        int r = k % fact;
        ans.push_back(nums[q] + '0');
        nums.erase(nums.begin() + q);
        if(nums.empty())
            break;
        k = r;
        fact = fact / nums.size();
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << kthPermutation(n, k);
}