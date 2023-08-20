// 443 Find position of the only set bit

// Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

#include <bits/stdc++.h>
using namespace std;

// int findPosition(int N)
// {
//     if(N == 0)
//         return -1;
//     if((N & (N-1)) != 0)
//         return -1;
//     int count = 0;
//     while(N != 0)
//     {
//         N = N >> 1;
//         count++;
//     }
//     return count;
// }

int findPosition(int N)
{
    if(N == 0)
        return -1;
    if((N & (N-1)) != 0)
        return -1;
    return log2(N) + 1;
}


int main()
{
    int N;
    cin >> N;
    cout << findPosition(N) << endl;
}