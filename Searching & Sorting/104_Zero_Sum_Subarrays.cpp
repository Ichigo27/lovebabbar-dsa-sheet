// 104 print all subarrays with 0 sum

// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

#include <bits/stdc++.h>
using namespace std;

// Idea is to use the prefix sum. One observation is if there exist a zero-sum subarray the value of prefix sum will repeat.
// let the given array is arr[] = 1  2  -2  3  -3  0 2
// so the presum array [] =       1  3   1   4  1  1 3
// 1 and 3 are repeating it means there zero-sum subarray. The zero-sum subarray exists in between two repeating presum values. So if the presum value repeat 2 times there is 1 zero-sum subarray. If the presum value repeat 3 times there is 3 zero-sum subarray (3C2 rule).

// Step 1: Initialize sum and counter with zero
// Step 2: Use a map to store the prefix sum which has appeared already, and number of occurrence.
// Step 3: iterating over the array.
// Step 4: calculate presum
// Step 5: if presum equals to zero update the counter
// Step 6: if prefix sum is already present in map then it is repeated which means there is a subarray whose summation is 0.
// update the counter by adding the occurrence of the presum value.
// Step 7: update the frequency of presum value.
// Step 8: Return the counter.

// Time Complexity: As we are using a unordered_map, which takes insertion time nearly O(1), so insertions of all presume will take O(N). N is the number of elements in the vector.
// Space Complexity: As we are using a unordered_map to store the occurrence of presum values so the space complexity is O(N).

long long int findSubarray(vector<long long int> &arr, int n)
{
    long long int ans = 0;
    vector<long long int> pf(n + 1, 0);
    unordered_map<int, int> mp;
    mp[0]++;
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + arr[i - 1];
        if (mp.find(pf[i]) != mp.end())
            ans += mp[pf[i]];
        mp[pf[i]]++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findSubarray(arr, n);
}