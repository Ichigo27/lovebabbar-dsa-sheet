// 397 Stack Permutations (Check if an array is stack permutation of other)

// You are given two arrays A and B of unique elements of size N. Check if array B is a stack permutation of the array A or not.
// Stack permutation means that array B can be created from array A using a stack and stack operations.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Rkx2ru2q5S0
int isStackPermutation(int N, vector<int> &A, vector<int> &B)
{
    stack<int> st;
    int i = 0, j = 0;
    while(i < N)
    {
        st.push(A[i]);
        if(st.top() == B[j])
        {
            while (!st.empty() && st.top() == B[j])
            {
                st.pop();
                j++;
            }
        }
        i++;
    }
    if(st.empty())
        return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << isStackPermutation(n, A, B) << "\n";
}