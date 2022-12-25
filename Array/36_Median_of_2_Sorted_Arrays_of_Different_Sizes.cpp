// 36 Median of 2 sorted arrays of different size

// Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;

// Approach 1 (Simple Mathematical Approach): 
// The given two arrays are sorted, so we need to merge them into a third array.
// Time Complexity: O((n+m) Log (n+m))
// Auxiliary Space: O(n+m). Since we are creating a new array of size n+m.

// Approach 2: 
// The given arrays are sorted, so merge the sorted arrays in an efficient way and keep the count of elements inserted in the output array or printed form. So when the elements in the output array are half the original size of the given array print the element as a median element.
// Time Complexity: O(m + n). To merge both the arrays O(m+n) time is needed.
// Auxiliary Space: O(1). No extra space is required.

// Approach 3 (Efficient):
// The idea is simple, calculate the median of both the arrays and discard one-half of each array. This approach takes into consideration the size of the arrays. The smaller-sized array is considered the first array in the parameter.
// Time Complexity: O(min(log m, log n)). In each step, one-half of each array is discarded. So the algorithm takes O(min(log m, log n)) time to reach the median value.
// Auxiliary Space: O(1). No extra space is required.

// Approach 4 (Binary Search):
// https://www.youtube.com/watch?v=NTop3VTjmxk
// Time Complexity: O(min(log m, log n)): Since binary search is being applied on the smaller of the 2 arrays
// Auxiliary Space: O(1)

double MedianOfArrays(vector<int> &array1, vector<int> &array2)
{
    int n1 = array1.size();
    int n2 = array2.size();
    if (n2 < n1)
        return MedianOfArrays(array2, array1);
    int low = 0;
    int high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : array1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : array2[cut2 - 1];
        int r1 = cut1 == n1 ? INT_MAX: array1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : array2[cut2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n1+n2)%2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            return max(l1, l2);
        }
        else if(l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << MedianOfArrays(arr1, arr2);
}