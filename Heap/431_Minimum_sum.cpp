// 431 Minimum sum of two numbers formed from digits of an array

// Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=EROEvvVmOsQ

string stringSum(string num1, string num2)
{
    if (num1.size() == 0 && num2.size() == 0)
        return "0";
    if (num1.size() < num2.size())
        return stringSum(num2, num1);
    string ans = "";
    int n1 = num1.size(), n2 = num2.size();
    int diff = n1 - n2;
    int carry = 0;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int sum = (num1[i + diff] - '0') + (num2[i] - '0') + carry;
        carry = sum / 10;
        ans.push_back((sum % 10) + '0');
    }
    for (int i = n1 - n2 - 1; i >= 0; i--)
    {
        int sum = (num1[i] - '0') + carry;
        carry = sum / 10;
        ans.push_back((sum % 10) + '0');
    }
    if (carry != 0)
        ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

// Using min heap
string solve(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(arr[i]);
    string num1 = "", num2 = "";
    while (!minHeap.empty())
    {
        if (minHeap.top() == 0 && num1.size() == 0)
        {
            minHeap.pop();
            continue;
        }
        num1 += to_string(minHeap.top());
        minHeap.pop();
        if (!minHeap.empty())
        {
            num2 += to_string(minHeap.top());
            minHeap.pop();
        }
    }
    return stringSum(num1, num2);
}

// Using sorting
// string solve(int arr[], int n)
// {
//     sort(arr, arr + n);
//     string num1 = "", num2 = "";
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0 && num1.size() == 0)
//             continue;
//         if (i % 2 == 0)
//             num1 += to_string(arr[i]);
//         else
//             num2 += to_string(arr[i]);
//     }
//     return stringSum(num1, num2);
// }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << solve(arr, n) << endl;
}