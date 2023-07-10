// 287 Maximum difference of zeros and ones in binary string

// Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

// Note: In the case of all 1s, the answer will be -1.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// Dynamic Programming
int maxSubstring(string S)
{
    int n = S.length();
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = S[i] == '0' ? 1 : -1;
        sum = max(curr, sum + curr);
        ans = max(ans, sum);
    }
    return ans != 0 ? ans : -1;
}


// Kadane's Algorithm
// int maxSubstring(string S)
// {
//     int n = S.length();
//     int sum = 0;
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int curr = S[i] == '0' ? 1 : -1;
//         sum += curr;
//         ans = max(ans, sum);
//         if (sum < 0)
//             sum = 0;
//     }
//     return ans != 0 ? ans : -1;
// }

int main()
{
    string S;
    cin >> S;
    cout << maxSubstring(S) << endl;
}