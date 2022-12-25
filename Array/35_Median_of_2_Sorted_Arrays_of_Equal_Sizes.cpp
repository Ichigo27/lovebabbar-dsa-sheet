// 35 Median of 2 sorted arrays of equal size

// Given two sorted arrays array1 and array2 of size n. Find the median of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;

// Simply count while Merging
// Time Complexity: O(n)
// Auxiliary Space: O(1)
// double getMedian(int ar1[], int ar2[], int n)
// {
//     int i = 0; /* Current index of
//                 i/p array ar1[] */
//     int j = 0; /* Current index of
//                 i/p array ar2[] */
//     int count;
//     int m1 = -1, m2 = -1;

//     /* Since there are 2n elements,
//     median will be average of elements
//     at index n-1 and n in the array
//     obtained after merging ar1 and ar2 */
//     for (count = 0; count <= n; count++)
//     {
//         /* Below is to handle case where
//         all elements of ar1[] are
//         smaller than smallest(or first)
//         element of ar2[]*/
//         if (i == n)
//         {
//             m1 = m2;
//             m2 = ar2[0];
//             break;
//         }

//         /*Below is to handle case where
//         all elements of ar2[] are
//         smaller than smallest(or first)
//         element of ar1[]*/
//         else if (j == n)
//         {
//             m1 = m2;
//             m2 = ar1[0];
//             break;
//         }
//         /* equals sign because if two
//         arrays have some common elements */
//         if (ar1[i] <= ar2[j])
//         {
//             /* Store the prev median */
//             m1 = m2;
//             m2 = ar1[i];
//             i++;
//         }
//         else
//         {
//             /* Store the prev median */
//             m1 = m2;
//             m2 = ar2[j];
//             j++;
//         }
//     }

//     return (1.0 * (m1 + m2)) / 2;
// }

// By comparing the medians of two arrays
// Time Complexity: O(logn)
// Auxiliary Space: O(logn)
// int median(int arr[], int n)
// {
//     if (n % 2 == 0)
//         return (arr[n / 2 - 1] + arr[n / 2]) / 2;
//     else
//         return arr[n / 2];
// }

// int getMedian(int ar1[],
//               int ar2[], int n)
// {
//     /* return -1 for
//     invalid input */
//     if (n <= 0)
//         return -1;
//     if (n == 1)
//         return (ar1[0] + ar2[0]) / 2;
//     if (n == 2)
//         return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

//     /* get the median of
//     the first array */
//     int m1 = median(ar1, n);

//     /* get the median of
//     the second array */
//     int m2 = median(ar2, n);

//     /* If medians are equal then
//     return either m1 or m2 */
//     if (m1 == m2)
//         return m1;

//     /* if m1 < m2 then median must
//     exist in ar1[m1....] and
//                 ar2[....m2] */
//     if (m1 < m2)
//     {
//         if (n % 2 == 0)
//             return getMedian(ar1 + n / 2 - 1,
//                              ar2, n - n / 2 + 1);
//         return getMedian(ar1 + n / 2,
//                          ar2, n - n / 2);
//     }
//     /* if m1 > m2 then median must
//     exist in ar1[....m1] and
//                 ar2[m2...] */
//     else
//     {
//         if (n % 2 == 0)
//             return getMedian(ar2 + n / 2 - 1,
//                              ar1, n - n / 2 + 1);
//         return getMedian(ar2 + n / 2,
//                          ar1, n - n / 2);
//     }
// }

// By Merging two arrays w/o extra space
// Time Complexity: O(logn)
// Auxiliary Space: O(1)
// int getMedian(int ar1[], int ar2[], int n)
// {
//     int i = n - 1;
//     int j = 0;
//     while (ar1[i] > ar2[j] && j < n && i > -1)
//         swap(ar1[i--], ar2[j++]);
//     sort(ar1, ar1 + n);
//     sort(ar2, ar2 + n);
//     return (ar1[n - 1] + ar2[0]) / 2;
// }

// Using binary search
// Time Complexity: O(logn)^2
// Auxiliary Space: O(1)
double getMedian(int arr1[], int arr2[], int n)
{
    // according to given constraints all numbers are in
    // this range
    int low = (int)-1e9, high = (int)1e9;

    int pos = n;
    double ans = 0.0;
    // binary search to find the element which will be
    // present at pos = totalLen/2 after merging two
    // arrays in sorted order
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        // total number of elements in arrays which are
        // less than mid
        int ub = upper_bound(arr1, arr1 + n, mid) - arr1 + upper_bound(arr2, arr2 + n, mid) - arr2;

        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }

    ans = low;

    // As there are even number of elements, we will
    // also have to find element at pos = totalLen/2 - 1
    pos--;
    low = (int)-1e9;
    high = (int)1e9;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int ub = upper_bound(arr1, arr1 + n, mid) - arr1 + upper_bound(arr2, arr2 + n, mid) - arr2;

        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // average of two elements in case of even
    // number of elements
    ans = (ans + low) / 2;

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    cout << getMedian(arr1, arr2, n);
}