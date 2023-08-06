// 411 Minimum sum of squares of character counts in a given string after removing “k” characters.

// Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=n5XaFXQjlIY

int minValue(string s, int k)
{
    int ans = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    priority_queue<int> pq;
    for(auto &ele: mp)
        pq.push(ele.second);
    for (int i = 0; i < k; i++)
    {
        int temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
    }
    while(!pq.empty())
    {
        ans += pq.top() * pq.top();
        pq.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << minValue(s, k) << endl;
}