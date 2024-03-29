// 190 Picking Up Chicks

// A flock of chickens are running east along a straight, narrow road. Each one is running with its own constant speed. Whenever a chick catches up to the one in front of it, it has to slow down and follow at the speed of the other chick. You are in a mobile crane behind the flock, chasing the chicks towards the barn at the end of the road. The arm of the crane allows you to pick up any chick momentarily, let the chick behind it pass underneath and place the picked up chick back down. This operation takes no time and can only be performed on a pair of chicks that are immediately next to each other, even if 3 or more chicks are in a row, one after the other.
// Given the initial locations (Xi) at time 0 and natural speeds (Vi) of the chicks, as well as the location of the barn (B), what is the minimum number of swaps you need to perform with your crane in order to have at least K of the N chicks arrive at the barn no later than time T?
// You may think of the chicks as points moving along a line. Even if 3 or more chicks are at the same location, next to each other, picking up one of them will only let one of the other two pass through. Any swap is instantaneous, which means that you may perform multiple swaps at the same time, but each one will count as a separate swap.

// Input

// The first line of the input gives the number of test cases, C. C test cases follow. Each test case starts with 4 integers on a line -- N, K, B and T. The next line contains the Ndifferent integers Xi, in increasing order. The line after that contains the N integers Vi. All distances are in meters; all speeds are in meters per second; all times are in seconds.

// Output

// For each test case, output one line containing "Case #x: S", where x is the case number (starting from 1) and S is the smallest number of required swaps, or the word "IMPOSSIBLE".

#include <bits/stdc++.h>
using namespace std;

void minSwaps(int n, vector<pair<int, int>> &c, int k, int b, int t, int j)
{
    int swaps = 0, slowChicks = 0, count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int remDist = b - c[i].first;
        int maxDist = c[i].second * t;
        if (maxDist >= remDist)
        {
            count++;
            if (slowChicks > 0)
                swaps += slowChicks;
        }
        else
        {
            slowChicks++;
        }
        if (count >= k)
            break;
    }
    if (count >= k)
        cout << "Case #" << j << ": " << swaps << endl;
    else
        cout << "Case #" << j << ": "
             << "IMPOSSIBLE" << endl;
}

int main()
{
    int t;
    cin >> t;
    int j = 1;
    while (t--)
    {
        int n, k, b, t;
        cin >> n >> k >> b >> t;
        vector<pair<int, int>> chicks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> chicks[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> chicks[i].second;
        }
        minSwaps(n, chicks, k, b, t, j++);
    }
}