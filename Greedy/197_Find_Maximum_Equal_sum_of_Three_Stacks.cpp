// 197 Find maximum sum possible equal sum of three stacks

// Given three stacks S1, S2, and S3 of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed.Stacks are represented as an array, and the first index of the array represents the top element of the stack.

#include <bits/stdc++.h>
using namespace std;

int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
{
    int sum1 = accumulate(S1.begin(), S1.end(), 0);
    int sum2 = accumulate(S2.begin(), S2.end(), 0);
    int sum3 = accumulate(S3.begin(), S3.end(), 0);
    int maxSum = min(sum1, min(sum2, sum3));
    int i = 0, j = 0, k = 0;
    while (i < S1.size() && j < S2.size() && k < S3.size())
    {
        while (sum1 > maxSum)
        {
            if (sum1 - S1[i] < maxSum)
                break;
            sum1 -= S1[i++];
        }
        while (sum2 > maxSum)
        {
            if (sum2 - S2[j] < maxSum)
                break;
            sum2 -= S2[j++];
        }
        while (sum3 > maxSum)
        {
            if (sum3 - S3[k] < maxSum)
                break;
            sum3 -= S3[k++];
        }
        if (sum1 == maxSum && sum2 == maxSum && sum3 == maxSum)
            return maxSum;
        maxSum = min(sum1 - S1[i], min(sum2 - S2[j], sum3 - S3[k]));
    }
    return 0;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> s1(n1), s2(n2), s3(n3);
    for (int i = 0; i < n1; i++)
    {
        cin >> s1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> s2[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> s3[i];
    }
    cout << maxEqualSum(n1, n2, n3, s1, s2, s3);
}
