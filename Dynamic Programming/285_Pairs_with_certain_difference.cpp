// 285 Maximum sum of pairs with specific difference

// Given an array of integers, arr[] and a number, K.You can pair two numbers of the array if the difference between them is strictly less than K. The task is to find the maximum possible sum of such disjoint pairs (i.e., each element of the array can be used at most once). The Sum of P pairs is the sum of all 2P elements of pairs.

#include <bits/stdc++.h>
using namespace std;


// DP is not required here. Just sort the array and add the elements in pairs.
// Time complexity: O(n*log(n))
// Space complexity: O(1)
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr + N);
    int ans = 0;
    int i = N - 1;
    while (i > 0)
    {
        if (arr[i] - arr[i - 1] < K)
        {
            ans += arr[i] + arr[i - 1];
            i -= 2;
        }
        else
        {
            i--;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << maxSumPairWithDifferenceLessThanK(arr, n, k) << endl;
}