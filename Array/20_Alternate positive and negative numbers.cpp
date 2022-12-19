// 20 Rearrange the array in alternating positive and negative items with O(1) extra space

// Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.

#include <bits/stdc++.h>
using namespace std;

// Method 1: Segregate Positive and Negative numbers
// We can store the positive values and negative values in two separate data structures. We will start filling the original array with alternating negative and positive values in the same order in which it appears in the original array.
// Time Complexity: O(N)
// Auxiliary Space: O(N)

// Method 2: Two pointer Approach
// Maintain Positive numbers in left side and Negative numbers on the right side and then arrange accordingly
// NOTE: The order of number changes
// https://www.youtube.com/watch?v=zUPMACE0uBs
// Time Complexity: O(N)
// Auxiliary Space: O(1)

// Method 3: Right Rotate Method
// The idea is to process the array from left to right. While processing, find the first out-of-place element in the remaining unprocessed array. Once we find an out-of-place element, we find the first element after it with an opposite sign. We right rotate the subarray between these two elements (including these two).
// https://www.youtube.com/watch?v=5MeI5Kk8KTQ
// Time Complexity: O(N^2), as we are using a loop to traverse N times and calling function to right rotate each time which will cost O(N)
// Auxiliary Space: O(1)
void rightrotate(int arr[], int start, int end)
{
    int temp = arr[end];
    for (int i = end; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrange(int arr[], int n)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (pos != -1)
        {
            if ((arr[pos] >= 0 && arr[i] < 0) || (arr[pos] < 0 && arr[i] >= 0))
            {
                rightrotate(arr, pos, i);
                if (i - pos >= 2)
                    pos += 2;
                else
                    pos = -1;
            }
        }
        else
        {
            if ((arr[i] < 0 && i % 2 == 0) || (arr[i] >= 0 && i % 2 == 1))
                pos = i;
        }
    }
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
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}