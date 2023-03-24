// 96 Find the repeating and the missing

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=5nMGY4VUoRY

//  Approach 1 Sorting

//  Approach 2 Count Tracker

//  Approach 3 Summation Trick
// steps:
// 1. Sum of all the numbers in the array = n(n+1)/2
// 2. Sum of squares of all the numbers in the array = n(n+1)(2n+1)/6
// 3. Find the difference between the sum of all the numbers and the sum of the squares of all the numbers.
// 4. This difference is equal to (A-B)^2
// 5. Divide this difference with the difference between the sum of n natural numbers and the sum of the array elements
// 6. This gives A+B
// 7. A-B = A+B - (A+B)
// 8. A = (A+B + A-B)/2
// 9. B = (A+B - A+B)/2
// 10. A+B = (n(n+1)/2) and A-B = (n(n+1)(2n+1)/6)

//  Approach 4 Sign Trick
// steps:
// 1. Traverse the array
// 2. If the element is positive, make it negative
// 3. If the element is negative, that element is the repeating element
// 4. To find the missing element, traverse the array again
// 5. If the element is positive, that element is the missing element

//  Approach 5 Bit Manipulation XOR
// steps:
// 1. XOR all the elements of the array
// 2. XOR all the numbers from 1 to n
// 3. XOR of the above two gives A^B
// 4. Find the rightmost set bit in the above XOR
// 5. Initialize two variables A and B to 0
// 6. Traverse the array and check if the bit is set or not
// 7. If the bit is set, XOR the element with A
// 8. If the bit is not set, XOR the element with B
// 9. Traverse the array from 1 to n and check if the bit is set or not
// 10. If the bit is set, XOR the element with A
// 11. If the bit is not set, XOR the element with B
// 12. A and B are the repeating and the missing elements

//  Approach 6 swap sort
// https://youtu.be/f5bK6ZlG68I
// Time Complexity: O(n)
// Auxiliary Space: O(1)
int *findTwoElement(int *arr, int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            i++;
    }
    int *ans;
    ans = new int[2];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            ans[0] = arr[i];
            ans[1] = i + 1;
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
        cin >> arr[i];
    int *res = findTwoElement(arr, n);
    cout << res[0] << " " << res[1];
}

// Path: Searching & Sorting\96_Find_Missing_And_Repeating.cpp
// 96 Find the repeating and the missing

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=5n

// Approach 6 swap sort
int *findTwoElement(int *arr, int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            i++;
    }
    int *ans;
    ans = new int[2];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            ans[0] = arr[i];
            ans[1] = i + 1;
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
        cin >> arr[i];
    int *res = findTwoElement(arr, n);
    cout << res[0] << " " << res[1];
}