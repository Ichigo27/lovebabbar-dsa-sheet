// 183 Program for Least Recently Used (LRU) Page Replacement algorithm

// In operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.

// Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number of page faults using Least Recently Used (LRU) Algorithm.

// Note:- Before solving this example revising the OS LRU cache mechanism is recommended.

#include <bits/stdc++.h>
using namespace std;

void increaseAge(vector<pair<int, int>> &cache)
{
    for (int i = 0; i < cache.size(); i++)
    {
        cache[i].second++;
    }
}

int pageFaults(int N, int C, int pages[])
{
    int pf = 0;
    vector<pair<int, int>> cache(C, {-1, 1000});
    for (int i = 0; i < N; i++)
    {
        int hit = 0;
        for (int j = 0; j < C; j++)
        {
            if (pages[i] == cache[j].first)
            {
                cache[j].second = 0;
                hit = 1;
                break;
            }
        }
        if (hit == 0)
        {
            pf++;
            int maxAge = 0, maxAgeIdx = -1;
            for (int j = 0; j < C; j++)
            {
                if (maxAge < cache[j].second)
                {
                    maxAge = cache[j].second;
                    maxAgeIdx = j;
                }
            }
            cache[maxAgeIdx].first = pages[i];
            cache[maxAgeIdx].second = 0;
        }
        increaseAge(cache);
    }
    return pf;
}

// /* Counts no. of page faults */
// int pageFaults(int n, int c, int pages[])
// {
//     // Initialise count to 0
//     int count = 0;

//     // To store elements in memory of size c
//     vector<int> v;
//     int i;
//     for (i = 0; i <= n - 1; i++)
//     {

//         // Find if element is present in memory or not
//         auto it = find(v.begin(), v.end(), pages[i]);

//         // If element is not present
//         if (it == v.end())
//         {

//             // If memory is full
//             if (v.size() == c)
//             {

//                 // Remove the first element
//                 // As it is least recently used
//                 v.erase(v.begin());
//             }

//             // Add the recent element into memory
//             v.push_back(pages[i]);

//             // Increment the count
//             count++;
//         }
//         else
//         {

//             // If element is present
//             // Remove the element
//             // And add it at the end as it is
//             // the most recent element
//             v.erase(it);
//             v.push_back(pages[i]);
//         }
//     }

//     // Return total page faults
//     return count;
// }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int c;
    cin >> c;
    cout << pageFaults(n, c, arr);
}