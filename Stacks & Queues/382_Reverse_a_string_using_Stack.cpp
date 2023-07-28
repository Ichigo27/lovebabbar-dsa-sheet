// 382

// You are given a string S, the task is to reverse the string using stack.

#include <bits/stdc++.h>
using namespace std;

char *reverse(char *S, int len)
{
    stack<char> s;
    int i = 0;
    while (i < len)
    {
        s.push(S[i++]);
    }
    i = 0;
    while(!s.empty())
    {
        S[i++] = s.top();
        s.pop();
    }
    return S;
}

int main()
{
    char S[1000];
    cin >> S;
    int len = strlen(S);
    char *rev = reverse(S, len);
    cout << rev;
    cout << endl;
}