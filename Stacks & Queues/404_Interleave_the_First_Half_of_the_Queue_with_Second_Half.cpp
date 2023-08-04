// 404 Interleave the first half of the queue with second half

// You are given a queue Q of N integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_gJ3to4RyeQ?t=4347

// Using queue
// vector<int> rearrangeQueue(queue<int> &q)
// {
//     vector<int> ans;
//     queue<int> temp;
//     int n = q.size();
//     for (int i = 0; i < n / 2; i++)
//     {
//         temp.push(q.front());
//         q.pop();
//     }
//     while (!temp.empty() && !q.empty())
//     {
//         ans.push_back(temp.front());
//         temp.pop();
//         ans.push_back(q.front());
//         q.pop();
//     }
//     while (!temp.empty())
//     {
//         ans.push_back(temp.front());
//         temp.pop();
//     }
//     while (!q.empty())
//     {
//         ans.push_back(q.front());
//         q.pop();
//     }
//     return ans;
// }

// Using Stack
vector<int> rearrangeQueue(queue<int> &q)
{
    vector<int> ans;
    stack<int> temp;
    int n = q.size();
    for (int i = 0; i < n / 2; i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
    for (int i = 0; i < n - (n / 2); i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n / 2; i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty() && !q.empty())
    {
        ans.push_back(temp.top());
        temp.pop();
        ans.push_back(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        ans.push_back(temp.top());
        temp.pop();
    }
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    while (n--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    vector<int> a = rearrangeQueue(q);
    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop_back();
    }
    cout << "\n";
}