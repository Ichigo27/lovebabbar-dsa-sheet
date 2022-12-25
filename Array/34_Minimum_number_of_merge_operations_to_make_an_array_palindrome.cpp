// 34 Minimum no. of operations required to make an array palindrome

// The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.


#include <bits/stdc++.h>
using namespace std;

// two pointer approach
// Time Complexity: O(n)
// Auxiliary Space: O(1)
int findMinOps(int arr[], int n)
{
    int ans = 0;
    int i, j;
    i = 0;
    j = n - 1;
    while(i<j)
    {
        if(arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i] < arr[j])
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
        else
        {
            j--;
            arr[j] += arr[j + 1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMinOps(arr, n);
}