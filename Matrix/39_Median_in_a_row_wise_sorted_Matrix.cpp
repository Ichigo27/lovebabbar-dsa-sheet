// 39 Find median in a row wise sorted matrix

// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Idea is to store all the elements in a container, then sort it to find the median.
// Time Complexity: As we are sorting r*c elements so the time complexity is O(r*c*log(r*c))
// Space Complexity: As we are storing r*c elements so the space complexity is O(r*c)

// Expected Approach
// https://youtu.be/63fPPOdIr2c
// The idea is that for a number to be median there should be exactly (n/2) numbers that are less than this number. So, we try to find the count of numbers less than the selected number. We select the number by using binary search.
// Time Complexity: Binary search over the range from max num to min num takes log(range), for 32 bit integer it will take O(32), binary search over all the row takes O(R*log(C )) time. So the total complexity is O(32 * R * log ( C )).
// Space Complexity: As we not using any extra space so the time complexity is O(1).
int count(vector<int> &arr, int n, int num)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] <= num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    // code here
    int low = 1;
    int high = 2000;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int cnt = 0;
        for (int i = 0; i < R; i++)
            cnt += count(matrix[i], C, mid);
        if (cnt <= (R * C) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << median(arr, n, m);
}