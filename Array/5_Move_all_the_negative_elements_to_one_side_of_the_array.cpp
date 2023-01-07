// 5 Move all the negative elements to one side of the array

// An array contains both positive and negative numbers in random order.Rearrange the array elements so that all negative numbers appear before all positive numbers.

#include <bits/stdc++.h>
using namespace std;

// Naive approach: The idea is to sort the array of elements, this will make sure that all the negative elements will come before all the positive elements.
// Time Complexity: O(n*log(n)), Where n is the length of the given array.
// Auxiliary Space: O(n)

// Efficient Approach 1:
// The idea is to simply apply the partition process of quicksort (quickselect). 
// Time complexity: O(N) 
// Auxiliary Space: O(1)
void quicksort(vector<int> &a)
{
    int i = -1;
    int j = 0;
    while (j < a.size())
    {
        if (a[j] < 0)
        {
            swap(a[++i], a[j]);
        }
        j++;
    }
}

// Efficient Approach 2:
// Two Pointer Approach: The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply take two variables like left and right which hold the 0 and N-1 indexes.
// Time Complexity: O(N)
// Auxiliary Space : O(1)
void twopointer(vector<int> &a)
{
    int left = 0;
    int right = a.size() - 1;
    while (left <= right)
    {
        if (a[left] < 0 && a[right] < 0)
        {
            left++;
        }
        else if (a[left] < 0 && a[right] > 0)
        {
            left++;
            right--;
        }
        else if (a[left] > 0 && a[right] < 0)
        {
            swap(a[left++], a[right--]);
        }
        else if (a[left] > 0 && a[right] > 0)
        {
            right--;
        }
    }
}

// Efficient Approach 3:
// Dutch National Flag Algorithm: The first color will be for all negative integers and the second color will be for all positive integers. We will divide the array into three partitions with the help of two pointers, low and high. 
// Time complexity: O(N) 
// Auxiliary Space : O(1)
void DNFalgo(vector<int> &a)
{
    int low = 0;
    int high = a.size() - 1;
    while (low < high)
    {
        if (a[low] < 0)
            low++;
        else if (a[high] > 0)
            high--;
        else
            swap(a[low], a[high]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // quicksort(a);
    // twopointer(a);
    // DNFalgo(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}