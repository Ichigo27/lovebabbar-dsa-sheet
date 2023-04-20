// 161 Find the first non-repeating character from a stream of characters

// Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    vector<int> hsh(26, -1);
    string res = "";
    for (int i = 0; i < A.size(); i++)
    {
        if (hsh[A[i] - 'a'] == -1)
            hsh[A[i] - 'a'] = i;
        else
            hsh[A[i] - 'a'] = INT_MAX;
        int check = INT_MAX;
        char fns = '#';
        for (int j = 0; j < 26; j++)
        {
            if (hsh[j] != -1 && hsh[j] < check)
            {
                check = hsh[j];
                fns = j + 'a';
            }
        }
        res.push_back(fns);
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << FirstNonRepeating(s);
}