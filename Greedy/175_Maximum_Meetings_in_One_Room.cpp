// 175 Find maximum meetings in one room

// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

// Note: If two meetings can be chosen for the same slot then choose meeting with smaller index in the given array.

#include <bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    vector<pair<int, int>> meetings;
    for (int i = 0; i < N; i++)
        meetings.push_back({F[i], i});
    sort(meetings.begin(), meetings.end());
    vector<int> ans;
    ans.push_back(meetings[0].second + 1);
    int prev = meetings[0].first;
    for (int i = 1; i < N; i++)
    {
        if (S[meetings[i].second] > prev)
        {
            ans.push_back(meetings[i].second + 1);
            prev = meetings[i].first;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    vector<int> ans = maxMeetings(n, s, f);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}