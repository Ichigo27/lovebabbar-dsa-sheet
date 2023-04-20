// 162 Activity Selection Problem

// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second <= b.second;
    return a.first <= b.first;
}

int maxMeetings(int start[], int end[], int n)
{
    int maxtime = *max_element(end, end + n);
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; i++)
    {
        meetings[i] = {start[i], end[i]};
    }
    sort(meetings.begin(), meetings.end(), compare);
    int ans = 0, prevEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (prevEnd < meetings[i].first)
        {
            ans++;
            prevEnd = meetings[i].second;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];
    cout << maxMeetings(start, end, n);
}
