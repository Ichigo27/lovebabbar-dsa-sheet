// 4 Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

#include <bits/stdc++.h>
using namespace std;

// method 1: sort() - O(nlog(n))
// method 2: count number of 0, 1 and 2 and fill them - O(2n)
// method 3: Dutch National Flag Algorithm, or 3-way Partitioning - https://www.youtube.com/watch?v=oaVa-9wmpns
// Time complexity is O(n)
// Space complexity is O(1)
void sort012(int a[], int n)
{
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while(mid <= high)
        {
            if(a[mid] == 0)
            {
                swap(a[low++], a[mid++]);
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else if(a[mid] == 2)
            {
                swap(a[high--], a[mid]);
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
    sort012(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}