// 10 Minimum no. of Jumps to reach end of an array

// Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

#include <bits/stdc++.h>
using namespace std;

// method 1: Brute Force using Recursion and Backtracking
// A simple approach to solve this problem is to start from the first element of the array and recursively travel to all elements that are reachable from that element. Similarly, recursively travel to all other elements and find the minimum jumps to reach the end of the array.
// Time Complexity: O(N^N), where N is the total elements in the array.
// Space Complexity: O(1), since no extra space is used.

// method 2: Greedy Approach
// https://www.youtube.com/watch?v=5Du2iSRrbEw
// Time complexity: O(n)
// Auxiliary Space: O(1)
int minJumps(int arr[], int n)
{
    int reachable, steps, jumps;

    // stores all time the maximal reachable index in the array.
    reachable = arr[0];
    // stores the number of steps we can still take
    steps = arr[0];
    // stores the number of jumps necessary to reach that maximal reachable position.
    jumps = 1;

    // The number of jumps needed to reach the starting index is 0
    if(n == 1)
        return 0;

    // Return -1 if not possible to jump
    if(arr[0] == 0)
        return -1;

    for (int i = 1; i < n-1; i++)
    {
        // updating reachable
        reachable = max(reachable, i + arr[i]);
        // we use a step to get to the current index
        steps--;
        // If no further steps left
        if(steps == 0)
        {
            // we must have used a jump
            jumps++;
            // check whether a step is becoming zero or negative
            if(i >= reachable)
                return -1;
            // re-initialize the steps to the amount of steps to reach reachable from position i.
            steps = reachable - i;
        }
    }

    return jumps;
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
    cout << minJumps(arr, n);
}