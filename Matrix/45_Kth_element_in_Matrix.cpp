// 45 Kth smallest element in a row-cpumn wise sorted matrix

// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

#include <bits/stdc++.h>
using namespace std;

// Using Max Heap
// The easy approach is that we iterate all elements in the matrix and and add elements into the maxHeap. The maxHeap will keep up to k smallest elements (because when maxHeap is over size of k, we do remove the top of maxHeap which is the largest one). Finally, the top of the maxHeap is the kth smallest element in the matrix.
// Time Complexity: O(M*N*log(K))
// Auxiliary Space: O(K)

// Using Binary Search
// This approach uses binary search to iterate over possible solutions. We know that 
//     answer >= mat[0][0]
//     answer <= mat[M-1][N-1]
// So we do a binary search on this range and in each  iteration determine the no of elements greater than or equal to our current middle element. The elements greater than or equal to current element can be found in O( n logn ) time using binary search.
// Time Complexity: O((M*Log(N))*Log(D))
// Auxiliary Space: O(1)
int kthSmallest(vector<vector<int>> &mat, int k)
{
    // Your code here
    int n = mat.size();
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    while (low < high)
    {
        int mid = low + ((high - low) >> 1);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        if (cnt < k)
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    int k;
    cin >> k;
    cout << kthSmallest(arr, k);
}