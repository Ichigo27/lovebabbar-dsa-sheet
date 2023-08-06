// 413 Next Smaller Element

// Professor X wants his students to help each other in the chemistry lab. He suggests that every student should help out a classmate who scored less marks than him in chemistry and whose roll number appears after him. But the students are lazy and they don't want to search too far. They each pick the first roll number after them that fits the criteria. Find the marks of the classmate that each student picks.
// Note: one student may be selected by multiple classmates.

#include <bits/stdc++.h>
using namespace std;

// Next Smaller Element from the right

vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> ans(n, INT_MAX);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> res = help_classmate(arr, n);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
}