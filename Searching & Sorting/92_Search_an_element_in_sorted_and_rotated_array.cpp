// 92 Search in a rotated sorted array

// Given a sorted and rotated array A of N distinct elements which are rotated at some point, and given an element K. The task is to find the index of the given element K in array A.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/r3pMQ8-Ad5s
// Time Complexity: O(log N).
// Auxiliary Space: O(1).
int Search(vector<int> &vec, int K)
{
    int n = vec.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (vec[mid] == K)
        {
            return mid;
        }
        else if (vec[low] <= vec[mid])
        {
            if (K >= vec[low] && K <= vec[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (K >= vec[mid] && K <= vec[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int k;
    cin >> k;
    cout << Search(vec, k);
}