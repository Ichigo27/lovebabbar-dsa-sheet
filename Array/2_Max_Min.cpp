// 2 Find the maximum and minimum element in an array

// Given an array A of size N of integers. Your task is to find the sum of minimum and maximum element in the array.

#include <bits/stdc++.h>
using namespace std;

// Maximum and minimum of an array using Linear search:

// Initialize values of min and max as minimum and maximum of the first two elements respectively. Starting from 3rd, compare each element with max and min, and change max and min accordingly (i.e., if the element is smaller than min then change min, else if the element is greater than max then change max, else ignore the element) 

// Time Complexity: O(n)
// Auxiliary Space: O(1) as no extra space was needed.
// In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case. 

// Maximum and minimum of an array using the tournament method:

// Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.

// Time Complexity: O(n)
// Auxiliary Space: O(log n) as the stack space will be filled for the maximum height of the tree formed during recursive calls same as a binary tree.
// The approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.

// Maximum and minimum of an array by comparing in pairs:

// If n is odd then initialize min and max as the first element. 
// If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
// For the rest of the elements, pick them in pairs and compare their 
// maximum and minimum with max and min respectively. 

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
    while (i < n - 1)
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