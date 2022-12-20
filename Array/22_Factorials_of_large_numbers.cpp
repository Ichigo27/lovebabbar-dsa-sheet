// 22 Find factorial of a large number

// Given an integer N, find its factorial.

#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    int index = 0;
    vector<int> ans = {1};
    if(N == 0 || N == 1)
        return ans;
    int sum = 0, carry = 0;
    for (int i = 2; i <= N; i++)
    {
        for (auto digit = ans.begin(); digit != ans.end(); digit++)
        {
            int temp = (*digit) * i + carry;
            sum = temp % 10;
            *digit = sum;
            carry = temp / 10;
        }
        while(carry > 0)
        {
            ans.push_back(carry%10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans = factorial(n);
    for (auto ele : ans)
    {
        cout << ele;
    }
}