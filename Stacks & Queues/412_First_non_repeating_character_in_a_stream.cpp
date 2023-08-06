// 412 Queue based approach or first non-repeating character in a stream.

// Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

// NOTE:
// 1. You need to find the answer for every i (0 <= i < n)
// 2. In order to find the solution for every i you need to consider the string from starting position till ith position.

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    string ans = "";
    int check[26];
    memset(check, 0, sizeof(check));
    queue<int> q;
    for (int i = 0; i < A.size(); i++)
    {
        char ch = A[i];
        if (check[ch - 'a'] == 0)
            q.push(ch);
        check[ch - 'a']++;
        while (!q.empty() && check[q.front() - 'a'] > 1)
            q.pop();
        ans.push_back(!q.empty() ? q.front() : '#');
    }
    return ans;
}

int main()
{
    string A;
    cin >> A;
    cout << FirstNonRepeating(A) << endl;
}
