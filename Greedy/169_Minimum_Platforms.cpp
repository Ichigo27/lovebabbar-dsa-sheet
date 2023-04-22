// 169 Minimum Platforms Problem

// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=dxVcMDI7vyI
// Time Complexity: O(nLogn)
// Auxiliary Space: O(n)
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat_needed = 1, i = 1, j = 0;
    int res = plat_needed;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            plat_needed--;
            j++;
        }
        res = max(res, plat_needed);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], dep[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    cout << findPlatform(arr, dep, n);
}