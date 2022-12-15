// 2 Find the maximum and minimum element in an array

// Given an array A of size N of integers. Your task is to find the sum of minimum and maximum element in the array.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Auxiliary Space : O(1) as no extra space was needed.
// If n is odd:    3*(n-1)/2
// If n is even:   1 Initial comparison for initializing min and max, and 3(n-2)/2 comparisons for rest of the elements =  1 + 3*(n-2)/2 = 3n/2 -2
int findSum(int arr[], int n)
{
    int min_ele = -1;
    int max_ele = -1;
    int i;
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            min_ele = arr[1];
            max_ele = arr[0];
        }
        else
        {
            min_ele = arr[0];
            max_ele = arr[1];
        }
        i = 2;
    }
    else
    {
        min_ele = arr[0];
        max_ele = arr[0];
        i = 1;
    }
    while (i < n)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i + 1] < min_ele)
            {
                min_ele = arr[i + 1];
            }
            if (arr[i] > max_ele)
            {
                max_ele = arr[i];
            }
        }
        else
        {
            if (arr[i] < min_ele)
            {
                min_ele = arr[i];
            }
            if (arr[i + 1] > max_ele)
            {
                max_ele = arr[i + 1];
            }
        }
        i += 2;
    }
    return min_ele + max_ele;
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
    cout << findSum(arr, n);
}