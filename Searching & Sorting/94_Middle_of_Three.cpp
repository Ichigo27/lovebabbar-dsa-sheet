// 94 Maximum and minimum of an array using minimum number of comparisons

// Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

#include<bits/stdc++.h>
using namespace std;

// Time Complexity:O(1)
// Auxillary Space:O(1)
int middle(int A, int B, int C)
{
    if (A < B)
        return (B < C) ? B : max(A, C);
    return (A < C) ? A : max(B, C);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << middle(a, b, c);
}