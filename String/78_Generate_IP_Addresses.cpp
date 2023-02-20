// 78 Program to generate all possible valid IP addresses from given  string.

// Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
// Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

// For string 11211 the IP address possible are
// 1.1.2.11
// 1.1.21.1
// 1.12.1.1
// 11.2.1.1

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^3), where n is the length of the string
// Three nested traversal of the string is needed, where n is always less than 12.
// Auxiliary Space: O(n).
// As extra space is needed.
bool checkIp(vector<string> ip)
{
    for (string &x : ip)
    {
        if (x.size() > 3 || stoi(x) < 0 || stoi(x) > 255)
            return false;
        if (x.size() > 1 && stoi(x) == 0)
            return false;
        if (x.size() > 1 && stoi(x) > 0 && x[0] == '0')
            return false;
    }
    return true;
}

vector<string> genIp(string &s)
{
    vector<string> ans;
    int n = s.size();
    if (n < 4 || n > 12)
        return ans;
    for (int i = 1; i < n - 2; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            for (int k = 1; k < n - i - j; k++)
            {
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                string c = s.substr(i + j, k);
                string d = s.substr(i + j + k, n - i - j - k);
                vector<string> ip = {a, b, c, d};
                if (checkIp(ip))
                {
                    ans.push_back(a + '.' + b + '.' + c + '.' + d);
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = genIp(s);
    for (auto &ip: ans)
    {
        cout << ip << endl;
    }
}