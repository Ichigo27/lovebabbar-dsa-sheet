// 114 Book Allocation Problem

// You are given N number of books. Every ith book has Ai number of pages.
// You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

// Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=gYmWHvRHu-s

// Time Complexity: O(N*log (M - max)), where N is the number of different books , max denotes the maximum number of pages from all the books and M denotes the sum of number of pages of all different books
// Auxiliary Space: O(1)

bool is_possible(int arr[], int n, int m, int p)
{
    int total = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > p)
            return false;
        if (total + arr[i] > p)
        {
            cnt++;
            total = arr[i];
        }
        else
        {
            total += arr[i];
        }
    }
    if (cnt > m)
        return false;
    return true;
}

int findPages(int A[], int N, int M)
{
    if (N < M)
        return -1;
    int res = INT_MAX;
    int low = *min_element(A, A + N), high = accumulate(A, A + N, 0), mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (is_possible(A, N, M, mid))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    cout << findPages(arr, n, m);
}