// 24 Find longest coinsecutive subsequence

// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

#include <bits/stdc++.h>
using namespace std;

// Naive Approach: Sort and Count
// Time Complexity: O(NlogN)
// Auxiliary Space: O(N)

// Optimal Approach 1: Using Priority Queue
// Time Complexity: O(NlogN)
// Auxiliary Space: O(N)
// int findLongestConseqSubseq(int arr[], int N)
// {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int i = 0; i < N; i++)
//     {

//         // adding element from
//         // array to PriorityQueue
//         pq.push(arr[i]);
//     }

//     // Storing the first element
//     // of the Priority Queue
//     // This first element is also
//     // the smallest element
//     int prev = pq.top();
//     pq.pop();

//     // Taking a counter variable with value 1
//     int c = 1;

//     // Storing value of max as 1
//     // as there will always be
//     // one element
//     int max = 1;
//     while (!pq.empty())
//     {

//         // check if current peek
//         // element minus previous
//         // element is greater than
//         // 1 This is done because
//         // if it's greater than 1
//         // then the sequence
//         // doesn't start or is broken here
//         if (pq.top() - prev > 1)
//         {

//             // Store the value of counter to 1
//             // As new sequence may begin
//             c = 1;

//             // Update the previous position with the
//             // current peek And remove it
//             prev = pq.top();
//             pq.pop();
//         }

//         // Check if the previous
//         //  element and peek are same
//         else if (pq.top() - prev == 0)
//         {

//             // Update the previous position with the
//             // current peek And remove it
//             prev = pq.top();
//             pq.pop();
//         }

//         // If the difference
//         // between previous element and peek is 1
//         else
//         {

//             // Update the counter
//             // These are consecutive elements
//             c++;

//             // Update the previous position
//             //  with the current peek And remove it
//             prev = pq.top();
//             pq.pop();
//         }

//         // Check if current longest
//         // subsequence is the greatest
//         if (max < c)
//         {

//             // Store the current subsequence count as
//             // max
//             max = c;
//         }
//     }
//     return max;
// }

// Optimal Approach 2: Using Hashing
// Time Complexity: O(N)
// Auxiliary Space: O(N)
int findLongestConseqSubseq(int arr[], int N)
{
    int ans = 0;
    int curr = 0;
    int maxi = INT_MIN;
    int hsh[100005] = {0};
    for (int i = 0; i < N; i++)
    {
        maxi = max(maxi, arr[i]);
        hsh[arr[i]]++;
    }
    for (int i = 1; i <= maxi; i++)
    {
        if (hsh[i] > 0)
        {
            curr++;
        }
        else
        {
            curr = 0;
        }
        ans = max(ans, curr);
    }
    return ans;
}

//  hashing gfg
// int findLongestConseqSubseq(int arr[], int n)
// {
//     unordered_set<int> S;
//     int ans = 0;

//     // Hash all the array elements
//     for (int i = 0; i < n; i++)
//         S.insert(arr[i]);

//     // check each possible sequence from
//     // the start then update optimal length
//     for (int i = 0; i < n; i++)
//     {
//         // if current element is the starting
//         // element of a sequence
//         if (S.find(arr[i] - 1) == S.end())
//         {
//             // Then check for next elements
//             // in the sequence
//             int j = arr[i];
//             while (S.find(j) != S.end())
//                 j++;

//             // update  optimal length if
//             // this length is more
//             ans = max(ans, j - arr[i]);
//         }
//     }
//     return ans;
// }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findLongestConseqSubseq(arr, n);
}