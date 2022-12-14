// 32 Three way partitioning of an array around a given value

// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Auxiliary Space: O(1)
void threeWayPartition(vector<int> &array, int a, int b)
{
    int i = 0, j = 0, k = array.size() - 1;
    while(j <= k)
    {
        if(array[j] < a)
        {
            swap(array[j++], array[i++]);
        }
        else if(array[j] > b)
        {
            swap(array[j], array[k--]);
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a, b;
    cin >> a >> b;
    threeWayPartition(arr, a, b);
}