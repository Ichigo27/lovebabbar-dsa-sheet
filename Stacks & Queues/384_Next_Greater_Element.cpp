// 384

// Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=T-E3hWEPWWU

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n, 0);
    stack<long long> st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<long long> res = nextLargerElement(arr, n);
    for (long long i : res)
        cout << i << " ";
}