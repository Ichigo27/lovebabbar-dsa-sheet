// 117 Missing Number in AP

// Given three integers 'A' denoting the first term of an arithmetic sequence, 'C' denoting the common difference of an arithmetic sequence and an integer 'B'.you need to tell whether 'B' exists in the arithmetic sequence or not .Return 1 if B is present in the sequence.Otherwise, returns 0.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
int inSequence(int A, int B, int C)
{
    if (C == 0)
        return B == A;
    return B == A + (abs(A - B) / abs(C)) * C;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << inSequence(a, b, c);
}