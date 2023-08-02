// 392 Largest rectangular Area in Histogram

// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    long long maxArea = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
        {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (!st.empty())
                width = i - st.top() - 1;
            else
                width = i;
            maxArea = max(maxArea, height * 1LL * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << getMaxArea(arr, n) << endl;
}