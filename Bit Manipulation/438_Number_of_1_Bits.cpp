// 438 Count set bits in an integer

// Given a positive integer N, print count of set bits in it.

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(logN)
// Space Complexity: O(1)
// int setBits(int N)
// {
//     int cnt = 0;
//     while(N)
//     {
//         cnt += N & 1;
//         N >= 1;
//     }
//     return cnt;
// }

// Time Complexity: O(logN)
// Space Complexity: O(1)
// int setBits(int N)
// {
//     int cnt = 0;
//     while(N)
//     {
//         N = N & (N-1);
//         cnt++;
//     }
//     return cnt;
// }

// Time Complexity: O(1)
// Space Complexity: O(1)
int setBits(int N)
{
    return __builtin_popcount(N);
}


int main()
{
    int N;
    cin>>N;
    cout<<setBits(N)<<endl;
}